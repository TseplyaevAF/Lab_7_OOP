#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculator.h"
#include <QPushButton>
#include <QLabel>
#include <QIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_0_clicked();

    void on_C_clicked();

    void on_erase_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_sign_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_equally_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_exp_clicked();

    void on_pushButton_ln_clicked();

    void on_pushButton_yx_clicked();

    void on_pushButton_sqrt_clicked();

    void on_pushButton_x2_clicked();

    void on_pushButton_sin_clicked();

    void on_pushButton_cos_clicked();

    void on_pushButton_tan_clicked();

    void on_pushButton_H_clicked();

    void on_delete_history_clicked();

private:
    Ui::MainWindow *ui;
    // переменная для вычислений
    Calculator num;
    // переменная для определения операции
    QString operation;
    bool flag = 0,
    note = 0, // для добавления в историю вычислений
    open = 0; // для открытия и закрытия поля history
    // функция добавления текста на экран
    void addLabel(QPushButton *button,QLabel *label);
    // функция для проверки операции
    void checkOperation();
    // функция для добавления операций в поле history
    void setHistory(QPushButton *button, QString str);

};
#endif // MAINWINDOW_H
