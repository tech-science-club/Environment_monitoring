#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QSerialPort>
#include <QTimer>
#include "qcustomplot.h"
#include <QDateTime>
#include <QLCDNumber>
#include <time.h>
#include <QtConcurrent>
/*#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>*/


QT_BEGIN_NAMESPACE

namespace Ui {

class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

private:
    QSerialPort serial;
    QByteArray buffer;


    Ui::MainWindow *ui;

    double time_;
    double time;
    double time2;
    double time3;
    double time4;
    double time5;

    QTimer * timer;
    QTimer * myTimer;
    QTimer * myTimer2;
    QTimer * myTimer3;
    QTimer * myTimer4;
    QTimer * myTimer5;
    QTimer * timer_debugging;
    QTimer * DateTime;
    QTimer * Timer_count;
    QTime time_count;
    QTime timer_;

    double m_value;
    int current_compound_index = 0;
    int temp;
    int hum;
    int CO2;
    int NH3;
    int CH4;
    int H2S;
    int LPG;
    int C3H8;
    int VOC;
    int CO;
    int NO2;
    int y_range_3_plot = 0;
    QString file_name;
    double DRAP;
    float mkSv;
    float DRAPCounts;
    double mSV_y_axes = 0.25;
    double DRAP_y_axes = 1.5;

    QString json_line;
    QString port;
    int baud;


private slots:

    void on_Port_connect_Button_clicked();
    void Counting_mSv();
    void receiveMessage();
    void update_plot();
    void update_plot2();
    void update_plot3();
    void update_plot4();
    void Update_labels();
    void on_select_compound_currentIndexChanged(int index);
    void on_plot_save_button_clicked();
    void on_clean_window_clicked();
    void on_save_to_jsonfile_clicked();
    void on_prscr1st_tab_clicked();
    void on_start_writing_json_clicked();
    void Json_writing();
    void on_stop_writing_json_clicked();
    void display_date_time();
    void display_timer();
};

#endif // MAINWINDOW_H
