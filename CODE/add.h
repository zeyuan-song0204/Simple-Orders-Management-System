#ifndef ADD_H
#define ADD_H
#include <QMainWindow>
namespace Ui {

class add;
}

class add : public QMainWindow
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = nullptr);
    ~add();

private slots:
    void on_pushButton_confirm_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::add *ui;
    //admin *a;
};

#endif // ADD_H
