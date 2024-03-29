#include "AED.h"
#include <QRandomGenerator>
/**
 * @brief Construct a new AED::AED object
 *
 */
AED::AED()
: battery(100), status(AED_OFF), connection(NONE), shocks(0),
patient(new Patient(PSC_NORMAL))
{
    qRegisterMetaType<WaitFor>("WaitFor");
    aedWorker = new AEDWorker();
    aedWorker->moveToThread(&workerThread);
    workerThread.start();
    connect(&workerThread, &QThread::finished, aedWorker, &QObject::deleteLater);
    connect(this, SIGNAL(wait(WaitFor)), aedWorker,SLOT(wait(WaitFor)));
    connect(aedWorker, SIGNAL(ready(WaitFor)), this, SLOT(handle(WaitFor)));
    emit wait(WF_UPDATE_HEART_RATE);
    emit wait(WF_CHECK_BATTERY);
}

/**
 * @brief Destroy the AED::AED object
 *
 */
AED::~AED(){
    aedWorker->abort = true;
    workerThread.exit();
    delete aedWorker;
    delete patient;
    workerThread.wait();
}

/**
 * @brief User attaches pad to the patient 
 * 
 * @param connection (ConnectionStatus) The quality of the connection to the patient
 */
void AED::setPadPlacement(ConnectionStatus connection) {
    this->connection = connection;
    if(connection != NONE || status == AED_OFF) return;
    aedWorker->abort = true;
    std::this_thread::sleep_for(milliseconds(11));
    aedWorker->abort = false;
    emit wait(WF_CHECK_CONNECTION);
    emit wait(WF_UPDATE_HEART_RATE);
}

/**
 * @brief Turns on, then calls for self test
 *
 */
void AED::turnOnHandler() {
    if(battery <= 0) return;
    aedWorker->abort = false;
    status = AED_ON;
    connection = NONE;
    emit update(status);
    emit wait(WF_SELF_TEST);
}

/**
 * @brief Operates self test, then calls to check responsiveness of patient
 *
 */
void AED::selfTestHandler() {
    if(status < 2) return;
    addLoadOnBattery(2);
    if (!doesTestFail){
        status = UNIT_OK;
        emit wait(WF_CHECK_RESPONSIVENESS);
    } else {
        status = AED_TEST_FAIL;
    }
    emit update(status);
}

/**
 * @brief Checks for the battery. replays until battery is not 0
 *
 */
void AED::checkBatteryHandler() {
    if (battery <= 0) {
        status = CHANGE_BATTERY;
        emit update(status);
    } else if (battery <= 10) {
        emit updateDisplay("BATTERY LOW");
    } else {
        if(status == CHANGE_BATTERY) {
            status = AED_OFF;
            emit update(status);
        }
    }
    emit wait(WF_CHECK_BATTERY);
}

/**
 * @brief Turns off device
 *
 */
void AED::turnOffHandler() {
    status = AED_OFF;
    aedWorker->abort = true;
    connection = NONE;
    shocks = 0;
    emit update(status);
}

/**
 * @brief Asks the user to check responsiveness of the patient
 *
 */
void AED::checkResponsivenessHandler() {
    if(status < 4) return;
    status = CHECK_RESPONSIVENESS;
    emit update(status);
    emit wait(WF_CALL_HELP);
}

/**
 * @brief Asks the user to call for help
 *
 */
void AED::callHelpHandler() {
    if(status < 5) return;
    status = CALL_HELP;
    emit update(status);
    emit wait(WF_ATTACH_PADS);
}

/**
 * @brief Checks the quality of connection. if good quality, move on
 *
 */
void AED::attachPadsHandler() {
    if(status < 6) return;
    if(status != ATTACH_PADS) {
        addLoadOnBattery(1);
        status = ATTACH_PADS;
        emit update(status);
    }
    emit wait(WF_CHECK_CONNECTION);
}

/**
 * @brief Checks the connection of the pads onto the patient
 *
 */
void AED::checkConnectionHandler() {
    if(status < ATTACH_PADS) return;
    if(status == ATTACH_PADS) {
        if (connection == GOOD) {
            addLoadOnBattery(1);
            status = DONT_TOUCH_PATIENT;
            update(status);
            emit updateDisplay(patient->getAge() < 8 ? "CHILD PADZ" : "ADULT PADZ");
            emit wait(WF_BEFORE_DONT_TOUCH_PATIENT);
        } else if(connection == BAD) {
            update(status);
            emit updateDisplay("CHECK CONNECTION");
        }
    } else if(status > ATTACH_PADS && connection == NONE) {
        // if we lost the connection after attaching the pads
        status = ATTACH_PADS;
        emit update(status);
    }
    emit wait(WF_CHECK_CONNECTION);
}
/**
 * @brief Checks the connection of the pads onto the patient
 *
 */
void AED::beforeDontTouchPatient() {
    status = DONT_TOUCH_PATIENT;
    update(status);
    emit wait(WF_DONT_TOUCH_PATIENT);
}

/**
 * @brief Asks user not to shock patient while analyzing
 *
 */
void AED::dontTouchPatientHandler() {
    if(status < 7) return;
    addLoadOnBattery(4);
    status = DONT_TOUCH_PATIENT;
    emit update(status);
    // keep checking until you have a proper heart rate
    if(patient->getHeartRate() == -1) {
        emit updateDisplay("UNABLE TO GET A GOOD HEART RATE READING. RETRYING...");
        emit wait(WF_DONT_TOUCH_PATIENT);
    } else if(patient->shockable()) {
        shockAdvisedHandler();
    } else if (patient->cprAble()) {
        startCprHandler();
    } else {
        patientHealthyHandler();
    }
}

/**
 * @brief Advises the user to use the defibrillator on the patient
 *
 */
void AED::shockAdvisedHandler() {
    if(status < 8) return;
    if(status != SHOCK_ADVISED) {
        status = SHOCK_ADVISED;
        emit update(status);
    }
}

/**
 * @brief Gives warning for shock
 *
 */
void AED::administerShock() {
    if(status != SHOCK_ADVISED) return;
    updateDisplay("ADMINISTERING SHOCK IN 3...2...1");
    emit wait(WF_ADMINISTER_SHOCK);
}
/**
 * @brief Administers a shock
 *
 */
void AED::administerShockHandler() {
    if(status != SHOCK_ADVISED) return;
    if(battery <= 10) {
        emit updateDisplay("NOT ENOUGH BATTERY FOR SHOCK");
        return;
    }
    addLoadOnBattery(10);
    // determine if it's a valid shock, with the following percentages of success [25%, 33%, 50%, 100%]
    if(shocks > 3 || QRandomGenerator::global()->bounded((int) 4-shocks) == 0) {
        patient->shock();
    }
    shocks++;
    status = DONT_TOUCH_PATIENT;
    emit update(status);
    emit updateDisplay("SHOCK ADMINISTERED, ANALYZING PATIENT");
    emit wait(WF_BEFORE_DONT_TOUCH_PATIENT);
}

/**
 * @brief Asks the user to start CPR
 *
 */
void AED::startCprHandler() {
    if(status < 8) return;
    if(status != START_CPR) {
        status = START_CPR;
        emit update(status);
    }
}

/**
 * @brief User does one complete push to the chest
 *
 * @param depth (double) The compression depth the user applies
 */
void AED::cpr(double depth) {
    if(status != START_CPR) return;
    emit update(status);
    CompressionResult result = patient->cpr(depth);
    std::vector<std::string> resultStr = { "GOOD COMPRESSION", "HARDER", "SOFTER", "SLOWER", "FASTER" };
    emit updateDisplay(resultStr.at(result));
    if(patient->getHeartRate() > 60) {
        status = DONT_TOUCH_PATIENT;
        emit update(status);
        emit wait(WF_DONT_TOUCH_PATIENT);
    }
}

/**
 * @brief Alerts user of the patient's health and stop operation
 *
 */
void AED::patientHealthyHandler() {
    if(status < 8) return;
    status = AED_PATIENT_HEALTHY;
    emit update(status);
}

/**
 * @brief Changes the display of the ECG
 *
 */
void AED::updateHeartRateHandler() {
    emit updateUiHeartRate();
    emit wait(WF_UPDATE_HEART_RATE);
}

/**
 * Base Handler for wait events, routes them by the waitFor parameter
 * @param waitFor what was the AEDWorker waiting for
 */
void AED::handle(WaitFor waitFor) {
    switch (waitFor) {
        case WF_SELF_TEST:
            selfTestHandler();
            break;
        case WF_CHECK_BATTERY:
            checkBatteryHandler();
            break;
        case WF_CHECK_CONNECTION:
            checkConnectionHandler();
            break;
        case WF_UPDATE_HEART_RATE:
            updateHeartRateHandler();
            break;
        case WF_ADMINISTER_SHOCK:
            administerShockHandler();
            break;
        case WF_CHECK_RESPONSIVENESS:
            checkResponsivenessHandler();
            break;
        case WF_CALL_HELP:
            callHelpHandler();
            break;
        case WF_ATTACH_PADS:
            attachPadsHandler();
            break;
        case WF_BEFORE_DONT_TOUCH_PATIENT:
            beforeDontTouchPatient();
            break;
        case WF_DONT_TOUCH_PATIENT:
            dontTouchPatientHandler();
            break;
    }
}

/**
 * @brief Depletes the battery by some variable amount
 * 
 * @param load (int) the amount of charge the battery is depleted
 */
void AED::addLoadOnBattery(int load) {
    battery -= load;
}

/**
 * @brief Resets the patient's starting condition
 * 
 * @param condition (PatientSCondition) The heartrate of the patient
 */
void AED::resetPatient(PatientSCondition condition) {
    patient->reset(condition);
}