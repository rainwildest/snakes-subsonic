#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPen>
#include <QBrush>
#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::timeout);

    resize(600, 368);

    QRectF rect(300, 180, nodeWidth, nodeHeight);
    snake.append(rect);
    addTop();
    addTop();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief 控制方向
 * @param event
 */
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Up:
            if(moveFlag != DIR_DOWN) {
                moveFlag = DIR_UP;
            }
            break;
        case Qt::Key_Down:
            if(moveFlag != DIR_UP) {
                moveFlag = DIR_DOWN;
            }
            break;
        case Qt::Key_Right:
            if(moveFlag != DIR_LEFT) {
                moveFlag = DIR_RIGHT;
            }
            break;
        case Qt::Key_Left:
            if(moveFlag != DIR_RIGHT) {
                moveFlag = DIR_LEFT;
            }
            break;
        case Qt::Key_Space:
            if(gameStart == false) {
                gameStart = true;
                // 启动定时器
                timer->start(time);
            } else {
                gameStart = false;
                timer->stop();
            }
            break;
        default:
            break;
    }
}

void MainWindow::timeout()
{
    switch(moveFlag) {
        case DIR_UP:
            break;
        case DIR_DOWN:
            break;
        case DIR_LEFT:
            break;
        case DIR_RIGHT:
            break;
        default:
            break;
    }
}

void MainWindow::addTop()
{
    QPointF leftTop;
    QPointF rightBottom;

    if(snake[0].y() - nodeHeight < 0) {
        leftTop = QPointF(snake[0].x(), this->height() - nodeHeight);
        rightBottom = QPointF(snake[0].x() + nodeWidth, this->height());
    } else {
        qDebug() << snake[0].y() - nodeHeight;
        leftTop = QPointF(snake[0].x(), snake[0].y() - nodeHeight);
        rightBottom = snake[0].topRight();
    }

    snake.insert(0, QRectF(leftTop, rightBottom));
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QBrush brush;

    // 背景图

    pen.setColor(Qt::black);
    brush.setColor(Qt::darkMagenta);
    brush.setStyle(Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);

    for(int i = 0; i < snake.length(); ++i) {
        painter.drawRect(snake[i]);
    }
}
