#include "change.h"
#include "ui_change.h"
#include "admin.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
change::change(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::change)
{

    ui->setupUi(this);
    ui->pushButton_change->setStyleSheet(
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
    ui->pushButton_cancel->setStyleSheet(
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
change::~change()
{
    delete ui;
}

void change::on_pushButton_change_clicked()
{
    QSqlQuery query;
    QString date,name,size,count,perPrice,price,seller,tel,note;
    date=ui->lineEdit_date->text();
    name=ui->lineEdit_name->text();
    size=ui->lineEdit_size->text();
    count=ui->lineEdit_count->text();
    perPrice=ui->lineEdit_perPrice->text();
    price=ui->lineEdit_price->text();
    seller=ui->lineEdit_seller->text();
    tel=ui->lineEdit_tel->text();
    note=ui->textEdit_note->toPlainText();

    query.exec("update goods set date='"+date+"',name='"+name+"',size='"+size+"',goodsCount='"+count+"',perPrice='"+perPrice+"',price='"+price+"',seller='"+seller+"',tel='"+tel+"',note='"+note+"' where id='"+change_id+"'");
    //qDebug()<<date;
    QMessageBox::about(NULL,"提示","订单修改成功！");
    ui->lineEdit_date->setText("");
    ui->lineEdit_name->setText("");
    ui->lineEdit_size->setText("");
    ui->lineEdit_count->setText("");
    ui->lineEdit_perPrice->setText("");
    ui->lineEdit_price->setText("");
    ui->lineEdit_seller->setText("");
    ui->lineEdit_tel->setText("");
    ui->textEdit_note->setText("");
    close();
    //admin.show();

}



void change::on_pushButton_cancel_clicked()
{
    ui->lineEdit_date->setText("");
    ui->lineEdit_name->setText("");
    ui->lineEdit_size->setText("");
    ui->lineEdit_count->setText("");
    ui->lineEdit_perPrice->setText("");
    ui->lineEdit_price->setText("");
    ui->lineEdit_seller->setText("");
    ui->lineEdit_tel->setText("");
    ui->textEdit_note->setText("");
    close();
}
