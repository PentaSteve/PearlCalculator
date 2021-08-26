//
// Created by pentasteve on 8/22/21.
//

#include <iostream>
#include <QVBoxLayout>
#include <sstream>
#include "mainwindow.h"


void MainWindow::setupUi(QMainWindow *MainWindow){

    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("setupUi"));
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

    chunkLoadButton = new QPushButton(tab);
    chunkLoadButton->setObjectName(QString::fromUtf8("chunkLoadButton"));
    chunkLoadButton->setGeometry(QRect(462, 2, 111, 26));
    chunkLoadButton->setAutoFillBackground(true);
    chunkLoadButton->setCheckable(false);
    chunkLoadButton->setAutoRepeat(false);
    chunkLoadButton->setAutoExclusive(false);
    chunkLoadButton->setAutoDefault(false);
    chunkLoadButton->setText(QCoreApplication::translate("setupUi", "Chunk Loading", nullptr));
    connect(chunkLoadButton, &QPushButton::released, this, &MainWindow::chunkLoad420);

    progButton = new QPushButton(tab);
    progButton->setObjectName(QString::fromUtf8("progButton"));
    progButton->setGeometry(QRect(590, 2, 81, 26));
    progButton->setAutoFillBackground(true);
    progButton->setCheckable(false);
    progButton->setAutoRepeat(false);
    progButton->setAutoExclusive(false);
    progButton->setAutoDefault(false);
    progButton->setText(QCoreApplication::translate("setupUi", "Program", nullptr));
    connect(progButton, &QPushButton::released, this, &MainWindow::prog420);

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

    //temporary for testing purposes
    destX->setText("22");
    destZ->setText("22");
    alignX->setText("1");
    alignZ->setText("1");
    maxTNT->setText("11");

    scrollArea420 = new QScrollArea(tab);
    scrollArea420->setObjectName(QString::fromUtf8("scrollArea420"));
    scrollArea420->setGeometry(QRect(3, 62, 850, 481));
    scrollArea420->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea420->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea420->setWidgetResizable(true);
    /*scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 848, 479));
    scrollArea420->setWidget(scrollAreaWidgetContents);*/
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
    MainWindow->setWindowTitle(QCoreApplication::translate("setupUi", "Pearl Calculator", nullptr));
    label->setText(QCoreApplication::translate("setupUi", "Dest X:", nullptr));
    label_2->setText(QCoreApplication::translate("setupUi", "Dest Z:", nullptr));
    calculateButton->setText(QCoreApplication::translate("setupUi", "Calculate", nullptr));
    label_3->setText(QCoreApplication::translate("setupUi", "Aligner X:", nullptr));
    label_4->setText(QCoreApplication::translate("setupUi", "Aligner Z:", nullptr));
    label_5->setText(QCoreApplication::translate("setupUi", "Max TNT:", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("setupUi", "420/420-69 FTL", nullptr));
    label1->setText(QCoreApplication::translate("setupUi", "Dest X:", nullptr));
    label_21->setText(QCoreApplication::translate("setupUi", "Dest Z:", nullptr));
    calculateButton_621->setText(QCoreApplication::translate("setupUi", "Calculate", nullptr));
    label_31->setText(QCoreApplication::translate("setupUi", "Aligner X:", nullptr));
    label_41->setText(QCoreApplication::translate("setupUi", "Aligner Z:", nullptr));
    label_51->setText(QCoreApplication::translate("setupUi", "Max TNT:", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("setupUi", "621 FTL", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("setupUi", "Autoload FTL (coming soon)", nullptr));
}

//621: 186.34881785360997
//420: 185.34881785360997
void MainWindow::calculateftl420() {
    int maxT = this->maxTNT->text().toInt();
    double desX = this->destX->text().toDouble();
    double desZ = this->destZ->text().toDouble();
    int alX = this->alignX->text().toInt();
    int alZ = this->alignZ->text().toInt();
    if (maxT != 0.0 && desX != 0.0 && desZ != 0.0 && alX != NULL && alZ != NULL) {
        if(!destinations.empty()){
            for(dest d : destinations){
                delete d.button;
            }
            destinations.clear();
        }
        destinations = pearl::calculateGenericFtl(185.34881785360997, 185.5F, maxT, desX, desZ, alX, alZ, 0.5100841893612624, 0);
        std::cout << destinations.size() << std::endl;
        list= new QWidget();
        list->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        list->setGeometry(QRect(0, 0, 848, 479));
        verticalLayout_2 = new QVBoxLayout(list);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButtons = new QButtonGroup(this);
        int i = 0;
        for(const dest& Dest : destinations){
            //std::cout << Dest.formatString() << std::endl;
            addItem(Dest, list, i, verticalLayout_2);
            i++;
        }
        radioButtons->button(0)->setChecked(true);
        //destinations[0].button->setChecked(true);
        //std::cout << verticalLayout_2->findChildren<QRadioButton*>("radioButton").size() << std::endl;
        scrollArea420->setWidget(list);
    }
    status = 1;
}

void MainWindow::addItem(dest d, QWidget *widget, int o, QVBoxLayout *layout) {
    //std::cout << "adding item" << std::endl;
    d.button = new QRadioButton(widget);
    d.button->setObjectName(QString::fromUtf8("radioButton"));
    d.button->setGeometry(QRect(0, 25 * o, 851, 24));
    //std::cout << d.formatString() << std::endl;
    layout->addWidget(d.button);
    radioButtons->addButton(d.button,o);
    d.button->setText(QCoreApplication::translate("setupUi", const_cast<char*>(d.formatString().c_str()), nullptr));
    //destinations.emplace_back(button);
}

void MainWindow::chunkLoad420(){
    if(status == 1 || status == 3){
        std::cout << "chunk Loading" << std::endl;
        dest d = getPressed();
        std::vector<std::string> items;
        int i = 0;
        for(std::array<double,3> gt : d.GTs){
            int chunkX = gt[0]/16;
            int chunkZ = gt[2]/16;
            std::cout << "Tick: " << i << "  Chunk: x:" << chunkX << " z:" << chunkZ << "  Pearl coords: x:" << gt[0] << " y:" << gt[1] << " z:" << gt[2] << std::endl;
            std::ostringstream ss;
            ss << "Tick: " << i << "  Chunk: x:" << chunkX << " z:" << chunkZ << "  Pearl coords: x:" << gt[0] << " y:" << gt[1] << " z:" << gt[2];
            items.emplace_back(ss.str());
            i++;
        }
        std::cout << "displaying" << std::endl;
        displayInfo(items);
        status = 2;
    }
}

void MainWindow::prog420(){
    if(status == 1 || status == 2){
        dest d = getPressed();
        displayInfo(pearl::getBits(d.redtnt,d.bluetnt,d.quadrant,this->maxTNT->text().toInt()));
    }
    status = 3;
}

/***
 *
 * @return returns the currently selected destination, if none are selected, returns the first one on the list.
 */
dest MainWindow::getPressed(){
    if(status == 2 || status == 3){
        std::cout << "returning selected " << selected->quadrant << std::endl;
        dest d = *selected;
        return d;
    } else {
        selected = &destinations[radioButtons->checkedId()];
        std::cout << selected->quadrant << std::endl;
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
        //info.push_back(QLabel());
    }
    scrollArea420->setWidget(list);

}