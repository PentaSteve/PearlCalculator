//
// Created by pentasteve on 8/22/21.
//

#ifndef PEARLCALCULATOR_DEST_H
#define PEARLCALCULATOR_DEST_H
#include <string>
#include <list>
#include <array>
#include <QtWidgets/QRadioButton>

class dest {
public:
    double dist;
    int redtnt;
    int bluetnt;
    int quadrant;
    bool reachable;
    std::list<std::array<double,3>> GTs;
    dest(double d, int bt, int rt, std::list<std::array<double,3>> gt, int q, bool reachable);
    std::string formatString();
    QRadioButton *button{};
};
/*

double getX();

double getZ();

double getDist();

int getGt();

int getRedTNT();

int getBlueTNT();*/

#endif //PEARLCALCULATOR_DEST_H
