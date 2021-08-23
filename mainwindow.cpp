//
// Created by pentasteve on 8/22/21.
//

#include "mainwindow.h"


void MainWindow::setupUi(QMainWindow *MainWindow){

    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(861, 600);


    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(0, 0, 861, 601));
    //tabWidget->setSizePolicy();
    QPalette palette;
    QBrush brush(QColor(255, 255, 255, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(32, 32, 32, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush1);
    QBrush brush2(QColor(48, 48, 48, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Light, brush2);
    QBrush brush3(QColor(40, 40, 40, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
    QBrush brush4(QColor(16, 16, 16, 255));
    brush4.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
    QBrush brush5(QColor(22, 22, 22, 255));
    brush5.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
    palette.setBrush(QPalette::Active, QPalette::Text, brush);
    palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
    palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    QBrush brush6(QColor(0, 0, 0, 255));
    brush6.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Base, brush6);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
    palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
    QBrush brush7(QColor(255, 255, 220, 255));
    brush7.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
    palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
    QBrush brush8(QColor(255, 255, 255, 128));
    brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
    palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
    palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
    palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
    palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
    palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
    palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
    palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
    palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
    palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
    tabWidget->setPalette(palette);
    tabWidget->setAutoFillBackground(true);
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
    connect(calculateButton, &QPushButton::released, this, &MainWindow::calculateftl420);
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
    scrollArea420 = new QScrollArea(tab);
    scrollArea420->setObjectName(QString::fromUtf8("scrollArea420"));
    scrollArea420->setGeometry(QRect(3, 62, 850, 481));
    scrollArea420->setWidgetResizable(true);
    scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 848, 479));
    frame = new QFrame(scrollAreaWidgetContents);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setGeometry(QRect(0, 0, 841, 26));
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Plain);
    frame->setLineWidth(0);
    label_6 = new QLabel(frame);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(76, 4, 761, 18));
    label_6->setLineWidth(0);
    pushButton_2 = new QPushButton(frame);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(0, 0, 31, 26));
    pushButton = new QPushButton(frame);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(32, 0, 41, 26));
    scrollArea420->setWidget(scrollAreaWidgetContents);
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

//621: 186.34881785360997
//420: 185.34881785360997
void MainWindow::calculateftl420() {
    int maxT = this->maxTNT->text().toInt();
    double desX = this->destX->text().toDouble();
    double desZ = this->destZ->text().toDouble();
    int alX = this->alignX->text().toInt();
    int alZ = this->alignZ->text().toInt();
    if (maxT != NULL && desX != NULL && desZ != NULL && alX != NULL && alZ != NULL) {
        pearl::calculateGenericFtl(185.34881785360997F, 185.5F, maxT, desX, desZ, alX, alZ,0.005F);
    }
}