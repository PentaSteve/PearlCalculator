#include <iostream>
#include <QApplication>
#include "main.h"
using namespace Ui;

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    std::cout << "1" << std::endl;
    QMainWindow w(nullptr);
    win.setupUi(&w);
    std::cout << "2" << std::endl;
    w.show();
    std::cout << win.calculateButton->isDown() << std::endl;
    //win.initEventListeners();

    return app.exec();//);
}

