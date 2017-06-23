#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "book.h"
#include "person.h"
#include "QFile"


class Controller
{
public:
    Controller();
    void personToBookController(QString&);
    void numberToPersonController(QString& name,QString& numb);

    void personDeleteController(QString&);
    void numberDeleteController(QString& name,QString& numb);

    void editPersonController(QString& name,QString& newName);
    void  saveToFile(QFile*);
     void loadingFileDate(QFile*);
    static Controller& getController();
    Book& getContacts();

private:
  Book _contacts;

};
#endif // CONTROLLER_H
