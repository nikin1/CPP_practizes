#include "mainwindow.h"
#include "./ui_mainwindow.h"


extern "C" {
    double calculator(char *A, double x, int *error);
    int validity_check(char *A);
//    Stack_t *convert_str_to_rpn_stack(char *A);
    double calculate_algoritm(Stack_t *S, double x);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graf = new graphic;
    connect(this, &MainWindow::signal, graf, &graphic::slot);


    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_left_bracket, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_rigth_bracket, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(digits_numbers()));

    connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(functions()));
    connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(functions()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(operashion()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(operashion()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(operashion()));
    connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(operashion()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(operashion()));
    connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(operashion()));
    connect(ui->pushButton_pi, SIGNAL(clicked()), this, SLOT(operashion()));
    connect(ui->pushButton_e, SIGNAL(clicked()), this, SLOT(operashion()));
    connect(ui->pushButton_res, SIGNAL(clicked()), this, SLOT(calculate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    if (button->text() == "AC") {
        ui->label->setText("");
    } else {
        QString vvod;
        vvod = ui->label->text() + button->text();
        ui->label->setText(vvod);
    }
}

void MainWindow::functions()
{
    QPushButton *button = (QPushButton *)sender();

    QString vvod;
    vvod = ui->label->text() + button->text() + "(";
    ui->label->setText(vvod);
}



void MainWindow::operashion()
{
    QPushButton *button = (QPushButton *)sender();
    QString vvod;
    vvod = ui->label->text();

    if (button->text() == "÷") {
        vvod += "/";
    } else if (button->text() == "×"){
        vvod += "*";
    } else if (button->text() == "pi") {
        vvod += "3.14159265358";
    } else if (button->text() == "e") {
        vvod += "2.718281828";
    } else {
        vvod += button->text();
    }
    ui->label->setText(vvod);
}

void MainWindow::calculate()
{
    QString input = ui->label->text();
    if (input != "") {

        QByteArray res_bit = input.toLocal8Bit();
        char *res_str = res_bit.data();

        int error = validity_check(res_str);

        if (error == 0) {
            ui->label->setText("Invalid Exspression");
        } else {


            if (ui->label->text().contains('x')) {
                emit signal(res_str, -1000.0, 1000.0, 0.001);
                graf->show();

            } else {

               double x = 0.0, y = 0.0;

               y = calculator(res_str, x,  &error);

               QString output = QString::number(y, 'g', 7);

               ui->label->setText(output);
            }
        }

    }
}



