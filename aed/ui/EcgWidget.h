//
// Created by Hamza on 2023-12-07.
//

#ifndef AED_ECGWIDGET_H
#define AED_ECGWIDGET_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <cmath>
#include "../model/patient/heart/pulse/Pulse.h"

class EcgWidget : public QWidget {
    Q_OBJECT
public:
    explicit EcgWidget(QWidget *parent=nullptr);
public slots:
    void draw(std::vector<Pulse> pulses);

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    std::vector<Pulse> pulses;
    int heartRate;
};


#endif //AED_ECGWIDGET_H
