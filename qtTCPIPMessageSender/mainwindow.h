#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void init();
    void createServer();
    void connectServer(QString ipString, qint64 port);


private slots:
    void acceptConnection();
    void displayError(QAbstractSocket::SocketError);
    void showDataClient();
    void showDataServer();

    void on_sendButton_clicked();

    void on_createServerButton_clicked();

    void on_connectButton_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer* qTcpServer;
    QTcpSocket* qTcpSocket;
};

#endif // MAINWINDOW_H
