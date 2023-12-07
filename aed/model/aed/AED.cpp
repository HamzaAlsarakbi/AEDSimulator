#include "AED.h"

AED::AED()
: battery(100), status(AED_OFF), connection(NONE), lastCompressionDepth(-1.0), shocks(0),
patient(new Patient(PSC_HEART_ATTACK))
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
    workerThread.start();
}

AED::~AED(){
    workerThread.quit();
    workerThread.wait();
    delete patient;
}

void AED::resetBattery() {
    setBattery(100);
    if(status != AED_BATTERY_DEAD) return;
    if(status == AED_OFF) return;
    emit initSelfTest();
}

void AED::setPadPlacement(ConnectionStatus connection) {
    if(status == AED_OFF) return;
    this->connection = connection;
    emit handleAttachPads();
}

void AED::handleTurnOn() {
    status = AED_ON;
    connection = NONE;
    emit update(status);
    emit initSelfTest();
}
void AED::handleSelfTest() {
    if(status == AED_OFF) return;
    if (!doesTestFail){
        status = UNIT_OK;
        emit initCheckResponsiveness();
    }
    else {
        status = AED_TEST_FAIL;
    }
    emit update(status);
}
void AED::handleChangeBattery() {
    if (battery == 0) {
        status = CHANGE_BATTERY;
        emit initChangeBattery();
    }
    else {
        emit initSelfTest();
    }

    emit update(status);
}
void AED::handleTurnOff() {
    status = AED_OFF;
    connection = NONE;
    lastCompressionDepth = -1.0;
    emit update(status);
}
void AED::handleCheckResponsiveness() {
    if(status == AED_OFF) return;
    status = CHECK_RESPONSIVENESS;
    if (battery == 0){emit initChangeBattery();}
    else {
        emit initCallHelp();
    }
    emit update(status);
}
void AED::handleCallHelp() {
    if(status == AED_OFF) return;
    status = CALL_HELP;
    if (battery == 0){emit initChangeBattery();}
    else {
        emit initAttachPads();
    }
    emit update(status);
}
void AED::handleAttachPads() {
    if(status == AED_OFF) return;
    battery--;
    status = ATTACH_PADS;
    if (battery == 0) {
        emit initChangeBattery();
        return;
    }
    if(connection == GOOD) {
        emit initTypeOfPads();
    } else if (connection == BAD) {
        emit initCheckConnection();
    } else {
        emit initAttachPads();
    }
    emit update(status);
}
void AED::handleCheckConnection() {
    if(status == AED_OFF) return;
    battery--;
    if (connection != GOOD) {
        emit updateDisplay("CHECK CONNECTION HABIBI");
        emit initCheckConnection();
    }
    else {
        emit initTypeOfPads();
        emit update(status);
        emit updateDisplay(patient->getAge() < 8 ? "CHILD PADZ" : "ADULT PADZ");
    }
}
void AED::handleTypeOfPads() {
    if(status == AED_OFF) return;
    emit initDontTouchPatient();
    emit update(status);
}
void AED::handleDontTouchPatient() {
    if(status == AED_OFF) return;
    battery -= 4;
    status = DONT_TOUCH_PATIENT;
    // keep checking until you have a proper heart rate
    if(patient->getHeartRate() == -1) {
        emit initDontTouchPatient();
    } else if(patient->shockable()) {
        emit initShockAdvised();
    } else if (patient->cprAble()) {
        emit initStartCpr();
    } else {
        emit initPatientHealthy();
    }
    emit update(status);
}
void AED::handleStartCpr() {
    if(status == AED_OFF) return;
    status = START_CPR;
    emit update(status);
}
void AED::handleShockAdvised() {
    if(status == AED_OFF) return;
    status = SHOCK_ADVISED;
    emit update(status);
}
void AED::handlePatientHealthy() {
    if(status == AED_OFF) return;
    status = AED_PATIENT_HEALTHY;
    emit update(status);
}


void AED::cpr(double depth) {
    if(status == AED_OFF) return;
    battery--;
    patient->cpr(depth);
    std::cout << "todo pass depth to Patient class from AED::cpr(...)" << std::endl;
}
/**
 * Administers a shock
 */
void AED::shock() {
    if(status == AED_OFF) return;
    shocks++;
    battery -= 10;
    std::cout << "todo pass shock() invokation to Patient class from AED::shock()" << std::endl;
}