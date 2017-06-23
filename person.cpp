#include "person.h"

Person::Person(QString name):
    _name(name)
{
    _id++;

}
Person::Person():
    _name("Inognito")
{
    _id++;

}
int Person::getId() const{
    return _id;
}

QString Person::getName() const
{
    return _name;
}

 void Person::addPhoneNumber(QString& numb){
    _numbs.append(numb);
 }

  QList<QString> Person::getPhoneNumbers(){
      return _numbs;
  }

    void  Person::delPhoneNumber(QString& numb){
      //  qDebug()<<numb+"------------";
        if(_numbs.contains(numb))
         _numbs.removeOne(numb);
      }

     void  Person::setName(QString& newName){
         _name= newName;

     }

 int Person::_id =0;
