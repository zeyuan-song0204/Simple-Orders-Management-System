#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    opendatabase();
    createTable();
    this->setWindowTitle("淄博国丰出货查询系统");
    this->setWindowIcon(QIcon(":/images/logo.PNG"));
    setStyleSheet(
                       //正常状态样式
                       "QPushButton{"
                       "background-color:rgba(100,225,100,30);"//背景色（也可以设置图片）
                       "border-style:outset;"                  //边框样式（inset/outset）
                       "border-width:4px;"                     //边框宽度像素
                       "border-radius:10px;"                   //边框圆角半径像素
                       "border-color:rgba(255,255,255,30);"    //边框颜色
                       "font:bold 30px;"                       //字体，字体大小
                       "color:rgba(0,0,0,100);"                //字体颜色
                       "padding:6px;"                          //填衬
                       "}"
                       //鼠标按下样式
                       "QPushButton:pressed{"
                       "background-color:rgba(100,255,100,200);"
                       "border-color:rgba(255,255,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"
                       //鼠标悬停样式
                       "QPushButton:hover{"
                       "background-color:rgba(100,255,100,100);"
                       "border-color:rgba(255,255,255,200);"
                       "color:rgba(0,0,0,200);"
                       "}");
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::opendatabase()
{
    QSqlDatabase myDB=QSqlDatabase::addDatabase("QSQLITE");
    myDB = QSqlDatabase::addDatabase("QSQLITE");
    //myDB.setDatabaseName(QApplication::applicationDirPath() +"mySQlite.db");
    myDB.setDatabaseName("./mySQlite.dat");
    if(myDB.open())
    {
        qDebug()<<"open success";

        return true;
    }
    else
    {
        qDebug()<<"open failed";
        return false;
    }
}
bool MainWindow::createTable()
{
    QSqlQuery *query=new QSqlQuery();

    QString goodStr="create table if not exists goods("
                    "[id] integer primary key autoincrement,"
                    "[date] varchar(30),"
                    "[name] varchar(30),"
                    "[size] varchar(30),"
                    "[goodsCount] varchar(30),"
                    "[perPrice] varchar(30),"
                    "[price] varchar(30),"
                    "[seller] varchar(30),"
                    "[tel] varchar(60),"
                    "[note] varchar(60)"
                    ")";
    if(query->exec(goodStr)){
        qDebug()<<"table created";
        return true;
    }else{
        qDebug()<<"table create failed";
        return false;
    }

}




void MainWindow::on_pushButton_login_clicked()
{
    username=ui->lineEdit_name->text();
    userpassword=ui->lineEdit_password->text();
    if(username=="tz"&&userpassword=="0303")
    {

            //QMessageBox::about(NULL,"提示","用户登陆成功");
            adm=new admin;
            adm->show();
            close();
    }
    else
    {
        QMessageBox::about(NULL,"提示","用户名或密码错误");
    }
}

void MainWindow::on_pushButton_exit_clicked()
{
    close();
}
