#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->doubleSpinBox->setDecimals(2);
    ui->doubleSpinBox->setRange(0.0, 100.0);
    ui->etykieta->setText("0.0000");

    ui->prawyButton->setEnabled(true);
    ui->lewyButton->setEnabled(false);

    ui->suwakPierwszy->setRange(0, 255);
    ui->suwakDrugi->setRange(0, 255);
    ui->suwakTrzeci->setRange(0, 255);

    ui->spinPierwszy->setRange(0, 255);
    ui->spinDrugi->setRange(0, 255);
    ui->spinTrzeci->setRange(0, 255);

    ui->suwakPierwszy->setValue(0);
    ui->suwakDrugi->setValue(0);
    ui->suwakTrzeci->setValue(0);
    aktualizujKolor();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::aktualizujKolor()
{
    int red = ui->suwakPierwszy->value();
    int green = ui->suwakDrugi->value();
    int blue = ui->suwakTrzeci->value();

    //ciąg CSS dla koloru RGB
    QString kolorTla = QString("background-color: rgb(%1, %2, %3);").arg(red).arg(green).arg(blue);

    // koolor tla
    ui->tlo->setStyleSheet(kolorTla);
}


void MainWindow::on_suwakPierwszy_valueChanged(int value)
{
    ui->spinPierwszy->setValue(value);
    aktualizujKolor();
}


void MainWindow::on_suwakDrugi_valueChanged(int value)
{
    ui->spinDrugi->setValue(value);
    aktualizujKolor();
}

void MainWindow::on_suwakTrzeci_valueChanged(int value)
{
    ui->spinTrzeci->setValue(value);
    aktualizujKolor();
}


void MainWindow::on_spinPierwszy_valueChanged(int value)
{
    ui->suwakPierwszy->setValue(value);
    aktualizujKolor();
}


void MainWindow::on_spinDrugi_valueChanged(int value)
{
    ui->suwakDrugi->setValue(value);
    aktualizujKolor();
}

void MainWindow::on_spinTrzeci_valueChanged(int value)
{
    ui->suwakTrzeci->setValue(value);
    aktualizujKolor();
}



void MainWindow::on_prawyButton_clicked()
{
    ui->prawyButton->setEnabled(false);
    ui->lewyButton->setEnabled(true);
}


void MainWindow::on_lewyButton_clicked()
{
    ui->prawyButton->setEnabled(true);
    ui->lewyButton->setEnabled(false);
}

void MainWindow::on_radioButtonPierwszy_toggled(bool checked)
{
    if (checked == true)
    {
        ui->textEdit->setText("Pierwszy");
    }
}

void MainWindow::on_radioButtonDrugi_toggled(bool checked)
{
    if (checked== true)
    {
        ui->textEdit->setText("Drugi");
    }
}

void MainWindow::on_radioButtonTrzeci_toggled(bool checked)
{
    if (checked== true)
    {
        ui->textEdit->setText("Trzeci");
    }
}


void MainWindow::on_dateEdit_dateChanged(const QDate &date)
{

    ui->calendarWidget->setSelectedDate(date);
}


void MainWindow::on_calendarWidget_activated(const QDate &date)
{

    ui->dateEdit->setDate(date);
}


void MainWindow::on_doubleSpinBox_valueChanged(double wartosc)
{
    double kwadrat = wartosc * wartosc;
    ui->etykieta->setText(QString::number(kwadrat, 'f', 4));
}
