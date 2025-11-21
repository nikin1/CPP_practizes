#include "graphic.h"
#include "ui_graphic.h"

extern "C" {
    double calculator(char *A, double x, int *error);
    int validity_check(char *A);
    Stack_t *convert_str_to_rpn_stack(char *A);
    double calculate_algoritm(Stack_t *S, double x);
    Stack_t *CopyStack(Stack_t *A);
    void PrintStack(Stack_t *last_el, char *A);
    int StringIsNumber(char *A);
}

graphic::graphic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graphic)
{
    ui->setupUi(this);

}

graphic::~graphic()
{
    delete ui;
}



void graphic::slot(char *res_str, double Xmin, double Xmax, double Step)
{

//    printf("%s\n", res_str);
//    if (Xmin <= -1000000.0 || Xmax >= 1000000.0) step = 0.2;
//    else if (Xmin >= -10000.0  && Xmax <= 10000.0) step = 0.001;
//    else if (Xmin >= -100.0  && Xmax <= 100.0) step = 0.001;
//    else step = 0.1;

    step = Step;
    xBegin = Xmin;
    xEnd = Xmax + step;
//    printf("step: %lf\n", step);
    ui->widget->xAxis->setRange(-20, 20);
    ui->widget->yAxis->setRange(-20, 20);

    ui->widget->clearGraphs();
    x.clear();
    y.clear();

    Stack_t *S = convert_str_to_rpn_stack(res_str);
    for (X = xBegin; X <= xEnd; X += step) {
        Stack_t *S1 = CopyStack(S);
        Y = calculate_algoritm(S1, X);
        x.push_back(X);
        y.push_back(Y);
    }

    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);

    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 3));

    ui->expression->setText(res_str);

    ui->widget->replot();


   // zoom
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);


}


void graphic::on_push_x_clicked()
{

    QString value_str = ui->x_value->text();

    QByteArray value_bit = value_str.toLocal8Bit();
    char *value_chars = value_bit.data();

    // проверить на то, что res_str - это число
    if (StringIsNumber(value_chars)) {
        double X = value_str.toDouble();

        int error;
        QString qres = ui->expression->text();
        QByteArray res_bit = qres.toLocal8Bit();
        char *res_str = res_bit.data();

        double Y = calculator(res_str, X, &error);
        QString output = QString::number(Y, 'g', 7);
        ui->answer->setText(output);
    } else {
        ui->answer->setText("Invalid Expression");
    }

}



void graphic::on_build_graphic_clicked()
{
    QString qres = ui->expression->text();
    QByteArray res_bit = qres.toLocal8Bit();
    char *res_str = res_bit.data();

    QString q_xmin, q_xmax, q_step;

    q_xmin = ui->xmin_value->text();
    q_xmax = ui->xmax_value->text();
    q_step = ui->step_value->text();

    QByteArray xmin_bit = q_xmin.toLocal8Bit();
    char *xmin_str = xmin_bit.data();

    QByteArray xmax_bit = q_xmax.toLocal8Bit();
    char *xmax_str = xmax_bit.data();

    QByteArray step_bit = q_step.toLocal8Bit();
    char *step_str = step_bit.data();

    if (StringIsNumber(xmin_str) && StringIsNumber(xmax_str) && StringIsNumber(step_str)) {
        ui->answer->setText("");
        double xmin = q_xmin.toDouble();
        double xmax = q_xmax.toDouble();
        double step = q_step.toDouble();
        graphic::slot(res_str, xmin, xmax, step);
    } else {
        ui->answer->setText("Invalid x_min or x_max");
    }
}

