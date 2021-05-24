#include "add.h"
#include "ui_add.h"
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlQuery>
#include "ui_admin.h"
add::add(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    this->setWindowTitle("新增出货单");
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

add::~add()
{
    delete ui;
}

void add::on_pushButton_confirm_clicked()
{
   QString id,date,name,size,count,perPrice,price,seller,tel,note;
   id=ui->lineEdit_id->text();
   date=ui->lineEdit_date->text();
   name=ui->lineEdit_name->text();
   size=ui->lineEdit_size->text();
   count=ui->lineEdit_count->text();
   perPrice=ui->lineEdit_perPrice->text();
   price=ui->lineEdit_price->text();
   seller=ui->lineEdit_seller->text();
   tel=ui->lineEdit_tel->text();
   note=ui->textEdit_note->toPlainText();
   QString sql;

   QSqlQuery query;
   query.exec("select * from goods where id='"+id+"'");
   if(query.next()){
       QMessageBox::information(NULL, "错误！", "所填订单号已存在",QMessageBox::Yes);
       ui->lineEdit_id->setText("");
   }else{
       sql="INSERT INTO goods (id,date,name,size,goodsCount,perPrice,price,seller,tel,note) VALUES ('"+id+"','"+date+"','"+name+"','"+size+"','"+count+"','"+perPrice+"','"+price+"','"+seller+"','"+tel+"','"+note+"')";
       QSqlQueryModel *modell=new QSqlQueryModel;
       modell->setQuery(sql);
       QMessageBox::about(NULL,"提示","订单添加成功！");
       //加载数据表
       /*QSqlQueryModel *model=new QSqlQueryModel;
       QString sql;
       sql="select id as 订单号,date as 出货日期,name as 商品名称,size as 规格, goodsCount as 数量,perPrice as 单价,price as 金额,seller as 单位名称,tel as 联系方式,note as 备注 from goods";
       model->setQuery(sql);
       a->ui->tableView_1->setModel(model);*/

       close();
   }


}

void add::on_pushButton_cancel_clicked()
{
    close();
}
