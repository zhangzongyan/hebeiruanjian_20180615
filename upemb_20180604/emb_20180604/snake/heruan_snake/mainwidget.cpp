#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QDebug>
#include "gamewidget.h" //游戏窗口类在此文件中定义的

//实例化对象时自动调用的方法
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    qDebug("构造方法自动调用了....\n");
    ui->setupUi(this); //界面
}

//析构，对象销毁的时候自动调用
MainWidget::~MainWidget()
{
    qDebug("析构方法调用了....\n");
    delete ui;
}

//开始按钮的槽函数
void MainWidget::on_pushButton_clicked()
{
    //qDebug("点击开始\n");
    //构建游戏窗口对象
    GameWidget *game = new GameWidget();
    game->show();

    //this->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
}
