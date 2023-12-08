#ifndef AEDWorker_H
#define AEDWorker_H

#include <QObject>
#include <QThread>


class AEDWorker : public QObject {
    Q_OBJECT

private:
    // milliseconds
    const unsigned long stepDuration = 10;
    const unsigned long dontTouchPatientDuration = 7000;
    const unsigned long testDuration = 10;
    const unsigned long turnOnDuration = 10;
    const unsigned long shockDuration = 3000;

public slots:
    void waitTurnOn() {
        QThread::msleep(turnOnDuration);
        emit readyTurnOn();
    }
    void waitSelfTest() {
        QThread::msleep(testDuration);
        emit readySelfTest();
    }
    void waitCheckResponsiveness() {
        QThread::msleep(stepDuration);
        emit readyCheckResponsiveness();
    }
    void waitCallHelp() {
        QThread::msleep(stepDuration);
        emit readyCallHelp();
    }
    void waitAttachPads() {
        QThread::msleep(stepDuration);
        emit readyAttachPads();
    }
    void waitCheckConnection() {
        QThread::msleep(stepDuration);
        emit readyCheckConnection();
    }
    void waitTypeOfPads() {
        QThread::msleep(stepDuration);
        emit readyTypeOfPads();
    }
    void waitDontTouchPatient() {
        QThread::msleep(dontTouchPatientDuration);
        emit readyDontTouchPatient();
    }
    void waitStartCpr() {
        QThread::msleep(stepDuration);
        emit readyStartCpr();
    }
    void waitShockAdvised() {
        QThread::msleep(stepDuration);
        emit readyShockAdvised();
    }
    void waitPatientHealthy() {
        QThread::msleep(stepDuration);
        emit readyPatientHealthy();
    }
    void waitChangeBattery() {
        QThread::msleep(stepDuration);
        emit readyChangeBattery();
    }
    void waitShock() {
        QThread::msleep(shockDuration);
        emit readyShock();
    }
    void waitUpdateHeartRate() {
        QThread::msleep(100);
        emit readyUpdateHeartRate();
    }

signals:
    void readyTurnOn();
    void readySelfTest();
    void readyChangeBattery();
    void readyCheckResponsiveness();
    void readyCallHelp();
    void readyAttachPads();
    void readyCheckConnection();
    void readyTypeOfPads();
    void readyDontTouchPatient();
    void readyStartCpr();
    void readyShockAdvised();
    void readyPatientHealthy();
    void readyShock();
    void readyUpdateHeartRate();
};

#endif
