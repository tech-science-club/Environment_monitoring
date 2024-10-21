#include "mainwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>

#define time_interval = 3600


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   
    MainWindow w;

    w.show();

    return a.exec();
}


