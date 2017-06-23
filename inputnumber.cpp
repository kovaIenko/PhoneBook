#include "inputnumber.h"

inputnumber::inputnumber(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

inputnumber::~inputnumber()
{
    delete ui;
}
