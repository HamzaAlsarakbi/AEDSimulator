#ifndef AED_H
#define AED_H

#include <QObject>
#include <iostream>
#include <QThread>
#include <vector>
#include "AEDWorker.h"
//#include "../model/patient/Patient.h"

using namespace std;

enum AEDStatus {
    CHECK_RESPONSIVENESS,
    CALL_HELP,
    ATTACH_PADS,
    DONT_TOUCH_PATIENT,
    START_CPR,
    AED_OFF,
    AED_BATTERY_DEAD,
    AED_TEST_FAIL
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

    // Test-related functions
    //void startSelfTest();
    void changeBatteries();

    // AED steps
    void turnOff();
    void turnOn();  // Initiates self-test
    void setPadPlacement(ConnectionStatus status);
    void resetBattery();
    void setBattery(int battery);
    void setLastCompressDepth(double depth);
    void updateState();

private:
    QThread thread;
    bool threadActive;
    AEDStatus status;
    int battery;
    // Patient* patient;
    ConnectionStatus connection;
    double lastCompressionDepth;

public slots:
    void handleTurnOn();
    void handleTurnOff();
    void handleSelfTest();
    void handleCheckResponsiveness();
    void handleCallHelp();
    void handleAttachPads();
    void handleDontTouchPatient();
    void handleStartCpr();
signals:
    void initTurnOn();
    void initSelfTest();
    void initCheckResponsiveness();
    void initCallHelp();
    void initAttachPads();
    void initDontTouchPatient();
    void initStartCpr();
};


#endif //AED_H
