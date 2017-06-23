#ifndef WINDOW_H
#define WINDOW_H
#include "QListWidget"
#include <QMainWindow>

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();
     static Window& getWindow();
     QListWidget& getListNames();
     QListWidget& getListPhones();
       void on_update_names();
       void on_update_phoneOfNames(QString& name);

private slots:
    void on_addNumb_clicked();
    void on_addPerson_clicked();
    void on_listNames_itemClicked(QListWidgetItem *item);
    void on_listNames_pressed(const QModelIndex &index);
    void on_delPerson_clicked();
    void on_delNumb_clicked();

    void on_save_clicked();

    void on_editPerson_clicked();

private:
    static int selectedIndexOfItem;
            Ui::Window *ui;
     QListWidget * names;
       QListWidget * phones;
};

#endif // WINDOW_H
