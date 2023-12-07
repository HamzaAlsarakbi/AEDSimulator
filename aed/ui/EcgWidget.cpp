//
// Created by Hamza on 2023-12-07.
//

#include <iostream>
#include "EcgWidget.h"

EcgWidget::EcgWidget(QWidget *parent): QWidget(parent), timestamps({}), heartRate(0) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMaximumWidth(1000);
    setMaximumHeight(1000);
}

void EcgWidget::draw(int heartRate) {
//    this->timestamps = timestamps;
    this->heartRate = heartRate;
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

//    draw generic sine wave (temp, implement full thing if we got time)
    painter.setPen(Qt::black);
    QPointF prevPoint;
    int frequency = heartRate / 10;
    for (int x = -width(); x < width(); ++x)
    {
        double y = amplitude * std::sin(2.0 * frequency * M_PI * x / width());
        QPointF curPoint(x, -y);
        if (x > -width())
            painter.drawLine(prevPoint, curPoint);
        prevPoint = curPoint;
    }

    std::vector<int> xPositions = {};
    int interval = timestamps.empty() ? 0 : width() / timestamps.size();
    for(int i = 0; i < timestamps.size(); i++) {
        xPositions.push_back(interval/2 + interval*i);
    }

    // center-point of each pulse
//    painter.setPen(Qt::red);
//    for (int xPos : xPositions) {
//        painter.drawLine(xPos, -height(), xPos, height());
//    }


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