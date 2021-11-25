//
// Created by pentasteve on 8/22/21.
//

#include <iostream>
#include <QtWidgets/QVBoxLayout>
#include <sstream>
#include "mainwindow.h"
#include <chrono>

void MainWindow::setupUi(QMainWindow *MainWindow){

    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("setupUi"));
    MainWindow->resize(861, 600);


    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(0, 0, 861, 601));

    qApp->setStyle(QStyleFactory::create("fusion"));
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
    qApp->setPalette(palette);

    // 420 FTL tab
    tab420 = new QWidget();
    tab420->setObjectName(QString::fromUtf8("tab420"));;

    //labels for 420 tab
    dXlabel_420 = new QLabel(tab420);
    dXlabel_420->setObjectName(QString::fromUtf8("dXlabel_420"));
    dXlabel_420->setGeometry(QRect(5, 5, 48, 18));
    dZlabel_420 = new QLabel(tab420);
    dZlabel_420->setObjectName(QString::fromUtf8("dZlabel_420"));
    dZlabel_420->setGeometry(QRect(185, 5, 48, 18));
    aXlabel_420 = new QLabel(tab420);
    aXlabel_420->setObjectName(QString::fromUtf8("aXlabel_420"));
    aXlabel_420->setGeometry(QRect(5, 35, 63, 18));
    aZlabel_420 = new QLabel(tab420);
    aZlabel_420->setObjectName(QString::fromUtf8("aZlabel_420"));
    aZlabel_420->setGeometry(QRect(185, 35, 63, 18));
    maxTntLabel_420 = new QLabel(tab420);
    maxTntLabel_420->setObjectName(QString::fromUtf8("maxTntLabel_420"));
    maxTntLabel_420->setGeometry(QRect(365, 35, 63, 18));
    sortByLabel_420 = new QLabel(tab420);
    sortByLabel_420->setObjectName(QString::fromUtf8("sortByLabel_420"));
    sortByLabel_420->setGeometry(QRect(508, 35, 51, 18));

    //input boxes for 420 tab
    destX_420 = new QLineEdit(tab420);
    destX_420->setObjectName(QString::fromUtf8("destX_420"));
    destX_420->setGeometry(QRect(55, 2, 113, 26));
    destZ_420 = new QLineEdit(tab420);
    destZ_420->setObjectName(QString::fromUtf8("destZ_420"));
    destZ_420->setGeometry(QRect(235, 2, 113, 26));
    alignX_420 = new QLineEdit(tab420);
    alignX_420->setObjectName(QString::fromUtf8("alignX_420"));
    alignX_420->setGeometry(QRect(70, 32, 98, 26));
    alignZ_420 = new QLineEdit(tab420);
    alignZ_420->setObjectName(QString::fromUtf8("alignZ_420"));
    alignZ_420->setGeometry(QRect(250, 32, 98, 26));
    maxTNT_420 = new QLineEdit(tab420);
    maxTNT_420->setObjectName(QString::fromUtf8("maxTNT_420"));
    maxTNT_420->setGeometry(QRect(430, 32, 61, 26));

    //buttons for 420 tab
    calcButton_420 = new QPushButton(tab420);
    calcButton_420->setObjectName(QString::fromUtf8("calcButton_420"));
    calcButton_420->setGeometry(QRect(365, 2, 80, 26));
    connect(calcButton_420, &QPushButton::released, this, &MainWindow::calculateftl420);
    chunkLoadButton_420 = new QPushButton(tab420);
    chunkLoadButton_420->setObjectName(QString::fromUtf8("chunkLoadButton_420"));
    chunkLoadButton_420->setGeometry(QRect(462, 2, 111, 26));
    connect(chunkLoadButton_420, &QPushButton::released, this, &MainWindow::chunkLoad420);\
    progButton_420 = new QPushButton(tab420);
    progButton_420->setObjectName(QString::fromUtf8("progButton_420"));
    progButton_420->setGeometry(QRect(590, 2, 81, 26));
    connect(progButton_420, &QPushButton::released, this, &MainWindow::prog420);

    //sort by radio buttons for 420 tab
    sortButtons = new QButtonGroup(this);
    sbClosest_420 = new QRadioButton(tab420);
    sbClosest_420->setObjectName(QString::fromUtf8("sbClosest"));
    sbClosest_420->setGeometry(QRect(569, 33, 71, 24));
    sortButtons->addButton(sbClosest_420,0);
    sbLeastGt_420 = new QRadioButton(tab420);
    sbLeastGt_420->setObjectName(QString::fromUtf8("sbLeastGt_420"));
    sbLeastGt_420->setGeometry(QRect(741, 33, 81, 24));
    sortButtons->addButton(sbLeastGt_420,1);
    sbLeastTnt_420 = new QRadioButton(tab420);
    sbLeastTnt_420->setObjectName(QString::fromUtf8("sbLeastTnt_420"));
    sbLeastTnt_420->setGeometry(QRect(650, 33, 81, 24));
    sortButtons->addButton(sbLeastTnt_420,2);
    sortButtons->button(0)->setChecked(true);

    //scroll area for 420 tab
    scrollArea420 = new QScrollArea(tab420);
    scrollArea420->setObjectName(QString::fromUtf8("scrollArea420"));
    scrollArea420->setGeometry(QRect(3, 62, 850, 481));


    scrollArea420->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea420->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea420->setWidgetResizable(true);
    tabWidget->addTab(tab420, QString());


    // 621 FTL
    tab621 = new QWidget();
    tab621->setObjectName(QString::fromUtf8("tab621"));

    //labels for 621 tab
    dXlabel_621 = new QLabel(tab621);
    dXlabel_621->setObjectName(QString::fromUtf8("dXlabel_420"));
    dXlabel_621->setGeometry(QRect(5, 5, 48, 18));
    dZlabel_621 = new QLabel(tab621);
    dZlabel_621->setObjectName(QString::fromUtf8("dZlabel_420"));
    dZlabel_621->setGeometry(QRect(185, 5, 48, 18));
    aXlabel_621 = new QLabel(tab621);
    aXlabel_621->setObjectName(QString::fromUtf8("aXlabel_621"));
    aXlabel_621->setGeometry(QRect(5, 35, 63, 18));
    aZlabel_621 = new QLabel(tab621);
    aZlabel_621->setObjectName(QString::fromUtf8("aZlabel_621"));
    aZlabel_621->setGeometry(QRect(185, 35, 63, 18));
    maxTntLabel_621 = new QLabel(tab621);
    maxTntLabel_621->setObjectName(QString::fromUtf8("maxTntLabel_621"));
    maxTntLabel_621->setGeometry(QRect(365, 35, 63, 18));

    //input boxes for 621 tab
    destX_621 = new QLineEdit(tab621);
    destX_621->setObjectName(QString::fromUtf8("destX_420"));
    destX_621->setGeometry(QRect(55, 2, 113, 26));
    destZ_621= new QLineEdit(tab621);
    destZ_621->setObjectName(QString::fromUtf8("destZ_420"));
    destZ_621->setGeometry(QRect(235, 2, 113, 26));
    alignX_621 = new QLineEdit(tab621);
    alignX_621->setObjectName(QString::fromUtf8("alignX_621"));
    alignX_621->setGeometry(QRect(70, 32, 98, 26));
    alignZ_621 = new QLineEdit(tab621);
    alignZ_621->setObjectName(QString::fromUtf8("alignZ_621"));
    alignZ_621->setGeometry(QRect(250, 32, 98, 26));
    maxTNT_621 = new QLineEdit(tab621);
    maxTNT_621->setObjectName(QString::fromUtf8("maxTNT_621"));
    maxTNT_621->setGeometry(QRect(430, 32, 61, 26));

    //buttons for 621 tab
    calcButton_621 = new QPushButton(tab621);
    calcButton_621->setObjectName(QString::fromUtf8("calcButton_420"));
    calcButton_621->setGeometry(QRect(365, 2, 80, 26));
    connect(calcButton_621, &QPushButton::released, this, &MainWindow::calculateftl420);
    chunkLoadButton_621 = new QPushButton(tab621);
    chunkLoadButton_621->setObjectName(QString::fromUtf8("chunkLoadButton_621"));
    chunkLoadButton_621->setGeometry(QRect(462, 2, 111, 26));
    connect(chunkLoadButton_621, &QPushButton::released, this, &MainWindow::chunkLoad420);
    progButton_621 = new QPushButton(tab621);
    progButton_621->setObjectName(QString::fromUtf8("progButton_631"));
    progButton_621->setGeometry(QRect(590, 2, 81, 26));
    connect(progButton_621, &QPushButton::released, this, &MainWindow::prog420);

    //scroll area for 621 tab
    scrollArea621 = new QScrollArea(tab621);
    scrollArea621->setObjectName(QString::fromUtf8("scrollArea621"));
    scrollArea621->setGeometry(QRect(3, 62, 850, 481));
    scrollArea621->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea621->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea621->setWidgetResizable(true);
    //tabWidget->addTab(tab621, QString());

    //V360
    tabV360 = new QWidget();
    tabV360->setObjectName(QString::fromUtf8("tabV360"));;

    //labels for V360 tab
    dXlabel_V360 = new QLabel(tabV360);
    dXlabel_V360->setObjectName(QString::fromUtf8("dXlabel_V360"));
    dXlabel_V360->setGeometry(QRect(5, 5, 48, 18));
    dZlabel_V360 = new QLabel(tabV360);
    dZlabel_V360->setObjectName(QString::fromUtf8("dZlabel_V360"));
    dZlabel_V360->setGeometry(QRect(185, 5, 48, 18));
    aXlabel_V360 = new QLabel(tabV360);
    aXlabel_V360->setObjectName(QString::fromUtf8("aXlabel_V360"));
    aXlabel_V360->setGeometry(QRect(5, 35, 63, 18));
    aZlabel_V360 = new QLabel(tabV360);
    aZlabel_V360->setObjectName(QString::fromUtf8("aZlabel_V360"));
    aZlabel_V360->setGeometry(QRect(185, 35, 63, 18));
    searchRangeLabel_V360 = new QLabel(tabV360);
    searchRangeLabel_V360->setObjectName(QString::fromUtf8("searchRangeLabel_V360"));
    searchRangeLabel_V360->setGeometry(QRect(365, 35, 63, 18));
    sortByLabel_V360 = new QLabel(tabV360);
    sortByLabel_V360->setObjectName(QString::fromUtf8("sortByLabel_V360"));
    sortByLabel_V360->setGeometry(QRect(508, 35, 51, 18));

    //input boxes for V360 tab
    destX_V360 = new QLineEdit(tabV360);
    destX_V360->setObjectName(QString::fromUtf8("destX_V360"));
    destX_V360->setGeometry(QRect(55, 2, 113, 26));
    destZ_V360 = new QLineEdit(tabV360);
    destZ_V360->setObjectName(QString::fromUtf8("destZ_V360"));
    destZ_V360->setGeometry(QRect(235, 2, 113, 26));
    alignX_V360 = new QLineEdit(tabV360);
    alignX_V360->setObjectName(QString::fromUtf8("alignX_V360"));
    alignX_V360->setGeometry(QRect(70, 32, 98, 26));
    alignZ_V360 = new QLineEdit(tabV360);
    alignZ_V360->setObjectName(QString::fromUtf8("alignZ_V360"));
    alignZ_V360->setGeometry(QRect(250, 32, 98, 26));
    searchRange_V360 = new QLineEdit(tabV360);
    searchRange_V360->setObjectName(QString::fromUtf8("searchRange_V360"));
    searchRange_V360->setGeometry(QRect(430, 32, 61, 26));

    destX_V360->setText("-100041");
    destZ_V360->setText("-29975");
    alignX_V360->setText("-756");
    alignZ_V360->setText("29");
    searchRange_V360->setText("1");

    //buttons for V360 tab
    calcButton_V360 = new QPushButton(tabV360);
    calcButton_V360->setObjectName(QString::fromUtf8("calcButton_V360"));
    calcButton_V360->setGeometry(QRect(365, 2, 80, 26));
    connect(calcButton_V360, &QPushButton::released, this, &MainWindow::calculateftlV360);
    chunkLoadButton_V360 = new QPushButton(tabV360);
    chunkLoadButton_V360->setObjectName(QString::fromUtf8("chunkLoadButton_V360"));
    chunkLoadButton_V360->setGeometry(QRect(462, 2, 111, 26));
    connect(chunkLoadButton_V360, &QPushButton::released, this, &MainWindow::chunkLoadV360);
    progButton_V360 = new QPushButton(tabV360);
    progButton_V360->setObjectName(QString::fromUtf8("progButton_V360"));
    progButton_V360->setGeometry(QRect(590, 2, 81, 26));
    connect(progButton_V360, &QPushButton::released, this, &MainWindow::progV360);

    //sort by radio buttons for V360 tab
    sortButtons = new QButtonGroup(this);
    sbClosest_V360 = new QRadioButton(tabV360);
    sbClosest_V360->setObjectName(QString::fromUtf8("sbClosest"));
    sbClosest_V360->setGeometry(QRect(569, 33, 71, 24));
    sortButtons->addButton(sbClosest_V360,0);
    sbLeastGt_V360 = new QRadioButton(tabV360);
    sbLeastGt_V360->setObjectName(QString::fromUtf8("sbLeastGt_V360"));
    sbLeastGt_V360->setGeometry(QRect(741, 33, 81, 24));
    sortButtons->addButton(sbLeastGt_V360,1);
    sbLeastTnt_V360 = new QRadioButton(tabV360);
    sbLeastTnt_V360->setObjectName(QString::fromUtf8("sbLeastTnt_V360"));
    sbLeastTnt_V360->setGeometry(QRect(650, 33, 81, 24));
    sortButtons->addButton(sbLeastTnt_V360,2);
    sortButtons->button(0)->setChecked(true);

    //scroll area for V360 tab
    scrollAreaV360 = new QScrollArea(tabV360);
    scrollAreaV360->setObjectName(QString::fromUtf8("scrollAreaV360"));
    scrollAreaV360->setGeometry(QRect(3, 62, 850, 481));


    scrollAreaV360->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollAreaV360->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollAreaV360->setWidgetResizable(true);
    tabWidget->addTab(tabV360, QString());
    tab_3 = new QWidget();
    tab_3->setObjectName(QString::fromUtf8("tab621"));
    //tabWidget->addTab(tab_3, QString());
    MainWindow->setCentralWidget(centralwidget);

    retranslateUi(MainWindow);

    tabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MainWindow);
}

void MainWindow::retranslateUi(QMainWindow *MainWindow) const {
    MainWindow->setWindowTitle(QCoreApplication::translate("setupUi", "Pearl Calculator", nullptr));
    dXlabel_420->setText(QCoreApplication::translate("setupUi", "Dest X:", nullptr));
    dZlabel_420->setText(QCoreApplication::translate("setupUi", "Dest Z:", nullptr));
    aXlabel_420->setText(QCoreApplication::translate("setupUi", "Aligner X:", nullptr));
    aZlabel_420->setText(QCoreApplication::translate("setupUi", "Aligner Z:", nullptr));
    maxTntLabel_420->setText(QCoreApplication::translate("setupUi", "Max TNT:", nullptr));
    sortByLabel_420->setText(QCoreApplication::translate("setupUi", "Sort by:", nullptr));

    calcButton_420->setText(QCoreApplication::translate("setupUi", "Calculate", nullptr));
    chunkLoadButton_420->setText(QCoreApplication::translate("setupUi", "Chunk Loading", nullptr));
    progButton_420->setText(QCoreApplication::translate("setupUi", "Program", nullptr));

    sbClosest_420->setText(QCoreApplication::translate("setupUi", "dist*GT", nullptr));
    sbLeastGt_420->setText(QCoreApplication::translate("setupUi", "least TNT", nullptr));
    sbLeastTnt_420->setText(QCoreApplication::translate("setupUi", "least GT", nullptr));

    tabWidget->setTabText(tabWidget->indexOf(tab420), QCoreApplication::translate("setupUi", "420/420-69 FTL", nullptr));


    dXlabel_V360->setText(QCoreApplication::translate("setupUi", "Dest X:", nullptr));
    dZlabel_V360->setText(QCoreApplication::translate("setupUi", "Dest Z:", nullptr));
    aXlabel_V360->setText(QCoreApplication::translate("setupUi", "Aligner X:", nullptr));
    aZlabel_V360->setText(QCoreApplication::translate("setupUi", "Aligner Z:", nullptr));
    searchRangeLabel_V360->setText(QCoreApplication::translate("setupUi", "Range:", nullptr));
    sortByLabel_V360->setText(QCoreApplication::translate("setupUi", "Sort by:", nullptr));

    calcButton_V360->setText(QCoreApplication::translate("setupUi", "Calculate", nullptr));
    chunkLoadButton_V360->setText(QCoreApplication::translate("setupUi", "Chunk Loading", nullptr));
    progButton_V360->setText(QCoreApplication::translate("setupUi", "Program", nullptr));

    sbClosest_V360->setText(QCoreApplication::translate("setupUi", "dist*GT", nullptr));
    sbLeastGt_V360->setText(QCoreApplication::translate("setupUi", "least TNT", nullptr));
    sbLeastTnt_V360->setText(QCoreApplication::translate("setupUi", "least GT", nullptr));

    tabWidget->setTabText(tabWidget->indexOf(tabV360), QCoreApplication::translate("setupUi", "V360", nullptr));

    dXlabel_621->setText(QCoreApplication::translate("setupUi", "Dest X:", nullptr));
    dZlabel_621->setText(QCoreApplication::translate("setupUi", "Dest Z:", nullptr));
    aXlabel_621->setText(QCoreApplication::translate("setupUi", "Aligner X:", nullptr));
    aZlabel_621->setText(QCoreApplication::translate("setupUi", "Aligner Z:", nullptr));
    maxTntLabel_621->setText(QCoreApplication::translate("setupUi", "Max TNT:", nullptr));

    calcButton_621->setText(QCoreApplication::translate("setupUi", "Calculate", nullptr));
    chunkLoadButton_621->setText(QCoreApplication::translate("setupUi", "Chunk Loading", nullptr));
    progButton_621->setText(QCoreApplication::translate("setupUi", "Program", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab621), QCoreApplication::translate("setupUi", "621 FTL", nullptr));

    tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("setupUi", "Autoload FTL (coming soon\u2122)", nullptr));
}

//621: 186.34881785360997
//420: 185.34881785360997
void MainWindow::calculateftl420() {
    auto start = std::chrono::high_resolution_clock::now();


    int maxT = this->maxTNT_420->text().toInt();
    double desX = this->destX_420->text().toDouble();
    double desZ = this->destZ_420->text().toDouble();
    int alX = this->alignX_420->text().toInt();
    int alZ = this->alignZ_420->text().toInt();
    if (maxT != 0.0 && desX != 0.0 && desZ != 0.0 && alX != NULL && alZ != NULL) {
        if(!destinations.empty()) {
            for (const dest &d : destinations) {
                delete d.button;
            }
            destinations.clear();
        }
        destinations = pearl::calculateGenericFtl(185.34881785360997, 185.5F, maxT, desX, desZ, alX, alZ, 0.5100841893612624, 0);
        destinations = pearl::bubbleSort(destinations,destinations.size(),sortButtons->checkedId());
        std::cout << "Found " << destinations.size() << " destinations within 50 blocks of target" << std::endl;
        list= new QWidget();
        list->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        list->setGeometry(QRect(0, 0, 848, 479));
        verticalLayout_2 = new QVBoxLayout(list);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButtons = new QButtonGroup(this);
        int i = 0;
        for(const dest& Dest : destinations){
            addItem(Dest, list, i, verticalLayout_2);
            i++;
        }
        if(radioButtons->buttons().size() > 0){
            radioButtons->button(0)->setChecked(true);
        }
        scrollArea420->setWidget(list);
        status = 1;
        auto end = std::chrono::high_resolution_clock::now();
        double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "finished in " << time_taken/1000000 << " milliseconds" << std::endl;
    }


}

void MainWindow::addItem(dest d, QWidget *widget, int o, QVBoxLayout *layout) {
    d.button = new QRadioButton(widget);
    d.button->setObjectName(QString::fromUtf8("radioButton"));
    d.button->setGeometry(QRect(0, 25 * o, 851, 24));
    layout->addWidget(d.button);
    radioButtons->addButton(d.button,o);
    d.button->setText(QCoreApplication::translate("setupUi", const_cast<char*>(d.formatString().c_str()), nullptr));
}

void MainWindow::chunkLoad420(){
    if(status == 1 || status == 3){
        dest d = getPressed();
        std::vector<std::string> items;
        int i = 0;
        for(std::array<double,3> gt : d.GTs){
            int chunkX = gt[0]/16;
            int chunkZ = gt[2]/16;
            std::ostringstream ss;
            ss << "Tick: " << i << "  Chunk: x:" << chunkX << " z:" << chunkZ << "  Pearl coords: x:" << gt[0] << " y:" << gt[1] << " z:" << gt[2];
            items.emplace_back(ss.str());
            i++;
        }
        displayInfo(items);
        status = 2;
    }
}

void MainWindow::prog420(){
    if(status == 1 || status == 2){
        dest d = getPressed();
        displayInfo(pearl::getBits(d.redtnt,d.bluetnt,d.quadrant,this->maxTNT_420->text().toInt()));
    }
    status = 3;
}

/***
 *
 * @return returns the currently selected destination, if none are selected, returns the first one on the list.
 */
dest MainWindow::getPressed(){
    if(status == 2 || status == 3) {
        dest d = *selected;
        return d;
    } else {
        selected = &destinations[radioButtons->checkedId()];
        //std::cout << selected->quadrant << std::endl;
        dest d = *selected;
        return d;
    }

}

void MainWindow::displayInfo(const std::vector<std::string>& v){
    //clear the list
    list = new QWidget();
    list->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
    list->setGeometry(QRect(0, 0, 848, 479));
    int i = 0;
    verticalLayout_2 = new QVBoxLayout(list);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

    for(const std::string& s : v) {
        auto *lab = new QLabel();
        lab->setText(QString::fromUtf8(s.c_str()));
        lab->setGeometry(QRect(0, 25 * i, 851, 24));
        verticalLayout_2->addWidget(lab);
    }
    scrollArea420->setWidget(list);

}


void MainWindow::calculateftlV360() {



    int maxT = 100000000;
    int searchRadius = this->searchRange_V360->text().toInt();
    double desX = this->destX_V360->text().toDouble();
    double desZ = this->destZ_V360->text().toDouble();
    double alX = this->alignX_V360->text().toInt()+290.8659577064391;
    double alZ = this->alignZ_V360->text().toInt()-19.86470963359534;
    if (this->searchRange_V360->text() != nullptr && this->destX_V360->text() != nullptr && this->destZ_V360->text() != nullptr && this->alignX_V360->text() != nullptr && this->alignZ_V360->text() != nullptr) {
        if(!destinations.empty()) {
            for (const dest &d : destinations) {
                delete d.button;
            }
            destinations.clear();
        }
        auto start = std::chrono::high_resolution_clock::now();
        destinations = pearl::calculateVoidFtl(maxT, desX, desZ, alX, alZ, 0, searchRadius);//pearl::calculateGenericFtl(185.34881785360997, 185.5F, maxT, desX, desZ, alX, alZ, 0.5100841893612624, 0);
        auto end = std::chrono::high_resolution_clock::now();
        destinations = pearl::bubbleSort(destinations,destinations.size(),sortButtons->checkedId());
        std::cout << "Found " << destinations.size() << " destinations within " << searchRadius << " blocks of target" << std::endl;
        list= new QWidget();
        list->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        list->setGeometry(QRect(0, 0, 848, 479));
        verticalLayout_2 = new QVBoxLayout(list);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButtons = new QButtonGroup(this);
        int i = 0;
        for(const dest& Dest : destinations){
            addItem(Dest, list, i, verticalLayout_2);
            i++;
        }
        if(radioButtons->buttons().size() > 0){
            radioButtons->button(0)->setChecked(true);
        }
        scrollAreaV360->setWidget(list);
        status = 1;

        double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        std::cout << "finished in " << time_taken/1000000 << " milliseconds" << std::endl;
    }
}

void MainWindow::chunkLoadV360() {
    if(status == 1 || status == 3){
        dest d = getPressed();
        std::vector<std::string> items;
        int i = 0;
        items.emplace_back("It's a void cannon... why would you care about chunk loading?");
        /*for(std::array<double,3> gt : d.GTs){
            int chunkX = gt[0]/16;
            int chunkZ = gt[2]/16;
            std::ostringstream ss;
            ss << "Tick: " << i << "  Chunk: x:" << chunkX << " z:" << chunkZ << "  Pearl coords: x:" << gt[0] << " y:" << gt[1] << " z:" << gt[2];
            items.emplace_back(ss.str());
            i++;
        }*/
        displayInfoV360(items);
        status = 2;
    }
}

void MainWindow::progV360(){
    if(status == 1 || status == 2){
        dest d = getPressed();
        displayInfoV360(pearl::getV360Bits(d.redtnt,d.bluetnt,d.quadrant,d.worldQuadrant,109000000));
    }
    status = 3;
}

void MainWindow::displayInfoV360(const std::vector<std::string>& v){
    //clear the list
    listV360 = new QWidget();
    listV360->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
    listV360->setGeometry(QRect(0, 0, 848, 479));
    int i = 0;
    verticalLayout_2V360 = new QVBoxLayout(listV360);
    verticalLayout_2V360->setObjectName(QString::fromUtf8("verticalLayout_2"));

    for(const std::string& s : v) {
        auto *lab = new QLabel();
        lab->setText(QString::fromUtf8(s.c_str()));
        lab->setGeometry(QRect(0, 25 * i, 851, 24));
        verticalLayout_2V360->addWidget(lab);
    }
    scrollAreaV360->setWidget(listV360);

}