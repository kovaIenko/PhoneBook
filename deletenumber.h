#ifndef DELETENUMBER_H
#define DELETENUMBER_H

#include <QDialog>
#include "QLineEdit"

namespace Ui {
class DeleteNumber;
}

class DeleteNumber : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteNumber(QWidget *parent = 0);
    ~DeleteNumber();

private slots:
    void on_del_OK_clicked();

private:
    Ui::DeleteNumber *ui;
    QLineEdit * name;
    QLineEdit * numb;
};

#endif // DELETENUMBER_H
