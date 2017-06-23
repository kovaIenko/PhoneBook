#ifndef ADDNUMBER_H
#define ADDNUMBER_H
#include "QLineEdit"
#include <QDialog>

namespace Ui {
class addnumber;
}

class addnumber : public QDialog
{
    Q_OBJECT

public:
    explicit addnumber(QWidget *parent = 0);
    ~addnumber();

private slots:
    void on_OK_Numb_clicked();

private:
    Ui::addnumber *ui;
    QLineEdit * name;
    QLineEdit * numb;
};

#endif // ADDNUMBER_H
