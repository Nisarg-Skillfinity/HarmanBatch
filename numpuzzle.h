#ifndef NUMPUZZLE_H
#define NUMPUZZLE_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class NumPuzzle;
}

class NumPuzzle : public QMainWindow
{
    Q_OBJECT

public:
    explicit NumPuzzle(QWidget *parent = 0);
    void FillArray();
    void ButtonClicked(int);
    bool IsNeighbour(int, int);
    bool NeighbourEmpty(int);

    ~NumPuzzle();

private slots:
    void on_pushButton_0_clicked();
    void on_pushButton_13_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::NumPuzzle *ui;
    int val[16];
    bool flag = false;
    int selectedIndex = 99;
    QPushButton* buttons[];
};

#endif // NUMPUZZLE_H
