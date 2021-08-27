//
// Created by pentasteve on 8/22/21.
//
#include <iostream>
#include <utility>
#include "pearl.h"
std::vector<dest> pearl::calculateGenericFtl(double pearlHeight, double tntHeight, int maxTNT, double destX, double destZ, int alignX, int alignZ, double initM, int sort) {
    std::vector<dest> dests;
    std::array<double,3> destC = {destX, 128, destZ};
    double deltaAngle = ((double) 2) / maxTNT / 4;
    std::array<double,3> initL = {(double) (alignX+1), pearlHeight, (double) alignZ};


    double angle = atan2(destC[0] - initL[0], destC[2] - initL[2]);
    int quadrant = getQuadrant(angle);
    double maxRatio = getTntRatio(angle+deltaAngle,quadrant);
    double minRatio = getTntRatio(angle-deltaAngle,quadrant);

    //swap ratios if minRatio is greater than maxRatio
    if(minRatio > maxRatio){
        double temp = minRatio;
        minRatio = maxRatio;
        maxRatio = temp;
    }

    if (quadrant == 4) {
        std::cout << "quadrant = 4" << std::endl;
        return dests;
    }

    std::array<double,3> firstE = getFirst(quadrant);
    std::array<double,3> secondE = getSecond(quadrant);
    for(int sec = ceil(maxRatio < 1 ? maxTNT : (1/maxRatio * maxTNT)-1); sec >= 0; sec--) {
        for(int fir = ceil((sec+1)*maxRatio); fir >= floor((sec+1)*minRatio); fir--){
            std::array<double,3> vector = add(mul(firstE,fir),mul(secondE,sec));
            vector = add(vector,{0,initM,0});
            std::list<std::array<double,3>> gameticks = getGt(initL, vector, destC);
            double d = pythag(gameticks.back()[0],gameticks.back()[2],destC[0],destC[2]);
            if(d < 2500){
                dests.emplace_back(sqrt(d),fir,sec,gameticks,quadrant);
            }
        }
    }
    return dests;
}

int getQuadrant(double angle) {
    if (angle <= 0.7853981633974483 && angle >= -0.7853981633974483) {
        return 0;
    } else if (angle <= 2.356194490192345 && angle >= 0.7853981633974483) {
        return 3;
    } else if (angle <= -0.7853981633974483 && angle >= -2.356194490192345) {
        return 1;
    } else if ((angle <= -2.356194490192345 && angle >= -3.141592653589793) || (angle >= 2.356194490192345 && angle <= 3.141592653589793)) {
        return 2;
    } else {
        return 4;
    }
}

//not currently functional or used, intended to calculate tnt acceleration
std::array<double, 3> getTntAccel(double pearl[], std::array<double,3> tnt){
    double xAccel = pearl[0] - tnt[0];
    double yAccel = (pearl[1] + 0.2125) - tnt[1];
    double zAccel = pearl[2] - tnt[2];
    double sqAccel = sqrt((xAccel*xAccel)+(yAccel*yAccel)+(zAccel*zAccel));

    std::array<double,3> accel = {xAccel/sqAccel, yAccel/sqAccel, zAccel/sqAccel};

    return accel;
}

/***
 *
 * @param dir 0 = northwest, 1 = northeast, 2 = southeast, 3 = southwest
 * @param alX
 * @param alZ
 * @param tY
 * @return
 */
std::array<double,3> getTntCoord(int dir, int alX, int alZ, double tY) {
    std::array<double,3> coord{};
    coord[1] = tY;
    switch(dir){
        case 0:
            coord[0] = alX+0.11500000953674;
            coord[2] = alZ-0.88499999046326;
        case 1:
            coord[0] = alX+1.88499999046326;
            coord[2] = alZ-0.88499999046326;
        case 3:
            coord[0] = alX+1.88499999046326;
            coord[2] = alZ+0.88499999046326;
        case 2:
            coord[0] = alX+0.11500000953674;
            coord[2] = alZ+0.88499999046326;
        default:
            coord[0] = alX;
            coord[2] = alZ;
    }
    return coord;
}

std::array<double,3> getFirst(int quadrant) {
    std::array<double,3> nn = {-0.5948995891439429, 4.5614600939925386E-5, -0.5948995891439429};
    std::array<double,3> np = {-0.5948995891439429, 4.5614600939925386E-5, 0.5948995891439429};
    std::array<double,3> pn = {0.5948995891439429, 4.5614600939925386E-5, -0.5948995891439429};
    std::array<double,3> pp = {0.5948995891439429, 4.5614600939925386E-5, 0.5948995891439429};
    std::array<double,3> null = {0,0,0};
    switch (quadrant) {
        case 0:
            return pp;
        case 1:
            return nn;
        case 3:
            return pn;
        case 2:
            return pn;
    }
    return null;
}

std::array<double,3> getSecond(int quadrant) {
    std::array<double,3> nn = {-0.5948995891439429, 4.5614600939925386E-5, -0.5948995891439429};
    std::array<double,3> np = {-0.5948995891439429, 4.5614600939925386E-5, 0.5948995891439429};
    std::array<double,3> pn = {0.5948995891439429, 4.5614600939925386E-5, -0.5948995891439429};
    std::array<double,3> pp = {0.5948995891439429, 4.5614600939925386E-5, 0.5948995891439429};
    std::array<double,3> null = {0,0,0};
    switch (quadrant) {
        case 0:
            return np;
        case 1:
            return np;
        case 3:
            return pp;
        case 2:
            return nn;
    }
    return null;
}

std::array<double,3> mul(std::array<double,3> one, double mul){
    return {one[0]*mul,one[1]*mul,one[2]*mul};
}

std::array<double,3> add(std::array<double,3> one, std::array<double,3> two) {
    return {one[0]+two[0],one[1]+two[1],one[2]+two[2]};
}

std::list<std::array<double,3>> getGt(std::array<double,3> initL, std::array<double,3> vec, std::array<double,3> dest) {
    double lowestDistance = pythag(initL[0],initL[2],dest[0],dest[2]);
    std::list<std::array<double,3>> list;
    list.push_back(initL);
    std::array<double,3> initL2 = initL;

    while(true){
        initL2 = add(initL2,vec);
        double newDist = pythag(initL2[0],initL2[2],dest[0],dest[2]);
        if(newDist>lowestDistance){
            return list;
        } else {
            lowestDistance = newDist;
            list.push_back(initL2);
        }
        if(initL2[1] < 128){
            return list;
        }

        //gravity and deceleration
        vec = add(mul(vec,0.99F),{0,-0.03F,0});
    }
}

double pythag(double a1, double b1, double a2, double b2){
    return pow(a1-a2, 2)+pow(b1-b2,2);
}


double pearl::getTntRatio(double angle, int quadrant){
    double pi = 3.1415926535897932;
    double ratio = abs(tan(angle+(pi/4)));
    if (quadrant <= 1){
        return ratio;
    } else if (quadrant >= 2){
        return 1/ratio;
    } else {
        return ratio;
    }
}
/***
 *
 * @param list
 * @param n
 * @param type 0 = GT sort, 1 = total tnt sort, 2 = distance sort
 */

std::vector<std::string> pearl::getBits(int r, int b, int q, int maxTnt) {
    int bits = pow(2, ceil(log(ceil(maxTnt-11)/286)/log(2)));
    std::ostringstream Bits;
    Bits << "Binary: ";
    std::vector<std::string> list;
    for(int i = 0; i<2; i++){
        int tnt;
        if(i == 0){
            tnt = b;
        } else {
            tnt = r;
        }
        int t286 = tnt / 286;
        tnt = tnt % 286;
        int t143 = tnt / 143;
        tnt = tnt % 143;
        int t11 = tnt / 11;
        int t1 = tnt % 11;

        if (t11 == 1) {
            t11 = 0;
            t1 = 11;
        }
        if (t11 == 0 && t143 == 0 && t286 > 0) {
            t286 -= 1;
            t11 = 13;
            t143 = 1;
        }

        list.emplace_back((i == 0 ? "----Blue----" : "----Red----"));

        list.emplace_back("Large:");
        for (int j = bits; j > 0; j = j / 2){
            if(j == (t286 & j)){
                std::ostringstream ss;
                ss << "+" << 286*j << " TNT";
                list.emplace_back(ss.str());
                Bits << "1";
            } else {
                Bits << "0";
            }
        }


        list.emplace_back(" ");
        list.emplace_back("Medium:");
        for (int j = 8; j > 0; j = j / 2){
            if(j == (t11 & j)){
                std::ostringstream ss;
                ss << "+" << 11*j << " TNT";
                list.emplace_back(ss.str());
                Bits << "1";
            } else {
                Bits << "0";
            }
        }
        if(t143 == 1){
            list.emplace_back("+143 TNT");
            Bits << "1";
        } else {
            Bits << "0";
        }


        list.emplace_back(" ");
        list.emplace_back("Small:");
        for(int j = 8; j > 0; j = j / 2) {
            if (j == (t1 & j)){
                std::ostringstream ss;
                ss << "+" << j << " TNT";
                list.emplace_back(ss.str());
                Bits << "1";
            } else {
                Bits << "0";
            }
        }
        if(i == 0){
            list.emplace_back(" ");
            std::ostringstream ss;
            ss << "Left Bit: " << q/2;
            list.emplace_back(ss.str());
            std::ostringstream ss1;
            ss1 << "Right Bit: " << q%2;
            list.emplace_back(ss1.str());
            Bits << (q/2);
            Bits << (q%2);
        }
        list.emplace_back(" ");
    }

    list.emplace_back(Bits.str());
    return list;
}

std::vector<dest> pearl::bubbleSort(std::vector<dest> list, int n, int type)
{
    std::vector<dest> l = std::move(list);
    int i, j;
    switch(type){
        case 0:{
            for (i = 0; i < n-1; i++) {
                for (j = 0; j < n - i - 1; j++) {
                    if ((l[j].dist*l[j].GTs.size()) > (l[j+1].dist*l[j+1].GTs.size())) {
                        dest temp = l[j];
                        l[j] = l[j + 1];
                        l[j + 1] = temp;
                    }
                }
            }
            return l;
        }
        case 1:{
            std::cout << "sorting by tnt" << std::endl;
            for (i = 0; i < n-1; i++) {
                for (j = 0; j < n - i - 1; j++) {
                    if ((l[j].redtnt+l[j].bluetnt) > (l[j+1].redtnt+l[j+1].bluetnt)) {
                        dest temp = l[j];
                        l[j] = l[j + 1];
                        l[j + 1] = temp;
                    }
                }
            }
            return l;
        }
        case 2:{
            std::cout << "sorting by gameticks" << std::endl;
            for (i = 0; i < n-1; i++) {
                for (j = 0; j < n - i - 1; j++) {
                    if (l[j].GTs.size() > l[j + 1].GTs.size()) {
                        dest temp = l[j];
                        l[j] = l[j + 1];
                        l[j + 1] = temp;
                    }
                }
            }
            return l;
        }
        default: return l;
    }
}