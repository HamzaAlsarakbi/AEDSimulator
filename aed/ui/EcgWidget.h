//
// Created by Hamza on 2023-12-07.
//

#ifndef AED_ECGWIDGET_H
#define AED_ECGWIDGET_H

#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <cmath>

class EcgWidget : public QWidget {
    Q_OBJECT
public:
    explicit EcgWidget(QWidget *parent=nullptr);
public slots:
    void draw(int heartRate);

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    std::vector<long long> timestamps;
    int heartRate;
};


#endif //AED_ECGWIDGET_H
