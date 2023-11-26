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
    connect(ui->batterySlider, &QSlider::valueChanged, this, &MainWindow::batterySliderHandler);
    connect(ui->baseDepthSlider, &QSlider::valueChanged, this, &MainWindow::baseDepthSliderHandler);
    connect(ui->baseDepthVarianceSlider, &QSlider::valueChanged, this, &MainWindow::baseDepthVarianceSliderHandler);
    connect(ui->ageSlider, &QSlider::valueChanged, this, &MainWindow::ageSliderHandler);
    connect(ui->qrsWidthSlider, &QSlider::valueChanged, this, &MainWindow::qrsWidthSliderHandler);
    connect(ui->qrsWidthVarianceSlider, &QSlider::valueChanged, this, &MainWindow::qrsWidthVarianceSliderHandler);
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
