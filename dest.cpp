//
// Created by pentasteve on 8/22/21.
//

#include "dest.h"

#include <utility>
#include <sstream>
#include <string>
#include <cstring>
#include <iostream>


dest::dest(double d, int bt, int rt, std::list<std::array<double,3>> gt, int q, bool reachable, int wq) {
    this->dist = d;
    this->redtnt = rt;
    this->bluetnt = bt;
    this->GTs = std::move(gt);
    this->quadrant = q;
    this->worldQuadrant = wq;
    this->reachable = reachable;
}

std::string dest::formatString(){
    if(!reachable){
        return "Destination is unreachable";
    }
    std::ostringstream ss;
    ss << "Distance: " << this->dist << " (Tick: " << this->GTs.size()-1 << ")  TNT: " << this->redtnt+this->bluetnt << " (Blue: " << this->bluetnt << ", Red: " << this->redtnt << ")" << " quadrant: " << this->quadrant;
    return ss.str();
}
