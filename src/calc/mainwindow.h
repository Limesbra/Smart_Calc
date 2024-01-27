#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

extern "C" {
#include "../SmartCalc_v1.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  QVector<double> x, y;

 private slots:
  void inputValue();
  void inputFunction();
  //    void on_pushButton_dot_clicked();
  //    void hardExpression();
  void on_pushButton_AC_clicked();
  void on_pushButton_C_clicked();
  void on_pushButton_sqrt_clicked();
  void on_pushButton_pi_clicked();
  void on_pushButton_equal_clicked();
  void on_Create_graph_clicked();
  void on_pushButton_differentiated_clicked();
  void on_pushButton_annuity_clicked();
};
#endif  // MAINWINDOW_H
