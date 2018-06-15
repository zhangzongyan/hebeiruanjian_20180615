#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPaintEvent>//QWidget类的paintEvent()
#include <QTimer>
#include <QKeyEvent>
#include <QMediaPlayer>

#define HEAD_UP     0
#define HEAD_DOWN   1
#define HEAD_LEFT   2
#define HEAD_RIGHT  3

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();
    void paintEvent(QPaintEvent *event);
    //按键按下会触发的函数
    void keyPressEvent(QKeyEvent *evt);

    void randFoodPos();


private slots:
    void on_pushButton_5_clicked();
    //蛇头移动
    void timeout_handler(void);

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

signals:
    void pressAsignal();
    void pressSsignal();
    void pressDsignal();
    void pressWsignal();

private:
    Ui::GameWidget *ui;
    int direction;
    QTimer *tm;
    int foodcount;//统计吃到苹果个数
    int count;
    int level;
    QMediaPlayer *bg_player;
    QMediaPlayer *eat_player;

    int snake[200][2]; //存储蛇头到蛇尾每一个组成部分的坐标值
    int tmp[200][2];
    int foodx, foody; //食物的坐标

};

#endif // GAMEWIDGET_H
