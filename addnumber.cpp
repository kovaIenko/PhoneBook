#include "addnumber.h"
#include "ui_addnumber.h"
#include "controller.h"
#include "QDebug"


addnumber::addnumber(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::addnumber)
{
    ui->setupUi(this);
     numb=findChild<QLineEdit*>("inNumb");
      numb->setPlaceholderText("38 *** *** ** **");

     name=findChild<QLineEdit*>("inName");
     name->setPlaceholderText("Kovalenko Ruslan");
}

addnumber::~addnumber()
{
    delete ui;
}

void addnumber::on_OK_Numb_clicked()
{
    QString input_numb= numb->text();
     QString input_name= name->text();
    Controller::getController().numberToPersonController(input_name,input_numb);
    name->clear();
    numb->clear();
    this->close();

}
