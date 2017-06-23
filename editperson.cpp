#include "editperson.h"
#include "ui_editperson.h"
#include "controller.h"
#include "QLineEdit"
#include "QDebug"
EditPerson::EditPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditPerson)
{
    ui->setupUi(this);
    name= findChild<QLineEdit*>("name");
    name->setPlaceholderText("kovalenko rulan");
     newName= findChild<QLineEdit*>("newName");
      newName->setPlaceholderText("kovalenko rulan");
}

EditPerson::~EditPerson()
{
    delete ui;
}

void EditPerson::on_Edit_OK_clicked()
{
    QString input_name= name->text();
     QString input_newName= newName->text();
    Controller::getController().editPersonController(input_name,input_newName);
    name->clear();
    newName->clear();
    this->close();
}
