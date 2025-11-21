#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graphic.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//typedef enum {
//    NUMBER = 1,
//    X = 2,
//    PLUS = 3,
//    MINUS = 4,
//    MULT = 5,
//    DIV = 6,
//    POW = 7,
//    MOD = 8,
//    COS = 9,
//    SIN = 10,
//    TAN = 11,
//    ACOS = 12,
//    ASIN = 13,
//    ATAN = 14,
//    SQRT = 15,
//    LN = 16,
//    LOG = 17,
//    LEFT_BRACKET = 18,
//    RIGHT_BRACKET = 19
//} type_t;

//typedef struct Stack {
//    double value;
//    int priority;
//    type_t type;
//    struct Stack *prev;
//} Stack_t;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    graphic *graf;

private slots:
    void digits_numbers();
    void functions();
    void operashion();
    void calculate();


signals:
    void signal(char *, double, double, double);
};
#endif // MAINWINDOW_H
