#ifndef EDITPERSON_H
#define EDITPERSON_H

#include <QDialog>
#include "QLineEdit"
namespace Ui {
class EditPerson;
}

class EditPerson : public QDialog
{
    Q_OBJECT

public:
    explicit EditPerson(QWidget *parent = 0);
    ~EditPerson();

private slots:
    void on_Edit_OK_clicked();

private:
    Ui::EditPerson *ui;
    QLineEdit * name;
    QLineEdit * newName;
};

#endif // EDITPERSON_H
