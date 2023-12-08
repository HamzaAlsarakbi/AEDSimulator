//
// Created by Hamza on 2023-12-07.
//

#include <iostream>
#include <QRandomGenerator>
#include "EcgWidget.h"

EcgWidget::EcgWidget(QWidget *parent): QWidget(parent), pulses({}), totalTime(0) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMaximumWidth(10000);
    setMaximumHeight(10000);
}

void EcgWidget::draw(long long totalTime, std::vector<Pulse*> pulses) {
    this->totalTime = totalTime;
    this->pulses = pulses;
    repaint();
}

void EcgWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    int amplitude = 50;
    const int totalWidth = ((totalTime % 6000) / 6000.0) * width();
    int unit = (width() / 6); // 1s
    int bigBox = (width() / 6) * .2; // 0.20s
    int smallBox = (width() / 6) * .04; // 0.04s


    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::lightGray);
//    set origin at
//      [         ]
//      [*        ]
//      [         ]
    painter.translate(0, height() / 2);
//    1 second vertical lines
    for (int x = 0; x < width(); x += unit) {
        painter.drawLine(x, -height(), x, height());
    }
//    big box horizontal lines
    for (int y = -height()/2; y < height()/2; y += bigBox) {
        painter.drawLine(0, y, width(), y);
    }

    // std::vector<int> xCenter = {};
    std::vector<int> xLeft = {};
    std::vector<PulseType> pulseTypes = {};
    // std::vector<int> xRight = {};
    for(Pulse* pulse : pulses) {
        int xPos = ((pulse->getTime().count() % 6000) / 6000.0) * width();
        if(xPos < totalWidth) {
            xLeft.push_back(xPos);
            pulseTypes.push_back(pulse->getType());
        }
    }

    int x = 0;
    QPointF prevPoint;
    const double amp = 1;
    const double vtachAmp = 1;
    const double vfibAmp = 20;
    painter.setPen(Qt::blue);
    while (x <= totalWidth) {
        double y = QRandomGenerator::global()->bounded((int) -1*amp, (int) amp+1);
        QPointF curPoint(x, y);
        // std::cout << "empty? " << xLeft.empty() << ", x: " << x << ", Left.at(0): " << (xLeft.empty() ? -1 : xLeft[0]) << std::endl;
        if(!xLeft.empty() && x == xLeft.at(0)) {
            // std::cout << "ommak line" << std::endl;
            painter.drawLine(x, -height(), x, height());
            xLeft.erase(xLeft.begin());
            int size = 20;
            if(!xLeft.empty()) {
                if(pulseTypes[0] == PULSE_VFIB || x+size > xLeft.at(0)) {
                    size = xLeft.at(0)- x -1;
                }
            }
            for(int ix = x; ix < x+size; ix++) {
                if (pulseTypes[0] == PULSE_ASYSTOLE) {
                    y = QRandomGenerator::global()->bounded((int) -1*amp, (int) amp+1);
                } else if (pulseTypes[0] == PULSE_VTACH) {
                    y = vtachAmp * std::sin(2.0 * size * M_PI * ix / width());
                } else if (pulseTypes[0] == PULSE_VFIB) {
                    y = QRandomGenerator::global()->bounded((int) -1*vfibAmp, (int) amp+1);
                }
                curPoint = QPointF(ix, y);
                painter.drawLine(prevPoint, curPoint);
                prevPoint = curPoint;
            }
            x += size;

            pulseTypes.erase(pulseTypes.begin());
        } else {
            painter.drawLine(prevPoint, curPoint);
        }
        prevPoint = curPoint;
        x++;
    }


//    QPointF prevPoint;
//    painter.setPen(Qt::black);
//    for (int xPos : xCenter) {
//        int xStart = xPos - interval/2;
//        int xEnd = xPos + interval/2;
//        for(int x = xStart; x < xEnd; x++) {
//            QPointF currentPoint(x, -y);
//            painter.drawLine(prevPoint, currentPoint);
//            prevPoint = currentPoint;
//        }
//    }
}