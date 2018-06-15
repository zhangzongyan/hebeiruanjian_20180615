#include "gamewidget.h"
#include "ui_gamewidget.h"

#include <QDebug>
#include <QPainter>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QTime>
#include <QMessageBox>

#define ROW 18
#define COL 20


GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    // 设置背景图片
    QPalette palet;//调色板
    palet.setBrush(QPalette::Background, \
                   QBrush(QPixmap(":/new/prefix1/images/green.jpg").scaled(580,370)));
    this->setPalette(palet);

    //产生蛇头和食物的位置
    QTime curt = QTime::currentTime();//当前系统时间
    qsrand(curt.msec());
    snake[0][0] = qrand() % COL;
    snake[0][1] = qrand() % ROW;
    direction = qrand() % 4;

    // 食物的坐标
    randFoodPos();

    //创建时钟对象
    tm = new QTimer();
    tm->setInterval(500);//0.5s产生一次timeout()信号

    //链接时钟的timeout()信号与蛇运动的槽函数
    connect(tm, SIGNAL(timeout()), this, SLOT(timeout_handler()));

    //链接按键的信号与槽
    connect(this, SIGNAL(pressAsignal()), ui->pushButton_4, SLOT(click()));
    connect(this, SIGNAL(pressWsignal()), ui->pushButton, SLOT(click()));
    connect(this, SIGNAL(pressSsignal()), ui->pushButton_3, SLOT(click()));
    connect(this, SIGNAL(pressDsignal()), ui->pushButton_2, SLOT(click()));

    foodcount = 0;
    count = 0;
    level = 1;

    //背景音乐
    bg_player = new QMediaPlayer(this);
    bg_player->setMedia(QUrl::fromLocalFile("../heruan_snake/sounds/yinxiao.wav"));
    bg_player->setVolume(100);

    eat_player = new QMediaPlayer(this);
    eat_player->setMedia(QUrl::fromLocalFile("../heruan_snake/sounds/eat.wav"));
    eat_player->setVolume(100);
}

//为食物产生新坐标
void GameWidget::randFoodPos()
{
    int i;

    QTime curt = QTime::currentTime();//当前系统时间
    qsrand(curt.msec());
    while (1) {
        foodx = qrand() % COL;
        foody = qrand() % ROW;
        for (i = 0; i <= foodcount; i++) {
            if (foodx == snake[i][0] && foody == snake[i][1])
                break;
        }
        if (i > foodcount) {
            break;
        }
    }
}

//蛇头移动函数
void GameWidget::timeout_handler(void)
{
    int i;

    //判断是否吃到食物
    if (foodx == snake[0][0] && foody == snake[0][1]) {
        eat_player->play();
        //吃到食物
        foodcount ++;
        count += 3;
        ui->scoreLabel->setText(QString::number(count, 10));
        //等级
        if (count >= 20 && count <= 50){
            level = 2;
            tm->setInterval(300);
        } else if (count > 50 && count <= 100) {
            level = 3;
            tm->setInterval(150);
        } else if (count > 100) {
            level = 4;
            tm->setInterval(80);
        }
        ui->levelLabel->setText(QString::number(level, 10));
        //产生新食物
        randFoodPos();
    }

    memcpy(tmp, snake, sizeof(snake));
    //新蛇身赋予位置
    for (int i = foodcount; i > 0; i--) {
        snake[i][0] = snake[i-1][0];
        snake[i][1] = snake[i-1][1];
    }

    //蛇头位置
    switch (direction) {
    case HEAD_UP:
        snake[0][1] --;
        break;
    case HEAD_DOWN:
        snake[0][1] ++;
        break;
    case HEAD_LEFT:
        snake[0][0] --;
        break;
    case HEAD_RIGHT:
        snake[0][0] ++;
        break;
    default:
        break;
    }

    //判断游戏是否终止
    int eatflag = 0, beyond = 0;
    for (i = 1; i <= foodcount; i++) {
        if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1]) {
            eatflag = 1;
            break;
        }
    }
    if (snake[0][0] < 0 || snake[0][0] >= COL || snake[0][1] < 0 || snake[0][1] >= ROW)
        beyond = 1;
    if (eatflag || beyond) {
        bg_player->stop();
        tm->stop();
        memcpy(snake, tmp, sizeof(tmp));
        //游戏结束
        if (QMessageBox::question(this, QString("游戏结束"), QString("游戏结束！是否重新开始？"), \
                              QMessageBox::Yes, QMessageBox::No) == QMessageBox::No) {
            exit(0);
        } else {
            //重新开始游戏
            foodcount = 0;
            level = 1;
            count = 0;
            ui->scoreLabel->setText(QString::number(count, 10));
            //产生蛇头和食物的位置
            QTime curt = QTime::currentTime();//当前系统时间
            qsrand(curt.msec());
            snake[0][0] = qrand() % COL;
            snake[0][1] = qrand() % ROW;
            direction = qrand() % 4;
            randFoodPos();
        }

    }


    this->repaint();//调用paintEvent()
}

GameWidget::~GameWidget()
{
    delete ui;
}

//只要调用update方法，自动调用paintEvent()
void GameWidget::paintEvent(QPaintEvent *event)
{
    char img_path[100] = {};//蛇头图片的途径

    //画笔对象
    QPainter painter(this);
    int i, j;
    int tailx, taily, fd_tailx, fd_taily;
    //画网格
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            painter.drawRect(j*20,i*20,20,20);
        }
    }

    //画食物
    painter.drawImage(foodx*20, foody*20, \
                      QImage(":/new/prefix1/images/apple.png").scaled(20, 20));

    //画蛇头
    snprintf(img_path, 100, ":/new/prefix1/images/head%d.png", direction);
    painter.drawImage(snake[0][0]*20, snake[0][1]*20, \
            QImage(img_path).scaled(20, 20));
    //画蛇身

    int f1x, f1y, b1x, b1y, cx, cy;
    QImage img;
    i = 1; // 避免只有蛇头 判断
    for (; i < foodcount; i++) {
        cx = snake[i][0];
        cy = snake[i][1];
        f1x = snake[i-1][0];
        f1y = snake[i-1][1];
        b1x = snake[i+1][0];
        b1y = snake[i+1][1];
        if ((cy==f1y && cx>f1x && cx==b1x && cy<b1y) || \
                (cx==f1x && cy<f1y && cy==b1y && cx>b1x)) {
            img = QImage(":/new/prefix1/images/tr_corner.png").scaled(20,20);
        } else if ((cy==f1y && cx<f1x && cx==b1x && cy>b1y) || \
                   (cx==f1x && cy>f1y && cy==b1y && cx<b1x)) {
            img = QImage(":/new/prefix1/images/bl_corner.png").scaled(20,20);//左下
        } else if ((cy>f1y && cx==f1x && cx>b1x && cy==b1y) || \
                   (cx>f1x && cy==f1y && cy>b1y && cx==b1x)) {
            img = QImage(":/new/prefix1/images/br_corner.png").scaled(20,20);//右下
        } else if ((cy==f1y && cx<f1x && cx==b1x && cy<b1y) || \
                   (cx==f1x && cy<f1y && cy==b1y && cx<b1x)) {
            img = QImage(":/new/prefix1/images/tl_corner.png").scaled(20,20);
        } else if (cy == f1y && cy == b1y) {
            img = QImage(":/new/prefix1/images/h_body.png").scaled(20,20);

        } else {
            img = QImage(":/new/prefix1/images/v_body.png").scaled(20,20);
        }

        painter.drawImage(snake[i][0]*20, snake[i][1]*20, \
                img);
    }

    //蛇尾
    tailx = snake[foodcount][0];
    taily = snake[foodcount][1];
    fd_tailx = snake[foodcount-1][0];
    fd_taily = snake[foodcount-1][1];
    if (foodcount == i) {
        if (tailx == fd_tailx && taily > fd_taily)
            snprintf(img_path, 100, ":/new/prefix1/images/tail0.png");//下
        else if(tailx == fd_tailx && taily < fd_taily)
            snprintf(img_path, 100, ":/new/prefix1/images/tail1.png");//上
        else if(taily == fd_taily && tailx < fd_tailx)
            snprintf(img_path, 100, ":/new/prefix1/images/tail3.png");
        else
            snprintf(img_path, 100, ":/new/prefix1/images/tail2.png");

        painter.drawImage(snake[foodcount][0]*20, snake[foodcount][1]*20, \
                QImage(img_path).scaled(20, 20));
    }
}

//开始按钮的槽函数
void GameWidget::on_pushButton_5_clicked()
{
    //是能时钟信号
    tm->start();
    bg_player->play();
}

void GameWidget::on_pushButton_clicked()
{
    if (direction == HEAD_DOWN)
        return;
    direction = HEAD_UP;
}

void GameWidget::on_pushButton_4_clicked()
{
    if (direction == HEAD_RIGHT)
        return;
    direction = HEAD_LEFT;
}

void GameWidget::on_pushButton_2_clicked()
{
    if (direction == HEAD_LEFT)
        return;
    direction = HEAD_RIGHT;
}

void GameWidget::on_pushButton_3_clicked()
{
    if (direction == HEAD_UP)
        return;
    direction = HEAD_DOWN;
}

void GameWidget::on_pushButton_6_clicked()
{
    tm->stop();
    bg_player->stop();
}

//按键触发函数
void GameWidget::keyPressEvent(QKeyEvent *evt)
{
    //qDebug("%d\n", evt->key());
    int keyvalue = evt->key();

    switch (keyvalue) {
    case Qt::Key_A:
        emit pressAsignal();//发送信号
        break;
    case Qt::Key_D:
        emit pressDsignal();//发送信号
        break;
    case Qt::Key_W:
        emit pressWsignal();//发送信号
        break;
    case Qt::Key_S:
        emit pressSsignal();//发送信号
        break;
    default:
        break;
    }


}











