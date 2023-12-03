#include "AED.h"

AED::AED()
: battery(100), status(AED_OFF), connection(NONE), lastCompressionDepth(-1.0) {
    AEDWorker* worker = new AEDWorker;
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &AED::initTurnOn, worker, &AEDWorker::waitTurnOn);
    connect(this, &AED::initSelfTest, worker, &AEDWorker::waitSelfTest);
    connect(this, &AED::initCheckResponsiveness, worker, &AEDWorker::waitCheckResponsiveness);
    connect(this, &AED::initCallHelp, worker, &AEDWorker::waitCallHelp);
    connect(this, &AED::initAttachPads, worker, &AEDWorker::waitAttachPads);
    connect(this, &AED::initDontTouchPatient, worker, &AEDWorker::waitDontTouchPatient);
    connect(this, &AED::initStartCpr, worker, &AEDWorker::waitStartCpr);
    connect(this, &AED::initChangeBattery, worker, &AEDWorker::waitChangeBattery);

    connect(worker, &AEDWorker::readyTurnOn, this, &AED::handleTurnOn);
    connect(worker, &AEDWorker::readySelfTest, this, &AED::handleSelfTest);
    connect(worker, &AEDWorker::readyChangeBattery, this, &AED::handleChangeBattery);
    connect(worker, &AEDWorker::readyCheckResponsiveness, this, &AED::handleCheckResponsiveness);
    connect(worker, &AEDWorker::readyCallHelp, this, &AED::handleCallHelp);
    connect(worker, &AEDWorker::readyAttachPads, this, &AED::handleAttachPads);
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

void AED::setTestFail(bool state){
    doesTestFail = state;
}
bool AED::getTestFail(){return doesTestFail;}

void AED::setBattery(int battery) {
    this->battery = battery;
    std::cout << "todo emit signal to update batteryLabel from AED::setBattery(...)" << std::endl;
}
int AED::getBattery(){return battery;}

void AED::setPadPlacement(ConnectionStatus connection) {
    this->connection = connection;
    emit handleAttachPads();
}

void AED::handleTurnOn() {
    status = AED_ON;
    connection = NONE;
    emit initSelfTest();   
}
void AED::handleSelfTest() {
    if (doesTestFail == false){
        status = UNIT_OK;
        std::cout << "todo emit signal to set display to UNIT OK" << std::endl;
        emit initCheckResponsiveness();
    }
    else {
        status = AED_TEST_FAIL;
        std::cout << "todo emit signal to set display to TEST FAIL" << std::endl;
    }   
}
void AED::handleChangeBattery() {
    if (battery == 0) {
        std::cout << "todo emit signal to set display to CHANGE BATTERIES" << std::endl;
        emit initChangeBattery();
    }
    else {
        std::cout << "new battery detected" << std::endl;
        emit initSelfTest();
    }
}
void AED::handleTurnOff() {
    status = AED_OFF;
    connection = NONE;
    lastCompressionDepth = -1.0;
    std::cout << "todo emit signal to set display to blank" << std::endl;
}
void AED::handleCheckResponsiveness() {
    if (battery == 0){emit initChangeBattery();}
    else {
        std::cout << "todo emit signal to set display to CHECK RESPONSIVENESS" << std::endl;
        emit initCallHelp();   
    }
}
void AED::handleCallHelp() {
    if (battery == 0){emit initChangeBattery();}
    else {
        std::cout << "todo emit signal to set display to CALL FOR HELP" << std::endl;
        emit initAttachPads();   
    }   
}
void AED::handleAttachPads() {
    std::cout << "todo emit signal to set display to ATTACH DEFIB PADS TO PATIENT'S CHEST" << std::endl;
    if(connection == GOOD) {
        emit initDontTouchPatient();
        return;
    }
    else if (connection == BAD) {
        std::cout << "todo emit signal to set display to ATTACH DEFIB PADS TO PATIENT'S CHEST" << std::endl;
    }
}
void AED::handleDontTouchPatient() {
    std::cout << "todo emit signal to set display to dont touch patient" << std::endl;
    emit initStartCpr(); 
}
void AED::handleStartCpr() {
    std::cout << "todo emit signal to set display to Start cpr" << std::endl;
    
}