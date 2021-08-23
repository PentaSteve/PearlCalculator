//
// Created by pentasteve on 8/22/21.
//

#ifndef PEARLCALCULATOR_DEST_H
#define PEARLCALCULATOR_DEST_H
#include <string>

class dest {
    double x{};
    double z{};
    double dist{};
    int gt{};
    int redtnt{};
    int bluetnt{};
    dest(double x, double z, double d, int g, int rt, int bt);
};

std::string getFormatted();

double getX();

double getZ();

double getDist();

int getGt();

int getRedTNT();

int getBlueTNT();

#endif //PEARLCALCULATOR_DEST_H
