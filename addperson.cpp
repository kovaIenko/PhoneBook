#include "addperson.h"
#include "ui_addperson.h"
#include "person.h"
#include "QDebug"
#include "controller.h"

AddPerson::AddPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPerson)
{
    ui->setupUi(this);
     name=findChild<QLineEdit*>("name");
      name->setPlaceholderText("Kovalenko Ruslan");
}

AddPerson::~AddPerson()
{
    delete ui;
}

void AddPerson::on_OK_clicked()
{
  QString namePrs =  name->text();
  Controller::getController().personToBookController(namePrs);
  name->clear();
  this->close();
}


