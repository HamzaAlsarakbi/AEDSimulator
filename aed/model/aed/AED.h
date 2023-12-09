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
    void turnOnHandler();
    void selfTestHandler();
    void checkBatteryHandler();
    void checkResponsivenessHandler();
    void callHelpHandler();
    void attachPadsHandler();
    void checkConnectionHandler();
    void beforeDontTouchPatient();
    void dontTouchPatientHandler();
    void startCprHandler();
    void shockAdvisedHandler();
    void patientHealthyHandler();
    void administerShockHandler();
    void updateHeartRateHandler();

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
    void handle(WaitFor);
    void turnOffHandler();

signals:
    void wait(WaitFor);
    void update(AEDStatus state);
    void updateDisplay(std::string text);
    void updateUiHeartRate();

};


#endif //AED_H
