#ifndef EDITNUMBER_H
#define EDITNUMBER_H

#include <QDialog>

namespace Ui {
class EditNumber;
}

class EditNumber : public QDialog
{
    Q_OBJECT

public:
    explicit EditNumber(QWidget *parent = 0);
    ~EditNumber();

private:
    Ui::EditNumber *ui;
    QLineEdit * name;
    QLineEdit * numb;
    QLineEdit * name;
};

#endif // EDITNUMBER_H
