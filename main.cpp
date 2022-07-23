#include <QApplication>
#ifndef QT_NO_SYSTEMTRAYICON
#include <QMessageBox>
#include "MainWindow.h"
int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(images);  // if del ，icon will not show
    QApplication a(argc, argv);
    MainWindow w;
    return a.exec();
}
#else

#include <QLabel>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QString text("QSystemTrayIcon is not supported on this platform");

    QLabel *label = new QLabel(text);
    label->setWordWrap(true);

    label->show();
    qDebug() << text;

    app.exec();
}

#endif
