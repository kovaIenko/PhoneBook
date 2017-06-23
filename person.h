#ifndef PERSON_H
#define PERSON_H
#include "QString";
#include "QList"

class Person
{
public:
     Person(QString);
   Person();
    QString getName() const;
    QString  getPhoneNumbers() const;
    int getId() const;

    void setName(QString&);
    void addPhoneNumber(QString& numb);
    void delPhoneNumber(QString& numb);
   QList<QString> getPhoneNumbers();

private:
    QString _name;
   QList<QString> _numbs;
    static int _id;
};

#endif // PERSON_H
