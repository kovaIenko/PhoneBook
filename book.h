#ifndef BOOK_H
#define BOOK_H
#include "QMultiMap"
#include "person.h";
class Book{
public:
    Book();
    ~Book();
    void addPersonInBook(Person&);
    void  addNumberToPerson(QString&,QString&);

   void delPerson(QString&);
   void delNumber(QString & , QString &);

    QMultiMap <QString,Person>::const_iterator end() const;
      QMultiMap <QString,Person>::const_iterator begin() const;
       int size() const;

       QMultiMap<QString,Person> getBook();
       const Person& value(QString &) const ;
       void setPersonInBook(Person& contact);
         void replacementPersons(QString& oldName, Person& person);
       bool isPresent(QString&);

       void editPerson(QString & , QString &);

private:
   QMultiMap<QString,Person> _book;


};

#endif // BOOK_H
