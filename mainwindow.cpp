//
// Created by pentasteve on 8/22/21.
//

#include "mainwindow.h"


void MainWindow::setupUi(QMainWindow *MainWindow){
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(863, 600);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(0, 0, 861, 601));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    destX = new QLineEdit(tab);
    destX->setObjectName(QString::fromUtf8("destX"));
    destX->setGeometry(QRect(55, 2, 113, 26));
    label = new QLabel(tab);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(5, 5, 48, 18));
    destZ = new QLineEdit(tab);
    destZ->setObjectName(QString::fromUtf8("destZ"));
    destZ->setGeometry(QRect(235, 2, 113, 26));
    label_2 = new QLabel(tab);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(185, 5, 48, 18));
    calculateButton = new QPushButton(tab);
    calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
    calculateButton->setGeometry(QRect(365, 2, 80, 26));
    connect(calculateButton, &QPushButton::released, this, calculateftl420());
    label_3 = new QLabel(tab);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(5, 35, 63, 18));
    alignX = new QLineEdit(tab);
    alignX->setObjectName(QString::fromUtf8("alignX"));
    alignX->setGeometry(QRect(70, 32, 98, 26));
    label_4 = new QLabel(tab);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(185, 35, 63, 18));
    alignZ = new QLineEdit(tab);
    alignZ->setObjectName(QString::fromUtf8("alignZ"));
    alignZ->setGeometry(QRect(250, 32, 98, 26));
    label_5 = new QLabel(tab);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(365, 35, 63, 18));
    maxTNT = new QLineEdit(tab);
    maxTNT->setObjectName(QString::fromUtf8("maxTNT"));
    maxTNT->setGeometry(QRect(430, 32, 61, 26));
    ListWidget420 = new QListWidget(tab);
    ListWidget420->setObjectName(QString::fromUtf8("ListWidget420"));
    ListWidget420->setGeometry(QRect(0, 62, 860, 508));
    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    destX_621 = new QLineEdit(tab_2);
    destX_621->setObjectName(QString::fromUtf8("destX_621"));
    destX_621->setGeometry(QRect(55, 2, 113, 26));
    label1 = new QLabel(tab_2);
    label1->setObjectName(QString::fromUtf8("label1"));
    label1->setGeometry(QRect(5, 5, 48, 18));
    destZ_621 = new QLineEdit(tab_2);
    destZ_621->setObjectName(QString::fromUtf8("destZ_621"));
    destZ_621->setGeometry(QRect(235, 2, 113, 26));
    label_21 = new QLabel(tab_2);
    label_21->setObjectName(QString::fromUtf8("label_21"));
    label_21->setGeometry(QRect(185, 5, 48, 18));
    calculateButton_621 = new QPushButton(tab_2);
    calculateButton_621->setObjectName(QString::fromUtf8("calculateButton_621"));
    calculateButton_621->setGeometry(QRect(365, 2, 80, 26));
    label_31 = new QLabel(tab_2);
    label_31->setObjectName(QString::fromUtf8("label_31"));
    label_31->setGeometry(QRect(5, 35, 63, 18));
    alignX_621 = new QLineEdit(tab_2);
    alignX_621->setObjectName(QString::fromUtf8("alignX_621"));
    alignX_621->setGeometry(QRect(70, 32, 98, 26));
    label_41 = new QLabel(tab_2);
    label_41->setObjectName(QString::fromUtf8("label_41"));
    label_41->setGeometry(QRect(185, 35, 63, 18));
    alignZ_621 = new QLineEdit(tab_2);
    alignZ_621->setObjectName(QString::fromUtf8("alignZ_621"));
    alignZ_621->setGeometry(QRect(250, 32, 98, 26));
    label_51 = new QLabel(tab_2);
    label_51->setObjectName(QString::fromUtf8("label_51"));
    label_51->setGeometry(QRect(365, 35, 63, 18));
    maxTNT_621 = new QLineEdit(tab_2);
    maxTNT_621->setObjectName(QString::fromUtf8("maxTNT_621"));
    maxTNT_621->setGeometry(QRect(430, 32, 61, 26));
    tabWidget->addTab(tab_2, QString());
    tab_3 = new QWidget();
    tab_3->setObjectName(QString::fromUtf8("tab_3"));
    tabWidget->addTab(tab_3, QString());
    MainWindow->setCentralWidget(centralwidget);

    retranslateUi(MainWindow);

    tabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MainWindow);
}

void MainWindow::retranslateUi(QMainWindow *MainWindow) const {
    MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    label->setText(QCoreApplication::translate("MainWindow", "Dest X:", nullptr));
    label_2->setText(QCoreApplication::translate("MainWindow", "Dest Z:", nullptr));
    calculateButton->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
    label_3->setText(QCoreApplication::translate("MainWindow", "Aligner X:", nullptr));
    label_4->setText(QCoreApplication::translate("MainWindow", "Aligner Z:", nullptr));
    label_5->setText(QCoreApplication::translate("MainWindow", "Max TNT:", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "420/420-69 FTL", nullptr));
    label1->setText(QCoreApplication::translate("MainWindow", "Dest X:", nullptr));
    label_21->setText(QCoreApplication::translate("MainWindow", "Dest Z:", nullptr));
    calculateButton_621->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
    label_31->setText(QCoreApplication::translate("MainWindow", "Aligner X:", nullptr));
    label_41->setText(QCoreApplication::translate("MainWindow", "Aligner Z:", nullptr));
    label_51->setText(QCoreApplication::translate("MainWindow", "Max TNT:", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "621 FTL", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Autoload FTL (coming soon)", nullptr));
}

void MainWindow::calculateftl420() {
    pearl::calculate420();
}
