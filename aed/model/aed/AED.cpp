#include "AED.h"

AED::AED()
: battery(100), status(AED_OFF), connection(NONE), shocks(0),
patient(new Patient(PSC_NORMAL))
{
    AEDWorker* worker = new AEDWorker;
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &AED::initTurnOn, worker, &AEDWorker::waitTurnOn);
    connect(this, &AED::initSelfTest, worker, &AEDWorker::waitSelfTest);
    connect(this, &AED::initCheckResponsiveness, worker, &AEDWorker::waitCheckResponsiveness);
    connect(this, &AED::initCallHelp, worker, &AEDWorker::waitCallHelp);
    connect(this, &AED::initAttachPads, worker, &AEDWorker::waitAttachPads);
    connect(this, &AED::initCheckConnection, worker, &AEDWorker::waitCheckConnection);
    connect(this, &AED::initTypeOfPads, worker, &AEDWorker::waitTypeOfPads);
    connect(this, &AED::initDontTouchPatient, worker, &AEDWorker::waitDontTouchPatient);
    connect(this, &AED::initStartCpr, worker, &AEDWorker::waitStartCpr);
    connect(this, &AED::initShockAdvised, worker, &AEDWorker::waitShockAdvised);
    connect(this, &AED::initPatientHealthy, worker, &AEDWorker::waitPatientHealthy);
    connect(this, &AED::initChangeBattery, worker, &AEDWorker::waitChangeBattery);
    connect(this, &AED::initShock, worker, &AEDWorker::waitShock);
    connect(this, &AED::initUpdateHeartRate, worker, &AEDWorker::waitUpdateHeartRate);

    connect(worker, &AEDWorker::readyTurnOn, this, &AED::handleTurnOn);
    connect(worker, &AEDWorker::readySelfTest, this, &AED::handleSelfTest);
    connect(worker, &AEDWorker::readyChangeBattery, this, &AED::handleChangeBattery);
    connect(worker, &AEDWorker::readyCheckResponsiveness, this, &AED::handleCheckResponsiveness);
    connect(worker, &AEDWorker::readyCallHelp, this, &AED::handleCallHelp);
    connect(worker, &AEDWorker::readyAttachPads, this, &AED::handleAttachPads);
    connect(worker, &AEDWorker::readyCheckConnection, this, &AED::handleCheckConnection);
    connect(worker, &AEDWorker::readyTypeOfPads, this, &AED::handleTypeOfPads);
    connect(worker, &AEDWorker::readyDontTouchPatient, this, &AED::handleDontTouchPatient);
    connect(worker, &AEDWorker::readyStartCpr, this, &AED::handleStartCpr);
    connect(worker, &AEDWorker::readyShockAdvised, this, &AED::handleShockAdvised);
    connect(worker, &AEDWorker::readyPatientHealthy, this, &AED::handlePatientHealthy);
    connect(worker, &AEDWorker::readyShock, this, &AED::handleShock);
    connect(worker, &AEDWorker::readyUpdateHeartRate, this, &AED::handleUpdateHeartRate);
    workerThread.start();
    emit initUpdateHeartRate();
}

AED::~AED(){
    workerThread.quit();
    workerThread.wait();
    delete patient;
}

void AED::setPadPlacement(ConnectionStatus connection) {
    if(status == AED_OFF) return;
    this->connection = connection;
    emit handleAttachPads();
}

void AED::handleTurnOn() {
    if(battery <= 0) return;
    status = AED_ON;
    connection = NONE;
    emit update(status);
    emit initSelfTest();
}
void AED::handleSelfTest() {
    if(status < 2) return;
    addLoadOnBattery(2);
    if (!doesTestFail){
        status = UNIT_OK;
        emit initCheckResponsiveness();
    } else {
        status = AED_TEST_FAIL;
    }
    emit update(status);
}
void AED::handleChangeBattery() {
    if (battery <= 0) {
        status = CHANGE_BATTERY;
        emit initChangeBattery();
    } else {
        emit initTurnOn();
    }
    emit update(status);
}
void AED::handleTurnOff() {
    status = AED_OFF;
    connection = NONE;
    emit update(status);
}
void AED::handleCheckResponsiveness() {
    if(status < 2) return;
    status = CHECK_RESPONSIVENESS;
    emit update(status);
    emit initCallHelp();
}
void AED::handleCallHelp() {
    if(status < 2) return;
    status = CALL_HELP;
    emit update(status);
    emit initAttachPads();
}
void AED::handleAttachPads() {
    if(status < 2) return;
    addLoadOnBattery(1);
    status = ATTACH_PADS;
    emit update(status);
    if(connection == GOOD) {
        emit initTypeOfPads();
    } else if (connection == BAD) {
        emit initCheckConnection();
    } else {
        emit initAttachPads();
    }
}
void AED::handleCheckConnection() {
    if(status < 2) return;
    addLoadOnBattery(1);
    if (connection != GOOD) {
        emit updateDisplay("CHECK CONNECTION HABIBI");
        emit initCheckConnection();
    } else {
        emit initTypeOfPads();
    }
}
void AED::handleTypeOfPads() {
    if(status < 2) return;
    emit updateDisplay(patient->getAge() < 8 ? "CHILD PADZ" : "ADULT PADZ");
    emit initDontTouchPatient();
}
void AED::handleDontTouchPatient() {
    if(status < 7) return;
    addLoadOnBattery(4);
    status = DONT_TOUCH_PATIENT;
    emit update(status);
    // keep checking until you have a proper heart rate
    if(patient->getHeartRate() == -1) {
        emit initDontTouchPatient();
        return;
    } else if(patient->shockable()) {
        emit initShockAdvised();
        return;
    } else if (patient->cprAble()) {
        emit initStartCpr();
        return;
    }
    emit initPatientHealthy();
}
void AED::handleStartCpr() {
    if(status <= 7) return;
    if(status != START_CPR) {
        status = START_CPR;
        emit update(status);
    }
    if(patient->shockable()) {
        emit initShockAdvised();
    } else if (!patient->cprAble()) {
        emit initPatientHealthy();
    } else {
        emit initStartCpr();
    }
}
void AED::handleShockAdvised() {
    if(status < 7) return;
    if(status != SHOCK_ADVISED) {
        status = SHOCK_ADVISED;
        emit update(status);
    }
    if(patient->shockable()) {
        emit initShockAdvised();
    } else if (patient->cprAble()) {
        emit initStartCpr();
    } else {
        emit initPatientHealthy();
    }
}
void AED::handlePatientHealthy() {
    if(status < 7) return;
    status = AED_PATIENT_HEALTHY;
    emit update(status);
    if(patient->shockable()) {
        emit initShockAdvised();
    } else if (patient->cprAble()) {
        emit initStartCpr();
    } else {
        emit initPatientHealthy();
    }
}

void AED::administerShock() {
    if(status != SHOCK_ADVISED) return;
    updateDisplay("Administering shock in 3...2...1");
    emit initShock();
}


void AED::cpr(double depth) {
    if(status < 6) return;
    emit update(status);
    CompressionResult result = patient->cpr(depth);
    std::vector<std::string> resultStr = { "GOOD COMPRESSION", "HARDER ;)", "SOFTER :(", "SLOWER :(", "FASTER ;)" };
    emit updateDisplay(resultStr.at(result));
    if(patient->shockable()) {
        emit initShockAdvised();
    } else if (!patient->cprAble()) {
        emit initPatientHealthy();
    }
}
void AED::handleUpdateHeartRate() {
    emit initUpdateHeartRate();
}
/**
 * Administers a shock
 */
void AED::handleShock() {
    if(status < 6) return;
    if(battery <= 10) {
        emit updateDisplay("NOT ENOUGH BATTERY FOR SHOCK");
        emit initChangeBattery();
        return;
    }
    addLoadOnBattery(10);
    shocks++;
    patient->shock();
    emit initStartCpr();
}

void AED::addLoadOnBattery(int load) {
    battery -= load;
    if(battery <= 0) handleChangeBattery();
}
/**
 * Resets the patient's starting condition
*/
void AED::resetPatient(PatientSCondition condition) {
    patient->reset(condition);
}