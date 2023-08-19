/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *resultPanel;
    QLineEdit *x_value;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_1;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_exp;
    QPushButton *pushButton_9;
    QPushButton *pushButton_log;
    QPushButton *pushButton_pi;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_0;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_AC;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_math_bracket_left;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_7;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_2;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_div;
    QPushButton *pushButton_math_bracket_right;
    QPushButton *pushButton_8;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_C;
    QPushButton *pushButton_4;
    QPushButton *pushButton_X;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(572, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        resultPanel = new QLineEdit(centralwidget);
        resultPanel->setObjectName(QString::fromUtf8("resultPanel"));
        resultPanel->setGeometry(QRect(9, 24, 551, 61));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(resultPanel->sizePolicy().hasHeightForWidth());
        resultPanel->setSizePolicy(sizePolicy);
        resultPanel->setLayoutDirection(Qt::LeftToRight);
        resultPanel->setMaxLength(255);
        resultPanel->setCursorPosition(0);
        resultPanel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        x_value = new QLineEdit(centralwidget);
        x_value->setObjectName(QString::fromUtf8("x_value"));
        x_value->setGeometry(QRect(89, 394, 471, 45));
        sizePolicy.setHeightForWidth(x_value->sizePolicy().hasHeightForWidth());
        x_value->setSizePolicy(sizePolicy);
        x_value->setMinimumSize(QSize(0, 0));
        x_value->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setPointSize(14);
        x_value->setFont(font);
        x_value->setMaxLength(255);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 104, 551, 271));
        sizePolicy.setHeightForWidth(layoutWidget->sizePolicy().hasHeightForWidth());
        layoutWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_cos = new QPushButton(layoutWidget);
        pushButton_cos->setObjectName(QString::fromUtf8("pushButton_cos"));
        pushButton_cos->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_cos->sizePolicy().hasHeightForWidth());
        pushButton_cos->setSizePolicy(sizePolicy);
        pushButton_cos->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(18);
        pushButton_cos->setFont(font1);

        gridLayout_2->addWidget(pushButton_cos, 4, 2, 1, 1);

        pushButton_1 = new QPushButton(layoutWidget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);
        pushButton_1->setFont(font1);

        gridLayout_2->addWidget(pushButton_1, 2, 2, 1, 1);

        pushButton_ln = new QPushButton(layoutWidget);
        pushButton_ln->setObjectName(QString::fromUtf8("pushButton_ln"));
        sizePolicy.setHeightForWidth(pushButton_ln->sizePolicy().hasHeightForWidth());
        pushButton_ln->setSizePolicy(sizePolicy);
        pushButton_ln->setFont(font1);

        gridLayout_2->addWidget(pushButton_ln, 2, 1, 1, 1);

        pushButton_dot = new QPushButton(layoutWidget);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        sizePolicy.setHeightForWidth(pushButton_dot->sizePolicy().hasHeightForWidth());
        pushButton_dot->setSizePolicy(sizePolicy);
        pushButton_dot->setFont(font1);

        gridLayout_2->addWidget(pushButton_dot, 3, 4, 1, 1);

        pushButton_exp = new QPushButton(layoutWidget);
        pushButton_exp->setObjectName(QString::fromUtf8("pushButton_exp"));
        sizePolicy.setHeightForWidth(pushButton_exp->sizePolicy().hasHeightForWidth());
        pushButton_exp->setSizePolicy(sizePolicy);
        pushButton_exp->setFont(font1);

        gridLayout_2->addWidget(pushButton_exp, 1, 0, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setFont(font1);

        gridLayout_2->addWidget(pushButton_9, 0, 4, 1, 1);

        pushButton_log = new QPushButton(layoutWidget);
        pushButton_log->setObjectName(QString::fromUtf8("pushButton_log"));
        sizePolicy.setHeightForWidth(pushButton_log->sizePolicy().hasHeightForWidth());
        pushButton_log->setSizePolicy(sizePolicy);
        pushButton_log->setFont(font1);

        gridLayout_2->addWidget(pushButton_log, 1, 1, 1, 1);

        pushButton_pi = new QPushButton(layoutWidget);
        pushButton_pi->setObjectName(QString::fromUtf8("pushButton_pi"));
        sizePolicy.setHeightForWidth(pushButton_pi->sizePolicy().hasHeightForWidth());
        pushButton_pi->setSizePolicy(sizePolicy);
        pushButton_pi->setFont(font1);

        gridLayout_2->addWidget(pushButton_pi, 2, 0, 1, 1);

        pushButton_5 = new QPushButton(layoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setFont(font1);

        gridLayout_2->addWidget(pushButton_5, 1, 3, 1, 1);

        pushButton_6 = new QPushButton(layoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFont(font1);

        gridLayout_2->addWidget(pushButton_6, 1, 4, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFont(font1);

        gridLayout_2->addWidget(pushButton_3, 2, 4, 1, 1);

        pushButton_equal = new QPushButton(layoutWidget);
        pushButton_equal->setObjectName(QString::fromUtf8("pushButton_equal"));
        sizePolicy.setHeightForWidth(pushButton_equal->sizePolicy().hasHeightForWidth());
        pushButton_equal->setSizePolicy(sizePolicy);
        pushButton_equal->setFont(font1);

        gridLayout_2->addWidget(pushButton_equal, 3, 6, 2, 1);

        pushButton_minus = new QPushButton(layoutWidget);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));
        sizePolicy.setHeightForWidth(pushButton_minus->sizePolicy().hasHeightForWidth());
        pushButton_minus->setSizePolicy(sizePolicy);
        pushButton_minus->setFont(font1);

        gridLayout_2->addWidget(pushButton_minus, 2, 5, 1, 1);

        pushButton_0 = new QPushButton(layoutWidget);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        sizePolicy.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy);
        pushButton_0->setFont(font1);

        gridLayout_2->addWidget(pushButton_0, 3, 2, 1, 2);

        pushButton_sqrt = new QPushButton(layoutWidget);
        pushButton_sqrt->setObjectName(QString::fromUtf8("pushButton_sqrt"));
        sizePolicy.setHeightForWidth(pushButton_sqrt->sizePolicy().hasHeightForWidth());
        pushButton_sqrt->setSizePolicy(sizePolicy);
        pushButton_sqrt->setFont(font1);

        gridLayout_2->addWidget(pushButton_sqrt, 3, 1, 1, 1);

        pushButton_mult = new QPushButton(layoutWidget);
        pushButton_mult->setObjectName(QString::fromUtf8("pushButton_mult"));
        sizePolicy.setHeightForWidth(pushButton_mult->sizePolicy().hasHeightForWidth());
        pushButton_mult->setSizePolicy(sizePolicy);
        pushButton_mult->setFont(font1);

        gridLayout_2->addWidget(pushButton_mult, 1, 5, 1, 1);

        pushButton_AC = new QPushButton(layoutWidget);
        pushButton_AC->setObjectName(QString::fromUtf8("pushButton_AC"));
        sizePolicy.setHeightForWidth(pushButton_AC->sizePolicy().hasHeightForWidth());
        pushButton_AC->setSizePolicy(sizePolicy);
        pushButton_AC->setFont(font1);

        gridLayout_2->addWidget(pushButton_AC, 0, 6, 1, 1);

        pushButton_mod = new QPushButton(layoutWidget);
        pushButton_mod->setObjectName(QString::fromUtf8("pushButton_mod"));
        sizePolicy.setHeightForWidth(pushButton_mod->sizePolicy().hasHeightForWidth());
        pushButton_mod->setSizePolicy(sizePolicy);
        pushButton_mod->setFont(font1);

        gridLayout_2->addWidget(pushButton_mod, 1, 6, 1, 1);

        pushButton_acos = new QPushButton(layoutWidget);
        pushButton_acos->setObjectName(QString::fromUtf8("pushButton_acos"));
        sizePolicy.setHeightForWidth(pushButton_acos->sizePolicy().hasHeightForWidth());
        pushButton_acos->setSizePolicy(sizePolicy);
        pushButton_acos->setFont(font1);

        gridLayout_2->addWidget(pushButton_acos, 4, 3, 1, 1);

        pushButton_math_bracket_left = new QPushButton(layoutWidget);
        pushButton_math_bracket_left->setObjectName(QString::fromUtf8("pushButton_math_bracket_left"));
        sizePolicy.setHeightForWidth(pushButton_math_bracket_left->sizePolicy().hasHeightForWidth());
        pushButton_math_bracket_left->setSizePolicy(sizePolicy);
        pushButton_math_bracket_left->setFont(font1);

        gridLayout_2->addWidget(pushButton_math_bracket_left, 0, 0, 1, 1);

        pushButton_sin = new QPushButton(layoutWidget);
        pushButton_sin->setObjectName(QString::fromUtf8("pushButton_sin"));
        sizePolicy.setHeightForWidth(pushButton_sin->sizePolicy().hasHeightForWidth());
        pushButton_sin->setSizePolicy(sizePolicy);
        pushButton_sin->setFont(font1);

        gridLayout_2->addWidget(pushButton_sin, 4, 0, 1, 1);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setFont(font1);

        gridLayout_2->addWidget(pushButton_7, 0, 2, 1, 1);

        pushButton_pow = new QPushButton(layoutWidget);
        pushButton_pow->setObjectName(QString::fromUtf8("pushButton_pow"));
        sizePolicy.setHeightForWidth(pushButton_pow->sizePolicy().hasHeightForWidth());
        pushButton_pow->setSizePolicy(sizePolicy);
        pushButton_pow->setFont(font1);

        gridLayout_2->addWidget(pushButton_pow, 3, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFont(font1);

        gridLayout_2->addWidget(pushButton_2, 2, 3, 1, 1);

        pushButton_atan = new QPushButton(layoutWidget);
        pushButton_atan->setObjectName(QString::fromUtf8("pushButton_atan"));
        sizePolicy.setHeightForWidth(pushButton_atan->sizePolicy().hasHeightForWidth());
        pushButton_atan->setSizePolicy(sizePolicy);
        pushButton_atan->setFont(font1);

        gridLayout_2->addWidget(pushButton_atan, 4, 5, 1, 1);

        pushButton_plus = new QPushButton(layoutWidget);
        pushButton_plus->setObjectName(QString::fromUtf8("pushButton_plus"));
        sizePolicy.setHeightForWidth(pushButton_plus->sizePolicy().hasHeightForWidth());
        pushButton_plus->setSizePolicy(sizePolicy);
        pushButton_plus->setFont(font1);

        gridLayout_2->addWidget(pushButton_plus, 3, 5, 1, 1);

        pushButton_div = new QPushButton(layoutWidget);
        pushButton_div->setObjectName(QString::fromUtf8("pushButton_div"));
        sizePolicy.setHeightForWidth(pushButton_div->sizePolicy().hasHeightForWidth());
        pushButton_div->setSizePolicy(sizePolicy);
        pushButton_div->setFont(font1);

        gridLayout_2->addWidget(pushButton_div, 2, 6, 1, 1);

        pushButton_math_bracket_right = new QPushButton(layoutWidget);
        pushButton_math_bracket_right->setObjectName(QString::fromUtf8("pushButton_math_bracket_right"));
        sizePolicy.setHeightForWidth(pushButton_math_bracket_right->sizePolicy().hasHeightForWidth());
        pushButton_math_bracket_right->setSizePolicy(sizePolicy);
        pushButton_math_bracket_right->setFont(font1);

        gridLayout_2->addWidget(pushButton_math_bracket_right, 0, 1, 1, 1);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setFont(font1);

        gridLayout_2->addWidget(pushButton_8, 0, 3, 1, 1);

        pushButton_asin = new QPushButton(layoutWidget);
        pushButton_asin->setObjectName(QString::fromUtf8("pushButton_asin"));
        sizePolicy.setHeightForWidth(pushButton_asin->sizePolicy().hasHeightForWidth());
        pushButton_asin->setSizePolicy(sizePolicy);
        pushButton_asin->setFont(font1);

        gridLayout_2->addWidget(pushButton_asin, 4, 1, 1, 1);

        pushButton_tan = new QPushButton(layoutWidget);
        pushButton_tan->setObjectName(QString::fromUtf8("pushButton_tan"));
        sizePolicy.setHeightForWidth(pushButton_tan->sizePolicy().hasHeightForWidth());
        pushButton_tan->setSizePolicy(sizePolicy);
        pushButton_tan->setFont(font1);

        gridLayout_2->addWidget(pushButton_tan, 4, 4, 1, 1);

        pushButton_C = new QPushButton(layoutWidget);
        pushButton_C->setObjectName(QString::fromUtf8("pushButton_C"));
        sizePolicy.setHeightForWidth(pushButton_C->sizePolicy().hasHeightForWidth());
        pushButton_C->setSizePolicy(sizePolicy);
        pushButton_C->setFont(font1);

        gridLayout_2->addWidget(pushButton_C, 0, 5, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setFont(font1);

        gridLayout_2->addWidget(pushButton_4, 1, 2, 1, 1);

        pushButton_X = new QPushButton(centralwidget);
        pushButton_X->setObjectName(QString::fromUtf8("pushButton_X"));
        pushButton_X->setGeometry(QRect(10, 390, 67, 53));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_X->sizePolicy().hasHeightForWidth());
        pushButton_X->setSizePolicy(sizePolicy1);
        pushButton_X->setMinimumSize(QSize(67, 53));
        pushButton_X->setMaximumSize(QSize(67, 53));
        pushButton_X->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 572, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_exp->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_pi->setText(QCoreApplication::translate("MainWindow", "\317\200", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_AC->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_math_bracket_left->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_math_bracket_right->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_C->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_X->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
