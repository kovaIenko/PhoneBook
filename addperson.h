#ifndef ADDPERSON_H
#define ADDPERSON_H
#include "QLineEdit"
#include <QDialog>
#include "controller.h"

namespace Ui {
class AddPerson;
}
 class Controller;
class AddPerson : public QDialog
{
    Q_OBJECT

public:
    explicit AddPerson(QWidget *parent = 0);
    ~AddPerson();

private slots:
    void on_OK_clicked();

private:
    Ui::AddPerson *ui;

    QLineEdit * name;
};

#endif // ADDPERSON_H
