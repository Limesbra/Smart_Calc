#include "mainwindow.h"

#include "./ui_mainwindow.h"

double numFirst;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(inputValue()));
  connect(ui->pushButton_math_bracket_left, SIGNAL(clicked()), this,
          SLOT(inputValue()));
  connect(ui->pushButton_math_bracket_right, SIGNAL(clicked()), this,
          SLOT(inputValue()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(inputFunction()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(inputFunction()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(inputFunction()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(inputFunction()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(inputFunction()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(inputFunction()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(inputFunction()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(inputFunction()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(inputFunction()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(inputFunction()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::inputValue() {
  QPushButton *button = (QPushButton *)sender();
  QString expression = (ui->resultPanel->text() + button->text());

  ui->resultPanel->setText(expression);
}

void MainWindow::inputFunction() {
  QPushButton *button = (QPushButton *)sender();
  QString expression = (ui->resultPanel->text() + button->text() + "(");

  ui->resultPanel->setText(expression);
}

void MainWindow::on_pushButton_AC_clicked() { ui->resultPanel->setText(""); }

void MainWindow::on_pushButton_C_clicked() {
  QString expression = ui->resultPanel->text();
  expression.chop(1);
  ui->resultPanel->setText(expression);
}

void MainWindow::on_pushButton_sqrt_clicked() {
  QString expression = (ui->resultPanel->text() + "sqrt(");

  ui->resultPanel->setText(expression);
}

void MainWindow::on_pushButton_pi_clicked() {
  QString expression = (ui->resultPanel->text() + "pi");

  ui->resultPanel->setText(expression);
}

void MainWindow::on_pushButton_equal_clicked() {
  double expression_for_x = 0.0;
  QString expression = (ui->resultPanel->text().remove(" "));
  std::string expression_cpp = expression.toStdString();
  char *expression_c = (char *)expression_cpp.c_str();
  expression_for_x = (ui->x_value->text().toDouble());
  double result = 0;
  int error = S21_SmartCalc(expression_c, expression_for_x, &result);
  if (error == 0) {
    QString answer = QString::number(result, 'f', 7);
    ui->resultPanel->setText(answer);
  } else {
    QString answer = "ERROR";
    ui->resultPanel->setText(answer);
  }
}

void MainWindow::on_Create_graph_clicked() {
  ui->graph_place->clearGraphs();
  x.clear();
  y.clear();
  QString expression = (ui->resultPanel->text().remove(" "));
  std::string expression_cpp = expression.toStdString();
  char *expression_c = (char *)expression_cpp.c_str();
  double xBegin = (ui->From_x->text().toDouble());
  double xEnd = (ui->To_x->text().toDouble());
  double yBegin = (ui->From_Y->text().toDouble());
  double yEnd = (ui->To_Y->text().toDouble());
  double dValue = 500.0;
  double expression_for_x = xBegin;
  double result = 0;
  int error = 0;
  ui->graph_place->xAxis->setRange(xBegin, xEnd);
  ui->graph_place->yAxis->setRange(yBegin, yEnd);
  for (int i = 0; i <= dValue; i++) {
    error = S21_SmartCalc(expression_c, expression_for_x, &result);
    x.push_back(expression_for_x);
    y.push_back(result);
    expression_for_x += (xEnd - xBegin) / dValue;
  }
  if (error == 0) {
    ui->graph_place->addGraph();
    ui->graph_place->graph(0)->setData(x, y);
    ui->graph_place->replot();
  }
}

void MainWindow::on_pushButton_differentiated_clicked() {
  ui->listWidget->clear();
  double year = (ui->year->text().toDouble());
  double percent = (ui->percent->text().toDouble());
  double period = year * 12;
  double size = (ui->money->text().toDouble());
  double ante = percent / (100.0 * 12);
  double mDebt = size / period;
  double total = 0.0;
  double overpay = 0.0;
  double *payt = (double *)calloc(sizeof(double), period);
  int *nPayment = (int *)calloc(sizeof(int), period);
  creditCalcDif(size, ante, mDebt, payt, nPayment, &total, &overpay);
  for (int i = 0; i < period; i++) {
    QString count = QString::number(nPayment[i]) + '.' + "     ";
    QString widget = count + QString::number(payt[i], 'f', 2) + '\n';
    ui->listWidget->addItem(widget);
  }
  QString fOverpay = QString::number(overpay, 'f', 2);
  ui->lineEdit_2->setText(fOverpay);
  QString fTotal = QString::number(total, 'f', 2);
  ui->lineEdit_3->setText(fTotal);
  free(payt);
  free(nPayment);
}

void MainWindow::on_pushButton_annuity_clicked() {
  ui->listWidget->clear();
  double year = (ui->year->text().toDouble());
  double percent = (ui->percent->text().toDouble());
  double period = year * 12.0;
  double size = (ui->money->text().toDouble());
  double ante = percent / (100.0 * 12);
  double total = 0.0;
  double overpay = 0.0;
  double result = 0.0;
  creditCalcAnnuity(size, ante, period, &total, &overpay, &result);
  QString count = "ежемесячный платеж ";
  QString widget = count + QString::number(result, 'f', 2) + '\n';
  ui->listWidget->addItem(widget);
  QString fOverpay = QString::number(overpay, 'f', 2);
  ui->lineEdit_2->setText(fOverpay);
  QString fTotal = QString::number(total, 'f', 2);
  ui->lineEdit_3->setText(fTotal);
}
