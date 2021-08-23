//
// Created by pentasteve on 8/22/21.
//

#ifndef PEARLCALCULATOR_PEARL_H
#define PEARLCALCULATOR_PEARL_H
#include "mainwindow.h"
#include "dest.h"
namespace pearl {
    dest * calculateGenericFtl(double pearlHeight, double tntHeight, int * maxTNT, double * destX, double * destZ, int * alignX, int * alignZ);
}

#endif //PEARLCALCULATOR_PEARL_H
