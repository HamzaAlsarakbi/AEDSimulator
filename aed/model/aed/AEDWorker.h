#ifndef AEDWorker_H
#define AEDWorker_H

#include <QObject>
#include <QThread>


class AEDWorker : public QObject {
    Q_OBJECT

public:
    using WaitCallback = std::function<void()>;

private:
    const unsigned long stepDuration = 2;
    const unsigned long testDuration = 2;
    const unsigned long turnOnDuration = 2;

public slots:
    void waitTurnOn() {
        QThread::sleep(turnOnDuration);
        emit readyTurnOn();
    }
    void waitSelfTest() {
        QThread::sleep(testDuration);
        emit readySelfTest();
    }
    void waitCheckResponsiveness() {
        QThread::sleep(stepDuration);
        emit readyCheckResponsiveness();
    }
    void waitCallHelp() {
        QThread::sleep(stepDuration);
        emit readyCallHelp();
    }
    void waitAttachPads() {
        QThread::sleep(stepDuration);
        emit readyAttachPads();
    }
    void waitCheckConnection() {
        QThread::sleep(stepDuration);
        emit readyCheckConnection();
    }
    void waitTypeOfPads() {
        QThread::sleep(stepDuration);
        emit readyTypeOfPads();
    }
    void waitDontTouchPatient() {
        QThread::sleep(stepDuration);
        emit readyDontTouchPatient();
    }
    void waitStartCpr() {
        QThread::sleep(stepDuration);
        emit readyStartCpr();
    }
    void waitChangeBattery()    {
        QThread::sleep(stepDuration);
        emit readyChangeBattery();
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
};

#endif
