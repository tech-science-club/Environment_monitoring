#include "mainwindow.h"

#include <QApplication>
#include <QCoreApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>
/*#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>*/

#define time_interval = 3600


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*0QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));*/


    MainWindow w;

    w.show();

    return a.exec();
}


