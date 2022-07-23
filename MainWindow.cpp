#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include "QZXing.h"
#include<QDesktopServices>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSysTrayIcon();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::scanQR()
{
    ScreenWidget::Instance()->showFullScreen();
}

bool MainWindow::isURL(QString url)
{
    return false;
}

void MainWindow::initSysTrayIcon()
{
        this->hide();
        m_sysTrayIcon = new QSystemTrayIcon(this);
        QIcon icon = QIcon(":/iamages/qrcode.png");
        m_sysTrayIcon->setIcon(icon);
        m_sysTrayIcon->setToolTip(QString("QR Code Scaner"));
        connect(m_sysTrayIcon, &QSystemTrayIcon::activated,
                [=](QSystemTrayIcon::ActivationReason act)
        {
            switch(act)
            {
            case QSystemTrayIcon::Trigger:
                //m_sysTrayIcon->showMessage(QObject::trUtf8("Welcome"), QObject::trUtf8(""),QSystemTrayIcon::Information,1000);
                //on_scanQrCode();
                 this->show();
                break;
            case QSystemTrayIcon::DoubleClick:
                this->show();
                break;
            default:
                break;
            }
        });

        createActions();
        createMenu();
        m_sysTrayIcon->show();
        m_sysTrayIcon->showMessage(QObject::trUtf8("Running..."), QObject::trUtf8(""),QSystemTrayIcon::Information,1000);



}

void MainWindow::createActions()
{
   m_scanQRcode = new QAction(QStringLiteral("Scan QRCode"), this);
   connect(m_scanQRcode,&QAction::triggered,this,&MainWindow::on_scanQrCode);
   m_about =new QAction(QStringLiteral("About"),this);
   connect(m_about,&QAction::triggered,this,&MainWindow::on_about);
   m_exit = new QAction(QStringLiteral("Exit"),this);
   connect(m_exit,&QAction::triggered,this,&MainWindow::on_exit);
 }

void MainWindow::createMenu()
{
    m_menu =new QMenu(this);
    m_menu->addAction(m_scanQRcode);
    m_menu->addAction(m_about);
    m_menu->addSeparator();
    m_menu->addAction(m_exit);
    m_sysTrayIcon->setContextMenu(m_menu);


}

void MainWindow::on_scanQrCode()
{
   ScreenWidget::Instance()->showFullScreen();
}

void MainWindow::on_about()
{
  //qDebug()<<"about";
    m_sysTrayIcon->showMessage(QObject::trUtf8("QRcode tool based on QZxing\nby CodeCopier"), QObject::trUtf8(""),QSystemTrayIcon::Information,2000);
}

void MainWindow::on_exit()
{
  qApp->exit();
}
void MainWindow::closeEvent(QCloseEvent *event){
    QApplication::setQuitOnLastWindowClosed(true);
    this->hide();
    event->ignore();
}


void MainWindow::on_pushButton_clicked()
{
   QDesktopServices::openUrl(QUrl("https://github.com/vampirely/Qt_QRCodeScaner"));
   m_sysTrayIcon->showMessage(QObject::trUtf8("Maybe the link is open ?"), QObject::trUtf8(""),QSystemTrayIcon::Information,1000);
}
