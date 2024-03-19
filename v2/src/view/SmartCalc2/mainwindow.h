#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <iostream>

#include "../../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace calc {
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr, s21::Controller *controller = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  s21::Controller *controller_;

 private slots:
  void ButtonsConnect();
  void InputValue();
  void InputPi();
  void InputSqrt();
  void ClearDefenition();
  void DeleteLastSymbol();
  void ViewResult();
  void CreateGraph();
  void Annuity();
  void Differentiated();
};
}  // namespace calc
#endif  // MAINWINDOW_H
