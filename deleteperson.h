#ifndef DELETEPERSON_H
#define DELETEPERSON_H
#include "QLineEdit"
#include <QDialog>

namespace Ui {
class DeletePerson;
}

class DeletePerson : public QDialog
{
    Q_OBJECT

public:
    explicit DeletePerson(QWidget *parent = 0);
    ~DeletePerson();

private slots:
    void on_del_OK_clicked();

private:
    Ui::DeletePerson *ui;
      QLineEdit * name;
};

#endif // DELETEPERSON_H
