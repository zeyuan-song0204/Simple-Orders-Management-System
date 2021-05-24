#ifndef CHANGE_H
#define CHANGE_H

#include <QMainWindow>
#include <QString>


extern QString changeID;
namespace Ui {
class change;
}

class change : public QMainWindow
{
    Q_OBJECT

public:
    explicit change(QWidget *parent = nullptr);
    Ui::change *ui;
    ~change();
    QString change_id;
    QString date,name,size,count,perPrice,price,seller,tel,note;


private slots:
    void on_pushButton_change_clicked();




    void on_pushButton_cancel_clicked();



public:


};

#endif // CHANGE_H
