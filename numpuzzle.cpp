#include "numpuzzle.h"
#include "ui_numpuzzle.h"
#include <qglobal.h>

NumPuzzle::NumPuzzle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NumPuzzle)
{
    ui->setupUi(this);
    this->FillArray();
}

NumPuzzle::~NumPuzzle()
{
    delete ui;
}

void NumPuzzle::FillArray()
{
    buttons[0] = ui->pushButton_0;
    buttons[1] = ui->pushButton_1;
    buttons[2] = ui->pushButton_2;
    buttons[3] = ui->pushButton_3;
    buttons[4] = ui->pushButton_4;
    buttons[5] = ui->pushButton_5;
    buttons[6] = ui->pushButton_6;
    buttons[7] = ui->pushButton_7;
    buttons[8] = ui->pushButton_8;
    buttons[9] = ui->pushButton_9;
    buttons[10] = ui->pushButton_10;
    buttons[11] = ui->pushButton_11;
    buttons[12] = ui->pushButton_12;
    buttons[13] = ui->pushButton_13;
    buttons[14] = ui->pushButton_14;
    buttons[15] = ui->pushButton_15;

    for(int i = 0; i <= 15; i++)
    {
        buttons[i]->setStyleSheet("background-color: green");
    }

    for(int i = 0; i < 14; i++)
    {
        //qsrand(qrand);
        int x;
        while(true)
        {
            x = (qrand() % 14 + 1);
            bool entry = false;
            for(int j = 0; j <= i; j++)
            {
                if(buttons[j]->text() == QString::number(x))
                {
                    x = (qrand() % 14 + 1);
                    entry = true;
                }
            }
            if(!entry)
            {
                break;
            }
        }
        buttons[i]->setText(QString::number(x));
    }
    buttons[14]->setText("");
    buttons[15]->setText("");
}


void NumPuzzle::on_pushButton_0_clicked()
{
    ButtonClicked(0);
}

void NumPuzzle::on_pushButton_1_clicked()
{
    ButtonClicked(1);
}

void NumPuzzle::on_pushButton_2_clicked()
{
    ButtonClicked(2);
}

void NumPuzzle::on_pushButton_3_clicked()
{
    ButtonClicked(3);
}

void NumPuzzle::on_pushButton_4_clicked()
{
    ButtonClicked(4);
}

void NumPuzzle::on_pushButton_5_clicked()
{
    ButtonClicked(5);
}

void NumPuzzle::on_pushButton_7_clicked()
{
    ButtonClicked(7);
}

void NumPuzzle::on_pushButton_6_clicked()
{
    ButtonClicked(6);
}

void NumPuzzle::on_pushButton_8_clicked()
{
    ButtonClicked(8);
}

void NumPuzzle::on_pushButton_9_clicked()
{
    ButtonClicked(9);
}

void NumPuzzle::on_pushButton_11_clicked()
{
    ButtonClicked(11);
}

void NumPuzzle::on_pushButton_10_clicked()
{
    ButtonClicked(10);
}

void NumPuzzle::on_pushButton_12_clicked()
{
    ButtonClicked(12);
}

void NumPuzzle::on_pushButton_14_clicked()
{
    ButtonClicked(14);
}

void NumPuzzle::on_pushButton_15_clicked()
{
    ButtonClicked(15);
}

void NumPuzzle::on_pushButton_13_clicked()
{
    ButtonClicked(13);
}

void NumPuzzle::ButtonClicked(int selfIndex)
{
    if(flag == false || (flag && buttons[selfIndex]->text() != ""))
    {
        if(NeighbourEmpty(selfIndex))
        {
            if(selectedIndex != 99)
            {
                buttons[selectedIndex]->setStyleSheet("background-color: green");
            }
            selectedIndex = selfIndex;
            buttons[selectedIndex]->setStyleSheet("background-color: red");
            flag = true;
        }
    }
    else if(buttons[selfIndex]->text() == "")
    {
        if(IsNeighbour(selfIndex, selectedIndex))
        {
            buttons[selfIndex]->setText(buttons[selectedIndex]->text());
            buttons[selectedIndex]->setText("");
            buttons[selectedIndex]->setStyleSheet("background-color: green");
            selectedIndex = 99;
            flag = false;
        }
    }
}

bool NumPuzzle::IsNeighbour(int self, int selected)
{
    int n1 = self - 1;
    int n2 = self + 1;
    int n3 = self - 4;
    int n4 = self + 4;

    if(selected == n1 || selected == n2 || selected == n3 || selected == n4)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool NumPuzzle::NeighbourEmpty(int index)
{
    int n1 = index - 1;
    int n2 = index + 1;
    int n3 = index - 4;
    int n4 = index + 4;

    if(n1 >= 0 && buttons[n1]->text() == "")
    {
        return true;
    }
    else if(n2 <= 15 && buttons[n2]->text() == "")
    {
        return true;
    }
    else if(n3 >= 0 && buttons[n3]->text() == "")
    {
        return true;
    }
    else if(n4 <= 15 && buttons[n4]->text() == "")
    {
        return true;
    }
    else
    {
        return false;
    }
}
