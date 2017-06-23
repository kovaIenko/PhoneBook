#include "window.h"
#include <QApplication>
#include "window.h"
#include "QFile"
#include "book.h"
#include "controller.h"

   QFile input("../numbs2.dat");

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
       Window::getWindow().show();
     Controller::getController().loadingFileDate(&input);
    return a.exec();
}


