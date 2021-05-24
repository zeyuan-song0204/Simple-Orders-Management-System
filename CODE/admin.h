#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include "add.h"
#include <QSqlTableModel>
#include "change.h"
#include "ui_change.h"
#include <QMenu>
#include <QAction>
#include <QTableView>
namespace Ui {
class admin;
}

class admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();
     Ui::admin *ui;
    QString idd;


private slots:
    void clicked_rightMenu(const QPoint &pos); //右键信号槽函数
    void on_pushButton_search_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_clear_clicked();

    void init();
    void find();
    void del();
    void on_pushButton_exit_clicked();

    void on_pushButton_refresh_clicked();


    void createRightMenu();
    void initTable();

    void on_tableView_1_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    add *ad;
    change ch;
    //QSqlTableModel *tablemodel;

    QString date,name,size,count,perPrice,price,seller,tel,note;

    QTableView *tableview;
    QMenu *rightMenu; //右键菜单
    QAction *delAction; //删除
    QAction *changeAction; //修改


};

#endif // ADMIN_H
