/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_20;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout;
    QFrame *indicator1;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *indicator2;
    QLabel *label_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QFrame *indicator3;
    QLabel *label_4;
    QWidget *screen;
    QVBoxLayout *verticalLayout_2;
    QWidget *horizontalWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLabel *shocksCount;
    QLabel *shocksCount_2;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_3;
    QWidget *ecgGraphWidget;
    QHBoxLayout *horizontalLayout_13;
    QLabel *shocksCount_3;
    QSlider *depthSlider;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_8;
    QFrame *indicator5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_11;
    QFrame *frame_9;
    QFrame *indicator4_2;
    QLabel *label_9;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_9;
    QFrame *indicator4;
    QLabel *label_7;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_12;
    QSlider *horizontalSlider_2;
    QLabel *baseDepthLabel;
    QLabel *qrsWidthLabel_4;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_11;
    QSlider *horizontalSlider;
    QLabel *baseDepthVarianceLabel;
    QLabel *qrsWidthLabel_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_14;
    QVBoxLayout *actionsWidget;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_16;
    QSlider *ageSlider;
    QLabel *ageLabel;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_17;
    QSlider *qrsWidthSlider;
    QLabel *qrsWidthLabel;
    QLabel *qrsWidthLabel_2;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_19;
    QSlider *qrsWithVarianceSlider;
    QLabel *qrsWidthVarianceLabel;
    QLabel *qrsWidthLabel_3;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *actionsWidget_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(875, 354);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_20 = new QHBoxLayout(centralwidget);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalWidget->setMinimumSize(QSize(338, 0));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        indicator1 = new QFrame(verticalWidget);
        indicator1->setObjectName(QString::fromUtf8("indicator1"));
        indicator1->setMaximumSize(QSize(10, 10));
        indicator1->setStyleSheet(QString::fromUtf8("background: hsl(120, 80%, 60%);"));
        indicator1->setFrameShape(QFrame::StyledPanel);
        indicator1->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(indicator1);

        label = new QLabel(verticalWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAutoFillBackground(false);

        horizontalLayout->addWidget(label);


        horizontalLayout_5->addLayout(horizontalLayout);

        widget = new QWidget(verticalWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(100, 0));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        indicator2 = new QFrame(widget);
        indicator2->setObjectName(QString::fromUtf8("indicator2"));
        indicator2->setMaximumSize(QSize(10, 10));
        indicator2->setStyleSheet(QString::fromUtf8("background: hsl(120, 00%, 60%);"));
        indicator2->setFrameShape(QFrame::StyledPanel);
        indicator2->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(indicator2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(label_2);


        horizontalLayout_5->addWidget(widget);

        widget1 = new QWidget(verticalWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setMinimumSize(QSize(150, 0));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        indicator3 = new QFrame(widget1);
        indicator3->setObjectName(QString::fromUtf8("indicator3"));
        indicator3->setMaximumSize(QSize(10, 10));
        indicator3->setStyleSheet(QString::fromUtf8("background: hsl(120, 00%, 60%);"));
        indicator3->setFrameShape(QFrame::StyledPanel);
        indicator3->setFrameShadow(QFrame::Raised);

        horizontalLayout_4->addWidget(indicator3);

        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAutoFillBackground(false);

        horizontalLayout_4->addWidget(label_4);


        horizontalLayout_5->addWidget(widget1);


        verticalLayout->addLayout(horizontalLayout_5);

        screen = new QWidget(verticalWidget);
        screen->setObjectName(QString::fromUtf8("screen"));
        screen->setMinimumSize(QSize(300, 150));
        screen->setMaximumSize(QSize(300, 16777215));
        screen->setStyleSheet(QString::fromUtf8("background: hsl(75, 20%, 40%)"));
        verticalLayout_2 = new QVBoxLayout(screen);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalWidget_4 = new QWidget(screen);
        horizontalWidget_4->setObjectName(QString::fromUtf8("horizontalWidget_4"));
        horizontalWidget_4->setMinimumSize(QSize(0, 30));
        horizontalWidget_4->setMaximumSize(QSize(16777215, 20));
        horizontalLayout_7 = new QHBoxLayout(horizontalWidget_4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(horizontalWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(0, 20));
        label_5->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_7->addWidget(label_5);

        shocksCount = new QLabel(horizontalWidget_4);
        shocksCount->setObjectName(QString::fromUtf8("shocksCount"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(shocksCount->sizePolicy().hasHeightForWidth());
        shocksCount->setSizePolicy(sizePolicy1);
        shocksCount->setMinimumSize(QSize(0, 20));
        shocksCount->setFont(font);
        shocksCount->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_7->addWidget(shocksCount);

        shocksCount_2 = new QLabel(horizontalWidget_4);
        shocksCount_2->setObjectName(QString::fromUtf8("shocksCount_2"));
        sizePolicy1.setHeightForWidth(shocksCount_2->sizePolicy().hasHeightForWidth());
        shocksCount_2->setSizePolicy(sizePolicy1);
        shocksCount_2->setMinimumSize(QSize(0, 20));
        shocksCount_2->setFont(font);
        shocksCount_2->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        horizontalLayout_7->addWidget(shocksCount_2);


        verticalLayout_2->addWidget(horizontalWidget_4);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ecgGraphWidget = new QWidget(screen);
        ecgGraphWidget->setObjectName(QString::fromUtf8("ecgGraphWidget"));
        horizontalLayout_13 = new QHBoxLayout(ecgGraphWidget);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));

        verticalLayout_3->addWidget(ecgGraphWidget);

        shocksCount_3 = new QLabel(screen);
        shocksCount_3->setObjectName(QString::fromUtf8("shocksCount_3"));
        sizePolicy1.setHeightForWidth(shocksCount_3->sizePolicy().hasHeightForWidth());
        shocksCount_3->setSizePolicy(sizePolicy1);
        shocksCount_3->setFont(font);
        shocksCount_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(shocksCount_3);


        horizontalLayout_12->addLayout(verticalLayout_3);

        depthSlider = new QSlider(screen);
        depthSlider->setObjectName(QString::fromUtf8("depthSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(depthSlider->sizePolicy().hasHeightForWidth());
        depthSlider->setSizePolicy(sizePolicy2);
        depthSlider->setTracking(false);
        depthSlider->setOrientation(Qt::Vertical);
        depthSlider->setInvertedAppearance(false);

        horizontalLayout_12->addWidget(depthSlider);


        verticalLayout_2->addLayout(horizontalLayout_12);


        verticalLayout->addWidget(screen);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        indicator5 = new QFrame(verticalWidget);
        indicator5->setObjectName(QString::fromUtf8("indicator5"));
        indicator5->setMaximumSize(QSize(10, 10));
        indicator5->setStyleSheet(QString::fromUtf8("background: hsl(120, 00%, 60%);"));
        indicator5->setFrameShape(QFrame::StyledPanel);
        indicator5->setFrameShadow(QFrame::Raised);

        horizontalLayout_8->addWidget(indicator5);

        label_6 = new QLabel(verticalWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAutoFillBackground(false);

        horizontalLayout_8->addWidget(label_6);


        horizontalLayout_6->addLayout(horizontalLayout_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        frame_9 = new QFrame(verticalWidget);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setMaximumSize(QSize(10, 10));
        frame_9->setStyleSheet(QString::fromUtf8("background: hsl(120, 00%, 60%);"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        indicator4_2 = new QFrame(frame_9);
        indicator4_2->setObjectName(QString::fromUtf8("indicator4_2"));
        indicator4_2->setGeometry(QRect(0, 0, 10, 10));
        indicator4_2->setMaximumSize(QSize(10, 10));
        indicator4_2->setStyleSheet(QString::fromUtf8("background: hsl(120, 00%, 60%);"));
        indicator4_2->setFrameShape(QFrame::StyledPanel);
        indicator4_2->setFrameShadow(QFrame::Raised);

        horizontalLayout_11->addWidget(frame_9);

        label_9 = new QLabel(verticalWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAutoFillBackground(false);

        horizontalLayout_11->addWidget(label_9);


        horizontalLayout_6->addLayout(horizontalLayout_11);

        widget2 = new QWidget(verticalWidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setMinimumSize(QSize(150, 0));
        horizontalLayout_9 = new QHBoxLayout(widget2);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        indicator4 = new QFrame(widget2);
        indicator4->setObjectName(QString::fromUtf8("indicator4"));
        indicator4->setMaximumSize(QSize(10, 10));
        indicator4->setStyleSheet(QString::fromUtf8("background: hsl(120, 00%, 60%);"));
        indicator4->setFrameShape(QFrame::StyledPanel);
        indicator4->setFrameShadow(QFrame::Raised);

        horizontalLayout_9->addWidget(indicator4);

        label_7 = new QLabel(widget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAutoFillBackground(false);

        horizontalLayout_9->addWidget(label_7);


        horizontalLayout_6->addWidget(widget2);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_20->addWidget(verticalWidget);

        verticalWidget_2 = new QWidget(centralwidget);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        verticalWidget_2->setMinimumSize(QSize(500, 0));
        verticalLayout_4 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_10 = new QLabel(verticalWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_5->addWidget(label_10);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_12 = new QLabel(verticalWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(150, 0));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_15->addWidget(label_12);

        horizontalSlider_2 = new QSlider(verticalWidget_2);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(300);
        horizontalSlider_2->setValue(200);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(100);

        horizontalLayout_15->addWidget(horizontalSlider_2);

        baseDepthLabel = new QLabel(verticalWidget_2);
        baseDepthLabel->setObjectName(QString::fromUtf8("baseDepthLabel"));
        baseDepthLabel->setMinimumSize(QSize(0, 0));
        baseDepthLabel->setMaximumSize(QSize(16777215, 16777215));
        baseDepthLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(baseDepthLabel);

        qrsWidthLabel_4 = new QLabel(verticalWidget_2);
        qrsWidthLabel_4->setObjectName(QString::fromUtf8("qrsWidthLabel_4"));
        qrsWidthLabel_4->setMinimumSize(QSize(0, 0));
        qrsWidthLabel_4->setMaximumSize(QSize(16777215, 16777215));
        qrsWidthLabel_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(qrsWidthLabel_4);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_11 = new QLabel(verticalWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(150, 0));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_14->addWidget(label_11);

        horizontalSlider = new QSlider(verticalWidget_2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(10);

        horizontalLayout_14->addWidget(horizontalSlider);

        baseDepthVarianceLabel = new QLabel(verticalWidget_2);
        baseDepthVarianceLabel->setObjectName(QString::fromUtf8("baseDepthVarianceLabel"));
        baseDepthVarianceLabel->setMinimumSize(QSize(0, 0));
        baseDepthVarianceLabel->setMaximumSize(QSize(16777215, 16777215));
        baseDepthVarianceLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(baseDepthVarianceLabel);

        qrsWidthLabel_5 = new QLabel(verticalWidget_2);
        qrsWidthLabel_5->setObjectName(QString::fromUtf8("qrsWidthLabel_5"));
        qrsWidthLabel_5->setMinimumSize(QSize(0, 0));
        qrsWidthLabel_5->setMaximumSize(QSize(16777215, 16777215));
        qrsWidthLabel_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(qrsWidthLabel_5);


        verticalLayout_5->addLayout(horizontalLayout_14);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_14 = new QLabel(verticalWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_6->addWidget(label_14);

        actionsWidget = new QVBoxLayout();
        actionsWidget->setObjectName(QString::fromUtf8("actionsWidget"));

        verticalLayout_6->addLayout(actionsWidget);


        verticalLayout_5->addLayout(verticalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_15 = new QLabel(verticalWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_7->addWidget(label_15);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_16 = new QLabel(verticalWidget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(150, 0));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_17->addWidget(label_16);

        ageSlider = new QSlider(verticalWidget_2);
        ageSlider->setObjectName(QString::fromUtf8("ageSlider"));
        ageSlider->setMinimum(6);
        ageSlider->setOrientation(Qt::Horizontal);
        ageSlider->setTickPosition(QSlider::TicksBelow);
        ageSlider->setTickInterval(10);

        horizontalLayout_17->addWidget(ageSlider);

        ageLabel = new QLabel(verticalWidget_2);
        ageLabel->setObjectName(QString::fromUtf8("ageLabel"));
        ageLabel->setMinimumSize(QSize(0, 0));
        ageLabel->setMaximumSize(QSize(16777215, 16777215));
        ageLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(ageLabel);


        verticalLayout_7->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_17 = new QLabel(verticalWidget_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(150, 0));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_18->addWidget(label_17);

        qrsWidthSlider = new QSlider(verticalWidget_2);
        qrsWidthSlider->setObjectName(QString::fromUtf8("qrsWidthSlider"));
        qrsWidthSlider->setMinimum(200);
        qrsWidthSlider->setMaximum(2000);
        qrsWidthSlider->setValue(1000);
        qrsWidthSlider->setOrientation(Qt::Horizontal);
        qrsWidthSlider->setTickPosition(QSlider::TicksBelow);
        qrsWidthSlider->setTickInterval(100);

        horizontalLayout_18->addWidget(qrsWidthSlider);

        qrsWidthLabel = new QLabel(verticalWidget_2);
        qrsWidthLabel->setObjectName(QString::fromUtf8("qrsWidthLabel"));
        qrsWidthLabel->setMinimumSize(QSize(0, 0));
        qrsWidthLabel->setMaximumSize(QSize(16777215, 16777215));
        qrsWidthLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_18->addWidget(qrsWidthLabel);

        qrsWidthLabel_2 = new QLabel(verticalWidget_2);
        qrsWidthLabel_2->setObjectName(QString::fromUtf8("qrsWidthLabel_2"));
        qrsWidthLabel_2->setMinimumSize(QSize(0, 0));
        qrsWidthLabel_2->setMaximumSize(QSize(16777215, 16777215));
        qrsWidthLabel_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_18->addWidget(qrsWidthLabel_2);


        verticalLayout_7->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_19 = new QLabel(verticalWidget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(150, 0));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_19->addWidget(label_19);

        qrsWithVarianceSlider = new QSlider(verticalWidget_2);
        qrsWithVarianceSlider->setObjectName(QString::fromUtf8("qrsWithVarianceSlider"));
        qrsWithVarianceSlider->setMaximum(120);
        qrsWithVarianceSlider->setSingleStep(10);
        qrsWithVarianceSlider->setOrientation(Qt::Horizontal);
        qrsWithVarianceSlider->setTickPosition(QSlider::TicksBelow);
        qrsWithVarianceSlider->setTickInterval(10);

        horizontalLayout_19->addWidget(qrsWithVarianceSlider);

        qrsWidthVarianceLabel = new QLabel(verticalWidget_2);
        qrsWidthVarianceLabel->setObjectName(QString::fromUtf8("qrsWidthVarianceLabel"));
        qrsWidthVarianceLabel->setMinimumSize(QSize(0, 0));
        qrsWidthVarianceLabel->setMaximumSize(QSize(16777215, 16777215));
        qrsWidthVarianceLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(qrsWidthVarianceLabel);

        qrsWidthLabel_3 = new QLabel(verticalWidget_2);
        qrsWidthLabel_3->setObjectName(QString::fromUtf8("qrsWidthLabel_3"));
        qrsWidthLabel_3->setMinimumSize(QSize(0, 0));
        qrsWidthLabel_3->setMaximumSize(QSize(16777215, 16777215));
        qrsWidthLabel_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(qrsWidthLabel_3);


        verticalLayout_7->addLayout(horizontalLayout_19);

        label_18 = new QLabel(verticalWidget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_7->addWidget(label_18);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        actionsWidget_2 = new QVBoxLayout();
        actionsWidget_2->setObjectName(QString::fromUtf8("actionsWidget_2"));

        verticalLayout_8->addLayout(actionsWidget_2);


        verticalLayout_7->addLayout(verticalLayout_8);


        verticalLayout_4->addLayout(verticalLayout_7);


        horizontalLayout_20->addWidget(verticalWidget_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 875, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Check OK", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Call for Help", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Attach defib Pads", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Shocks: ", nullptr));
        shocksCount->setText(QCoreApplication::translate("MainWindow", "shocksCountLabel", nullptr));
        shocksCount_2->setText(QCoreApplication::translate("MainWindow", "timeLabel", nullptr));
        shocksCount_3->setText(QCoreApplication::translate("MainWindow", "messageLabel", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Start CPR", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Heart", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Don't Touch Patient", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Rescuer</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Base Depth: ", nullptr));
        baseDepthLabel->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        qrsWidthLabel_4->setText(QCoreApplication::translate("MainWindow", "in", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Base Depth Variance: ", nullptr));
        baseDepthVarianceLabel->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        qrsWidthLabel_5->setText(QCoreApplication::translate("MainWindow", "in", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Patient</span></p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Age: ", nullptr));
        ageLabel->setText(QCoreApplication::translate("MainWindow", "99", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "QRS Width", nullptr));
        qrsWidthLabel->setText(QCoreApplication::translate("MainWindow", "0000", nullptr));
        qrsWidthLabel_2->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "QRS Width Variance: ", nullptr));
        qrsWidthVarianceLabel->setText(QCoreApplication::translate("MainWindow", "0120", nullptr));
        qrsWidthLabel_3->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Actions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
