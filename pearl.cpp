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

    std::cout << "tan 10: " << tan(10) << std::endl;
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
    std::cout << "test" << std::endl;
    for(int sec = ceil(maxRatio < 1 ? maxTNT : (1/maxRatio * maxTNT)-1); sec >= 0; sec--) {
        for(int fir = ceil((sec+1)*maxRatio); fir >= floor((sec+1)*minRatio); fir--){
            std::array<double,3> vector = add(mul(firstE,fir),mul(secondE,sec));
            vector = add(vector,{0,initM,0});
            std::list<std::array<double,3>> gameticks = getGt(initL, vector, destC);
            double d = pythag(gameticks.back()[0],gameticks.back()[2],destC[0],destC[2]);
            if(d < 2500){
                dests.emplace_back(sqrt(d),fir,sec,gameticks,quadrant,true);
            }
        }
    }
    if(dests.empty()){
        std::list<std::array<double,3>> gameticks = {initL};
        dests.emplace_back(0.0,0,0,gameticks,quadrant, false);
    }

    return dests;
}

std::vector<dest> pearl::calculateVoidFtl(int maxTNT, double destX, double destZ, double alignX, double alignZ, int sort, int searchRange) {
    std::vector<dest> dests;
    std::cout << alignX << ", " << alignZ << std::endl;
    std::array<double,3> destC = {destX, 64, destZ};
    std::array<double,3> initL = {alignX, 64, alignZ};
    std::cout << destX << ", " << destZ << std::endl;
    int count = 0;
    double pi = 3.1415926535897932;
    std::cout << "tan 10: " << atan(3.31466323913)-pi << std::endl;
    double angle = atan2((destX - initL[0]), (destZ - initL[2]));
    std::cout << (destX - initL[0]) << ", " << (destZ - initL[2]) << std::endl;
    //double angle2 = atan((destX - initL[0])/(destZ - initL[2]))-pi;
    std::cout << angle << ", " << (destX - initL[0])/(destZ - initL[2]) << std::endl;
    int quadrant = getQuadrant(angle);
    std::array<int, 2> exactTntVec = calculateNeededTnt(1,destX,destZ,alignX,alignZ,quadrant,angle);
    if(exactTntVec[0] > maxTNT || exactTntVec[1] > maxTNT){
        std::list<std::array<double,3>> gameticks = {initL};
        dests.emplace_back(0,exactTntVec[0],exactTntVec[1],gameticks,quadrant,false);
    }
    int tntRange = floor(searchRange/sqrt(pow(getTntV360(quadrant,1)[0],2)+pow(getTntV360(quadrant,0)[0],2)));
    for(int sec = exactTntVec[0]+tntRange; sec >= exactTntVec[0]-tntRange; sec--) {
        for(int fir = exactTntVec[1]+tntRange; fir >= exactTntVec[1]-tntRange; fir--){
            std::array<double,3> vector{};
            vector = add(mul(getTntV360(quadrant,1),sec),mul(getTntV360(quadrant,0),fir));

            std::list<std::array<double,3>> gameticks = {add(initL,vector)};
            double d = pythag(gameticks.back()[0],gameticks.back()[2],destX,destZ);
            std::cout << vector[0]*0.99 << ", " << vector[2]*0.99 << ", " << fir << ", " << sec << ", " << atan2(gameticks.back()[0]-alignX,gameticks.back()[2]-alignZ) << std::endl;
            dests.emplace_back(sqrt(d),fir,sec,gameticks,quadrant,true);
            count++;
        }
    }

    std::cout << "tried " << count << " destinations" << std::endl;

    return dests;
}

int getQuadrant(double angle) {
    if (angle <= 0.7853981633974483 && angle >= -0.7853981633974483) {
        return 0;
    } else if (angle <= 2.356194490192345 && angle >= 0.7853981633974483) {
        return 2;
    } else if (angle <= -0.7853981633974483 && angle >= -2.356194490192345) {
        return 1;
    } else if ((angle <= -2.356194490192345 && angle >= -3.141592653589793) || (angle >= 2.356194490192345 && angle <= 3.141592653589793)) {
        return 3;
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


std::array<double,3> getTntV360(int quadrant, int first){
    std::array<double,3> S1{-0.6197856102380207, 0, 0.6197856102380207}; //1
    std::array<double,3> S2{0.6197856102380207, 0, 0.6197856102380207}; //2
    std::array<double,3> S3{0.6197856102380173, 0, -0.6197856102380241}; //3
    std::array<double,3> S4{-0.6197856102380173, 0, -0.6197856102380241}; //4

    switch (quadrant){
        case 0:
            return first ? S2 : S1;
        case 1:
            return first ? S4 : S1;
        case 2:
            return first ? S3 : S2;
        case 3:
            return first ? S3 : S4;
        default:
            return {0,0,0};
    }
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
    double ratio = pearl::abs(tan(angle+(pi/4)));
    if (quadrant <= 1){
        return ratio;
    } else if (quadrant >= 2){
        return 1/ratio;
    } else {
        return ratio;
    }
}

double pearl::abs(double a){
    if(a < 0){
        return a*-1;
    } else {
        return a;
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

std::array<int, 2> calculateNeededTnt(int gt, double destX, double destZ, double startX, double startZ, int quad, double angle){

    double pi = 3.1415926535897932;
    double velocity = sqrt(pow(destX-startX,2)+pow(destZ-startZ,2));// m/gt not m/s
    //std::cout << "velocity: " << velocity << std::endl;
    double Vx = cos(angle+(pi/4))*velocity;
    double Vz = sin(angle+(pi/4))*velocity;
    double accelXL = sqrt(pow(getTntV360(quad, 1)[0],2)+pow(getTntV360(quad, 1)[2],2));
    double accelZL = sqrt(pow(getTntV360(quad, 0)[0],2)+pow(getTntV360(quad, 0)[2],2));
    int tnt1 = (int) abs(Vx / accelXL);
    int tnt2 = (int) abs(Vz / accelZL);

    //std::cout << "tnt1: " << tnt1 << std::endl << "tnt2: " << tnt2 << std::endl << "Vx: " << Vx << std::endl << "Vz: " << Vz << std::endl << "accelX: " << accelXL << std::endl << "accelZ: " << accelZL << std::endl;
    if(quad >= 2){
        int temp = tnt1;
        tnt1 = tnt2;
        tnt2 = temp;
    }


    std::array<int, 2> out = {tnt2+1, tnt1+1};
    return out;
}

std::vector<std::string> pearl::getV360Bits(int r, int b, int q, int maxTnt) {
    int bits = pow(2, ceil(log(ceil(maxTnt-11)/286)/log(2)));
    std::ostringstream Bits;
    int base = 416;
    Bits << "Binary: ";
    std::vector<std::string> list;
    for(int i = 0; i<2; i++){
        int tnt;
        if(i == 0){
            tnt = b;
        } else {
            tnt = r;
        }
        int tnt416 = tnt / base;
        tnt = tnt % base;
        int tnt9bit = tnt;


        list.emplace_back((i == 0 ? "Program 1" : "Program 2"));

        list.emplace_back("9 bit: ");
        for (int j = 512; j > 0; j = j / 2){
            if(j == (tnt9bit & j)){
                std::ostringstream ss;
                ss << "+" << j << " TNT";
                list.emplace_back(ss.str());

                Bits << "1";
            } else {
                Bits << "0";
            }
        }
        list.emplace_back(" ");
        list.emplace_back("416 duper: ");
        std::vector<int> strings;
        for (int j = bits; j > 0; j = j / 2){
            if(j == (tnt416 & j)){
                std::ostringstream ss;
                ss << "+" << base*j << " TNT";
                strings.push_back(base*j);
            } else {
                strings.push_back(-1);

            }
        }

        //reverse the order of the 416 duper bits
        for(int k = strings.size()-1; k >= 0; k--){
            if(strings[k] != -1 || (strings[k] % 416) == 0){
                std::ostringstream ss;
                ss << "+" << strings[k] << " TNT";
                list.emplace_back(ss.str());
                Bits << "1";
            } else {
                Bits << "0";
            }
        }

        std::ostringstream ss;
        list.emplace_back(ss.str());
    }

    list.emplace_back(Bits.str());
    return list;
}