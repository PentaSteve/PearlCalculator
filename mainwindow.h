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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <QSizePolicy>
#include "pearl.h"
//#include "main.h"

namespace Ui {
    class MainWindow;
} // namespace Ui


class MainWindow : public QObject
{
    Q_OBJECT
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *destX;
    QLabel *label;
    QLineEdit *destZ;
    QLabel *label_2;
    QPushButton *calculateButton;
    QLabel *label_3;
    QLineEdit *alignX;
    QLabel *label_4;
    QLineEdit *alignZ;
    QLabel *label_5;
    QLineEdit *maxTNT;
    QListWidget *ListWidget420;
    QWidget *tab_2;
    QLineEdit *destX_621;
    QLabel *label1;
    QLineEdit *destZ_621;
    QLabel *label_21;
    QPushButton *calculateButton_621;
    QLabel *label_31;
    QLineEdit *alignX_621;
    QLabel *label_41;
    QLineEdit *alignZ_621;
    QLabel *label_51;
    QLineEdit *maxTNT_621;
    QWidget *tab_3;

    void retranslateUi(QMainWindow *MainWindow) const; // retranslateUi

    //void initEventListeners();
    void setupUi(QMainWindow *MainWindow);
    void calculateftl420();
};


#endif // PEARLCALCULATORXJPJNW_H
