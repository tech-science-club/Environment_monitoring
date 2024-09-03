/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *Page1;
    QCustomPlot *plot_box_1;
    QGridLayout *gridLayout_2;
    QCustomPlot *plot_box_2;
    QGridLayout *gridLayout_4;
    QCustomPlot *plot_box_3;
    QGridLayout *gridLayout_5;
    QFrame *frame;
    QWidget *rad_widget_2;
    QLabel *label_5;
    QLabel *mkSv_label_3;
    QLabel *label_6;
    QLabel *det_particles;
    QWidget *rad_widget;
    QLabel *label;
    QLabel *mkSv_label;
    QLabel *label_2;
    QWidget *rad_widget_3;
    QLabel *label_7;
    QLabel *temp_label;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *hum_label;
    QLabel *label_11;
    QWidget *rad_widget_4;
    QLabel *label_13;
    QLabel *temp_label_2;
    QLabel *label_16;
    QWidget *rad_widget_5;
    QLabel *label_14;
    QLabel *temp_label_3;
    QLabel *label_17;
    QWidget *rad_widget_6;
    QLabel *label_15;
    QLabel *temp_label_4;
    QLabel *label_18;
    QWidget *rad_widget_7;
    QLabel *label_19;
    QLabel *temp_label_5;
    QLabel *label_20;
    QWidget *rad_widget_8;
    QLabel *label_21;
    QLabel *temp_label_6;
    QLabel *label_22;
    QWidget *rad_widget_9;
    QLabel *label_23;
    QLabel *temp_label_7;
    QLabel *label_24;
    QWidget *rad_widget_10;
    QLabel *label_25;
    QLabel *temp_label_8;
    QLabel *label_26;
    QWidget *rad_widget_11;
    QLabel *label_27;
    QLabel *temp_label_9;
    QLabel *label_28;
    QPushButton *prscr1st_tab;
    QGroupBox *groupBox_2;
    QComboBox *Baud_comboBox;
    QLabel *label_12;
    QComboBox *Port_comboBox;
    QLabel *label_10;
    QPushButton *Port_connect_Button;
    QLabel *label_3;
    QGroupBox *groupBox_3;
    QLabel *datetime;
    QGroupBox *groupBox_4;
    QLabel *run_timer;
    QWidget *tab;
    QCustomPlot *plot_box_4;
    QGridLayout *gridLayout_6;
    QLabel *label_4;
    QComboBox *select_compound;
    QLabel *label_30;
    QLabel *label_33;
    QLabel *label_34;
    QPushButton *plot_save_button;
    QWidget *page2;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_29;
    QPushButton *clean_window;
    QPushButton *save_to_jsonfile;
    QPushButton *start_writing_json;
    QPushButton *stop_writing_json;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1244, 758);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        QFont font;
        font.setBold(false);
        tabWidget->setFont(font);
        tabWidget->setMouseTracking(false);
        tabWidget->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 1px solid black; /* Make the border less pronounced */\n"
"    background-color:rgb(43, 43, 43);    /* Set a uniform background color */\n"
"    margin: 0px;                /* Remove any default margin */\n"
"    padding: 0px;               /* Remove any default padding */\n"
"}"));
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget->setElideMode(Qt::TextElideMode::ElideNone);
        Page1 = new QWidget();
        Page1->setObjectName("Page1");
        plot_box_1 = new QCustomPlot(Page1);
        plot_box_1->setObjectName("plot_box_1");
        plot_box_1->setGeometry(QRect(20, 330, 581, 271));
        plot_box_1->setStyleSheet(QString::fromUtf8("QCustomPlot\n"
"{\n"
"	background-color: black;\n"
"}"));
        gridLayout_2 = new QGridLayout(plot_box_1);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(1, -1, -1, -1);
        plot_box_2 = new QCustomPlot(Page1);
        plot_box_2->setObjectName("plot_box_2");
        plot_box_2->setGeometry(QRect(620, 330, 581, 271));
        plot_box_2->setStyleSheet(QString::fromUtf8("QCustomPlot\n"
"{\n"
"	border-color: gray;\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"    border-radius: 10px;\n"
"   \n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}"));
        gridLayout_4 = new QGridLayout(plot_box_2);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        gridLayout_4->setContentsMargins(1, -1, -1, -1);
        plot_box_3 = new QCustomPlot(Page1);
        plot_box_3->setObjectName("plot_box_3");
        plot_box_3->setGeometry(QRect(20, 50, 581, 271));
        plot_box_3->setStyleSheet(QString::fromUtf8("QCustomPlot\n"
"{\n"
"	background-color: black;\n"
"}"));
        gridLayout_5 = new QGridLayout(plot_box_3);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(1, -1, -1, -1);
        frame = new QFrame(Page1);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(620, 50, 581, 271));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        rad_widget_2 = new QWidget(frame);
        rad_widget_2->setObjectName("rad_widget_2");
        rad_widget_2->setGeometry(QRect(437, 0, 141, 91));
        rad_widget_2->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-color: gray;\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}"));
        label_5 = new QLabel(rad_widget_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(5, 5, 131, 31));
        label_5->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"	color: yellow;\n"
"}"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        mkSv_label_3 = new QLabel(rad_widget_2);
        mkSv_label_3->setObjectName("mkSv_label_3");
        mkSv_label_3->setGeometry(QRect(437, 39, 90, 40));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        mkSv_label_3->setFont(font1);
        mkSv_label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        mkSv_label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_6 = new QLabel(rad_widget_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(88, 44, 51, 41));
        label_6->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold 10px;\n"
"    padding: 6px;\n"
"}"));
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        det_particles = new QLabel(rad_widget_2);
        det_particles->setObjectName("det_particles");
        det_particles->setGeometry(QRect(0, 40, 100, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setBold(true);
        font2.setItalic(false);
        det_particles->setFont(font2);
        det_particles->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        det_particles->setScaledContents(false);
        det_particles->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        rad_widget = new QWidget(frame);
        rad_widget->setObjectName("rad_widget");
        rad_widget->setGeometry(QRect(437, 90, 141, 91));
        rad_widget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-color: gray;\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}"));
        label = new QLabel(rad_widget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 10, 141, 31));
        label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 18px;\n"
"    padding: 6px;\n"
"    color: yellow;\n"
"}"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        mkSv_label = new QLabel(rad_widget);
        mkSv_label->setObjectName("mkSv_label");
        mkSv_label->setGeometry(QRect(8, 39, 100, 41));
        mkSv_label->setFont(font2);
        mkSv_label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        mkSv_label->setScaledContents(false);
        mkSv_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_2 = new QLabel(rad_widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 44, 49, 41));
        label_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 10px;\n"
"    padding: 6px;\n"
"}"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rad_widget_3 = new QWidget(frame);
        rad_widget_3->setObjectName("rad_widget_3");
        rad_widget_3->setGeometry(QRect(5, 0, 141, 91));
        rad_widget_3->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-color: gray;\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold 14px;\n"
"    padding: 6px;\n"
"}"));
        label_7 = new QLabel(rad_widget_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(-5, 5, 151, 31));
        label_7->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 12px;\n"
"    padding: 6px;\n"
"    color: yellow;\n"
"}"));
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        temp_label = new QLabel(rad_widget_3);
        temp_label->setObjectName("temp_label");
        temp_label->setGeometry(QRect(7, 40, 61, 40));
        temp_label->setFont(font1);
        temp_label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        temp_label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_8 = new QLabel(rad_widget_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(44, 38, 41, 31));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 12px;\n"
"    padding: 6px;\n"
"}"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_9 = new QLabel(rad_widget_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(53, 38, 41, 41));
        QFont font3;
        font3.setBold(false);
        font3.setItalic(false);
        label_9->setFont(font3);
        label_9->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font:  24px;\n"
"    padding: 6px;\n"
"}"));
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);
        hum_label = new QLabel(rad_widget_3);
        hum_label->setObjectName("hum_label");
        hum_label->setGeometry(QRect(81, 40, 51, 41));
        hum_label->setFont(font1);
        hum_label->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        hum_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_11 = new QLabel(rad_widget_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(110, 40, 41, 31));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 12px;\n"
"    padding: 6px;\n"
"}"));
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rad_widget_4 = new QWidget(frame);
        rad_widget_4->setObjectName("rad_widget_4");
        rad_widget_4->setGeometry(QRect(5, 90, 141, 91));
        rad_widget_4->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-color: gray;\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold30px;\n"
"    padding: 6px;\n"
"}"));
        label_13 = new QLabel(rad_widget_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 0, 81, 41));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"	fontcolor: yellow;\n"
"    background-color: none;\n"
"    color: yellow;\n"
"	font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);
        temp_label_2 = new QLabel(rad_widget_4);
        temp_label_2->setObjectName("temp_label_2");
        temp_label_2->setGeometry(QRect(60, 40, 61, 40));
        temp_label_2->setFont(font1);
        temp_label_2->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        temp_label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_16 = new QLabel(rad_widget_4);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(110, 40, 41, 31));
        label_16->setFont(font1);
        label_16->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 12px;\n"
"    padding: 6px;\n"
"}"));
        label_16->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rad_widget_5 = new QWidget(frame);
        rad_widget_5->setObjectName("rad_widget_5");
        rad_widget_5->setGeometry(QRect(5, 180, 141, 91));
        rad_widget_5->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-color: gray;\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold30px;\n"
"    padding: 6px;\n"
"}"));
        label_14 = new QLabel(rad_widget_5);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 0, 81, 41));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"	color: yellow;\n"
"}"));
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);
        temp_label_3 = new QLabel(rad_widget_5);
        temp_label_3->setObjectName("temp_label_3");
        temp_label_3->setGeometry(QRect(60, 40, 61, 40));
        temp_label_3->setFont(font1);
        temp_label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        temp_label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_17 = new QLabel(rad_widget_5);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(110, 40, 41, 31));
        label_17->setFont(font1);
        label_17->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 12px;\n"
"    padding: 6px;\n"
"}"));
        label_17->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rad_widget_6 = new QWidget(frame);
        rad_widget_6->setObjectName("rad_widget_6");
        rad_widget_6->setGeometry(QRect(149, 0, 141, 91));
        rad_widget_6->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-color: gray;\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold30px;\n"
"    padding: 6px;\n"
"}"));
        label_15 = new QLabel(rad_widget_6);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(10, 0, 81, 41));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: yellow;\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        label_15->setAlignment(Qt::AlignmentFlag::AlignCenter);
        temp_label_4 = new QLabel(rad_widget_6);
        temp_label_4->setObjectName("temp_label_4");
        temp_label_4->setGeometry(QRect(60, 40, 61, 40));
        temp_label_4->setFont(font1);
        temp_label_4->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        temp_label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_18 = new QLabel(rad_widget_6);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(110, 40, 41, 31));
        label_18->setFont(font1);
        label_18->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 12px;\n"
"    padding: 6px;\n"
"}"));
        label_18->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rad_widget_7 = new QWidget(frame);
        rad_widget_7->setObjectName("rad_widget_7");
        rad_widget_7->setGeometry(QRect(149, 90, 141, 91));
        rad_widget_7->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-color: gray;\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold30px;\n"
"    padding: 6px;\n"
"}"));
        label_19 = new QLabel(rad_widget_7);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 0, 81, 41));
        label_19->setFont(font1);
        label_19->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"	 color: yellow;\n"
"}"));
        label_19->setAlignment(Qt::AlignmentFlag::AlignCenter);
        temp_label_5 = new QLabel(rad_widget_7);
        temp_label_5->setObjectName("temp_label_5");
        temp_label_5->setGeometry(QRect(60, 40, 61, 40));
        temp_label_5->setFont(font1);
        temp_label_5->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        temp_label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_20 = new QLabel(rad_widget_7);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(110, 40, 41, 31));
        label_20->setFont(font1);
        label_20->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 12px;\n"
"    padding: 6px;\n"
"}"));
        label_20->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rad_widget_8 = new QWidget(frame);
        rad_widget_8->setObjectName("rad_widget_8");
        rad_widget_8->setGeometry(QRect(149, 180, 141, 91));
        rad_widget_8->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-color: gray;\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold30px;\n"
"    padding: 6px;\n"
"}"));
        label_21 = new QLabel(rad_widget_8);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(10, 0, 81, 41));
        label_21->setFont(font1);
        label_21->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"	 color: yellow;\n"
"}"));
        label_21->setAlignment(Qt::AlignmentFlag::AlignCenter);
        temp_label_6 = new QLabel(rad_widget_8);
        temp_label_6->setObjectName("temp_label_6");
        temp_label_6->setGeometry(QRect(60, 40, 61, 40));
        temp_label_6->setFont(font1);
        temp_label_6->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        temp_label_6->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_22 = new QLabel(rad_widget_8);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(110, 40, 41, 31));
        label_22->setFont(font1);
        label_22->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 12px;\n"
"    padding: 6px;\n"
"}"));
        label_22->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rad_widget_9 = new QWidget(frame);
        rad_widget_9->setObjectName("rad_widget_9");
        rad_widget_9->setGeometry(QRect(293, 180, 141, 91));
        rad_widget_9->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-color: gray;\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold30px;\n"
"    padding: 6px;\n"
"}"));
        label_23 = new QLabel(rad_widget_9);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(10, 0, 81, 41));
        label_23->setFont(font1);
        label_23->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"	color: yellow;\n"
"}"));
        label_23->setAlignment(Qt::AlignmentFlag::AlignCenter);
        temp_label_7 = new QLabel(rad_widget_9);
        temp_label_7->setObjectName("temp_label_7");
        temp_label_7->setGeometry(QRect(60, 40, 61, 40));
        temp_label_7->setFont(font1);
        temp_label_7->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        temp_label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_24 = new QLabel(rad_widget_9);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(110, 40, 41, 31));
        label_24->setFont(font1);
        label_24->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 12px;\n"
"    padding: 6px;\n"
"}"));
        label_24->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rad_widget_10 = new QWidget(frame);
        rad_widget_10->setObjectName("rad_widget_10");
        rad_widget_10->setGeometry(QRect(293, 0, 141, 91));
        rad_widget_10->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-color: gray;\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold30px;\n"
"    padding: 6px;\n"
"}"));
        label_25 = new QLabel(rad_widget_10);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(10, 0, 81, 41));
        label_25->setFont(font1);
        label_25->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"	color: yellow;\n"
"}"));
        label_25->setAlignment(Qt::AlignmentFlag::AlignCenter);
        temp_label_8 = new QLabel(rad_widget_10);
        temp_label_8->setObjectName("temp_label_8");
        temp_label_8->setGeometry(QRect(60, 40, 61, 40));
        temp_label_8->setFont(font1);
        temp_label_8->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        temp_label_8->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_26 = new QLabel(rad_widget_10);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(110, 40, 41, 31));
        label_26->setFont(font1);
        label_26->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 12px;\n"
"    padding: 6px;\n"
"}"));
        label_26->setAlignment(Qt::AlignmentFlag::AlignCenter);
        rad_widget_11 = new QWidget(frame);
        rad_widget_11->setObjectName("rad_widget_11");
        rad_widget_11->setGeometry(QRect(293, 90, 141, 91));
        rad_widget_11->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border-color: gray;\n"
"	border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: black;\n"
"    font: bold30px;\n"
"    padding: 6px;\n"
"}"));
        label_27 = new QLabel(rad_widget_11);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(10, 0, 81, 41));
        label_27->setFont(font1);
        label_27->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"	color: yellow;\n"
"}"));
        label_27->setAlignment(Qt::AlignmentFlag::AlignCenter);
        temp_label_9 = new QLabel(rad_widget_11);
        temp_label_9->setObjectName("temp_label_9");
        temp_label_9->setGeometry(QRect(60, 40, 61, 40));
        temp_label_9->setFont(font1);
        temp_label_9->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        temp_label_9->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_28 = new QLabel(rad_widget_11);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(110, 40, 41, 31));
        label_28->setFont(font1);
        label_28->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 12px;\n"
"    padding: 6px;\n"
"}"));
        label_28->setAlignment(Qt::AlignmentFlag::AlignCenter);
        prscr1st_tab = new QPushButton(Page1);
        prscr1st_tab->setObjectName("prscr1st_tab");
        prscr1st_tab->setGeometry(QRect(1080, 628, 121, 31));
        prscr1st_tab->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(209, 209, 209);\n"
"    border-width: 2px; \n"
"    border-radius: 6; \n"
"    border-color: gray; \n"
"    border-style: solid; \n"
"    padding: 2px; \n"
"}\n"
"\n"
"QPushButton:pressed\n"
" {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(184, 184, 184);\n"
"    font:12px;\n"
"}\n"
""));
        prscr1st_tab->setAutoDefault(false);
        prscr1st_tab->setFlat(false);
        groupBox_2 = new QGroupBox(Page1);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 610, 381, 51));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setItalic(false);
        groupBox_2->setFont(font4);
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    \n"
"    border: 2px solid gray;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left; /* position at the top center */\n"
"    padding: 0 3px;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 100, 255, 255), stop:1 rgba(255, 255, 37, 255))\n"
"}"));
        groupBox_2->setTitle(QString::fromUtf8("Connection "));
        groupBox_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        groupBox_2->setFlat(false);
        Baud_comboBox = new QComboBox(groupBox_2);
        Baud_comboBox->addItem(QString());
        Baud_comboBox->addItem(QString());
        Baud_comboBox->addItem(QString());
        Baud_comboBox->addItem(QString());
        Baud_comboBox->addItem(QString());
        Baud_comboBox->setObjectName("Baud_comboBox");
        Baud_comboBox->setGeometry(QRect(200, 20, 70, 24));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setItalic(false);
        Baud_comboBox->setFont(font5);
        Baud_comboBox->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"	border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 1px 1px 1px;\n"
"} \n"
"QComboBox::drop-down\n"
"{\n"
"	border: none;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(\"C:/Users/admin/Documents/EnvironmentPro/build/Desktop_Qt_6_7_2_llvm_mingw_64_bit-Debug/pngwing.com.png\");\n"
"}"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(134, 18, 61, 28));
        label_12->setFont(font5);
        Port_comboBox = new QComboBox(groupBox_2);
        Port_comboBox->addItem(QString());
        Port_comboBox->addItem(QString());
        Port_comboBox->addItem(QString());
        Port_comboBox->addItem(QString());
        Port_comboBox->addItem(QString());
        Port_comboBox->setObjectName("Port_comboBox");
        Port_comboBox->setGeometry(QRect(53, 20, 71, 24));
        Port_comboBox->setFont(font5);
        Port_comboBox->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"	border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 1px 1px 1px;\n"
"} \n"
"QComboBox::drop-down\n"
"{\n"
"	border: none;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(\"C:/Users/admin/Documents/EnvironmentPro/build/Desktop_Qt_6_7_2_llvm_mingw_64_bit-Debug/pngwing.com.png\");\n"
"}"));
        Port_comboBox->setInsertPolicy(QComboBox::InsertPolicy::InsertAtCurrent);
        Port_comboBox->setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy::AdjustToMinimumContentsLengthWithIcon);
        Port_comboBox->setFrame(true);
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(-8, 18, 71, 28));
        label_10->setFont(font5);
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Port_connect_Button = new QPushButton(groupBox_2);
        Port_connect_Button->setObjectName("Port_connect_Button");
        Port_connect_Button->setGeometry(QRect(280, 20, 80, 24));
        Port_connect_Button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(209, 209, 209);\n"
"    border-width: 2px; \n"
"    border-radius: 6; \n"
"    border-color: gray; \n"
"    border-style: solid; \n"
"    padding: 2px; \n"
"}\n"
"\n"
"QPushButton:pressed\n"
" {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(184, 184, 184);\n"
"    font:12px;\n"
"}\n"
""));
        Port_connect_Button->setFlat(true);
        label_3 = new QLabel(Page1);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 0, 911, 41));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font: bold 30px;\n"
"    padding: 6px;\n"
"}"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox_3 = new QGroupBox(Page1);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(1040, 10, 161, 33));
        groupBox_3->setFont(font4);
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    \n"
"    border: 2px solid gray;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"	\n"
"    background-color: transparent;\n"
"    subcontrol-position: top left; /* position at the top center */\n"
"   \n"
"}"));
        groupBox_3->setTitle(QString::fromUtf8("Date"));
        groupBox_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        groupBox_3->setFlat(false);
        datetime = new QLabel(groupBox_3);
        datetime->setObjectName("datetime");
        datetime->setGeometry(QRect(37, 9, 121, 21));
        datetime->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(255, 170, 127);\n"
"	font: 12pt \"Ticking Timebomb BB\";\n"
"}"));
        datetime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        groupBox_4 = new QGroupBox(Page1);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(620, 628, 161, 33));
        groupBox_4->setFont(font4);
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    \n"
"    border: 2px solid gray;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex; /* leave space at the top for the title */\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"	\n"
"    background-color: transparent;\n"
"    subcontrol-position: top left; /* position at the top center */\n"
"   \n"
"}"));
        groupBox_4->setTitle(QString::fromUtf8("Timer"));
        groupBox_4->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        groupBox_4->setFlat(false);
        run_timer = new QLabel(groupBox_4);
        run_timer->setObjectName("run_timer");
        run_timer->setGeometry(QRect(60, 10, 94, 21));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Ticking Timebomb BB")});
        font6.setPointSize(14);
        font6.setBold(false);
        font6.setItalic(false);
        run_timer->setFont(font6);
        run_timer->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: rgb(0, 255, 127);\n"
"	font: 14pt \"Ticking Timebomb BB\";\n"
"}"));
        run_timer->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tabWidget->addTab(Page1, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        plot_box_4 = new QCustomPlot(tab);
        plot_box_4->setObjectName("plot_box_4");
        plot_box_4->setGeometry(QRect(40, 70, 1101, 541));
        plot_box_4->setStyleSheet(QString::fromUtf8("QCustomPlot\n"
"{\n"
"	background-color: black;\n"
"}"));
        gridLayout_6 = new QGridLayout(plot_box_4);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(1, -1, -1, -1);
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 34, 81, 33));
        label_4->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color:white;\n"
"	border-style: none;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    background-color: none;\n"
"    font:12px;\n"
"    padding: 6px;\n"
"}"));
        select_compound = new QComboBox(tab);
        select_compound->addItem(QString());
        select_compound->addItem(QString());
        select_compound->addItem(QString());
        select_compound->addItem(QString());
        select_compound->addItem(QString());
        select_compound->addItem(QString());
        select_compound->addItem(QString());
        select_compound->setObjectName("select_compound");
        select_compound->setGeometry(QRect(120, 40, 46, 22));
        QFont font7;
        font7.setBold(true);
        select_compound->setFont(font7);
        select_compound->setStyleSheet(QString::fromUtf8("QComboBox\n"
"{\n"
"	border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"    padding: 1px 1px 1px 1px;\n"
"} \n"
"QComboBox::drop-down\n"
"{\n"
"	border: none;\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(\"C:/Users/admin/Documents/EnvironmentPro/build/Desktop_Qt_6_7_2_llvm_mingw_64_bit-Debug/pngwing.com.png\");\n"
"}"));
        select_compound->setEditable(false);
        select_compound->setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy::AdjustToContents);
        label_30 = new QLabel(tab);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(350, -2, 461, 61));
        QFont font8;
        font8.setPointSize(32);
        font8.setBold(true);
        label_30->setFont(font8);
        label_30->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"}"));
        label_30->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_33 = new QLabel(tab);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(990, 20, 71, 31));
        QFont font9;
        font9.setPointSize(24);
        font9.setBold(false);
        label_33->setFont(font9);
        label_33->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"}"));
        label_33->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_34 = new QLabel(tab);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(1070, 20, 61, 31));
        QFont font10;
        font10.setPointSize(14);
        font10.setBold(false);
        label_34->setFont(font10);
        label_34->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color: white;\n"
"}"));
        label_34->setAlignment(Qt::AlignmentFlag::AlignCenter);
        plot_save_button = new QPushButton(tab);
        plot_save_button->setObjectName("plot_save_button");
        plot_save_button->setGeometry(QRect(40, 620, 80, 24));
        plot_save_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(209, 209, 209);\n"
"    border-width: 2px; \n"
"    border-radius: 6; \n"
"    border-color: gray; \n"
"    border-style: solid; \n"
"    padding: 2px; \n"
"}\n"
"\n"
"QPushButton:pressed\n"
" {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(184, 184, 184);\n"
"    font:12px;\n"
"}\n"
""));
        tabWidget->addTab(tab, QString());
        page2 = new QWidget();
        page2->setObjectName("page2");
        plainTextEdit = new QPlainTextEdit(page2);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(60, 40, 1091, 571));
        label_29 = new QLabel(page2);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(470, 0, 231, 41));
        QFont font11;
        font11.setPointSize(17);
        font11.setBold(false);
        label_29->setFont(font11);
        label_29->setAlignment(Qt::AlignmentFlag::AlignCenter);
        clean_window = new QPushButton(page2);
        clean_window->setObjectName("clean_window");
        clean_window->setGeometry(QRect(960, 625, 91, 24));
        clean_window->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(209, 209, 209);\n"
"    border-width: 2px; \n"
"    border-radius: 6; \n"
"    border-color: gray; \n"
"    border-style: solid; \n"
"    padding: 2px; \n"
"}\n"
"\n"
"QPushButton:pressed\n"
" {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(184, 184, 184);\n"
"    font:12px;\n"
"}\n"
""));
        save_to_jsonfile = new QPushButton(page2);
        save_to_jsonfile->setObjectName("save_to_jsonfile");
        save_to_jsonfile->setGeometry(QRect(1060, 625, 91, 24));
        save_to_jsonfile->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(209, 209, 209);\n"
"    border-width: 2px; \n"
"    border-radius: 6; \n"
"    border-color: gray; \n"
"    border-style: solid; \n"
"    padding: 2px; \n"
"}\n"
"\n"
"QPushButton:pressed\n"
" {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(184, 184, 184);\n"
"    font:12px;\n"
"}\n"
""));
        start_writing_json = new QPushButton(page2);
        start_writing_json->setObjectName("start_writing_json");
        start_writing_json->setGeometry(QRect(60, 625, 91, 24));
        start_writing_json->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(209, 209, 209);\n"
"    border-width: 2px; \n"
"    border-radius: 6; \n"
"    border-color: gray; \n"
"    border-style: solid; \n"
"    padding: 2px; \n"
"}\n"
"\n"
"QPushButton:pressed\n"
" {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(184, 184, 184);\n"
"    font:12px;\n"
"}\n"
""));
        stop_writing_json = new QPushButton(page2);
        stop_writing_json->setObjectName("stop_writing_json");
        stop_writing_json->setGeometry(QRect(160, 625, 91, 24));
        stop_writing_json->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(209, 209, 209);\n"
"    border-width: 2px; \n"
"    border-radius: 6; \n"
"    border-color: gray; \n"
"    border-style: solid; \n"
"    padding: 2px; \n"
"}\n"
"\n"
"QPushButton:pressed\n"
" {\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(184, 184, 184);\n"
"    font:12px;\n"
"}\n"
""));
        tabWidget->addTab(page2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1244, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(accessibility)
        tabWidget->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        label_5->setText(QCoreApplication::translate("MainWindow", "Detected particles", nullptr));
        mkSv_label_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "DPS/min", nullptr));
        det_particles->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Radiaton dose", nullptr));
        mkSv_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\302\265Sv/h", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Temperature/humidity", nullptr));
        temp_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\302\260C", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        hum_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "CO2", nullptr));
        temp_label_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "NH3", nullptr));
        temp_label_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "CH4", nullptr));
        temp_label_4->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "NO2", nullptr));
        temp_label_5->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "VOC", nullptr));
        temp_label_6->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "NH3", nullptr));
        temp_label_7->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "CO", nullptr));
        temp_label_8->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "NH3", nullptr));
        temp_label_9->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        prscr1st_tab->setText(QCoreApplication::translate("MainWindow", "Take  a screen  shot", nullptr));
        Baud_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "4800", nullptr));
        Baud_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "9600", nullptr));
        Baud_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "19200", nullptr));
        Baud_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "38400", nullptr));
        Baud_comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "115200", nullptr));

        label_12->setText(QCoreApplication::translate("MainWindow", "Baudrate", nullptr));
        Port_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "COM 1", nullptr));
        Port_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "COM 2", nullptr));
        Port_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "COM 3", nullptr));
        Port_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "COM 4", nullptr));
        Port_comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "COM 5", nullptr));

        label_10->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        Port_connect_Button->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Air quality measurements", nullptr));
        datetime->setText(QCoreApplication::translate("MainWindow", "dd-mm-yy hh:mm:ss", nullptr));
        run_timer->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Page1), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Compound", nullptr));
        select_compound->setItemText(0, QCoreApplication::translate("MainWindow", "CO2", nullptr));
        select_compound->setItemText(1, QCoreApplication::translate("MainWindow", "NH3", nullptr));
        select_compound->setItemText(2, QCoreApplication::translate("MainWindow", "CH4", nullptr));
        select_compound->setItemText(3, QCoreApplication::translate("MainWindow", "NO2", nullptr));
        select_compound->setItemText(4, QCoreApplication::translate("MainWindow", "CO", nullptr));
        select_compound->setItemText(5, QCoreApplication::translate("MainWindow", "VOC", nullptr));
        select_compound->setItemText(6, QCoreApplication::translate("MainWindow", "All", nullptr));

        label_30->setText(QCoreApplication::translate("MainWindow", "Concentration in air", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "ppm", nullptr));
        plot_save_button->setText(QCoreApplication::translate("MainWindow", "Save plot", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", " Json file", nullptr));
        clean_window->setText(QCoreApplication::translate("MainWindow", "Clean window", nullptr));
        save_to_jsonfile->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
        start_writing_json->setText(QCoreApplication::translate("MainWindow", "Start recording", nullptr));
        stop_writing_json->setText(QCoreApplication::translate("MainWindow", "Stop recording", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(page2), QCoreApplication::translate("MainWindow", "Tab 3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
