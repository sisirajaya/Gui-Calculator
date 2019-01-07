#include "mainwindow.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    MainWindow w;
    QFont font;
    w.setFixedSize(240, 380);
    w.show();

    return a.exec();
}
