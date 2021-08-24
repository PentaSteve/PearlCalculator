//
// Created by pentasteve on 8/22/21.
//

#include "dest.h"

#include <utility>
#include <sstream>
#include <string>
#include <cstring>
#include <iostream>


dest::dest(double d, int bt, int rt, std::list<std::array<double,3>> gt) {
    this->dist = d;
    this->redtnt = rt;
    this->bluetnt = bt;
    this->GTs = std::move(gt);
}

std::string dest::formatString(){
    std::ostringstream ss;
    ss << "Distance: " << this->dist << " (Tick: " << this->GTs.size() << ")  TNT: " << this->redtnt+this->bluetnt << " (Blue: " << this->bluetnt << ", Red: " << this->redtnt << ")";
    return ss.str();
}