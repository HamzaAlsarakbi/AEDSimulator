#ifndef AED_H
#define AED_H

#include <QObject>
#include <iostream>
#include <QThread>
#include <vector>
#include "AEDWorker.h"
#include "../patient/Patient.h"

using namespace std;

enum AEDStatus {
    AED_ON,
    AED_OFF,
    AED_BATTERY_DEAD,
    CHANGE_BATTERY,
    AED_TEST_FAIL,
    UNIT_OK,
    CHECK_RESPONSIVENESS,
    CALL_HELP,
    ATTACH_PADS,
    DONT_TOUCH_PATIENT,
    SHOCK_ADVISED,
    SHOCK_NOT_ADVISED,
    START_CPR,
    AED_PATIENT_HEALTHY
};

enum ConnectionStatus {
    GOOD, BAD, NONE
};

class AED: public QObject {
    Q_OBJECT
    QThread workerThread;
public:
    AED();
    ~AED();
    // Getters and setters
    AEDStatus getStatus() { return status; }
    ConnectionStatus getConnectionStatus() { return connection; }
    int getBattery() const { return battery; }
    int getShocksCount() const { return shocks; }
    int getHeartRate() const { return patient->getHeartRate(); }
    HeartStatus getHeartStatus() const { return patient->getHeart()->getStatus(); }
    long long getBasePulseTime() const { return patient->getHeart()->getBasePulseTime(); }
    long long getPulseTimeVariance() const { return patient->getHeart()->getPulseTimeVariance(); }
    int getPulsesCount() const { return patient->getHeart()->getPulsesCount(); }
    bool isPassing() const { return !doesTestFail; }
    int getMinCompressionDepth() const { return patient->getMinCompressionDepth(); }
    int getMaxCompressionDepth() const { return patient->getMaxCompressionDepth(); }
    void setBattery(int battery) { this->battery = battery; }
    void setTestFail(bool state) { doesTestFail = state; }
    void setPadPlacement(ConnectionStatus status);
    void setAge(int value) { patient->setAge(value); }
    void cpr(double depth);
    void administerShock();

    // Test-related functions
    //void startSelfTest();
    void changeBatteries();

    // AED steps
    void turnOff();
    void resetBattery();
    void shock();

private:
    QThread thread;
    bool threadActive;
    AEDStatus status;
    int battery;
    int shocks;
    bool doesTestFail = false;
    Patient* patient;
    ConnectionStatus connection;
    double lastCompressionDepth;

public slots:
    void handleTurnOn();
    void handleTurnOff();
    void handleSelfTest();
    void handleChangeBattery();
    void handleCheckResponsiveness();
    void handleCallHelp();
    void handleAttachPads();
    void handleCheckConnection();
    void handleTypeOfPads();
    void handleDontTouchPatient();
    void handleStartCpr();
    void handleShockAdvised();
    void handlePatientHealthy();
    void handleShock();
    void handleUpdateHeartRate();

signals:
    void initTurnOn();
    void initSelfTest();
    void initChangeBattery();
    void initCheckResponsiveness();
    void initCallHelp();
    void initAttachPads();
    void initCheckConnection();
    void initTypeOfPads();
    void initDontTouchPatient();
    void initStartCpr();
    void initShockAdvised();
    void initShockNotAdvised();
    void initPatientHealthy();
    void initUpdateHeartRate();
    void update(AEDStatus state);
    void updateDisplay(std::string text);

    void initShock();

};


#endif //AED_H
