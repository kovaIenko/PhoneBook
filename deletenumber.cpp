#include "deletenumber.h"
#include "ui_deletenumber.h"
#include "controller.h"

DeleteNumber::DeleteNumber(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteNumber)
{
    ui->setupUi(this);

    numb= findChild<QLineEdit*>("delNumb");
     numb->setPlaceholderText("38 *** *** ** **");

       name= findChild<QLineEdit*>("delName");
         name->setPlaceholderText("Kovalenko Ruslan");
}

DeleteNumber::~DeleteNumber()
{
    delete ui;
}

void DeleteNumber::on_del_OK_clicked()
{
    QString input_numb= numb->text();
     QString input_name= name->text();
    Controller::getController().numberDeleteController(input_name,input_numb);
    name->clear();
    numb->clear();
    this->close();
}
