#include "mainwindow.h"
#include "./ui_mainwindow.h"

double numFirst;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui -> pushButton_0, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_1, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_2, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_3, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_4, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_5, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_6, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_7, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_8, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_9, SIGNAL(clicked()), this, SLOT(inputValue()));
//    connect(ui -> pushButton_sign, SIGNAL(clicked()), this, SLOT(operations()));
//    connect(ui -> pushButton_percent, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_plus, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_minus, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_mult, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_div, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_X, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_dot, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_pi, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_exp, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_math_bracket_left, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_math_bracket_right, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_sin, SIGNAL(clicked()), this, SLOT(inputFunction()));
    connect(ui -> pushButton_asin, SIGNAL(clicked()), this, SLOT(inputFunction()));
    connect(ui -> pushButton_cos, SIGNAL(clicked()), this, SLOT(inputFunction()));
    connect(ui -> pushButton_acos, SIGNAL(clicked()), this, SLOT(inputFunction()));
    connect(ui -> pushButton_tan, SIGNAL(clicked()), this, SLOT(inputFunction()));
    connect(ui -> pushButton_atan, SIGNAL(clicked()), this, SLOT(inputFunction()));
    connect(ui -> pushButton_ln, SIGNAL(clicked()), this, SLOT(inputFunction()));
    connect(ui -> pushButton_log, SIGNAL(clicked()), this, SLOT(inputFunction()));
    connect(ui -> pushButton_sqrt, SIGNAL(clicked()), this, SLOT(inputFunction()));
    connect(ui -> pushButton_pow, SIGNAL(clicked()), this, SLOT(inputFunction()));
    connect(ui -> pushButton_mod, SIGNAL(clicked()), this, SLOT(inputFunction()));

//    ui -> pushButton_plus -> setCheckable(true);
//    ui -> pushButton_minus -> setCheckable(true);
//    ui -> pushButton_mult -> setCheckable(true);
//    ui -> pushButton_div -> setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputValue()
{

    QPushButton *button = (QPushButton *) sender();
    QString expression = (ui ->resultPanel->text()+button->text());

    ui->resultPanel->setText(expression);
}

void MainWindow::inputFunction()
{
    QPushButton *button = (QPushButton *) sender();
    QString expression = (ui ->resultPanel->text()+button->text() + "(");


    ui->resultPanel->setText(expression);
}
//void MainWindow::hardExpression()
//{
//    QPushButton *button = (QPushButton *) sender();
//    if(ui ->resultPanel->text() == "e"){
//        ui -> resultPanel -> setText(ui->resultPanel->text()+"e"); //2.7182818
//    }else if(ui ->resultPanel->text() == "pi"){
//        ui -> resultPanel -> setText(ui->resultPanel->text()+"pi"); //3.1415926
//    }
//    ui -> resultPanel -> setText(expression);
//    QPushButton *button = (QPushButton *) sender();
//    QString expression;
//    expression = (ui ->resultPanel->text()+button->text());

//    ui -> resultPanel -> setText(expression);
//}

//void MainWindow::on_pushButton_dot_clicked()
//{
//    if(!(ui -> resultPanel ->text().contains('.')))
//        ui -> resultPanel -> setText(ui->resultPanel->text()+".");
//}


void MainWindow::on_pushButton_AC_clicked()
{
    ui->resultPanel->setText("");
}


void MainWindow::on_pushButton_C_clicked()
{
    QString expression = ui->resultPanel->text();
    expression.chop(1);
    ui->resultPanel->setText(expression);
}

