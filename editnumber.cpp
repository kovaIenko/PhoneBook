#include "editnumber.h"
#include "ui_editnumber.h"

EditNumber::EditNumber(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditNumber)
{
    ui->setupUi(this);
}

EditNumber::~EditNumber()
{
    delete ui;
}
