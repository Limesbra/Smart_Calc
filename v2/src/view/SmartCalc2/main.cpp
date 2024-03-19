#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  calc::Model model;
  calc::Controller controller(&model);
  QApplication a(argc, argv);
  calc::MainWindow w(nullptr, &controller);
  w.setWindowTitle("SmartCalc_v2.0");
  w.show();
  return a.exec();
}
