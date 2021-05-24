#include "admin.h"
#include "ui_admin.h"
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlQuery>
#include <QStandardItemModel>



admin::admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);

    //initTable();

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
    init();
}

admin::~admin()
{
    delete ui;
}


void admin::initTable(){
    //tableiew->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置单元格不可编辑

    tableview->setContextMenuPolicy(Qt::CustomContextMenu); //少这句，右键没有任何反应的。

    createRightMenu(); //创建一个右键菜单
    connect(tableview,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(clicked_rightMenu(QPoint)));
}
void admin::clicked_rightMenu(const QPoint &pos){
    rightMenu->exec(QCursor::pos());
}
void admin::createRightMenu(){
    rightMenu=new QMenu;
    delAction=new QAction("删除",this);
    changeAction=new QAction("修改",this);
}


void admin::init()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    sql="select id as 订单号,date as 出货日期,name as 商品名称,size as 规格, goodsCount as 数量,perPrice as 单价,price as 金额,seller as 单位名称,tel as 联系方式,note as 备注 from goods";
    model->setQuery(sql);
    ui->tableView_1->setModel(model);
}

void admin::on_pushButton_search_clicked()
{
    find();
}

void admin::on_pushButton_add_clicked()
{
    ad = new add;
    ad->show();
}

void admin::on_pushButton_delete_clicked()
{
    QString id=ui->lineEdit_id->text();
    QSqlQuery query;
    query.exec("select * from goods where id='"+id+"'");
    if(!query.next()){
        QMessageBox::information(NULL, "错误！", "此订单号不存在",QMessageBox::Yes);
        ui->lineEdit_id->setText("");
    }else{
        QMessageBox::information(NULL, "Title", "确定删除？",
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(QMessageBox::Yes){
            del();
        }else{

        }
    }



}
void admin::find()
{
    QSqlQueryModel *modell=new QSqlQueryModel;
    QString id,product,buyer,date;
    id=ui->lineEdit_id->text();
    date=ui->lineEdit_date->text();
    product=ui->lineEdit_product->text();
    buyer=ui->lineEdit_buyer->text();
    QString sql;
    if(id==NULL&&date==NULL&&product==NULL&&buyer==NULL){
        sql="select id as 订单号,date as 出货日期,name as 商品名称,size as 规格, goodsCount as 数量,perPrice as 单价,price as 金额,seller as 单位名称,tel as 联系方式,note as 备注 from goods ";
    }
    if(id!=NULL){
        sql="select id as 订单号,date as 出货日期,name as 商品名称,size as 规格, goodsCount as 数量,perPrice as 单价,price as 金额,seller as 单位名称,tel as 联系方式,note as 备注 from goods where id LIKE '%"+id+"%'";
    }
    if(date!=NULL){
        sql="select id as 订单号,date as 出货日期,name as 商品名称,size as 规格, goodsCount as 数量,perPrice as 单价,price as 金额,seller as 单位名称,tel as 联系方式,note as 备注 from goods where date LIKE '%"+date+"%'";
    }
    if(product!=NULL){
        sql="select id as 订单号,date as 出货日期,name as 商品名称,size as 规格, goodsCount as 数量,perPrice as 单价,price as 金额,seller as 单位名称,tel as 联系方式,note as 备注 from goods where name LIKE '%"+product+"%'";
    }
    if(buyer!=NULL){
        sql="select id as 订单号,date as 出货日期,name as 商品名称,size as 规格, goodsCount as 数量,perPrice as 单价,price as 金额,seller as 单位名称,tel as 联系方式,note as 备注 from goods where seller LIKE '%"+buyer+"%'";

    }
    modell->setQuery(sql);

    ui->tableView_1->setModel(modell);

}
void admin::del(){
    QSqlQueryModel *modell=new QSqlQueryModel;
    QString id,product,buyer,date;
    id=ui->lineEdit_id->text();
    date=ui->lineEdit_date->text();
    product=ui->lineEdit_product->text();
    buyer=ui->lineEdit_buyer->text();
    QString sql;


        if(id!=NULL){
            sql="delete from goods where id = "+id+"";
        }
        modell->setQuery(sql);
        QString sql2;
        sql2="select id as 订单号,date as 出货日期,name as 商品名称,size as 规格, goodsCount as 数量,perPrice as 单价,price as 金额,seller as 单位名称,tel as 联系方式,note as 备注 from goods";
        modell->setQuery(sql2);
        ui->tableView_1->setModel(modell);


}
void admin::on_pushButton_clear_clicked()
{
    ui->lineEdit_id->setText("");
    ui->lineEdit_buyer->setText("");
    ui->lineEdit_product->setText("");
    ui->lineEdit_date->setText("");
}

void admin::on_pushButton_exit_clicked()
{
    close();
}

void admin::on_pushButton_refresh_clicked()
{
    init();
}
void admin::on_tableView_1_doubleClicked(const QModelIndex &index)
{
    idd= index.data().toString();
    QSqlQuery query;
    query.exec("select * from goods where id='"+idd+"'");
    if(query.next()){
        ch.change_id=idd;
        QSqlQuery query2;
        query2.exec("select date,name,size,goodsCount,perPrice,price,seller,tel,note from goods where id ='"+ch.change_id+"'");
        if(query2.next())
        {
            date = query.value(1).toString();
            name= query.value(2).toString();
            size= query.value(3).toString();
            count=query.value(4).toString();
            perPrice=query.value(5).toString();
            price=query.value(6).toString();
            seller=query.value(7).toString();
            tel=query.value(8).toString();
            note=query.value(9).toString();
        }
        ch.ui->lineEdit_id->setText(idd);
        ch.ui->lineEdit_date->setText(date);
        ch.ui->lineEdit_name->setText(name);
        ch.ui->lineEdit_size->setText(size);
        ch.ui->lineEdit_count->setText(count);
        ch.ui->lineEdit_perPrice->setText(perPrice);
        ch.ui->lineEdit_price->setText(price);
        ch.ui->lineEdit_seller->setText(seller);
        ch.ui->lineEdit_tel->setText(tel);
        ch.ui->textEdit_note->setText(note);
        ch.show();
    }else{
        QMessageBox::information(NULL, "Title", "请双击订单号进行修改",QMessageBox::Yes);
    }


}

void admin::on_pushButton_clicked()
{
    QMessageBox::information(NULL, "Title", "请双击订单号进行修改",QMessageBox::Yes);
}
