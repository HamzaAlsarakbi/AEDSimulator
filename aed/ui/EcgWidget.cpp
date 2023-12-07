//
// Created by Hamza on 2023-12-07.
//

#include <iostream>
#include "EcgWidget.h"

EcgWidget::EcgWidget(QWidget *parent): QWidget(parent), pulses({}), heartRate(0) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMaximumWidth(1000);
    setMaximumHeight(1000);
}

void EcgWidget::draw(std::vector<Pulse> pulses) {
    this->pulses = pulses;
    repaint();
}

void EcgWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    int amplitude = 50;
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
    for (int x = -width(); x < width(); x += unit) {
        painter.drawLine(x, -height(), x, height());
    }
//    big box horizontal lines
    for (int y = -height()/2; y < height()/2; y += bigBox) {
        painter.drawLine(0, y, width(), y);
    }

    std::vector<int> xPositions = {};
    int interval = pulses.empty() ? 0 : width() / pulses.size();
    for(int i = 0; i < pulses.size(); i++) {
        xPositions.push_back(interval/2 + interval*i);
    }

    // center-point of each pulse
   painter.setPen(Qt::red);
   for (int xPos : xPositions) {
       painter.drawLine(xPos, -height(), xPos, height());
   }


//    QPointF prevPoint;
//    painter.setPen(Qt::black);
//    for (int xPos : xPositions) {
//        int xStart = xPos - interval/2;
//        int xEnd = xPos + interval/2;
//        for(int x = xStart; x < xEnd; x++) {
//            QPointF currentPoint(x, -y);
//            painter.drawLine(prevPoint, currentPoint);
//            prevPoint = currentPoint;
//        }
//    }
}