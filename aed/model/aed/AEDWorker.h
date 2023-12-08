#ifndef AEDWorker_H
#define AEDWorker_H

#include <QObject>
#include <QThread>
#include <iostream>

enum WaitFor {
    WF_SELF_TEST,               // 0
    WF_CHECK_BATTERY,           // 1
    WF_CHECK_CONNECTION,        // 2
    WF_UPDATE_HEART_RATE,        // 3

    WF_ADMINISTER_SHOCK,        // 4

    WF_CHECK_RESPONSIVENESS,    // 5
    WF_CALL_HELP,               // 6
    WF_ATTACH_PADS,             // 7
    WF_BEFORE_DONT_TOUCH_PATIENT,      // 8
    WF_DONT_TOUCH_PATIENT,      // 9
};

class AEDWorker : public QObject {
Q_OBJECT

private:
    // milliseconds
    const unsigned long stepDuration = 1000;
    const unsigned long tickDuration = 10;
    const unsigned long checkDuration = 10;
    const unsigned long dontTouchPatientDuration = 7000;
    const unsigned long testDuration = 1000;
    const unsigned long shockDuration = 3000;
public:
    bool abort = false;

public slots:
    void wait(WaitFor waitFor) {
        const unsigned long totalDuration =
                waitFor == WF_SELF_TEST ? testDuration :
                waitFor < WF_ADMINISTER_SHOCK ? checkDuration :
                waitFor == WF_ADMINISTER_SHOCK ? shockDuration :
                waitFor == WF_DONT_TOUCH_PATIENT ? dontTouchPatientDuration :
                stepDuration;
        unsigned long duration = 0;
        while (!abort && duration < totalDuration) {
            QThread::msleep(tickDuration);
            duration += tickDuration;
        }
        if (abort) return;
        emit ready(waitFor);

    };

signals:
    void ready(WaitFor);
};

#endif
