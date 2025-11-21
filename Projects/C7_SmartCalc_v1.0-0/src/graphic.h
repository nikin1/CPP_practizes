#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>

//#include <QGraphicsScene>
//#include <QGraphicsView>
//#include <QGraphicsItem>

#include <QVector>

typedef enum {
    NUMBER = 1,
    X = 2,
    PLUS = 3,
    MINUS = 4,
    MULT = 5,
    DIV = 6,
    POW = 7,
    MOD = 8,
    COS = 9,
    SIN = 10,
    TAN = 11,
    ACOS = 12,
    ASIN = 13,
    ATAN = 14,
    SQRT = 15,
    LN = 16,
    LOG = 17,
    LEFT_BRACKET = 18,
    RIGHT_BRACKET = 19
} type_t;

typedef struct Stack {
    double value;
    int priority;
    type_t type;
    struct Stack *prev;
} Stack_t;



namespace Ui {
class graphic;
}

class graphic : public QWidget
{
    Q_OBJECT

public:
    explicit graphic(QWidget *parent = nullptr);
    ~graphic();

public slots:
    void slot(char *res_str, double Xmin, double Xmax, double Step);

private slots:
    void on_push_x_clicked();

    void on_build_graphic_clicked();

private:
    Ui::graphic *ui;
    double xBegin, xEnd, step, X, Y;
    int cnt;

    QVector<double> x,y;
//    QGraphicsScene *scene;
//    QGraphicsEllipseItem *ellipse;
//    QGraphicsRectItem *rectangle;
//    QGraphicsTextItem *text;

};

#endif // GRAPHIC_H
