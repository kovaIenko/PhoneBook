#include "window.h"
#include "addnumber.h"
#include "ui_window.h"
#include "addperson.h"
#include "deleteperson.h"
#include "deletenumber.h"
#include "editperson.h"
#include "QDebug"
#include "controller.h"
#include "QListWidget"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
     names= findChild<QListWidget*>("listNames");
   phones=findChild<QListWidget*>("listPhones");

}

Window::~Window()
{
    delete ui;
}

void Window::on_addNumb_clicked()
{
    addnumber w;
    w.setModal(true);
    w.exec();
}



void Window::on_addPerson_clicked()
{
    AddPerson w;
    w.setModal(true);
    w.exec();
}

void Window::on_update_names(){
      names->clear();
     if(Controller::getController().getContacts().size()==1){
          QMultiMap<int,Person>::iterator iter = Controller::getController().getContacts().begin();
        Window::getWindow().getListNames().addItem(iter.value().getName());
      }
      else{
        for(auto it=Controller::getController().getContacts().begin();it!=Controller::getController().getContacts().end();++it){
             Window::getWindow().getListNames().addItem(it.value().getName());
     }
     }
     }

  void Window::on_update_phoneOfNames(QString& name){
     phones->clear();
  Person tPerson(Controller::getController().getContacts().getBook().value(name));
    for(int i=0;i<tPerson.getPhoneNumbers().size();i++){
        phones->addItem(tPerson.getPhoneNumbers().value(i));
    }
  }

Window& Window::getWindow(){

    static Window s;
    return s;
}

QListWidget&  Window::getListNames(){
    return  *names;
}

void Window::on_listNames_pressed(const QModelIndex &index)
{
    selectedIndexOfItem=index.row();
}


int Window::selectedIndexOfItem=0;

QListWidget& Window::getListPhones()
{
    return *phones;
}

 void  Window::on_listNames_itemClicked(QListWidgetItem *item)
 {
     QString tName= item->text();
    Window::getWindow().on_update_phoneOfNames(tName);
 }


void Window::on_delPerson_clicked()
{
   DeletePerson w;
    w.setModal(true);
    w.exec();
}

void Window::on_delNumb_clicked(){
    DeleteNumber w;
     w.setModal(true);
     w.exec();
 }

 void Window::on_save_clicked(){
Controller::getController().saveToFile(&QFile("../numbs2.dat"));
 }


void Window::on_editPerson_clicked()
{
   EditPerson w;
     w.setModal(true);
     w.exec();

}
