#include <iostream>
#include <QRandomGenerator>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    aedDevice = new AED();

    connectUI();
    update(aedDevice->getStatus());
    ui->depthSlider->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete aedDevice;
}
void MainWindow::connectUI() {
    // Sliders
    connect(ui->batterySlider, &QSlider::valueChanged, this, &MainWindow::batterySliderHandler);
    connect(ui->baseDepthSlider, &QSlider::valueChanged, this, &MainWindow::baseDepthSliderHandler);
    connect(ui->baseDepthVarianceSlider, &QSlider::valueChanged, this, &MainWindow::baseDepthVarianceSliderHandler);
    connect(ui->ageSlider, &QSlider::valueChanged, this, &MainWindow::ageSliderHandler);
    connect(ui->qrsWidthSlider, &QSlider::valueChanged, this, &MainWindow::qrsWidthSliderHandler);
    connect(ui->qrsWidthVarianceSlider, &QSlider::valueChanged, this, &MainWindow::qrsWidthVarianceSliderHandler);

    // Buttonss
    connect(ui->turnOnButton, &QPushButton::pressed, this, &MainWindow::turnOnHandler);
    connect(ui->turnOffButton, &QPushButton::pressed, this, &MainWindow::turnOffHandler);
    connect(ui->changeBatteriesButton, &QPushButton::pressed, this, &MainWindow::changeBatteriesHandler);
    connect(ui->attachDefibPadsCorrectlyButton, &QPushButton::pressed, this, &MainWindow::padsCorrectHandler);
    connect(ui->attachDefibPadsIncorrectlyButton, &QPushButton::pressed, this, &MainWindow::padsIncorrectHandler);
    connect(ui->administerShockButton, &QPushButton::pressed, this, &MainWindow::administerShockHandler);
    connect(ui->cprButton, &QPushButton::pressed, this, &MainWindow::cprHandler);
    connect(aedDevice, SIGNAL(update(AEDStatus)), this, SLOT(update(AEDStatus)));
}
void MainWindow::update(AEDStatus status) {
    std::vector<QString> displayStrings = { "TURNING ON", "", "BATTERY DEAD", "CHANGE BATTERY", "TEST FAIL", "UNIT OK", "CHECK RESPONSIVENESS", "CALL HELP", "ATTACH PADS TO PATIENT'S CHEST", "DON'T TOUCH PATIENT, ANALYZING", "SHOCK ADVISED", "SHOCK NOT ADVISED", "START CPR" };
    std::vector<QFrame*> indicators = { ui->indicator1, ui->indicator2, ui->indicator3, ui->indicator4, ui->indicator5 };
    ui->displayLabel->setText(displayStrings.at(status));

//    AED Controls
    ui->turnOnButton->setDisabled(status != AED_OFF);
    ui->turnOffButton->setDisabled(status == AED_OFF);
//    AED Screen
    ui->batteryLabel->setText(status == AED_OFF ? "" : QString::fromStdString(std::to_string(aedDevice->getBattery()) + "%"));
    ui->shocksCount->setText(status == AED_OFF ? "" : QString::number(aedDevice->getShocksCount()));
//    AED Lights
    ui->testPassIndicator->setStyleSheet(aedDevice->isPassing() ? "background-color: green" : "background-color: red");
    for(int i = 0; i < indicators.size(); i++) {
        indicators.at(i)->setStyleSheet(i == (status-6) ? "background-color: green" : "background-color: gray");
        std::cout << "i: " << i << ", status+6: " << status-6 << ", status: " << displayStrings.at(status).toStdString() <<  std::endl;
    }



//    Rescuer Controls
    ui->batterySlider->setValue(aedDevice->getBattery());
    ui->changeBatteriesButton->setVisible(false);
    ui->attachDefibPadsCorrectlyButton->setVisible(status == ATTACH_PADS && aedDevice->getConnectionStatus() != GOOD);
    ui->attachDefibPadsIncorrectlyButton->setVisible(status == ATTACH_PADS && aedDevice->getConnectionStatus() == NONE);
    ui->failTestButton->setDisabled(status != AED_ON);
    ui->administerShockButton->setVisible(status == SHOCK_ADVISED);
    ui->cprButton->setVisible(status == START_CPR);

//    Patient Controls
    ui->ageWidget->setVisible(aedDevice->getConnectionStatus() == GOOD);
    ui->qrsWidthWidget->setVisible(aedDevice->getConnectionStatus() == GOOD);
    ui->qrsWidthVarianceWidget->setVisible(aedDevice->getConnectionStatus() == GOOD);
    ui->vtachWidget->setVisible(aedDevice->getConnectionStatus() == GOOD);
}
void MainWindow::batterySliderHandler(int value) {
    aedDevice->setBattery(value);
    ui->batterySliderLabel->setText(QString::number(value, 'd', 0));
    ui->batteryLabel->setText(QString::fromStdString(std::to_string(value) + "%"));
}

void MainWindow::baseDepthSliderHandler(int value) {
    ui->baseDepthLabel->setText(QString::number(value / 100.0, 'f', 2));
    std::cout << "todo MainWindow::baseDepthSliderHandler(value: " << value << ")" << std::endl;
}
void MainWindow::baseDepthVarianceSliderHandler(int value) {
    ui->baseDepthVarianceLabel->setText(QString::number(value / 100.0, 'f', 2));
    std::cout << "todo MainWindow::baseDepthVarianceSliderHandler(value: " << value << ")" << std::endl;
}
void MainWindow::ageSliderHandler(int value) {
    ui->ageLabel->setText(QString::number(value, 'd', 0));
    std::cout << "todo MainWindow::ageSliderHandler(value: " << value << ")" << std::endl;
}
void MainWindow::qrsWidthSliderHandler(int value) {
    ui->qrsWidthLabel->setText(QString::number(value, 'd', 0));
    std::cout << "todo MainWindow::qrsWidthSliderHandler(value: " << value << ")" << std::endl;
}
void MainWindow::qrsWidthVarianceSliderHandler(int value) {
    ui->qrsWidthVarianceLabel->setText(QString::number(value, 'd', 0));
    std::cout << "todo MainWindow::qrsWidthVarianceSliderHandler(value: " << value << ")" << std::endl;
}

void MainWindow::turnOnHandler(){
    emit aedDevice->initTurnOn();
}

void MainWindow::turnOffHandler(){
    std::cout << "todo MainWindow::turnOffHandler()" << std::endl;
}

void MainWindow::changeBatteriesHandler(){
    std::cout << "todo MainWindow::changeBatteriesHandler()" << std::endl;
}

void MainWindow::padsCorrectHandler(){
    aedDevice->setPadPlacement(GOOD);
}

void MainWindow::padsIncorrectHandler(){
    aedDevice->setPadPlacement(BAD);
}

void MainWindow::administerShockHandler(){
    std::cout << "todo MainWindow::administerShockHandler()" << std::endl;
}

void MainWindow::cprHandler(){
    int random = ui->baseDepthVarianceSlider->value();
    int variance = 0;
    if(random > 0)
        variance = (QRandomGenerator::global()->generate() % random+1) *
                ((QRandomGenerator::global()->generate()%2)*2-1);
    int actualDepth = ui->baseDepthSlider->value() + variance;
    aedDevice->cpr(actualDepth);
    std::cout << "todo get min and max depth values in MainWindow::cprHandler() from Patient values" << std::endl;
    int min = 200;
    int max = 240;
    max -= min;
    actualDepth -= min;
    double translatedDepth = (100.0/max) * actualDepth;
    ui->depthSlider->setValue((int) translatedDepth);
}

void MainWindow::failTestHandler(){
    if (aedDevice->isPassing()){
        aedDevice->setTestFail(true);
        std::cout << "Self Test will fail" << std::endl;}
    else {
        aedDevice->setTestFail(false);
        std::cout << "self Test will succeed" << std::endl;}
}
