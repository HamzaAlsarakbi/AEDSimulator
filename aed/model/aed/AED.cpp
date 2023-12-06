#include "AED.h"

AED::AED()
: battery(100), status(AED_OFF), connection(NONE), lastCompressionDepth(-1.0), shocks(0) {
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
    workerThread.start();
}

AED::~AED(){
    workerThread.quit();
    workerThread.wait();
}

void AED::resetBattery() {
    setBattery(100);
    if(status != AED_BATTERY_DEAD) return;
    emit initSelfTest();
    
}

void AED::setPadPlacement(ConnectionStatus connection) {
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
    if (!doesTestFail){
        status = UNIT_OK;
        emit initCheckResponsiveness();
    }
    else {
        status = AED_TEST_FAIL;
        std::cout << "todo emit signal to set display to TEST FAIL" << std::endl;
    }
    emit update(status);
}
void AED::handleChangeBattery() {
    if (battery == 0) {
        std::cout << "todo emit signal to set display to CHANGE BATTERIES" << std::endl;
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
    status = CHECK_RESPONSIVENESS;
    if (battery == 0){emit initChangeBattery();}
    else {
        emit initCallHelp();
    }
    emit update(status);
}
void AED::handleCallHelp() {
    status = CALL_HELP;
    if (battery == 0){emit initChangeBattery();}
    else {
        emit initAttachPads();
    }
    emit update(status);
}
void AED::handleAttachPads() {
    battery--;
    status = ATTACH_PADS;
    if (battery == 0){emit initChangeBattery();}
    else {
        if(connection == GOOD) {
            emit initTypeOfPads();
            emit update(status);
            return;
        }
        else if (connection == BAD) {
            emit initCheckConnection();
            emit update(status);
            return;
        }
        else {
            emit initAttachPads();
        }
    }
    emit update(status);
}
void AED::handleCheckConnection() {
    battery--;
    if (connection != GOOD) {
        std::cout << "todo emit signal to set display to CHECK CONNECTION" << std::endl;
        emit initCheckConnection();
    }
    else {
        emit initTypeOfPads();
    }
    emit update(status);
}
void AED::handleTypeOfPads() {
    /*
    if (patient->getAge() <= 8) {std::cout << "todo emit signal to set display to CHILD PADS" << std::endl;}
    else {std::cout << "todo emit signal to set display to ADULT PADS" << std::endl;}
    */
    std::cout << "Will display type of pads" << std::endl;
    emit initDontTouchPatient();
    emit update(status);
}
void AED::handleDontTouchPatient() {
    battery -= 4;
    status = DONT_TOUCH_PATIENT;
    emit initStartCpr();
    emit update(status);
}
void AED::handleStartCpr() {
    status = START_CPR;
    emit update(status);
}

void AED::cpr(double depth) {
    battery--;
    std::cout << "todo pass depth to Patient class from AED::cpr(...)" << std::endl;
}
/**
 * Administers a shock
 */
void AED::shock() {
    shocks++;
    battery -= 10;
    std::cout << "todo pass shock() invokation to Patient class from AED::shock()" << std::endl;
}