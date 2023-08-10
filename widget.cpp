#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbMilk->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoffee->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
    updateButton();
}

void Widget::updateButton()
{
    updateButtonState(ui->pbMilk, 200);
    updateButtonState(ui->pbTea, 150);
    updateButtonState(ui->pbCoffee, 100);
}

void Widget::updateButtonState(QPushButton *button, int amount)
{
    if (money < amount) {
        button->setEnabled(false);
    } else {
        button->setEnabled(true);
    }
}


void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    int coinTypes[] = {500, 100, 50, 10};
    int coins[4] = {0};
    int rest = money;

    for (int i = 0; i < 4; i++) {
        coins[i] = rest / coinTypes[i];
        rest %= coinTypes[i];
    }

    QString text = QString("500원: %1개, 100원: %2개, 50원: %3개, 10원: %4개").arg(coins[0]).arg(coins[1]).arg(coins[2]).arg(coins[3]);

    QMessageBox mb;
    mb.information(this, "Chagnes", text);

    money = 0;
    ui->lcdNumber->display(money);
    updateButton();

}

