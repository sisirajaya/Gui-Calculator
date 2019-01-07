#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow:public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    void pushButtonNumbers();
    void valueChangerOperator();
    void clearScreenOperation();
    void deleteOperation();
    void addDecimal();
    void additionOperation();
    void subtractionOperation();
    void multiplicationOperation();
    void divisionOperation();
    void displayEquation();
    void equalOperation();
    void clearEquationText();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
