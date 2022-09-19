#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef enum Direct {
    DIR_LEFT,
    DIR_RIGHT,
    DIR_UP,
    DIR_DOWN
} dir_t;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
    void deleteLast();

    void addTop();
    void addDown();
    void addRight();
    void addLeft();

private:
    Ui::MainWindow *ui;

    dir_t moveFlag = DIR_UP;
    bool gameStart = false;
    // 定时器
    QTimer *timer = nullptr;

    // 超时时间间隔，毫秒
    int time = 100;
    // 蛇
    QList <QRectF> snake;

    // 小方块的宽高
    int nodeWidth = 20;
    int nodeHeight = 20;

protected slots:
    void timeout();
};
#endif // MAINWINDOW_H
