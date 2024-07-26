#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mqttClient = new QMqttClient(this);
    mqttClient->setHostname("192.168.1.100");
    mqttClient->setPort(1883);
    mqttTopic.setName("SteamDeckInput");

    connect(mqttClient, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);
    connect(mqttClient, &QMqttClient::disconnected, this, &MainWindow::brokerDisconnected);
    // connect(mqttClient, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
    //     const QString content = QDateTime::currentDateTime().toString()
    //                             + " Received Topic: "
    //                             + topic.name()
    //                             + " Message: "
    //                             + message
    //                             + u'\n';
    //     Q_UNUSED(this)
    //     // ui->debugTest->insertPlainText(content);
    // });

    // connect(mqttClient, &QMqttClient::pingResponseReceived, this, [this]() {
    //     const QString content = QDateTime::currentDateTime().toString()
    //                             + "PingResponse\n";
    //     Q_UNUSED(this)
    //     // ui->debugTest->insertPlainText(content);
    // });
    mqttClient->connectToHost();

}

MainWindow::~MainWindow()
{
    delete ui;
    mqttClient->disconnectFromHost();
}

void MainWindow::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                            + ": State Change"
                            + QString::number(mqttClient->state())
                            + u'\n';Q_UNUSED(content);
    // ui->line2_row2_button->setText(content);
}

void MainWindow::brokerDisconnected()
{
    ui->line2_row1_button->setText("Disconnected");
}

void MainWindow::on_line1_row1_button_clicked()
{
    compteur.l1r1++;
    ui->line1_row1_button->setText("L1R1: "+QVariant(compteur.l1r1).toString());
    mqttMessage = "line1_row1";
    mqttClient->publish(mqttTopic,mqttMessage);
}


void MainWindow::on_line1_row2_button_clicked()
{
    compteur.l1r2++;
    ui->line1_row2_button->setText("L1R2: "+QVariant(compteur.l1r2).toString());
    mqttMessage = "line1_row2";
    mqttClient->publish(mqttTopic,mqttMessage);
    // ui->line1_row2_button->setStyleSheet("background-color:black;");
}


void MainWindow::on_line1_row3_button_clicked()
{
    compteur.l1r3++;
    ui->line1_row3_button->setText("L1R3: "+QVariant(compteur.l1r3).toString());
    mqttMessage = "line1_row3";
    mqttClient->publish(mqttTopic,mqttMessage);
}


void MainWindow::on_line1_row4_button_clicked()
{
    compteur.l1r4++;
    ui->line1_row4_button->setText("L1R4: "+QVariant(compteur.l1r4).toString());
    mqttMessage = "line1_row4";
    mqttClient->publish(mqttTopic,mqttMessage);
}


void MainWindow::on_line1_row1_button_released()
{
    // ui->line1_row1_button->setStyleSheet("background-color:white;");
}


void MainWindow::on_line1_row2_button_released()
{
    // ui->line1_row2_button->setStyleSheet("background-color:white;");
}

