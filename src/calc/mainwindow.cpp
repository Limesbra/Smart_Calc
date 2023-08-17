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
    connect(ui -> pushButton_plus, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_minus, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_mult, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_div, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_X, SIGNAL(clicked()), this, SLOT(inputValue()));
    connect(ui -> pushButton_dot, SIGNAL(clicked()), this, SLOT(inputValue()));
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
    connect(ui -> pushButton_pow, SIGNAL(clicked()), this, SLOT(inputFunction()));
    connect(ui -> pushButton_mod, SIGNAL(clicked()), this, SLOT(inputFunction()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inputValue()
{

    QPushButton *button = (QPushButton *) sender();
    QString expression = (ui ->resultPanel->text()+button->text());
    QString expression_for_x = (ui ->x_value->text());

    ui->resultPanel->setText(expression);
    if(button->text() == "X"){
        ui->x_value->setText(expression_for_x);
    }
}

void MainWindow::inputFunction()
{
    QPushButton *button = (QPushButton *) sender();
    QString expression = (ui ->resultPanel->text()+button->text() + "(");


    ui->resultPanel->setText(expression);
}

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


void MainWindow::on_pushButton_sqrt_clicked()
{
    QString expression = (ui ->resultPanel->text()+"sqrt(");

    ui->resultPanel->setText(expression);
}


void MainWindow::on_pushButton_pi_clicked()
{
    QString expression = (ui ->resultPanel->text()+"pi");

    ui->resultPanel->setText(expression);
}


void MainWindow::on_pushButton_equal_clicked()
{
    QString expression = (ui ->resultPanel->text().remove(" "));
    QString expression_for_x = (ui ->x_value->text());
    std::string expression_cpp = expression.toStdString();
    std::string expression_cpp_x = expression_for_x.toStdString();
    char *expression_c = (char *)expression_cpp.c_str();
    char *expression_c_x = (char *)expression_cpp_x.c_str();
    double result = 0;
    int error = S21_SmartCalc(expression_c, expression_c_x, &result);
    if(error == 0){
        QString expression = QString::number(result);
        ui->resultPanel->setText(expression);
    }
    else{
        QString expression = "ERROR";
        ui->resultPanel->setText(expression);
    }
}


