#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "admin.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool opendatabase();
    bool createTable();

private slots:

    void on_pushButton_login_clicked();

    void on_pushButton_exit_clicked();

private:
    Ui::MainWindow *ui;
     QString username;
     QString userpassword;
     admin *adm;
};
#endif // MAINWINDOW_H
