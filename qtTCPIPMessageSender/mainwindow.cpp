#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

void MainWindow::init()
{
    qTcpSocket = new QTcpSocket(this);
}

void MainWindow::createServer()
{
    qTcpServer = new QTcpServer(this);
    if(!qTcpServer->listen(QHostAddress::Any, 34894)){
        qDebug()<<qTcpServer->errorString();
        close();
        return;
    }
    if(!qTcpSocket){
        qTcpSocket = new QTcpSocket(this);
    }
    else{
        qTcpSocket->abort();
    }

    connect(qTcpServer, SIGNAL(newConnection()),
            this, SLOT(acceptConnection()));
    connect(qTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
}

void MainWindow::acceptConnection()
{
    //当有客户来访时将tcpSocket接受tcpServer建立的socket
    qTcpSocket = qTcpServer->nextPendingConnection();
    connect(qTcpSocket, SIGNAL(readyRead()),
            this, SLOT(showDataServer()));
}

void MainWindow::displayError(QAbstractSocket::SocketError)
{
   qDebug()<<qTcpSocket->errorString();
   qTcpSocket->close();
}

void MainWindow::connectServer(QString ipString, qint64 port)
{
    qTcpSocket->abort();
    qTcpSocket->connectToHost(ipString, port);
    connect(qTcpSocket, SIGNAL(readyRead()),
            this, SLOT(showDataClient()));
    connect(qTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
}

void MainWindow::showDataClient()
{
    QString data = qTcpSocket->readAll();
    qDebug()<<data;
    ui->clientBrowser->setText(data);
}

void MainWindow::showDataServer()
{
    QString data = qTcpSocket->readAll();
    qDebug()<<data;
    ui->serverBrowser->setText(data);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//----------events----------

void MainWindow::on_sendButton_clicked()
{
    if(!qTcpSocket){
        qDebug()<<"Error: TCP socket is not ready!\n";
        //close();
        return;
    }
    if(qTcpSocket->write(ui->messageEdit->text().toLatin1()) == -1){
        qDebug()<<"Error: socket write failed!";
        return;
    }
    qDebug()<<"Sending data: "<<ui->messageEdit->text();
}

void MainWindow::on_createServerButton_clicked()
{
    this->createServer();
    ui->createServerButton->setEnabled(false);
    ui->stopServerButton->setEnabled(true);
}

void MainWindow::on_connectButton_clicked()
{
    QString IPString = ui->IPLineEdit->text();
    QString portString = ui->portLineEdit->text();
    connectServer(IPString, portString.toInt());
    //qTcpServer->close();
    ui->createServerButton->setEnabled(true);
    ui->stopServerButton->setEnabled(false);
}
