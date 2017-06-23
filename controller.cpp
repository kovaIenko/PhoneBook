#include "controller.h"
#include "window.h"
#include "QDebug"
#include "QFile"

Controller::Controller()
{
}

void Controller::personToBookController(QString & name)
{
    name =name.trimmed();
    Person contact(name);
    Controller::getController().getContacts().addPersonInBook(contact);
      Window::getWindow().on_update_names();
}

void Controller::numberToPersonController(QString & inName, QString & inNumb)
{
    inName =inName.trimmed();
      inNumb =inNumb.trimmed();
    Controller::getController().getContacts().addNumberToPerson(inName,inNumb);
     Window::getWindow().on_update_phoneOfNames(inName);
}

 void Controller::personDeleteController(QString& name){
        Controller::getController().getContacts().delPerson(name);
          Window::getWindow().on_update_names();
       Window::getWindow().on_update_phoneOfNames(name);
 }

  void Controller::numberDeleteController(QString& name,QString& numb){
      Controller::getController().getContacts().delNumber(name,numb);
           Window::getWindow().on_update_phoneOfNames(name);
  }

   void Controller::editPersonController(QString& name,QString& newName){
       Controller::getController().getContacts().editPerson(name,newName);
         Window::getWindow().on_update_names();
   }

Controller& Controller::getController(){ //pattern Singleton

    static Controller s;
    return s;
}
 Book& Controller::getContacts()
 {
     return  _contacts;
 }

 void Controller::loadingFileDate(QFile* file){
     if(!file->exists())
     {
     qDebug() << "File is not exists";
     }
     file->open(QIODevice::ReadOnly);

     QTextStream in(file);
     QString lines_name="";
      QString lines_number="";
     while(!in.atEnd()){
      lines_name = in.readLine();
       Controller::getController().personToBookController(lines_name);
      lines_number= in.readLine();
     QStringList list=lines_number.split(',');
     for(int i=0;i<list.length();i++){
          Controller::getController().numberToPersonController(lines_name,list[i]);
     }
     }
     file->close();
 }

 void  Controller:: saveToFile(QFile* file){
     if(!file->exists())
     {
     qDebug() << "File is not exists";
     }
     QTextStream out(file);

     if(file->open(QIODevice::Append))
     {
         file->reset();
         for(auto it=Controller::getController().getContacts().begin();it!=Controller::getController().getContacts().end();++it){
             QString name=it.value().getName();
              QString numbers="";
             Person tPerson(Controller::getController().getContacts().getBook().value(name));
             for(int i=0;i<tPerson.getPhoneNumbers().size()-1;i++)
                 numbers+=tPerson.getPhoneNumbers().value(i)+",";
              numbers+=tPerson.getPhoneNumbers().value(tPerson.getPhoneNumbers().size()-1)+"";
                  out << name+" ";
                  out<<numbers<<" ";
     }
     file->close();
     }

 }
