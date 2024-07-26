#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMqttClient"

typedef struct lr{
    int l1r1 = 0;
    int l1r2 = 0;
    int l1r3 = 0;
    int l1r4 = 0;

    int l2r1 = 0;
    int l2r2 = 0;
    int l2r3 = 0;
    int l2r4 = 0;

    int l3r1 = 0;
    int l3r2 = 0;
    int l3r3 = 0;
    int l3r4 = 0;
}LR;

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

    QMqttClient *mqttClient;
    QMqttTopicName mqttTopic;
    QByteArray mqttMessage;

    int i = 0;
    int lr[3][4] = {{0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0}};
    LR compteur;
    QPalette pal = QPalette();

private slots:
    void on_line1_row1_button_clicked();

    void on_line1_row2_button_clicked();

    void on_line1_row3_button_clicked();

    void on_line1_row4_button_clicked();

    void on_line1_row1_button_released();

    void on_line1_row2_button_released();

private:
    Ui::MainWindow *ui;
    void updateLogStateChange();
    void brokerDisconnected();
};



#endif // MAINWINDOW_H
