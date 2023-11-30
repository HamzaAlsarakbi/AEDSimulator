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
    connect(worker, &AEDWorker::readyTurnOn, this, &AED::handleTurnOn);
    connect(worker, &AEDWorker::readySelfTest, this, &AED::handleSelfTest);
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

void AED::setBattery(int battery) {
    this->battery = battery;
    std::cout << "todo emit signal to update batteryLabel from AED::setBattery(...)" << std::endl;
}
void AED::setPadPlacement(ConnectionStatus connection) {
    this->connection = connection;
    emit handleAttachPads();
}

void AED::handleTurnOn() {
    emit initSelfTest();   
}
void AED::handleTurnOff() {
    status = AED_OFF;
    connection = NONE;
    lastCompressionDepth = -1.0;
    std::cout << "todo emit signal to set display to blank" << std::endl;
}
void AED::handleSelfTest() {
}
void AED::handleCheckResponsiveness() {
    std::cout << "todo emit signal to set display to check responsiveness" << std::endl;
    emit initCallHelp();
}
void AED::handleCallHelp() {
    std::cout << "todo emit signal to set display to Call help" << std::endl;
    emit initDontTouchPatient();   
}
void AED::handleAttachPads() {
    if(connection == GOOD) {
        emit initDontTouchPatient();
        return;
    }
    std::cout << "todo emit signal to set display to check or plug in patient" << std::endl;
}
void AED::handleDontTouchPatient() {
    std::cout << "todo emit signal to set display to dont touch patient" << std::endl;
    emit initStartCpr(); 
}
void AED::handleStartCpr() {
    std::cout << "todo emit signal to set display to Start cpr" << std::endl;
    
}