#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model/aed/AED.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void batterySliderHandler(int value);
    void baseDepthSliderHandler(int value);
    void baseDepthVarianceSliderHandler(int value);
    void ageSliderHandler(int value);
    void qrsWidthSliderHandler(int value);
    void qrsWidthVarianceSliderHandler(int value);
    
    void turnOnHandler();
    void turnOffHandler();
    void changeBatteriesHandler();
    void padsCorrectHandler();
    void padsIncorrectHandler();
    void administerShockHandler();
    void cprHandler();
    void failTestHandler();

private:
    Ui::MainWindow *ui;
    AED* aedDevice;
    void connectUI();
};
#endif // MAINWINDOW_H
