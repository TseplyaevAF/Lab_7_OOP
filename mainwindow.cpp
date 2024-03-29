#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->history->setVisible(0);
    ui->delete_history->setVisible(0);
//    ui->pushButton_H->setIcon(QIcon("history.png"));
//    ui->pushButton_H->setIconSize(QSize(5, 5));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addLabel(QPushButton *button, QLabel *label) {
    QString all_numbers; // переменная для записи всех чисел в строку

    if (flag) {
        label->setText(button->text());
        flag = 0;
        return;
    }

    if (label->text() == "0")
        label->setText(button->text());
    else {
        all_numbers = (ui->display->text() + button->text());
        label->setText(all_numbers);
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    addLabel(ui->pushButton_1, ui->display);
}

void MainWindow::on_pushButton_2_clicked()
{
    addLabel(ui->pushButton_2, ui->display);
}

void MainWindow::on_pushButton_3_clicked()
{
    addLabel(ui->pushButton_3, ui->display);
}

void MainWindow::on_pushButton_4_clicked()
{
    addLabel(ui->pushButton_4, ui->display);
}

void MainWindow::on_pushButton_5_clicked()
{
    addLabel(ui->pushButton_5, ui->display);
}

void MainWindow::on_pushButton_6_clicked()
{
    addLabel(ui->pushButton_6, ui->display);
}

void MainWindow::on_pushButton_7_clicked()
{
    addLabel(ui->pushButton_7, ui->display);
}

void MainWindow::on_pushButton_8_clicked()
{
    addLabel(ui->pushButton_8, ui->display);
}

void MainWindow::on_pushButton_9_clicked()
{
    addLabel(ui->pushButton_9, ui->display);
}

void MainWindow::on_pushButton_0_clicked()
{
    addLabel(ui->pushButton_0, ui->display);
}

void MainWindow::on_C_clicked()
{
    if (num.getValue() != 0.0)
        num.setValue(0);
    ui->display->setText("0");
    operation = "";
    ui->labelERROR->setText("");
}

void MainWindow::on_erase_clicked()
{
    QString str;
    str = ui->display->text();
    int size = str.size();
    str.resize(size-1);
    if (str == "") str = "0";
    ui->display->setText(str);
}

void MainWindow::on_pushButton_dot_clicked()
{
    // если в строке нет символа точки, то добавляем его
    if (!(ui->display->text().contains('.'))) {
        ui->display->setText(ui->display->text() + ".");
    }
}

void MainWindow::on_pushButton_sign_clicked()
{
   double res = ui->display->text().toDouble() * (-1.0);
   ui->display->setText(QString::number(res));
}

void MainWindow::checkOperation() {
    if (operation == "+")
        num += ui->display->text().toDouble();

    if (operation == "-")
        num -= ui->display->text().toDouble();

    if (operation == "*")
        num *= ui->display->text().toDouble();

    try {
        if (operation == "/") {
            num /= ui->display->text().toDouble();
        }
    } catch (Calculator::ERRORS e) {
        if (e == Calculator::divZero)
            ui->labelERROR->setText("Ошибка при делении на ноль");
    }

    if (operation == "pow")
       num.setValue(num.powValue(ui->display->text().toDouble()));
}

void MainWindow::on_pushButton_equally_clicked()
{
    checkOperation();
    ui->pushButton_add->setDefault(0);
    ui->pushButton_sub->setDefault(0);
    ui->pushButton_mul->setDefault(0);
    ui->pushButton_div->setDefault(0);
    ui->pushButton_yx->setDefault(0);
    ui->display->setText(QString::number(num.getValue()));
    operation = "";
    flag = 0;
}

void MainWindow::on_pushButton_add_clicked()
{
    ui->pushButton_add->setDefault(1);
    flag = 1;
    num.setValue(ui->display->text().toDouble());
    operation = "+";
}

void MainWindow::on_pushButton_sub_clicked()
{
    flag = 1;
    ui->pushButton_sub->setDefault(1);
    num.setValue(ui->display->text().toDouble());
    operation = "-";
}

void MainWindow::on_pushButton_mul_clicked()
{
    flag = 1;
    ui->pushButton_mul->setDefault(1);
    num.setValue(ui->display->text().toDouble());
    operation = "*";
}

void MainWindow::on_pushButton_div_clicked()
{
    flag = 1;
    ui->pushButton_div->setDefault(1);
    num.setValue(ui->display->text().toDouble());
    operation = "/";
}

void MainWindow::on_pushButton_exp_clicked()
{
    QString str;
    str = ui->display->text();
    num.setValue(str.toDouble());
    num.setValue(num.exprValue());
    ui->display->setText(QString::number(num.getValue()));
    setHistory(ui->pushButton_exp, str);
}

void MainWindow::on_pushButton_ln_clicked()
{
    QString str;
    str = ui->display->text();
    num.setValue(str.toDouble());

    try {
        num.setValue(num.lnValue());
        ui->display->setText(QString::number(num.getValue()));
        setHistory(ui->pushButton_ln, str);
    } catch (Calculator::ERRORS e) {
        if (e == Calculator::negativeNumber)
            ui->labelERROR->setText("Данные введены неверно");
    }
}

void MainWindow::on_pushButton_yx_clicked()
{
    ui->pushButton_yx->setDefault(1);
    flag = 1;
    num.setValue(ui->display->text().toDouble());
    operation = "pow";
}

void MainWindow::on_pushButton_sqrt_clicked()
{
    QString str;
    str = ui->display->text();
    num.setValue(str.toDouble());

    try {
        num.setValue(num.sqrtValue());
        ui->display->setText(QString::number(num.getValue()));
        setHistory(ui->pushButton_sqrt, str);
    } catch (Calculator::ERRORS e) {
        if (e == Calculator::negativeNumber)
            ui->labelERROR->setText("Данные введены неверно");
    }
}

void MainWindow::on_pushButton_x2_clicked()
{
    QString str;
    str = ui->display->text();
    num.setValue(str.toDouble());
    num.setValue(num.sqrValue());
    ui->display->setText(QString::number(num.getValue()));
    ui->history->append(str + "² = " + QString::number(num.getValue()));
}

void MainWindow::on_pushButton_sin_clicked()
{
    QString str;
    str = ui->display->text();
    num.setValue(str.toDouble());
    num.setValue(num.sinValue());
    ui->display->setText(QString::number(num.getValue()));
    setHistory(ui->pushButton_sin, str);
}

void MainWindow::on_pushButton_cos_clicked()
{
    QString str;
    str = ui->display->text();
    num.setValue(str.toDouble());
    num.setValue(num.cosValue());
    ui->display->setText(QString::number(num.getValue()));
    setHistory(ui->pushButton_cos, str);
}

void MainWindow::on_pushButton_tan_clicked()
{
    QString str;
    str = ui->display->text();
    num.setValue(str.toDouble());
    num.setValue(num.tgValue());
    ui->display->setText(QString::number(num.getValue()));
    setHistory(ui->pushButton_tan, str);
}

void MainWindow::on_pushButton_H_clicked()
{
    open = !open;
    ui->history->setVisible(open);
    ui->delete_history->setVisible(open);
}

void MainWindow::on_delete_history_clicked()
{
    ui->history->setText("");
}

void MainWindow::setHistory(QPushButton *button, QString str) {
    ui->history->append(button->text() + " " + str + " = " + QString::number(num.getValue()));
}
