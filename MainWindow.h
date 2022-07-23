#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>
#include<QMessageBox>
#include<QUrl>
#include"ScreenWidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void scanQR();
    bool isURL(QString url);

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *m_sysTrayIcon;
    void initSysTrayIcon();
   QMenu  *m_menu;
   QAction *m_scanQRcode;
   QAction *m_about;
   QAction *m_exit;
   void createActions();
   void createMenu();
private slots:
   void on_scanQrCode();
   void on_about();
   void on_exit();

   void on_pushButton_clicked();

protected:
    void closeEvent (QCloseEvent *event) override;
};

#endif // MAINWINDOW_H
