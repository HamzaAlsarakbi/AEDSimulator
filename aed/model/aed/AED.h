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
    AED_OFF,                // 0
    CHANGE_BATTERY,         // 1
    AED_ON,                 // 2
    AED_TEST_FAIL,          // 3
    UNIT_OK,                // 4

    CHECK_RESPONSIVENESS,   // 5
    CALL_HELP,              // 6
    ATTACH_PADS,            // 7
    DONT_TOUCH_PATIENT,     // 8

    SHOCK_ADVISED,          // 9
    START_CPR,              // 10
    AED_PATIENT_HEALTHY     // 11
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
    bool isHeartNull() const { return patient->getHeart() == nullptr; }
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
    void resetPatient(PatientSCondition condition);

private:
    QThread thread;
    AEDStatus status;
    int battery;
    int shocks;
    bool doesTestFail = false;
    Patient* patient;
    ConnectionStatus connection;
    void addLoadOnBattery(int load);

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
