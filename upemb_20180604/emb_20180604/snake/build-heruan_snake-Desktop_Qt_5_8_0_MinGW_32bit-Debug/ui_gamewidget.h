/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *scoreLabel;
    QLabel *levelLabel;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName(QStringLiteral("GameWidget"));
        GameWidget->resize(580, 370);
        GameWidget->setMinimumSize(QSize(580, 370));
        GameWidget->setMaximumSize(QSize(580, 370));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        GameWidget->setWindowIcon(icon);
        pushButton = new QPushButton(GameWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(480, 150, 41, 41));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(GameWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(530, 190, 41, 41));
        pushButton_2->setFlat(true);
        pushButton_3 = new QPushButton(GameWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 240, 41, 41));
        pushButton_3->setFlat(true);
        pushButton_4 = new QPushButton(GameWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(430, 190, 41, 41));
        pushButton_4->setFlat(true);
        pushButton_5 = new QPushButton(GameWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(430, 310, 51, 31));
        pushButton_6 = new QPushButton(GameWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(520, 310, 51, 31));
        label = new QLabel(GameWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(467, 20, 51, 21));
        QFont font;
        font.setFamily(QStringLiteral("Aharoni"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(GameWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(467, 60, 51, 21));
        label_2->setFont(font);
        scoreLabel = new QLabel(GameWidget);
        scoreLabel->setObjectName(QStringLiteral("scoreLabel"));
        scoreLabel->setGeometry(QRect(530, 20, 31, 20));
        scoreLabel->setFont(font);
        levelLabel = new QLabel(GameWidget);
        levelLabel->setObjectName(QStringLiteral("levelLabel"));
        levelLabel->setGeometry(QRect(530, 60, 41, 20));
        levelLabel->setFont(font);

        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QApplication::translate("GameWidget", "\350\264\252\345\220\203\350\233\207", Q_NULLPTR));
        pushButton->setText(QApplication::translate("GameWidget", "\342\206\221", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("GameWidget", "\342\206\222", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("GameWidget", "\342\206\223", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("GameWidget", "\342\206\220", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("GameWidget", "\345\274\200\345\247\213", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("GameWidget", "\346\232\202\345\201\234", Q_NULLPTR));
        label->setText(QApplication::translate("GameWidget", "\345\210\206\346\225\260:", Q_NULLPTR));
        label_2->setText(QApplication::translate("GameWidget", "\347\255\211\347\272\247:", Q_NULLPTR));
        scoreLabel->setText(QApplication::translate("GameWidget", "0", Q_NULLPTR));
        levelLabel->setText(QApplication::translate("GameWidget", "1", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
