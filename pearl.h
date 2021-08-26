//
// Created by pentasteve on 8/22/21.
//

#ifndef PEARLCALCULATOR_PEARL_H
#define PEARLCALCULATOR_PEARL_H
#include <cmath>
#include "mainwindow.h"
#include "dest.h"

namespace pearl {
    std::vector<dest> calculateGenericFtl(double pearlHeight, double tntHeight, int maxTNT, double destX, double destZ, int alignX, int alignZ, double initM, int sort);
    std::vector<dest> bubbleSort(std::vector<dest> list, int n, int type);
    std::vector<std::string> getBits(int r, int b, int q, int maxTnt);
}
int getQuadrant(double angle);
#endif //PEARLCALCULATOR_PEARL_H



std::array<double,3> getTntAccel(double pearl[], std::array<double,3> tnt);
std::array<double,3> getTntCoord(int dir, int alX, int alZ, double tY);
std::array<double,3> getFirst(int quadrant);
std::array<double,3> getSecond(int quadrant);

std::array<double,3> mul(std::array<double,3> one, double mul);

std::array<double,3> add(std::array<double,3> one, std::array<double,3> two);
double pythag(double a1, double b1, double a2, double b2);

std::list<std::array<double,3>> getGt(std::array<double,3> initL, std::array<double,3> vec, std::array<double,3> dest);
