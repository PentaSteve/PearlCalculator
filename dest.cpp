//
// Created by pentasteve on 8/22/21.
//

#include "dest.h"

#include <utility>

dest::dest(double d, int bt, int rt, std::list<std::array<double,3>> gt) {
    this->dist = d;
    this->redtnt = rt;
    this->bluetnt = bt;
    this->GTs = std::move(gt);
}

