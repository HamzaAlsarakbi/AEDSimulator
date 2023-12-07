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
    ecgWidget = new EcgWidget(ui->ecgGraphWidget);
    ui->ecgGraphWidget->layout()->addWidget(ecgWidget);
    connectUI();
    update(aedDevice->getStatus());
    ui->depthSlider->setDisabled(true);
//    emit drawEcg({1000, 2000, 3000, 4000, 5000, 6000});
}

MainWindow::~MainWindow()
{
    delete ecgWidget;
    delete ui;
    delete aedDevice;
}
void MainWindow::connectUI() {
    // Sliders
    connect(ui->batterySlider, &QSlider::valueChanged, this, &MainWindow::batterySliderHandler);
    connect(ui->baseDepthSlider, &QSlider::valueChanged, this, &MainWindow::baseDepthSliderHandler);
    connect(ui->baseDepthVarianceSlider, &QSlider::valueChanged, this, &MainWindow::baseDepthVarianceSliderHandler);
    connect(ui->ageSlider, &QSlider::valueChanged, this, &MainWindow::ageSliderHandler);
//    connect(this, SIGNAL(drawEcg(std::vector<long long>)), ecgWidget, SLOT(draw(std::vector<long long>)));
    connect(this, SIGNAL(drawEcg(int)), ecgWidget, SLOT(draw(int)));

    // Buttons
    connect(ui->turnOnButton, &QPushButton::pressed, this, &MainWindow::turnOnHandler);
    connect(ui->turnOffButton, SIGNAL(pressed()), aedDevice, SLOT(handleTurnOff()));
    connect(ui->attachDefibPadsCorrectlyButton, &QPushButton::pressed, this, &MainWindow::padsCorrectHandler);
    connect(ui->attachDefibPadsIncorrectlyButton, &QPushButton::pressed, this, &MainWindow::padsIncorrectHandler);
    connect(ui->failTestButton, &QPushButton::pressed, this, &MainWindow::failTestHandler);
    connect(ui->administerShockButton, &QPushButton::pressed, this, &MainWindow::administerShockHandler);
    connect(ui->cprButton, &QPushButton::pressed, this, &MainWindow::cprHandler);
    connect(aedDevice, SIGNAL(update(AEDStatus)), this, SLOT(update(AEDStatus)));
    connect(aedDevice, SIGNAL(updateDisplay(std::string)), this, SLOT(updateDisplay(std::string)));
    connect(aedDevice, SIGNAL(initUpdateHeartRate()), this, SLOT(updateHeartRate()));
}
void MainWindow::update(AEDStatus status) {
    std::vector<QString> displayStrings = { "TURNING ON", "", "CHANGE BATTERY", "TEST FAIL", "UNIT OK", "CHECK RESPONSIVENESS", "CALL HELP", "ATTACH PADS TO PATIENT'S CHEST", "DON'T TOUCH PATIENT, ANALYZING", "SHOCK ADVISED", "SHOCK NOT ADVISED", "START CPR", "PATIENT HEALTHY" };
    std::vector<QFrame*> indicators = { ui->indicator1, ui->indicator2, ui->indicator3, ui->indicator4, ui->indicator5 };
    ui->displayLabel->setText(displayStrings.at(status));

//    AED Controls
    ui->turnOnButton->setDisabled(status != AED_OFF);
    ui->turnOffButton->setDisabled(status == AED_OFF);
    ui->failTestButton->setDisabled(status != AED_ON && status != AED_OFF);
//    AED Screen
    ui->heartRateLabel->setVisible(status > 8);
    ui->batteryLabel->setText(status == AED_OFF ? "" : QString::fromStdString(std::to_string(aedDevice->getBattery()) + "%"));
    ui->shocksCount->setText(status == AED_OFF ? "" : QString::number(aedDevice->getShocksCount()));
    ecgWidget->setVisible(status > 8);
//    AED Lights
    ui->testPassIndicator->setStyleSheet(status == AED_OFF || status == AED_ON ? "background-color: gray" : aedDevice->isPassing() ? "background-color: green" : "background-color: red");
    for(int i = 0; i < indicators.size(); i++) {
        indicators.at(i)->setStyleSheet(i == (status-5) ? "background-color: green" : "background-color: gray");
    }
    ui->padsConnectedIndicator->setStyleSheet(aedDevice->getConnectionStatus() == GOOD ? "background-color: green" :
    aedDevice->getConnectionStatus() == BAD ? "background-color: red" : "background-color: gray");

//    Rescuer Controls
    ui->batterySlider->setValue(aedDevice->getBattery());
    ui->changeBatteriesButton->setVisible(false);
    ui->attachDefibPadsCorrectlyButton->setVisible(status == ATTACH_PADS && aedDevice->getConnectionStatus() != GOOD);
    ui->attachDefibPadsIncorrectlyButton->setVisible(status == ATTACH_PADS && aedDevice->getConnectionStatus() == NONE);
    ui->administerShockButton->setVisible(status > 8);
    ui->administerShockButton->setDisabled(status != SHOCK_ADVISED);
    ui->cprButton->setVisible(status > 8);
    ui->cprButton->setDisabled(status != START_CPR);

//    Patient Controls
    ui->ageWidget->setVisible(aedDevice->getConnectionStatus() == GOOD);
    ui->ageWidget->setDisabled(status > 8);
    ui->qrsWidthWidget->setVisible(status > 8);
    ui->qrsWidthVarianceWidget->setVisible(status > 8);
    ui->vtachWidget->setVisible(status > 8);
    ui->pulsesInLastSecondsWidget->setVisible(status > 8);
    ui->heartStatusWidget->setVisible(status > 8);
}

void MainWindow::updateDisplay(std::string text) {
    ui->displayLabel->setText(QString::fromStdString(text));
}
void MainWindow::updateHeartRate() {
    ui->heartRateLabel->setText(aedDevice->getHeartRate() == -1 ? "" : QString::number(aedDevice->getHeartRate()));
    ui->qrsWidthLabel->setText(QString::number(aedDevice->getBasePulseTime()));
    ui->qrsWidthVarianceLabel->setText(QString::number(aedDevice->getPulseTimeVariance()));
    ui->pulsesCountLabel->setText(QString::number(aedDevice->getPulsesCount()));
    std::vector<std::string> statuses = { "NORMAL", "VTACH", "VFIB", "ARISTOTLE" };
    ui->heartStatusLabel->setText(QString::fromStdString(statuses.at(aedDevice->getHeartStatus())));
    emit drawEcg(aedDevice->getHeartRate());
}

void MainWindow::batterySliderHandler(int value) {
    aedDevice->setBattery(value);
    ui->batterySliderLabel->setText(QString::number(value, 'd', 0));
    ui->batteryLabel->setText(QString::fromStdString(std::to_string(value) + "%"));
}

void MainWindow::baseDepthSliderHandler(int value) {
    ui->baseDepthLabel->setText(QString::number(value / 100.0, 'f', 2));
}
void MainWindow::baseDepthVarianceSliderHandler(int value) {
    ui->baseDepthVarianceLabel->setText(QString::number(value / 100.0, 'f', 2));
}
void MainWindow::ageSliderHandler(int value) {
    ui->ageLabel->setText(QString::number(value, 'd', 0));
    aedDevice->setAge(value);
}

void MainWindow::turnOnHandler(){
    emit aedDevice->initTurnOn();
}

void MainWindow::padsCorrectHandler(){
    aedDevice->setPadPlacement(GOOD);
}

void MainWindow::padsIncorrectHandler(){
    aedDevice->setPadPlacement(BAD);
}

void MainWindow::administerShockHandler(){
    ui->administerShockButton->setDisabled(true);
    aedDevice->administerShock();
}

void MainWindow::cprHandler(){
    int random = ui->baseDepthVarianceSlider->value();
    int variance = 0;
    if(random > 0)
        variance = (QRandomGenerator::global()->generate() % random+1) *
                ((QRandomGenerator::global()->generate()%2)*2-1);
    int actualDepth = ui->baseDepthSlider->value() + variance;
    aedDevice->cpr(actualDepth);
    int min = aedDevice->getMinCompressionDepth();
    int max = aedDevice->getMaxCompressionDepth();
    max -= min;
    actualDepth -= min;
    double translatedDepth = (100.0/max) * actualDepth;
    ui->depthSlider->setValue((int) translatedDepth);
}

void MainWindow::failTestHandler(){
    aedDevice->setTestFail(aedDevice->isPassing());
    ui->failTestButton->setText(aedDevice->isPassing() ? "Fail Test" : "Pass Test");
}
