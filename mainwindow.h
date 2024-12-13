#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_prawyButton_clicked();
    void on_lewyButton_clicked();
    void on_doubleSpinBox_valueChanged(double);
    void on_dateEdit_dateChanged(const QDate &date);
    void on_calendarWidget_activated(const QDate &date);
    void on_radioButtonPierwszy_toggled(bool checked);
    void on_radioButtonDrugi_toggled(bool checked);
    void on_radioButtonTrzeci_toggled(bool checked);

    void on_suwakPierwszy_valueChanged(int value);
    void on_suwakDrugi_valueChanged(int value);
    void on_suwakTrzeci_valueChanged(int value);

    void on_spinPierwszy_valueChanged(int value);
    void on_spinDrugi_valueChanged(int value);
    void on_spinTrzeci_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    void aktualizujKolor();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif
