/********************************************************************************
** Form generated from reading UI file 'PearlCalculatorXjPJNw.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PEARLCALCULATORXJPJNW_H
#define PEARLCALCULATORXJPJNW_H

#include <QObject>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <QtWidgets/QScrollArea>
#include <QSizePolicy>
#include "pearl.h"
#include "dest.h"
#include <string>
#include <list>
#include <QtWidgets/QVBoxLayout>
#include <sstream>
#include <QButtonGroup>
//#include "main.h"

namespace Ui {
    //class setupUi;
} // namespace Ui


class MainWindow : public QObject
{
    Q_OBJECT


public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab420;


    //labels 1-5 are for 420
    QLabel *dXlabel_420;
    QLabel *dZlabel_420;
    QLabel *aXlabel_420;
    QLabel *aZlabel_420;
    QLabel *maxTntLabel_420;

    QLineEdit *destX_420;
    QLineEdit *destZ_420;
    QLineEdit *alignX_420;
    QLineEdit *alignZ_420;
    QLineEdit *maxTNT_420;

    QPushButton *calcButton_420;
    QPushButton *chunkLoadButton_420;
    QPushButton *progButton_420;

    QScrollArea *scrollArea420;
    /*QWidget *scrollAreaWidgetContents;
    QFrame *frame;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton;*/

    //621 ftl stuff
    QWidget *tab621;

    QLabel *dXlabel_621;
    QLabel *dZlabel_621;
    QLabel *aXlabel_621;
    QLabel *aZlabel_621;
    QLabel *maxTntLabel_621;

    QLineEdit *destX_621;
    QLineEdit *destZ_621;
    QLineEdit *alignX_621;
    QLineEdit *alignZ_621;
    QLineEdit *maxTNT_621;


    QPushButton *calcButton_621;
    QPushButton *chunkLoadButton_621;
    QPushButton *progButton_621;

    QWidget *tab_3;
    std::vector<dest> destinations;

    QScrollArea *scrollArea621;

    QWidget *list;
    //std::vector<*QLabel>& info;
    QVBoxLayout *verticalLayout_2;
    QButtonGroup *radioButtons;

    dest *selected;
    //0 = nothing displayed, 1 = destinations displayed, 2 = chunk loading displayed, 3 = programming displayed
    int status = 0;
    void retranslateUi(QMainWindow *MainWindow) const; // retranslateUi

    //void initEventListeners();
    void setupUi(QMainWindow *MainWindow);
    void calculateftl420();
    void chunkLoad420();
    void prog420();
    void addItem(dest d, QWidget *widget, int o, QVBoxLayout *layout);
    void displayInfo(const std::vector<std::string>& s);
    dest getPressed();
};


#endif // PEARLCALCULATORXJPJNW_H
