#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QLabel>
#include <QString>
#include <QJsonDocument>

MainWindow::MainWindow(QWidget *parent)    :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    time_count(0,0,0), m_value(0), temp(0), hum(0), CO2(170), NH3(200), CH4(230), VOC(280), CO(300), NO2(350), DRAP(0), mkSv(0), DRAPCounts(0),  json_line(" ")
{
    ui->setupUi(this);

    //set timer to count radiation dose per 1 min
    //qDebug()<< DRAP;
    DateTime = new QTimer(this);
    connect(DateTime, &QTimer::timeout, this, &MainWindow::display_date_time);
    /*connect(DateTime, &QTimer::timeout, this, [this]() {
        QtConcurrent::run([this]() { display_date_time(); });
    });*/
    DateTime->start();

    Timer_count = new QTimer(this);
    connect(Timer_count, &QTimer::timeout, this, &MainWindow::display_timer);
    /*connect(Timer_count, &QTimer::timeout, this, [this]() {
        QtConcurrent::run([this]() { display_timer(); });
    });*/

    timer = new QTimer(this); // Use 'new' to create timer on the heap
    connect(timer, &QTimer::timeout, this, &MainWindow::Counting_mSv);
    /*connect(timer, &QTimer::timeout, this, [this]() {
        QtConcurrent::run([this]() { Counting_mSv(); });
    });*/

    timer->start(60000);  // 5 seconds interval

    timer_debugging = new QTimer(this); // Use 'new' to create timer on the heap
    connect(timer_debugging, &QTimer::timeout, this, &MainWindow::Update_labels);
    /*connect(timer_debugging, &QTimer::timeout, this, [this]() {
        QtConcurrent::run([this]() { Update_labels(); });
    });*/

    timer_debugging->start(1000);

    //set timer to udate plot
    time = 0.0;
    myTimer = new QTimer(this);
    connect(myTimer, &QTimer::timeout, this, &MainWindow::update_plot);
    /*connect(myTimer, &QTimer::timeout, this, [this]() {
        QtConcurrent::run([this]() { update_plot(); });
    });*/
    myTimer->start(100);

    //set timer to udate plot
    time2 = 0.0;
    myTimer2 = new QTimer(this);
    connect(myTimer2, &QTimer::timeout, this, &MainWindow::update_plot2);
    /*connect(myTimer2, &QTimer::timeout, this, [this]() {
        QtConcurrent::run([this]() { update_plot2(); });
    });*/
    myTimer2->start(60000);

    //set timer to udate plot
    time3 = 0.0;
    myTimer3 = new QTimer(this);
    connect(myTimer3, &QTimer::timeout, this, &MainWindow::update_plot3);
    /*connect(myTimer3, &QTimer::timeout, this, [this]() {
        QtConcurrent::run([this]() { update_plot3(); });
    });*/
    myTimer3->start(100);

    //set timer to udate plot
    time4 = 0.0;
    myTimer4 = new QTimer(this);
    connect(myTimer4, &QTimer::timeout, this, &MainWindow::update_plot4);
    /*connect(myTimer4, &QTimer::timeout, this, [this]() {
        QtConcurrent::run([this]() { update_plot4(); });
    });*/
    myTimer4->start(100);

    myTimer5 = new QTimer(this);
    connect(myTimer5, &QTimer::timeout, this, &MainWindow::Json_writing);
    /*connect(myTimer5, &QTimer::timeout, this, [this]() {
        QtConcurrent::run([this]() { Json_writing(); });
    });*/


    //---------------- set up plots--------------------
    QPen Pen;
    Pen.setWidth(3);
    Pen.setColor(QColorConstants::Blue);

    QPen Temppen;
    Temppen.setWidth(3);
    Temppen.setColor(QColorConstants::Red);

    QPen AxesPen;
    AxesPen.setColor(QColorConstants::White);
    AxesPen.setWidth(3);

    QPen TickPen;
    TickPen.setColor(QColorConstants::White);

    // -------------------detected particles plot--------------------------------------
    ui->plot_box_1->setBackground(Qt::black);
    ui->plot_box_1->addGraph();
    ui->plot_box_1->legend->setVisible(true);
    ui->plot_box_1->legend->setBrush(QBrush(QColor(Qt::lightGray)));
    ui->plot_box_1->graph()->setName("Impulse");

    ui->plot_box_1->graph()->setLineStyle((QCPGraph::lsImpulse)); //lsNone, lsLine
    ui->plot_box_1->graph()->setPen(QPen(QColor(40, 110, 255)));
    ui->plot_box_1->axisRect()->setBackground(QBrush(Qt::black));

    ui->plot_box_1->xAxis->setBasePen(AxesPen);
    ui->plot_box_1->xAxis->setTickLabelColor(QColorConstants::White);
    ui->plot_box_1->xAxis->setLabelColor(QColorConstants::White);
    ui->plot_box_1->xAxis->setLabel("time, sec");
    ui->plot_box_1->xAxis->setRange(0, 70);

    ui->plot_box_1->yAxis->setLabelColor(QColorConstants::White);
    ui->plot_box_1->yAxis->setTickLabelColor(QColorConstants::White);
    ui->plot_box_1->yAxis->setBasePen(AxesPen);
    ui->plot_box_1->yAxis->setLabel("Impulse/detected particles");
    ui->plot_box_1->yAxis->setRange(-0.5, DRAP_y_axes);


    //----------------------dose radiation plot----------------------------------------
    ui->plot_box_2->setBackground(Qt::black);
    ui->plot_box_2->addGraph();
    ui->plot_box_2->legend->setVisible(true);
    ui->plot_box_2->legend->setBrush(QBrush(QColor(Qt::lightGray)));
    ui->plot_box_2->graph()->setName("Radiation dose µSv/h");
    ui->plot_box_2->graph()->setLineStyle((QCPGraph::lsLine)); //lsNone, lsLine

    ui->plot_box_2->xAxis->setBasePen(AxesPen);
    ui->plot_box_2->xAxis->setTickLabelColor(QColorConstants::White);
    ui->plot_box_2->xAxis->setLabelColor(QColorConstants::White);


    ui->plot_box_2->graph()->setPen(Pen);
    ui->plot_box_2->graph()->setBrush(QBrush(QColor(0,255, 0)));
    ui->plot_box_2->axisRect()->setBackground(QBrush(Qt::black));
    ui->plot_box_2->xAxis->setLabel("time, min");
    ui->plot_box_2->xAxis->setRange(0, 65);

    ui->plot_box_2->yAxis->setLabelColor(QColorConstants::White);
    ui->plot_box_2->yAxis->setTickLabelColor(QColorConstants::White);
    ui->plot_box_2->yAxis->setBasePen(AxesPen);

    ui->plot_box_2->yAxis->setLabel("Radiation dose µSv/h");

    ui->plot_box_2->yAxis->setRange(-0.01, mSV_y_axes);


    //-------------gases concentration---------------------
    ui->plot_box_3->addGraph();  // Graph 1
    ui->plot_box_3->graph(0)->setLineStyle((QCPGraph::lsLine));
    ui->plot_box_3->graph(0)->setPen(QPen(Qt::red));  // Set color for graph 1
    ui->plot_box_3->graph(0)->setName("CO2"); // Set name for the legend
    //

    ui->plot_box_3->addGraph();  // Graph 2
    ui->plot_box_3->graph(1)->setLineStyle((QCPGraph::lsLine));
    ui->plot_box_3->graph(1)->setPen(QPen(Qt::blue));  // Set color for graph 2
    ui->plot_box_3->graph(1)->setName("NH3"); // Set name for the legend
    //

    ui->plot_box_3->addGraph();  // Graph 3
    ui->plot_box_3->graph(2)->setLineStyle((QCPGraph::lsLine));
    ui->plot_box_3->graph(2)->setPen(QPen(Qt::green));  // Set color for graph 3
    ui->plot_box_3->graph(2)->setName("CH4"); // Set name for the legend
    //

    ui->plot_box_3->addGraph();  // Graph 4
    ui->plot_box_3->graph(3)->setLineStyle((QCPGraph::lsLine));
    ui->plot_box_3->graph(3)->setPen(QPen(Qt::magenta));  // Set color for graph 4
    ui->plot_box_3->graph(3)->setName("NO2"); // Set name for the legend
    //

    ui->plot_box_3->addGraph();  // Graph 5
    ui->plot_box_3->graph(4)->setLineStyle((QCPGraph::lsLine));
    ui->plot_box_3->graph(4)->setPen(QPen(Qt::yellow));  // Set color for graph 5
    ui->plot_box_3->graph(4)->setName("CO"); // Set name for the legend
    //

    ui->plot_box_3->addGraph();  // Graph 5
    ui->plot_box_3->graph(5)->setLineStyle((QCPGraph::lsLine));
    ui->plot_box_3->graph(5)->setPen(QPen(Qt::white));  // Set color for graph 5
    ui->plot_box_3->graph(5)->setName("VOC"); // Set name for the legend
    //

    // Set plot background and axis properties
    ui->plot_box_3->setBackground(Qt::black);
    ui->plot_box_3->xAxis->setBasePen(QPen(Qt::white));
    ui->plot_box_3->xAxis->setTickLabelColor(Qt::white);
    ui->plot_box_3->xAxis->setLabelColor(Qt::white);
    ui->plot_box_3->xAxis->setLabel("Time, min");
    ui->plot_box_3->xAxis->setRange(0, 60);

    ui->plot_box_3->yAxis->setBasePen(QPen(Qt::white));
    ui->plot_box_3->yAxis->setTickLabelColor(Qt::white);
    ui->plot_box_3->yAxis->setLabelColor(Qt::white);
    ui->plot_box_3->yAxis->setLabel("Concentration");
    ui->plot_box_3->yAxis->setRange(0, 500);

    // Enable and customize the legend
    ui->plot_box_3->legend->setVisible(true); // Make the legend visible
    ui->plot_box_3->legend->setBrush(QBrush(QColor(255, 255, 255, 150))); // Set background color with transparency
    ui->plot_box_3->legend->setBorderPen(QPen(Qt::black)); // Set border color

    //----------------------pollutants plot----------------------------------

    ui->label_33->setText(QString::number(CO2));

    ui->plot_box_4->setBackground(Qt::black);
    ui->plot_box_4->addGraph();
    ui->plot_box_4->legend->setVisible(true);
    ui->plot_box_4->legend->setBrush(QBrush(QColor(Qt::lightGray)));
    ui->plot_box_4->graph()->setName("CO2");
    ui->plot_box_4->graph()->setLineStyle((QCPGraph::lsLine)); //lsNone, lsLine

    ui->plot_box_4->xAxis->setBasePen(AxesPen);
    ui->plot_box_4->xAxis->setTickLabelColor(QColorConstants::White);
    ui->plot_box_4->xAxis->setLabelColor(QColorConstants::White);


    ui->plot_box_4->graph()->setPen(Temppen);
    ui->plot_box_4->axisRect()->setBackground(QBrush(Qt::black));
    ui->plot_box_4->xAxis->setLabel("time, min");
    ui->plot_box_4->xAxis->setRange(0, 70);

    ui->plot_box_4->yAxis->setLabelColor(QColorConstants::White);
    ui->plot_box_4->yAxis->setTickLabelColor(QColorConstants::White);
    ui->plot_box_4->yAxis->setBasePen(AxesPen);

    ui->plot_box_4->yAxis->setLabel("CO2");
    ui->plot_box_4->yAxis->setRange(0, CO2+CO2*0.3);


    //=========================================================================
}

MainWindow::~MainWindow()
{
    delete ui;
}

//-----------connect to the port
void MainWindow::on_Port_connect_Button_clicked()
{
    QString portName = ui->Port_comboBox->currentText();
    QString port = portName.remove(" ");
    QString baudrate = ui->Baud_comboBox->currentText();
    int baud = baudrate.toInt();

    serial.setPortName(port);
    serial.setBaudRate(baud);

    //serial.setPortName("COM3");
    //serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if (!serial.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Cannot connect");
        qDebug() << "connection error";
    } else {
        QMessageBox::information(this, port, "connected to " + port + " with baudrate " + QString::number(baud));
        qDebug() << "connected to "<< port << " with baud " <<baud;
    }


    connect(&serial,&QSerialPort::readyRead,this,&MainWindow::receiveMessage);
    //connect()
    Timer_count->start(1000);
    //timer_debugging->start(2000);
}
void MainWindow::receiveMessage(){

    buffer.append(serial.readAll());
    // Check if the buffer contains a complete JSON object (ending with \r\n or \n)
    while (buffer.contains("\n")) {
        // Extract the first complete line (up to and including the \n)
        int endOfLineIndex = buffer.indexOf("\n");
        QByteArray line = buffer.left(endOfLineIndex);

        // Remove the processed line from the buffer
        buffer.remove(0, endOfLineIndex + 1);

        // Attempt to parse the JSON object
        QJsonDocument doc = QJsonDocument::fromJson(line);
        json_line = doc.toJson(QJsonDocument::Compact);

        //qDebug()<< json_line;
        if (!doc.isNull()) {
            QJsonObject obj = doc.object();
            temp = obj["temperature"].toInt();
            hum = obj["humidity"].toInt();
            CO2 = obj["CO2"].toInt();
            NH3 = obj["NH3"].toInt();
            CH4 = obj["CH4"].toInt();
            VOC = obj["VOC"].toInt();
            CO = obj["CO"].toInt();
            NO2 = obj["NO2"].toInt();
            DRAP = obj["DRAP"].toInt();

            //qDebug() << "Temperature:" << temp <<" "<<"humidity:"<<hum<<" " << "CO2: "<< CO2<<" "<< "NH3: "<< NH3<<" "<< "CH4: "<< CH4<<" "<< "VOC: " << VOC<<" "<<"CO: "<< CO<<" "<<"NO2: "<<NO2<<" "<< "DRAP: "<< DRAP;

            DRAPCounts += DRAP;
            //qDebug() << DRAPCounts;
        } else {
            qDebug() << "Invalid JSON received:" << line;
        }

    }

}
// ------------------ dose radiation counting-------------------

void MainWindow::Counting_mSv()
{
    //qDebug() << DRAPCounts;
    mkSv = float(DRAPCounts)/264;
    qDebug() << "mkSv/h:" << mkSv;
    DRAPCounts = 0;
}

void MainWindow::Update_labels()
{
   //qDebug() << "mkSv: "<<mkSv<< "DRAPCounts: "<<DRAPCounts << "DRAP: "<< DRAP;
    ui->temp_label->setText(QString::number(temp));
    ui->hum_label->setText(QString::number(hum));
}

// --------- func to update plots with timers---------------------
void MainWindow::update_plot()
{
    time+=0.1;

    //DRAP_y_axes = DRAP + 0.5;

    if (DRAP_y_axes<DRAP){
        DRAP_y_axes = DRAP + DRAP*0.25;
    }

    /*else {
        QTimer::singleShot(10000, this, [&]() {
            DRAP_y_axes = 2;
        });
    }*/
    ui->plot_box_1->yAxis->setRange(-0.05, DRAP_y_axes);
    ui->plot_box_1->graph()->addData(time, DRAP);

    ui->plot_box_1->replot();
    if (time>60){
        ui->plot_box_1->xAxis->setRange(time-60, time +10);

    }

    /*double DRAP_y_axes = 2;
    double valueToAdd = DRAP;

    QMetaObject::invokeMethod(this, [this, DRAP_y_axes, valueToAdd]() {
        ui->plot_box_1->yAxis->setRange(-0.05, DRAP_y_axes);
        ui->plot_box_1->graph()->addData(time, valueToAdd);
        ui->plot_box_1->replot();
        if (time > 60) {
            ui->plot_box_1->xAxis->setRange(time - 60, time + 10);
        }
    });*/
}

void MainWindow::update_plot2()
{
    time2+=1;

    if (mSV_y_axes < mkSv){
        mSV_y_axes = mkSv+mkSv*0.25;
    }
    /*else {
        QTimer::singleShot(10000, this, [&]() {
            mSV_y_axes = 0.25;
        });

    }*/
    ui->plot_box_2->yAxis->setRange(-0.01, mSV_y_axes);
    ui->plot_box_2->graph()->addData(time2, mkSv);

    ui->plot_box_2->replot();
    if (time2>60){
        ui->plot_box_2->xAxis->setRange(time2-60, time2 +5);

     }
    ui->det_particles->setText(QString::number(DRAPCounts));
    ui->mkSv_label->setText(QString().setNum(mkSv, 'g', 2));


    /*double mSV_y_axes = 0;
  // Calculate range based on data
    double mkSvValue = mkSv;   // Calculate new data point

    // Safely invoke GUI updates on the main thread
    QMetaObject::invokeMethod(this, [this, mSV_y_axes, mkSvValue]() {
        ui->plot_box_2->yAxis->setRange(-0.01, mSV_y_axes);
        ui->plot_box_2->graph()->addData(time2, mkSvValue);
        ui->plot_box_2->replot();
        if (time2 > 60) {
            ui->plot_box_2->xAxis->setRange(time2 - 60, time2 + 5);
        }
        ui->det_particles->setText(QString::number(DRAPCounts));
        ui->mkSv_label->setText(QString().setNum(mkSv, 'g', 2));
    });*/
    //ui->mkSv_label->setAlignment(Qt::AlignRight);

}

void MainWindow::update_plot3()
{
    time3+=0.1;
    /*if (DRAP_y_axes>DRAP){
        DRAP_y_axes = DRAP_y_axes;
    }
    else{
        DRAP_y_axes = DRAP + DRAP*0.33;
    }*/
    //ui->plot_box_1->yAxis->setRange(-0.05, DRAP_y_axes);
    ui->plot_box_3->graph(0)->addData(time3, CO2);
    ui->plot_box_3->graph(1)->addData(time3, NH3);
    ui->plot_box_3->graph(2)->addData(time3, CH4);
    ui->plot_box_3->graph(3)->addData(time3, NO2);
    ui->plot_box_3->graph(4)->addData(time3, CO);
    ui->plot_box_3->graph(5)->addData(time3, VOC);
    //if (m_value){
    //ui->plot_box_3->graph()->addData(time3, m_value);
    //}
    ui->plot_box_3->replot();
    if (time>60){
        ui->plot_box_3->xAxis->setRange(time-60, time +10);

    }
}

void MainWindow::update_plot4()
{
    time4+=0.1;
    ui->plot_box_4->yAxis->setRange(0, m_value+m_value*0.3);
    ui->plot_box_4->graph()->addData(time4, m_value);
    //qDebug() << time4;
    ui->plot_box_4->replot();

    if (time4>60){
        ui->plot_box_4->xAxis->setRange(time4-60, time4 +10);

    }
}

void MainWindow::on_select_compound_currentIndexChanged(int index)
{
    ui->plot_box_4->clearGraphs(); // Clear all graphs
    ui->plot_box_4->addGraph();    // Add a new graph for the selected case
    time4 = 0;                     // Reset time to start from 0

    switch (index){
    /*CO2(400), NH3(200), CH4(250),  VOC(320), CO(280), NO2(170)*/
    case 0:

        m_value = CO2;
        ui->label_33->setText(QString::number(m_value));
        ui->plot_box_4->graph()->setName("CO2");
        ui->plot_box_4->yAxis->setLabel("CO2");
        ui->plot_box_4->graph()->setPen(QPen(Qt::red));
        ui->plot_box_4->xAxis->setRange(time4, 70);
        //ui->plot_box_4->xAxis->setRange(time4, 70); // Set x-axis range from 0 to 60 (or other initial range)
        ui->plot_box_4->replot();
        break;

    case 1:

        m_value = NH3;
        ui->label_33->setText(QString::number(m_value));
        ui->plot_box_4->graph()->setName("NH3");
        ui->plot_box_4->yAxis->setLabel("NH3");
        //time4 = 0;
        ui->plot_box_4->xAxis->setRange(time4, 70);
        ui->plot_box_4->graph()->setPen(QPen(Qt::blue));
        ui->plot_box_4->replot();
        break;

    case 2:
        m_value = CH4;
        ui->label_33->setText(QString::number(m_value));
        ui->plot_box_4->graph()->setName("CH4");
        ui->plot_box_4->yAxis->setLabel("CH4");
        ui->plot_box_4->graph()->setPen(QPen(Qt::green));
        ui->plot_box_4->xAxis->setRange(time4, 70);
        ui->plot_box_4->replot();

        break;

    case 3:
        m_value = NO2;
        ui->label_33->setText(QString::number(m_value));
        ui->plot_box_4->graph()->setName("NO2");
        ui->plot_box_4->yAxis->setLabel("NO2");
        ui->plot_box_4->graph()->setPen(QPen(Qt::magenta));
        ui->plot_box_4->xAxis->setRange(time4, 70);
        ui->plot_box_4->replot();
        break;

    case 4:
        m_value = CO;
        ui->label_33->setText(QString::number(m_value));
        ui->plot_box_4->graph()->setName("CO");
        ui->plot_box_4->yAxis->setLabel("CO");
        ui->plot_box_4->graph()->setPen(QPen(Qt::yellow));
        ui->plot_box_4->xAxis->setRange(time4, 70);
        ui->plot_box_4->replot();
        break;

    case 5:
        m_value = VOC;
        ui->label_33->setText(QString::number(m_value));
        ui->plot_box_4->graph()->setName("VOC");
        ui->plot_box_4->yAxis->setLabel("VOC");
        ui->plot_box_4->graph()->setPen(QPen(Qt::white));
        ui->plot_box_4->xAxis->setRange(time4, 70);
        ui->plot_box_4->replot();
        break;

    case 6:

    default:
        break;
    }
}

void MainWindow::on_plot_save_button_clicked()
{
    QCPGraph *currentGraph = ui->plot_box_4->graph();

    // Retrieve the graph name to use it for the file name
    QString graphName = currentGraph->name();
    QString defaultFileName = graphName + ".png";
    QString filter = "PNG Image (*.png);;JPEG Image (*.jpg);;BMP Image (*.bmp);;PDF Document (*.pdf)";


    // Open a file dialog to get the file name and format to save
    QString fileName = QFileDialog::getSaveFileName(this, "Save Plot", defaultFileName, filter);

    // If the user cancels the dialog, fileName will be empty
    if (fileName.isEmpty()) {
        return; // Exit the function if no file name was provided
    }

    // Determine the file format based on the file extension
    if (fileName.endsWith(".png")) {
        ui->plot_box_4->savePng(fileName); // Save as PNG
    } else if (fileName.endsWith(".jpg")) {
        ui->plot_box_4->saveJpg(fileName); // Save as JPEG
    } else if (fileName.endsWith(".bmp")) {
        ui->plot_box_4->saveBmp(fileName); // Save as BMP
    } else if (fileName.endsWith(".pdf")) {
        ui->plot_box_4->savePdf(fileName); // Save as PDF
    } else {
        // Default to PNG if no valid extension is found
        ui->plot_box_4->savePng(fileName + ".png");
    }
}

void MainWindow::on_clean_window_clicked()
{
    ui->plainTextEdit->setPlainText(" ");
}

void MainWindow::on_save_to_jsonfile_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));

    // Check if the user specified a file path
    if (filePath.isEmpty()) {
        QMessageBox::information(this, "No File Selected", "No file was selected for saving.");
        return;
    }

    // Display the selected file path for debugging
    qDebug() << "Selected file path:" << filePath;

    // Create a QFile object using the selected file path
    QFile file(filePath);

    // Try to open the file in write-only mode
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file for writing: " + file.errorString());
        return;
    }

    // Create a QTextStream to write data to the file
    QTextStream out(&file);

    QString plainTextContent = ui->plainTextEdit->toPlainText();

    out << plainTextContent;


    // Close the file after writing
    file.close();

    // Show a confirmation message
    QMessageBox::information(this, "Success", "Data saved to file successfully.");
}

void MainWindow::on_prscr1st_tab_clicked()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle()) {
        screen = window->screen();
    }

    // Take a screenshot of the entire application window
    QPixmap screenshot = screen->grabWindow(this->winId());

    // Suggest a default file name with a timestamp
    QString defaultFileName = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss") + ".png";

    // Open a file dialog to choose where to save the screenshot
    QString fileName = QFileDialog::getSaveFileName(this, "Save Screenshot", defaultFileName, "PNG Image (*.png);;JPEG Image (*.jpg);;BMP Image (*.bmp)");

    // Check if a file name was chosen
    if (!fileName.isEmpty()) {
        screenshot.save(fileName);  // Save the screenshot to the chosen file
    }
}

void MainWindow::Json_writing()
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    json_line = currentDateTime + ": " + json_line + "\n";
    ui->plainTextEdit->insertPlainText(json_line);
}

void MainWindow::on_start_writing_json_clicked()
{
    myTimer5->start(1000);
    Json_writing();
}

void MainWindow::on_stop_writing_json_clicked()
{
    myTimer5->stop();
}

void MainWindow::display_date_time()
{
    QString date = QDateTime::currentDateTime().toString("dd-MM-yy HH:mm:ss");
    ui->datetime->setText(date);
}

void MainWindow::display_timer()
{

    time_count =time_count.addSecs(1);
    ui->run_timer->setText(time_count.toString("hh:mm:ss"));
    //qDebug()<< time_count.toString("hh:mm:ss");
}

