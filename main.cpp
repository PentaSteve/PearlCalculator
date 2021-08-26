#include <iostream>
#include <QApplication>
#include "mainwindow.h"
using namespace Ui;

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    //std::cout << "1" << std::endl;
    QMainWindow w(nullptr);
    MainWindow win;
    win.setupUi(&w);
    //std::cout << "2" << std::endl;
    w.show();
    //win.initEventListeners();
    std::cout.precision(16);
    return app.exec();//);
}

