#include <iostream>
#include <QRandomGenerator>
#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief Construct a new Main Window:: Main Window object
 * 
 */
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
    emit drawEcg({
        Pulse(milliseconds(1000), PULSE_NORMAL),
        Pulse(milliseconds(2000), PULSE_NORMAL),
        Pulse(milliseconds(3000), PULSE_NORMAL),
        Pulse(milliseconds(4000), PULSE_NORMAL),
        Pulse(milliseconds(5000), PULSE_NORMAL),
        Pulse(milliseconds(6000), PULSE_NORMAL),
    });
}

/**
 * @brief Destroy the Main Window:: Main Window object
 * 
 */
MainWindow::~MainWindow()
{
    delete ecgWidget;
    delete ui;
    delete aedDevice;
}

/**
 * @brief Connects the buttons on the ui to signals that emit to do the actual functions
 * 
 */
void MainWindow::connectUI() {
    // Sliders
    connect(ui->batterySlider, &QSlider::valueChanged, this, &MainWindow::batterySliderHandler);
    connect(ui->baseDepthSlider, &QSlider::valueChanged, this, &MainWindow::baseDepthSliderHandler);
    connect(ui->baseDepthVarianceSlider, &QSlider::valueChanged, this, &MainWindow::baseDepthVarianceSliderHandler);
    connect(ui->ageSlider, &QSlider::valueChanged, this, &MainWindow::ageSliderHandler);
    connect(ui->startingConditionBox, SIGNAL(currentTextChanged(QString)), this, SLOT(patientStartingConditionHandler(QString)));
    connect(this, SIGNAL(drawEcg(std::vector<Pulse>)), ecgWidget, SLOT(draw(std::vector<Pulse>)));

    // Buttons
    connect(ui->turnOnButton, &QPushButton::pressed, this, &MainWindow::turnOnHandler);
    connect(ui->turnOffButton, SIGNAL(pressed()), aedDevice, SLOT(turnOffHandler()));
    connect(ui->attachDefibPadsCorrectlyButton, &QPushButton::pressed, this, &MainWindow::padsCorrectHandler);
    connect(ui->attachDefibPadsIncorrectlyButton, &QPushButton::pressed, this, &MainWindow::padsIncorrectHandler);
    connect(ui->failTestButton, &QPushButton::pressed, this, &MainWindow::failTestHandler);
    connect(ui->administerShockButton, &QPushButton::pressed, this, &MainWindow::administerShockHandler);
    connect(ui->cprButton, &QPushButton::pressed, this, &MainWindow::cprHandler);
    connect(aedDevice, SIGNAL(update(AEDStatus)), this, SLOT(update(AEDStatus)));
    connect(aedDevice, SIGNAL(updateDisplay(std::string)), this, SLOT(updateDisplay(std::string)));
    connect(aedDevice, SIGNAL(updateUiHeartRate()), this, SLOT(updateHeartRate()));
}

/**
 * @brief Updates the UI to fit the current state of the AED 
 * 
 * @param status (AEDStatus) The current state the AED is in
 */
void MainWindow::update(AEDStatus status) {
    std::cout << "redrawing: " << status << std::endl;
    const QString RED = QString::fromStdString("background-color: rgb(255, 100, 100)");
    const QString GREEN = QString::fromStdString("background-color: rgb(100, 255, 100)");
    const QString GRAY = QString::fromStdString("background-color: rgb(175, 175, 175)");
    std::vector<QString> displayStrings = { "", "CHANGE BATTERY", "TURNING ON", "TEST FAIL", "UNIT OK", "CHECK RESPONSIVENESS", "CALL HELP", "ATTACH PADS TO PATIENT'S CHEST", "DON'T TOUCH PATIENT, ANALYZING", "SHOCK ADVISED", "START CPR", "PATIENT HEALTHY" };
    std::vector<QFrame*> indicators = { ui->indicator1, ui->indicator2, ui->indicator3, ui->indicator4, ui->indicator5, ui->indicator6 };
    ui->displayLabel->setText(displayStrings.at(status));

//    AED Controls
    ui->turnOnButton->setDisabled(status >= 2);
    ui->turnOffButton->setDisabled(status < 2);
    ui->failTestButton->setDisabled(status != AED_ON && status != AED_OFF);
//    AED Screen
    ui->heartRateLabel->setVisible(status > 7);
    ui->batteryLabel->setVisible(status > 1);
    ui->batteryLabel->setText(QString::fromStdString(std::to_string(aedDevice->getBattery()) + "%"));
    ui->shocksCount->setVisible(status > 1);
    ui->shocksCount->setText(QString::number(aedDevice->getShocksCount()));
    // ecgWidget->setVisible(status > 7);
//    AED Lights
    ui->testPassIndicator->setStyleSheet(status == AED_OFF || status == AED_ON ? GRAY : aedDevice->isPassing() ? GREEN : RED);
    for(int i = 0; i < indicators.size(); i++) {
        indicators.at(i)->setStyleSheet(i == (status-5) ? GREEN : GRAY);
    }
    ui->padsConnectedIndicator->setStyleSheet(aedDevice->getConnectionStatus() == GOOD ? GREEN :
    aedDevice->getConnectionStatus() == BAD ? RED : GRAY);

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
    ui->ageWidget->setDisabled(status > 8);
    ui->startingConditionWidget->setDisabled(status > 1);
    ui->qrsWidthWidget->setVisible(status > 8);
    ui->qrsWidthVarianceWidget->setVisible(status > 8);
    ui->vtachWidget->setVisible(status > 8);
    ui->pulsesInLastSecondsWidget->setVisible(status > 8);
    ui->heartStatusWidget->setVisible(status > 8);
}

/**
 * @brief displays the text representing the state of the AED
 * 
 * @param text (string) The text to be displayed
 */
void MainWindow::updateDisplay(std::string text) {
    ui->displayLabel->setText(QString::fromStdString(text));
}

/**
 * @brief Updates the UI depending on the state of the heart
 * 
 */
void MainWindow::updateHeartRate() {
    if(aedDevice->isHeartNull()) return;
    ui->heartRateLabel->setText(
            aedDevice->getHeartRate() == -1 ? "" :
            aedDevice->getHeartStatus() == VFIB ? QString::fromStdString("~"+std::to_string(aedDevice->getHeartRate())) :
            QString::number(aedDevice->getHeartRate())
            );
    ui->qrsWidthLabel->setText(QString::number(aedDevice->getBasePulseTime()));
    ui->qrsWidthVarianceLabel->setText(QString::number(aedDevice->getPulseTimeVariance()));
    ui->pulsesCountLabel->setText(QString::number(aedDevice->getPulsesCount()));
    std::vector<std::string> statuses = { "Dead", "Asystole", "Pulse-less Electrical Activity", "Arrythmic", "Normal", "Ventricular Tachycardia", "Ventricular Fibrillation" };
    ui->heartStatusLabel->setText(QString::fromStdString(statuses.at(aedDevice->getHeartStatus())));
    // emit drawEcg(aedDevice->getHeartRate());
}

/**
 * @brief updates the value of battery 
 * 
 * @param value (int) The value of the battery from the slider
 */
void MainWindow::batterySliderHandler(int value) {
    aedDevice->setBattery(value);
    ui->batterySliderLabel->setText(QString::number(value, 'd', 0));
    ui->batteryLabel->setText(QString::fromStdString(std::to_string(value) + "%"));
}

/**
 * @brief Updates the value of compression depth
 * 
 * @param value (int) The value of the compression depth from the slider
 */
void MainWindow::baseDepthSliderHandler(int value) {
    ui->baseDepthLabel->setText(QString::number(value / 100.0, 'f', 2));
}

/**
 * @brief Updates the value of the compression depth variance
 * 
 * @param value (int) the radius of the compression depth from the slider
 */
void MainWindow::baseDepthVarianceSliderHandler(int value) {
    ui->baseDepthVarianceLabel->setText(QString::number(value / 100.0, 'f', 2));
}

/**
 * @brief Updates the value of the compression depth variance
 * 
 * @param value (int) The value of the patient's age from the slider
 */
void MainWindow::ageSliderHandler(int value) {
    ui->ageLabel->setText(QString::number(value, 'd', 0));
    aedDevice->setAge(value);
}

/**
 * @brief Updates the starting condition of the patient on the UI
 * 
 * @param condition (QString) the starting condition of the patient
 */
void MainWindow::patientStartingConditionHandler(QString condition) {
    std::string c = condition.toStdString();
    aedDevice->resetPatient(
        c == "Normal" ? PSC_NORMAL :
        c == "Asystole" ? PSC_ASYSTOLE :
        c == "Sub 40" ? PSC_SUB40 :
        c == "Heart Attack VFIB" ? PSC_HEART_ATTACK_VFIB :
        PSC_HEART_ATTACK_VTACH);
}

/**
 * @brief Connects the UI's turn on button to the device
 * 
 */
void MainWindow::turnOnHandler(){
    emit aedDevice->turnOnHandler();
}

/**
 * @brief Sets the connection of the pad to good
 * 
 */
void MainWindow::padsCorrectHandler(){
    aedDevice->setPadPlacement(GOOD);
}

/**
 * @brief Sets the connection of the pad to bad
 * 
 */
void MainWindow::padsIncorrectHandler(){
    aedDevice->setPadPlacement(BAD);
}

/**
 * @brief Connects the UI's shock button to the shocking functionality
 * 
 */
void MainWindow::administerShockHandler(){
    ui->administerShockButton->setDisabled(true);
    aedDevice->administerShock();
}

/**
 * @brief Connects the UI's CPR button to the cpr functionality
 * 
 */
void MainWindow::cprHandler(){
    // Applies some variance to the cpr depth
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
    
    // Displays the cpr depth on the display to the right
    double translatedDepth = (100.0/max) * actualDepth;
    ui->depthSlider->setValue((int) translatedDepth);
}

/**
 * @brief connects the UI's fail test button to the fail test functionality
 * 
 */
void MainWindow::failTestHandler(){
    aedDevice->setTestFail(aedDevice->isPassing());
    ui->failTestButton->setText(aedDevice->isPassing() ? "Fail Test" : "Pass Test");
}
