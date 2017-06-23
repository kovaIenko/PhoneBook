#include "book.h"
#include "controller.h"
#include "QDebug"
#include "Window.h"

Book::Book()
{

}
Book::~Book()
{
}

void Book::addPersonInBook(Person & contact)
{
    if(contact.getName().length()>1&&!isPresent(contact.getName()))
    _book.insert(contact.getName(), contact);
}
void Book:: setPersonInBook(Person& contact){
    if(isPresent(contact.getName())){
        _book.remove(contact.getName());
        addPersonInBook(contact);
    }

}
void Book::addNumberToPerson(QString & name,QString & numb)
{
  if(isPresent(name)){
      Person tPerson(Controller::getController().getContacts().getBook().value(name));
      tPerson.addPhoneNumber(numb);
      setPersonInBook(tPerson);
  }

}
bool Book::isPresent(QString& name){
    for(auto it=_book.begin();it!=_book.end();++it){
        if(it.key()==name)
            return true;
    }
    return false;
}

void Book::delPerson(QString& name){
    if(isPresent(name)){
       _book.remove(name);
    }
}

   void Book::delNumber(QString & name , QString & numb){
       if(isPresent(name)){
           Person tPerson(Controller::getController().getContacts().getBook().value(name));
           tPerson.delPhoneNumber(numb);
            setPersonInBook(tPerson);
       }
   }

   void Book::editPerson(QString & name, QString &newName){
       if(isPresent(name)){
          Person tPerson(Controller::getController().getContacts().getBook().value(name));;
          tPerson.setName(newName);
       replacementPersons(name, tPerson);
       }
   }

   void Book::replacementPersons(QString& oldName, Person& person){
       if(isPresent(oldName)){
           _book.remove(oldName);
           addPersonInBook(person);
       }
   }

  QMultiMap <QString,Person>::const_iterator Book::end() const{
      if(_book.size()==1)
          return _book.begin();
         return _book.end();
     }
 QMultiMap <QString,Person>::const_iterator Book::begin() const{
         return _book.begin();
     }

 int Book::size() const
 {
     return Book::_book.size();
 }
 const Person& Book::value(QString & key) const{
     Person res=_book.value(key);
     return res;
 }

 QMultiMap<QString,Person> Book::getBook(){
   return _book;
 }



