#include "mainwindow.h"

#include "ui_mainwindow.h"

namespace calc {

MainWindow::MainWindow(QWidget *parent,
                       calc::Controller *controller)  // constructor
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  controller_ = controller;
  ui->resultPanel->setReadOnly(true);
  ui->x_value->setReadOnly(true);
  ui->resultPanel->setFocus();

  ButtonsConnect();
}

MainWindow::~MainWindow()  // destructor
{
  delete ui;
}

void MainWindow::InputValue() {
  QLineEdit *activeLineEdit =
      qobject_cast<QLineEdit *>(QApplication::focusWidget());
  QLineEdit *nameWidget = nullptr;
  if (activeLineEdit == ui->resultPanel)
    nameWidget = ui->resultPanel;
  else
    nameWidget = ui->x_value;
  QPushButton *button = (QPushButton *)sender();
  if (button->text() == "cos" || button->text() == "acos" ||
      button->text() == "sin" || button->text() == "asin" ||
      button->text() == "tan" || button->text() == "atan" ||
      button->text() == "log" || button->text() == "ln" ||
      button->text() == "*" || button->text() == "/" || button->text() == "^" ||
      button->text() == "(" || button->text() == ")" || button->text() == "%" ||
      button->text() == "X") {
    if (nameWidget == ui->resultPanel) {
      if (button->text() == "cos" || button->text() == "acos" ||
          button->text() == "sin" || button->text() == "asin" ||
          button->text() == "tan" || button->text() == "atan" ||
          button->text() == "log" || button->text() == "ln") {
        QString expression = (nameWidget->text() + button->text() + "(");
        nameWidget->setText(expression);
      } else {
        QString expression = (nameWidget->text() + button->text());
        nameWidget->setText(expression);
      }
    }
  } else {
    QString expression = (nameWidget->text() + button->text());
    nameWidget->setText(expression);
  }
}

void MainWindow::InputPi() {
  QLineEdit *activeLineEdit =
      qobject_cast<QLineEdit *>(QApplication::focusWidget());
  QLineEdit *nameWidget = nullptr;
  if (activeLineEdit == ui->resultPanel)
    nameWidget = ui->resultPanel;
  else
    nameWidget = ui->x_value;
  QString expression = (nameWidget->text() + "3.1415926");
  nameWidget->setText(expression);
}

void MainWindow::InputSqrt() {
  QLineEdit *activeLineEdit =
      qobject_cast<QLineEdit *>(QApplication::focusWidget());
  QLineEdit *nameWidget = nullptr;
  if (activeLineEdit == ui->resultPanel)
    nameWidget = ui->resultPanel;
  else
    return;
  QString expression = (nameWidget->text() + "sqrt(");
  nameWidget->setText(expression);
}

void MainWindow::ClearDefenition() {
  QLineEdit *activeLineEdit =
      qobject_cast<QLineEdit *>(QApplication::focusWidget());
  QLineEdit *nameWidget = nullptr;
  if (activeLineEdit == ui->resultPanel)
    nameWidget = ui->resultPanel;
  else
    nameWidget = ui->x_value;
  nameWidget->setText("");
}

void MainWindow::DeleteLastSymbol() {
  QLineEdit *activeLineEdit =
      qobject_cast<QLineEdit *>(QApplication::focusWidget());
  QLineEdit *nameWidget = nullptr;
  if (activeLineEdit == ui->resultPanel)
    nameWidget = ui->resultPanel;
  else
    nameWidget = ui->x_value;
  QString expression = nameWidget->text();
  expression.chop(1);
  nameWidget->setText(expression);
}

void MainWindow::ViewResult() {
  if (ui->resultPanel->text() != "") {
    std::string expr = ui->resultPanel->text().toStdString();
    std::string X = ui->x_value->text().toStdString();
    if (X == "") X = "0";
    int err = controller_->LetsCalc(expr, X);
    if (!err) {
      QString answer =
          QString::number(controller_->GetResultFromModel(), 'g', 8);
      ui->resultPanel->setText(answer);
    } else {
      QString answer = QString::fromStdString(controller_->GetErrorFromModel());
      ui->resultPanel->setText(answer);
    }
  }
}

void MainWindow::CreateGraph() {
  ui->graph_place->clearGraphs();
  std::string expr = ui->resultPanel->text().toStdString();
  if (!expr.empty()) {
    double xBegin = (ui->From_x->text().toDouble());
    double xEnd = (ui->To_x->text().toDouble());
    double yBegin = (ui->From_Y->text().toDouble());
    double yEnd = (ui->To_Y->text().toDouble());
    int err = controller_->LetsGraph(expr, xBegin, xEnd, yBegin, yEnd);
    if (!err) {
      ui->graph_place->xAxis->setRange(xBegin, xEnd);
      ui->graph_place->yAxis->setRange(yBegin, yEnd);
      std::vector<double> vec1 = controller_->GetVectorXfromModel();
      std::vector<double> vec2 = controller_->GetVectorYfromModel();
      QVector<double> x = QVector<double>(vec1.begin(), vec1.end());
      QVector<double> y = QVector<double>(vec2.begin(), vec2.end());
      ui->graph_place->addGraph();
      ui->graph_place->graph(0)->setData(x, y);
      ui->graph_place->replot();
    } else {
      QString answer = QString::fromStdString(controller_->GetErrorFromModel());
      ui->resultPanel->setText(answer);
    }
  }
}

void MainWindow::Annuity() {
  ui->listWidget->clear();
  std::vector<double> dataCredit;
  dataCredit.push_back(ui->money->text().toDouble());  // размер суммы
  dataCredit.push_back(ui->year->text().toDouble());  // период кредита в годах
  dataCredit.push_back(ui->percent->text().toDouble());  // процент
  controller_->LetsAnnuity(dataCredit);
  QString widget = "ежемесячный платеж " +
                   QString::number(controller_->GetAnnuity().at(0), 'f', 2) +
                   '\n';
  ui->listWidget->addItem(widget);
  QString fOverpay = QString::number(controller_->GetAnnuity().at(2), 'f', 2);
  ui->lineEdit_2->setText(fOverpay);
  QString fTotal = QString::number(controller_->GetAnnuity().at(1), 'f', 2);
  ui->lineEdit_3->setText(fTotal);
}

void MainWindow::Differentiated() {
  ui->listWidget->clear();
  std::vector<double> dataCredit;
  dataCredit.push_back(ui->money->text().toDouble());  // размер суммы
  dataCredit.push_back(ui->year->text().toDouble());  // период кредита в годах
  dataCredit.push_back(ui->percent->text().toDouble());  // процент
  controller_->LetsDiff(dataCredit);
  auto vec = controller_->GetDiff();
  auto it = vec.begin();
  for (int i = -1; it != vec.end(); ++it, ++i) {
    if (i < 0) {
      QString fTotal = QString::number(*it, 'f', 2);
      ui->lineEdit_3->setText(fTotal);
      continue;
    }
    if (i < 1) {
      QString fOverpay = QString::number(*it, 'f', 2);
      ui->lineEdit_2->setText(fOverpay);
      continue;
    }
    QString count = QString::number(i) + '.' + "     ";
    QString widget = count + QString::number(*it, 'f', 2) + '\n';
    ui->listWidget->addItem(widget);
  }
}

void MainWindow::ButtonsConnect() {
  connect(ui->pushButton_C, SIGNAL(clicked()), this, SLOT(DeleteLastSymbol()));
  connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(ClearDefenition()));
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_math_bracket_left, SIGNAL(clicked()), this,
          SLOT(InputValue()));
  connect(ui->pushButton_math_bracket_right, SIGNAL(clicked()), this,
          SLOT(InputValue()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(InputValue()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(InputSqrt()));
  connect(ui->pushButton_pi, SIGNAL(clicked()), this, SLOT(InputPi()));
  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(ViewResult()));
  connect(ui->Create_graph, SIGNAL(clicked()), this, SLOT(CreateGraph()));
  connect(ui->pushButton_annuity, SIGNAL(clicked()), this, SLOT(Annuity()));
  connect(ui->pushButton_differentiated, SIGNAL(clicked()), this,
          SLOT(Differentiated()));
};

}  // namespace calc
