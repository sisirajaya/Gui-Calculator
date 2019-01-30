#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>
#include <QProcess>
#include <QtMath>

//QT has a qDebug function to debug your runtime errors : qDebug << "test case ";

static double firstNumber;
static bool secondNumberPressed = false;
static bool secondNumberPressed2 = false;



MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
    //Pointer ui stores memory address of the instance of class MainWindow
    //Ui accesses member pushButton of class QPushButton
    //Signal is essentially a pointer that signals to a callback function SLOT when a event
    //such as a button being pressed occurs. SLOT is the function that is called
    //Function printPushButton does all the dirty work ;)
    connect(ui->pushButton0, SIGNAL(released()), this, SLOT(pushButtonNumbers()));
    connect(ui->pushButton1, SIGNAL(released()), this, SLOT(pushButtonNumbers()));
    connect(ui->pushButton2, SIGNAL(released()), this, SLOT(pushButtonNumbers()));
    connect(ui->pushButton3, SIGNAL(released()), this, SLOT(pushButtonNumbers()));
    connect(ui->pushButton4, SIGNAL(released()), this, SLOT(pushButtonNumbers()));
    connect(ui->pushButton5, SIGNAL(released()), this, SLOT(pushButtonNumbers()));
    connect(ui->pushButton6, SIGNAL(released()), this, SLOT(pushButtonNumbers()));
    connect(ui->pushButton7, SIGNAL(released()), this, SLOT(pushButtonNumbers()));
    connect(ui->pushButton8, SIGNAL(released()), this, SLOT(pushButtonNumbers()));
    connect(ui->pushButton9, SIGNAL(released()), this, SLOT(pushButtonNumbers()));
    connect(ui->pushButtonAdd, SIGNAL(released()), this, SLOT(additionOperation()));
    connect(ui->pushButtonSubtraction, SIGNAL(released()), this, SLOT(subtractionOperation()));
    connect(ui->pushButtonFullClear, SIGNAL(released()), this, SLOT(clearScreenOperation()));
    connect(ui->pushButtonFullClear, SIGNAL(released()), this, SLOT(clearEquationText()));
    connect(ui->pushButtonMultiplication, SIGNAL(released()), this, SLOT(multiplicationOperation()));
    connect(ui->pushButtonDivision, SIGNAL(released()), this, SLOT(divisionOperation()));
    connect(ui->pushButtonEqual, SIGNAL(released()), this, SLOT(equalOperation()));
    connect(ui->pushButtonDelete, SIGNAL(released()), this, SLOT(deleteOperation()));
    connect(ui->pushButtonValueChanger, SIGNAL(released()), this, SLOT(valueChangerOperator()));
    connect(ui->pushButtonDecimal, SIGNAL(released()), this, SLOT(addDecimal()));
    connect(ui->pushButton0, SIGNAL(released()), this, SLOT(displayEquation()));
    connect(ui->pushButton1, SIGNAL(released()), this, SLOT(displayEquation()));
    connect(ui->pushButton2, SIGNAL(released()), this, SLOT(displayEquation()));
    connect(ui->pushButton3, SIGNAL(released()), this, SLOT(displayEquation()));
    connect(ui->pushButton4, SIGNAL(released()), this, SLOT(displayEquation()));
    connect(ui->pushButton5, SIGNAL(released()), this, SLOT(displayEquation()));
    connect(ui->pushButton6, SIGNAL(released()), this, SLOT(displayEquation()));
    connect(ui->pushButton7, SIGNAL(released()), this, SLOT(displayEquation()));
    connect(ui->pushButton8, SIGNAL(released()), this, SLOT(displayEquation()));
    connect(ui->pushButton9, SIGNAL(released()), this, SLOT(displayEquation()));
    connect(ui->pushButtonEqual, SIGNAL(released()), this, SLOT(clearEquationText()));
    connect(ui->squareRootButton, SIGNAL(released()), this, SLOT(squareRootOperation()));
    connect(ui->squareButton, SIGNAL(released()), this, SLOT(squareFunction()));
    connect(ui->exponentButton, SIGNAL(released()), this, SLOT(exponentFunction()));
    connect(ui->factorialButton, SIGNAL(released()), this, SLOT(factorialOperation()));
    connect(ui->clearEntryButton, SIGNAL(released()), this, SLOT(clearEntryNumber()));

    ui->pushButtonDecimal->setCheckable(true);
    ui->pushButtonAdd->setCheckable(true);
    ui->pushButtonSubtraction->setCheckable(true);
    ui->pushButtonMultiplication->setCheckable(true);
    ui->pushButtonDivision->setCheckable(true);
    ui->squareButton->setCheckable(true);
    ui->squareRootButton->setCheckable(true);
    ui->exponentButton->setCheckable(true);
    ui->factorialButton->setCheckable(true);


    QString windowTitle("Calculator");
    setWindowTitle(windowTitle);

}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::pushButtonNumbers(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    double calculatorTextNumber;
    QString newCalculatorText;
    newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
    //ui->calculatorText->setText(newCalculatorText);

    if((ui->pushButtonAdd->isChecked()) && (!secondNumberPressed)){
        calculatorTextNumber = pressedButton->text().toDouble();
        secondNumberPressed = true;
    }else if((ui->pushButtonSubtraction->isChecked()) && (!secondNumberPressed)){
        calculatorTextNumber = pressedButton->text().toDouble();
        secondNumberPressed = true;
    }else if((ui->pushButtonMultiplication->isChecked()) && (!secondNumberPressed)){
        calculatorTextNumber = pressedButton->text().toDouble();
        secondNumberPressed = true;
    }else if((ui->pushButtonDivision->isChecked()) && (!secondNumberPressed)){
        calculatorTextNumber = pressedButton->text().toDouble();
        secondNumberPressed = true;
    }else if((ui->squareButton->isChecked()) && (!secondNumberPressed)){
        calculatorTextNumber = pressedButton->text().toDouble();
        secondNumberPressed = false;
    }else if((ui->squareRootButton->isChecked()) && (!secondNumberPressed)){
        calculatorTextNumber = pressedButton->text().toDouble();
        secondNumberPressed = false;
    }else if((ui->exponentButton->isChecked()) && (!secondNumberPressed)){
        calculatorTextNumber = pressedButton->text().toDouble();
        secondNumberPressed = false;
    }else if((ui->factorialButton->isChecked()) && (!secondNumberPressed)){
        calculatorTextNumber = pressedButton->text().toDouble();
        secondNumberPressed = false;
    }else{
       calculatorTextNumber = (ui->calculatorText->text() + pressedButton->text()).toDouble();
   }

    newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
    ui->calculatorText->setText(newCalculatorText);

}

void MainWindow::valueChangerOperator(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());

    double calculatorTextNumber;
    QString newCalculatorText;
    calculatorTextNumber = (ui->calculatorText->text() + pressedButton->text()).toDouble();

    if(pressedButton == ui->pushButtonValueChanger){
        calculatorTextNumber = ui->calculatorText->text().toDouble();
        calculatorTextNumber = calculatorTextNumber * (-1);
        newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
    }

    ui->calculatorText->setText(newCalculatorText);
}

void MainWindow::clearScreenOperation(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    QString newCalculatorText;

    if(pressedButton == ui->pushButtonFullClear){
        newCalculatorText = '0';
        clearEquationText();
        equalOperation();
        firstNumber = 0;
        ui->pushButtonDecimal->setEnabled(true);
    }

    ui->calculatorText->setText(newCalculatorText);
    ui->pushButtonDecimal->setChecked(false);

}

void MainWindow::deleteOperation(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    QString newCalculatorText = ui->calculatorText->text();

    if(pressedButton == ui->pushButtonDelete){
        newCalculatorText.chop(1);
        if(newCalculatorText.isEmpty()){
            newCalculatorText = "0";
        }
     }
    ui->calculatorText->setText(newCalculatorText);
}

void MainWindow::addDecimal(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    double calculatorTextNumber;
    QString newCalculatorText;
    calculatorTextNumber = (ui->calculatorText->text() + pressedButton->text()).toDouble();
    newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);

    if(pressedButton == ui->pushButtonDecimal){
        for(int i = 0; i < newCalculatorText.length(); i++){
            if(newCalculatorText[i] == '.'){
                pressedButton->setChecked(false);
                break;
            }else{
                pressedButton->setChecked(true);
                newCalculatorText = newCalculatorText + '.';
                pressedButton->setChecked(false);
                break;
            }
           //pressedButton->setChecked(true);
           //break;
        }
    }
    pressedButton->setChecked(true);
    pressedButton->setEnabled(false);

    ui->calculatorText->setText(newCalculatorText);
}

void MainWindow::equalOperation(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    double calculatorTextNumber;
    double secondNumber;
    QString newCalculatorText;
    secondNumber = ui->calculatorText->text().toDouble();

    if(ui->pushButtonAdd->isChecked()){
        calculatorTextNumber = firstNumber + secondNumber;
        newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
        ui->calculatorText->setText(newCalculatorText);
        ui->pushButtonAdd->setChecked(false);
        secondNumberPressed = false;
        if(ui->pushButtonSubtraction->isChecked()){
            calculatorTextNumber = firstNumber - secondNumber;
            newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
            ui->calculatorText->setText(newCalculatorText);
            ui->pushButtonSubtraction->setChecked(false);
            secondNumberPressed = false;
        }else if(ui->pushButtonMultiplication->isChecked()){
            calculatorTextNumber = firstNumber * secondNumber;
            newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
            ui->calculatorText->setText(newCalculatorText);
            ui->pushButtonMultiplication->setChecked(false);
            secondNumberPressed = false;
        }else if(ui->pushButtonDivision->isChecked()){
            calculatorTextNumber = firstNumber / secondNumber;
            newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
            ui->calculatorText->setText(newCalculatorText);
            ui->pushButtonDivision->setChecked(false);
            secondNumberPressed = false;
        }
    }else if(ui->pushButtonSubtraction->isChecked()){
        calculatorTextNumber = firstNumber - secondNumber;
        newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
        ui->calculatorText->setText(newCalculatorText);
        ui->pushButtonSubtraction->setChecked(false);
        secondNumberPressed = false;
        if(ui->pushButtonAdd->isChecked()){
            calculatorTextNumber = firstNumber + secondNumber;
            newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
            ui->calculatorText->setText(newCalculatorText);
            ui->pushButtonAdd->setChecked(false);
            secondNumberPressed = false;
        }else if(ui->pushButtonMultiplication->isChecked()){
            calculatorTextNumber = firstNumber * secondNumber;
            newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
            ui->calculatorText->setText(newCalculatorText);
            ui->pushButtonMultiplication->setChecked(false);
            secondNumberPressed = false;
       }else if(ui->pushButtonDivision->isChecked()){
            calculatorTextNumber = firstNumber / secondNumber;
            newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
            ui->calculatorText->setText(newCalculatorText);
            ui->pushButtonDivision->setChecked(false);
            secondNumberPressed = false;
        }
    }else if(ui->pushButtonMultiplication->isChecked()){
        calculatorTextNumber = firstNumber * secondNumber;
        newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
        ui->calculatorText->setText(newCalculatorText);
        ui->pushButtonMultiplication->setChecked(false);
        secondNumberPressed = false;

        if(ui->pushButtonAdd->isChecked()){
            calculatorTextNumber = firstNumber + secondNumber;
            newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
            ui->calculatorText->setText(newCalculatorText);
            ui->pushButtonAdd->setChecked(false);
            secondNumberPressed = false;
        }else if(ui->pushButtonSubtraction->isChecked()){
            calculatorTextNumber = firstNumber - secondNumber;
            newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
            ui->calculatorText->setText(newCalculatorText);
            ui->pushButtonSubtraction->setChecked(false);
            secondNumberPressed = false;
        }else if(ui->pushButtonDivision->isChecked()){
            calculatorTextNumber = firstNumber / secondNumber;
            newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
            ui->calculatorText->setText(newCalculatorText);
            ui->pushButtonDivision->setChecked(false);
            secondNumberPressed = false;
        }
    }else if(ui->pushButtonDivision->isChecked()){
        calculatorTextNumber = firstNumber / secondNumber;
        newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
        ui->calculatorText->setText(newCalculatorText);
        ui->pushButtonDivision->setChecked(false);
        secondNumberPressed = false;

        if(ui->pushButtonAdd->isChecked()){
            calculatorTextNumber = firstNumber + secondNumber;
            newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
            ui->calculatorText->setText(newCalculatorText);
            ui->pushButtonAdd->setChecked(false);
            secondNumberPressed = false;
        }else if(ui->pushButtonSubtraction->isChecked()){
            calculatorTextNumber = firstNumber - secondNumber;
            newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
            ui->calculatorText->setText(newCalculatorText);
            ui->pushButtonSubtraction->setChecked(false);
            secondNumberPressed = false;
        }else if(ui->pushButtonMultiplication->isChecked()){
            calculatorTextNumber = firstNumber * secondNumber;
            newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
            ui->calculatorText->setText(newCalculatorText);
            ui->pushButtonMultiplication->setChecked(false);
            secondNumberPressed = false;
       }
    }else if(ui->exponentButton->isChecked()){
        calculatorTextNumber = qPow(firstNumber, secondNumber);
        newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
        ui->calculatorText->setText(newCalculatorText);
        ui->exponentButton->setChecked(false);
        secondNumberPressed = false;
    }

    if(pressedButton == ui->pushButtonEqual){
        ui->pushButtonDecimal->setEnabled(true);
        ui->pushButtonDecimal->setChecked(false);

    }

    clearEquationText();



}

void MainWindow::additionOperation(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    firstNumber = ui->calculatorText->text().toDouble();
    pressedButton->setChecked(true);
    ui->pushButtonSubtraction->setChecked(false);
    ui->pushButtonMultiplication->setChecked(false);
    ui->pushButtonDivision->setChecked(false);

    if(ui->pushButtonDecimal->isChecked()){
        ui->pushButtonDecimal->setChecked(false);
        ui->pushButtonDecimal->setEnabled(true);
        secondNumberPressed = false;
    }


}

void MainWindow::subtractionOperation(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    firstNumber = ui->calculatorText->text().toDouble();
    pressedButton->setChecked(true);
    ui->pushButtonAdd->setChecked(false);
    ui->pushButtonMultiplication->setChecked(false);
    ui->pushButtonDivision->setChecked(false);

    if(ui->pushButtonDecimal->isChecked()){
        ui->pushButtonDecimal->setChecked(false);
        ui->pushButtonDecimal->setEnabled(true);
        secondNumberPressed = false;
    }

}

void MainWindow::multiplicationOperation(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    firstNumber = ui->calculatorText->text().toDouble();
    pressedButton->setChecked(true);
    ui->pushButtonAdd->setChecked(false);
    ui->pushButtonSubtraction->setChecked(false);
    ui->pushButtonDivision->setChecked(false);

    if(ui->pushButtonDecimal->isChecked()){
        ui->pushButtonDecimal->setChecked(false);
        ui->pushButtonDecimal->setEnabled(true);
        secondNumberPressed = false;
    }

}

void MainWindow::divisionOperation(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    firstNumber = ui->calculatorText->text().toDouble();
    pressedButton->setChecked(true);
    ui->pushButtonAdd->setChecked(false);
    ui->pushButtonSubtraction->setChecked(false);
    ui->pushButtonMultiplication->setChecked(false);

    if(ui->pushButtonDecimal->isChecked()){
        ui->pushButtonDecimal->setChecked(false);
        ui->pushButtonDecimal->setEnabled(true);
        secondNumberPressed = false;
    }

}

void MainWindow::exponentFunction(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    firstNumber = ui->calculatorText->text().toDouble();
    pressedButton->setChecked(true);

}

void MainWindow::squareFunction(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    double calculatorTextNumber;
    QString newCalculatorText;
    calculatorTextNumber = (ui->calculatorText->text() + pressedButton->text()).toDouble();
    firstNumber = ui->calculatorText->text().toDouble();

    if(pressedButton == ui->squareButton){
        calculatorTextNumber = firstNumber * firstNumber;
    }

    newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
    ui->calculatorText->setText(newCalculatorText);

    pressedButton->setChecked(false);

}

void MainWindow::squareRootOperation(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    double calculatorTextNumber;
    QString newCalculatorText;
    calculatorTextNumber = (ui->calculatorText->text() + pressedButton->text()).toDouble();
    firstNumber = ui->calculatorText->text().toDouble();

    if(pressedButton == ui->squareRootButton){
        calculatorTextNumber = qPow(firstNumber, 0.5);
    }

    newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
    ui->calculatorText->setText(newCalculatorText);
    pressedButton->setChecked(false);

}


void MainWindow::factorialOperation(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    double calculatorTextNumber;
    QString newCalculatorText;
    calculatorTextNumber = (ui->calculatorText->text() + pressedButton->text()).toDouble();
    firstNumber = ui->calculatorText->text().toDouble();

    if(pressedButton == ui->factorialButton){
        if(firstNumber >= 2){
            for(double i = firstNumber-1; i >= 1; i--){
                firstNumber = firstNumber * i;
            }
        }else{
            firstNumber = 1;
        }
    }

    calculatorTextNumber = firstNumber;
    newCalculatorText = QString::number(calculatorTextNumber, 'g', 15);
    ui->calculatorText->setText(newCalculatorText);
    pressedButton->setChecked(false);

}

void MainWindow::displayEquation(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    double calculatorTextNumber;
    QString newCalculatorText;

    if((ui->pushButtonAdd->isChecked()) && (!secondNumberPressed2)){
        calculatorTextNumber = pressedButton->text().toDouble();
        newCalculatorText = QString::number(firstNumber, 'g', 15);
        ui->equationText->setText(newCalculatorText + " + ");
    }

    if((ui->pushButtonSubtraction->isChecked()) && (!secondNumberPressed2)){
        calculatorTextNumber = pressedButton->text().toDouble();
        newCalculatorText = QString::number(firstNumber, 'g', 15);
        ui->equationText->setText(newCalculatorText + " - ");
    }

    if((ui->pushButtonMultiplication->isChecked()) && (!secondNumberPressed2)){
        calculatorTextNumber = pressedButton->text().toDouble();
        newCalculatorText = QString::number(firstNumber, 'g', 15);
        ui->equationText->setText(newCalculatorText + " x ");
    }

    if((ui->pushButtonDivision->isChecked()) && (!secondNumberPressed2)){
        calculatorTextNumber = pressedButton->text().toDouble();
        newCalculatorText = QString::number(firstNumber, 'g', 15);
        ui->equationText->setText(newCalculatorText + " / ");
    }

    if((ui->exponentButton->isChecked()) && (!secondNumberPressed2)){
        calculatorTextNumber = pressedButton->text().toDouble();
        newCalculatorText = QString::number(firstNumber, 'g', 15);
        ui->equationText->setText(newCalculatorText + " ^ ");
    }

}

void MainWindow::clearEquationText(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    QString newCalculatorText;

    if(pressedButton == ui->pushButtonEqual){
        newCalculatorText = ' ';
    }

    ui->equationText->setText(newCalculatorText);
}

void MainWindow::clearEntryNumber(){
    QPushButton *pressedButton = dynamic_cast<QPushButton*>(sender());
    QString newCalculatorText;

    if(pressedButton == ui->clearEntryButton){
        newCalculatorText = '0';

    }

    ui->calculatorText->setText(newCalculatorText);
}
