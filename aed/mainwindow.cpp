#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::connectUI() {
    // Sliders
    connect(ui->batterySlider, &QSlider::valueChanged, this, &MainWindow::batterySliderHandler);
    connect(ui->baseDepthSlider, &QSlider::valueChanged, this, &MainWindow::baseDepthSliderHandler);
    connect(ui->baseDepthVarianceSlider, &QSlider::valueChanged, this, &MainWindow::baseDepthVarianceSliderHandler);
    connect(ui->ageSlider, &QSlider::valueChanged, this, &MainWindow::ageSliderHandler);
    connect(ui->qrsWidthSlider, &QSlider::valueChanged, this, &MainWindow::qrsWidthSliderHandler);
    connect(ui->qrsWidthVarianceSlider, &QSlider::valueChanged, this, &MainWindow::qrsWidthVarianceSliderHandler);

    // Buttons
    connect(ui->turnOnButton, &QPushButton::pressed, this, &MainWindow::turnOnHandler);
    connect(ui->turnOffButton, &QPushButton::pressed, this, &MainWindow::turnOffHandler);
    connect(ui->changeBatteriesButton, &QPushButton::pressed, this, &MainWindow::changeBatteriesHandler);
    connect(ui->attachDefibPadsCorrectlyButton, &QPushButton::pressed, this, &MainWindow::padsCorrectHandler);
    connect(ui->attachDefibPadsIncorrectlyButton, &QPushButton::pressed, this, &MainWindow::padsIncorrectHandler);
    connect(ui->administerShockButton, &QPushButton::pressed, this, &MainWindow::administerShockHandler);
    connect(ui->cprButton, &QPushButton::pressed, this, &MainWindow::cprHandler);
}

void MainWindow::batterySliderHandler(int value) {
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
    std::cout << "todo MainWindow::turnOnHandler()" << std::endl;
}

void MainWindow::turnOffHandler(){
    std::cout << "todo MainWindow::turnOffHandler()" << std::endl;
}

void MainWindow::changeBatteriesHandler(){
    std::cout << "todo MainWindow::changeBatteriesHandler()" << std::endl;
}

void MainWindow::padsCorrectHandler(){
    std::cout << "todo MainWindow::padsCorrectHandler()" << std::endl;
}

void MainWindow::padsIncorrectHandler(){
    std::cout << "todo MainWindow::padsIncorrectHandler()" << std::endl;
}

void MainWindow::administerShockHandler(){
    std::cout << "todo MainWindow::administerShockHandler()" << std::endl;
}

void MainWindow::cprHandler(){
    std::cout << "todo MainWindow::cprHandler()" << std::endl;
}