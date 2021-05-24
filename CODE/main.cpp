#include "mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QApplication>
#include <QSqlQuery>
#include <QDir>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    //QApplication::addLibraryPath("./plugins");

    QApplication a(argc, argv);
    //QString strLibPath(QDir::toNativeSeparators(QApplication::applicationDirPath()) + QDir::separator() + "plugins");
    //a.addLibraryPath(strLibPath);
    MainWindow w;
    w.show();
    return a.exec();
}
