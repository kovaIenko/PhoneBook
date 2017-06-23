#include "deleteperson.h"
#include "ui_deleteperson.h"
#include "controller.h"

DeletePerson::DeletePerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeletePerson)
{
    ui->setupUi(this);
      name= findChild<QLineEdit*>("delName");
       name->setPlaceholderText("Kovalenko Ruslan");
}

DeletePerson::~DeletePerson()
{
    delete ui;
}

void DeletePerson::on_del_OK_clicked()
{
    QString del_name= name->text();
    Controller::getController().personDeleteController(del_name);
    name->clear();
    this->close();
}
