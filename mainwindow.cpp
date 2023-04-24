
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void drawBorschtPot(QPainter &painter, int x, int y, float k)
{
    QPen grayPen;
    grayPen.setColor(Qt::gray);
    grayPen.setWidth(1);
    painter.setPen(grayPen);
    painter.setBrush(Qt::gray);

    QPen bluePen;
    bluePen.setColor(Qt::blue);
    bluePen.setWidth(1);
    QPen yellowPen;
    yellowPen.setColor(Qt::yellow);
    yellowPen.setWidth(1);

    // дно
    painter.drawEllipse(x, y + 40 * k, 70 * k, 60 * k);

    // стенки
    painter.drawRect(x, y + 35 * k, 70 * k, 40 * k);

    // верх
    painter.setBrush(Qt::red);
    painter.drawEllipse(x, y, 70 * k, 60 * k);


    //ручки
    grayPen.setWidth(4);
    painter.setPen(grayPen);
    QRectF rectangle_left(x + 30 * k, y + 40 * k, 50 * k, 20 * k);
    painter.drawArc(rectangle_left, 45 * 16, -90 * 16);
    QRectF rectangle_right(x - 8 * k, y + 40 * k, 50 * k, 20  * k);
    painter.drawArc(rectangle_right, 135 * 16, 90 * 16);

    //рисуночек
    // я щас умру какой рисуночек эти дуги говно
    painter.setPen(bluePen);
    painter.setBrush(Qt::blue);
    QRectF petal_left(x + 20 * k, y + 63 * k, 30 * k, 30.0 * k);
    painter.drawPie(petal_left, 30 * 16, -60 * 16);
    QRectF petal_right(x + 20 * k, y + 63 * k, 30 * k, 30.0 * k);
    painter.drawPie(petal_right, 60 * 16, 60 * 16);
    QRectF petal_up(x + 20 * k, y + 63 * k, 30 * k, 30.0 * k);
    painter.drawPie(petal_up, 150 * 16, 60 * 16);
    QRectF petal_down(x + 20 * k, y + 63 * k, 30 * k, 30.0 * k);
    painter.drawPie(petal_down, 240 * 16, 60 * 16);

    painter.setPen(yellowPen);
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(x + 30 * k, y + 73 * k, 10 * k, 10 * k);

    // в борще должна быть картошка
    yellowPen.setWidth(6);
    painter.setPen(yellowPen);

    painter.drawLine(x + 35 * k, y + 35 * k, x + 40 * k, y + 40 * k);
    painter.drawLine(x + 30 * k, y + 23 * k, x + 25 * k, y + 28 * k);
    painter.drawLine(x + 55 * k, y + 50 * k, x + 49 * k, y + 39 * k);
    painter.drawLine(x + 15 * k, y + 13 * k, x + 10 * k, y + 18 * k);
    painter.drawLine(x + 25 * k, y + 45 * k, x + 30 * k, y + 40 * k);
    painter.drawLine(x + 35 * k, y + 15 * k, x + 45 * k, y + 18 * k);
}


void drawBeaver(QPainter &painter, int x, int y, float k) {
    // рисуем тело бобра
    QPen brownPen;
    brownPen.setColor(QColor(51,21,0));
    brownPen.setWidth(5);
    QPen whitePen;
    whitePen.setColor(QColor(255,255,255));
    whitePen.setWidth(5);
    QPen blackPen;
    blackPen.setColor(QColor(0,0,0));
    blackPen.setWidth(3);
    painter.setPen(brownPen);
    QBrush brownBrush;
    brownBrush.setStyle(Qt::SolidPattern);
    brownBrush.setColor(QColor(139,69,19));
    QBrush blackBrush;
    blackBrush.setStyle(Qt::SolidPattern);
    QBrush whiteBrush;
    whiteBrush.setStyle(Qt::SolidPattern);
    whiteBrush.setColor(QColor(255,255,255));

    painter.setBrush(brownBrush);
    painter.drawEllipse(x + 50*k, y + 50*k, 80*k, 60*k);
    brownBrush.setColor(QColor(139,69,19));
    painter.drawEllipse(x + 70*k, y + 30*k, 60*k, 60*k);
    painter.setPen(blackPen);

    // рисуем глаза бобра
    painter.setPen(whitePen);
    painter.setBrush(whiteBrush);
    painter.drawEllipse(x + 65*k, y + 50*k, 20*k, 20*k);
    painter.drawEllipse(x + 115*k, y + 50*k, 20*k, 20*k);
    painter.setPen(blackPen);
    painter.setBrush(blackBrush);
    painter.drawEllipse(x + 72*k, y + 57*k, 6*k, 6*k);
    painter.drawEllipse(x + 122*k, y + 57*k, 6*k, 6*k);

    // рисуем зубы бобра
    painter.setPen(blackPen);
    painter.setBrush(whiteBrush);
    painter.drawRect(x + 80*k, y + 75*k, 10*k, 5*k);
    painter.drawRect(x + 90*k, y + 75*k, 10*k, 12*k);
    painter.drawRect(x + 100*k, y + 75*k, 10*k, 12*k);
    painter.drawRect(x + 110*k, y + 75*k, 10*k, 5*k);

    // хвост
    painter.setPen(brownPen);
    painter.setBrush(brownBrush);
    QRectF rectangle(x + 15*k, y + 55*k, 80*k, 80.0*k);
    int startAngle = 100 * 16;
    int spanAngle = 35 * 16;
    painter.drawPie(rectangle, startAngle, spanAngle);
    brownBrush.setStyle(Qt::DiagCrossPattern);
    brownBrush.setColor(QColor(51,21,0));
    painter.setBrush(brownBrush);
    painter.drawPie(rectangle, startAngle, spanAngle);

    //лапы
    brownBrush.setStyle(Qt::SolidPattern);
    brownBrush.setColor(QColor(51,21,0));
    painter.setBrush(brownBrush);
    QRectF rectangle_fpaw(x + 60*k, y + 100*k, 30*k, 20.0*k);
    int startAnglePaw = 0 * 16;
    int spanAnglePaw = 180 * 16;
    painter.drawPie(rectangle_fpaw, startAnglePaw, spanAnglePaw);

    QRectF rectangle_spaw(x + 100*k, y + 100*k, 30*k, 20.0*k);
    painter.drawPie(rectangle_spaw, startAnglePaw, spanAnglePaw);
}

void drawTable(QPainter &painter, int x, int y, float k)
{
    QPen brownPen;
    brownPen.setColor(QColor(51, 25, 0));
    brownPen.setWidth(4 * k);
    painter.setPen(brownPen);
    painter.setBrush(QColor(153, 76, 0));

    QBrush patBrush;
    patBrush.setStyle(Qt::Dense6Pattern);
    patBrush.setColor(QColor(51, 25, 0));

    QBrush mainBrush;
    mainBrush.setStyle(Qt::SolidPattern);
    mainBrush.setColor(QColor(153, 76, 0));
    // основная поверхность
    QPointF table[4] = {
        QPointF(x + 50 * k , y),
        QPointF(x + 260 * k , y),
        QPointF(x + 210 * k , y + 100 * k),
        QPointF(x , y + 100 * k),
    };
    painter.drawPolygon(table, 4);
    painter.setBrush(patBrush);
    painter.drawPolygon(table, 4);
    painter.setBrush(mainBrush);
    // ножки
    painter.drawRect(x, y + 100 * k, 20 * k, 60 * k);
    QPointF table_leg_V1[4] = {
        QPointF(x + 20 * k, y + 100 * k),
        QPointF(x + 30 * k, y + 100 * k),
        QPointF(x + 30 * k, y + 150 * k),
        QPointF(x + 20 * k, y + 160 * k),
    };
    painter.drawPolygon(table_leg_V1, 4);

    painter.drawRect(x + 190 * k, y + 100 * k, 20 * k, 60 * k);
    QPointF table_leg_V2[4] = {
        QPointF(x + 210 * k, y + 100 * k),
        QPointF(x + 220 * k, y + 80 * k),
        QPointF(x + 220 * k, y + 150 * k),
        QPointF(x + 210 * k, y + 160 * k),
    };
    painter.drawPolygon(table_leg_V2, 4);


    QPointF table_leg_3V[4] = {
        QPointF(x + 260 * k, y),
        QPointF(x + 250 * k, y + 20 * k),
        QPointF(x + 250 * k, y + 80 * k),
        QPointF(x + 260 * k, y + 70 * k),
    };
    painter.drawPolygon(table_leg_3V, 4);
    QPointF table_leg_3[4] = {
        QPointF(x + 250 * k, y + 20 * k),
        QPointF(x + 250 * k, y + 80 * k),
        QPointF(x + 230 * k, y + 80 * k),
        QPointF(x + 230 * k, y + 70 * k),
    };
    painter.drawPolygon(table_leg_3, 4);
    QPointF table_leg_V3[4] = {
        QPointF(x + 210 * k, y + 100 * k),
        QPointF(x + 220 * k, y + 80 * k),
        QPointF(x + 220 * k, y + 150 * k),
        QPointF(x + 210 * k, y + 160 * k),
    };
    painter.drawPolygon(table_leg_V3, 4);
    //объём основной поверхности
    painter.setBrush(mainBrush);
    QPointF VtableDown[4] = {
        QPointF(x, y + 100 * k),
        QPointF(x, y + 115 * k),
        QPointF(x + 210 * k , y + 115 * k),
        QPointF(x + 210 * k , y + 100 * k),
    };
    painter.drawPolygon(VtableDown, 4);
    QPointF VtableRight[4] = {
        QPointF(x + 260 * k, y),
        QPointF(x + 260 * k, y + 15 * k),
        QPointF(x + 210 * k, y + 115 * k),
        QPointF(x + 210 * k, y + 100 * k),
    };
    painter.drawPolygon(VtableRight, 4);

}

void drawSoyjak(QPainter &painter, int x, int y, float k) {
    QBrush solid_black;
    solid_black.setStyle(Qt::SolidPattern);
    solid_black.setColor(Qt::black);
    QBrush solid_white;
    solid_white.setStyle(Qt::SolidPattern);
    solid_white.setColor(Qt::white);
    QPen mainPen;
    mainPen.setColor(Qt::black);
    mainPen.setWidth(2 * k);
    painter.setPen(mainPen);
    painter.setBrush(solid_white);
    //тело и рука
    QPointF body[30] = {
        QPointF(x + 55 * k, y + 400 * k),
        QPointF(x + 70 * k, y + 220 * k),
        QPointF(x + 95 * k, y + 180 * k),
        QPointF(x + 20 * k, y + 130 * k),
        QPointF(x + 24 * k, y + 120 * k),
        QPointF(x, y + 107 * k),
        QPointF(x + 30 * k, y + 115 * k),
        QPointF(x + 30 * k, y + 110 * k),
        QPointF(x + 85 * k, y + 150 * k),
        QPointF(x + 225 * k, y + 150 * k),
        QPointF(x + 250 * k, y + 220 * k),
        QPointF(x + 270 * k, y + 400 * k),
    };
    painter.drawPolygon(body, 12);
    //голова
    painter.drawEllipse(x + 80 * k, y, 150 * k, 210 * k);
    //щетина
    painter.setBrush(Qt::Dense7Pattern);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(x + 90 * k, y + 110 * k, 100 * k, 90 * k);

    painter.setPen(mainPen);
    painter.setBrush(solid_white);

    //рот
    painter.drawEllipse(x + 114 * k, y + 147 * k, 47 * k, 40 * k);
    painter.setBrush(solid_black);
    painter.drawEllipse(x + 110 * k, y + 140 * k, 50 * k, 40 * k);
    painter.drawEllipse(x + 110 * k, y + 130 * k, 25 * k, 32 * k);
    painter.drawEllipse(x + 125 * k, y + 130 * k, 25 * k, 32 * k);

    //глаза
    painter.setBrush(solid_white);
    painter.drawEllipse(x + 80 * k, y + 50 * k, 40 * k, 25 * k);
    painter.drawEllipse(x + 155 * k, y + 52 * k, 40 * k, 20 * k);
    painter.setBrush(solid_black);
    painter.drawEllipse(x + 88 * k, y + 50 * k, 25 * k, 25 * k);
    painter.drawEllipse(x + 165 * k, y + 52 * k, 20 * k, 20 * k);
    //Дискотека Овсянкин
    //Эмо рэперы панки
    //Здесь вас выдадут замуж

    // брови
    painter.setPen(QPen(Qt::black, 5));
    painter.drawLine(x + 85 * k, y + 45 * k, x + 115 * k, y + 36 * k);
    painter.drawLine(x + 165 * k, y + 37 * k, x + 190 * k, y + 50 * k);

    // морщины
    painter.setPen(mainPen);
    painter.drawLine(x + 105 * k, y + 25 * k, x + 190 * k, y + 25 * k);
    painter.drawLine(x + 105 * k, y + 30 * k, x + 190 * k, y + 30 * k);
    painter.drawLine(x + 105 * k, y + 35 * k, x + 190 * k, y + 35 * k);

    //нос
    painter.setBrush(solid_white);
    QPointF nose[3] = {
        QPointF(x + 135 * k, y + 70 * k),
        QPointF(x + 155 * k, y + 109 * k),
        QPointF(x + 117 * k, y + 103 * k),
    };
    painter.drawPolygon(nose, 3);
    painter.setBrush(solid_black);
    painter.drawEllipse(x + 123 * k, y + 93 * k, 10 * k, 10 * k);
    painter.drawEllipse(x + 139 * k, y + 96 * k, 10 * k, 10 * k);

}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter;
    painter.begin(this);
//    Идeт мyжик пo бaзару, видит - грузин бобра продает.
//       - Че за бобер?
//       - Сосeт отлично!
//       - Та нy, бобер и сосет?
//       - Ну дa, возьми, проверишь, понравится - завтра бабло принесешь мне!
//    Cлeдyющий дeнь, утро, мужик просыпается, а бобер реально сосет, и хорошо тaк coсет!
//    Он выходит на кухню, ставит бобра на стол, говорит жене:
//       - Бобра видишь?
//       - Вижу ....
//       - Haучи вapить бopщ, и пошлa из дoма!
//    drawBeaver(painter, 150, 150, 4);
    drawTable(painter, 200, 200, 1.1);
    drawBorschtPot(painter, 370, 160, 1.2);
    drawBeaver(painter, 180, 130, 1.3);
    drawSoyjak(painter, 380, 130, 1.5);
    painter.end();
}

