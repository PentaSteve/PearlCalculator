//
// Created by pentasteve on 8/22/21.
//
#include <iostream>
#include "pearl.h"
std::list<dest> pearl::calculateGenericFtl(double pearlHeight, double tntHeight, int maxTNT, double destX, double destZ, int alignX, int alignZ, double initM) {
    std::list<dest> dests;
    std::cout << "pressed" << std::endl;
    /*std::cout << "pearl-height: " << pearlHeight << std::endl;
    std::cout << "TNT-Height: " << tntHeight << std::endl;
    std::cout << "max-TNT: " << maxTNT << std::endl;
    std::cout << "destC-X: " << destX << std::endl;
    std::cout << "destC-Z: " << destZ << std::endl;
    std::cout << "aligner-X: " << alignX << std::endl;
    std::cout << "aligner-Z: " << alignZ << std::endl;*/
    std::array<double,3> destC = {destX, 128, destZ};
    double deltaAngle = ((double) 10) / maxTNT;
    std::cout << "deltaAngle: " << deltaAngle << std::endl;
    std::array<double,3> initL = {(double) (alignX+1), pearlHeight, (double) alignZ};

    std::cout << "meese" << std::endl;

    double angle = atan2(destC[0] - initL[0], destC[2] - initL[2]);
    std::cout << "angle: " << angle << std::endl;
    int quadrant = getQuadrant(angle);
    if (quadrant == 4) {
        std::cout << "quadrant = 4" << std::endl;
        return dests;
    }

    std::array<double,3> firstE = getFirst(quadrant);
    std::array<double,3> secondE = getSecond(quadrant);

    for(int sec = maxTNT; sec >= 0; sec--) {
        for(int fir = maxTNT; fir >= 0; fir--){

            std::array<double,3> vector = add(mul(firstE,fir),mul(secondE,sec));
            double vAngle = atan2(vector[0],vector[2]);
            std::cout << "testing " << vAngle << std::endl;

            if(vAngle > angle - deltaAngle && vAngle < angle+deltaAngle){
                std::cout << "passed " << fir << ", " << sec << std::endl;
                vector = add(vector,{0,initM,0});
                std::cout << "vecadd " << fir << ", " << sec << std::endl;
                std::list<std::array<double,3>> gameticks = getGt(initL, vector, destC);
                std::cout << "getgt " << fir << ", " << sec << std::endl;
                dests.emplace_back(pythag(gameticks.front()[0],gameticks.front()[2],destC[0],destC[2]),fir,sec,gameticks);
                std::cout << "done " << fir << ", " << sec << std::endl;
            }
        }
    }
    std::cout << "done" << std::endl;
    return dests;
    /*std::array<double,3> nwp = getTntAccel(initL,getTntCoord(0,alignX,alignZ,tntHeight));
    std::cout << nwp[0] << ", " << nwp[1] << ", " << nwp[2] << std::endl;*/

    //double targetX =
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
        case 2:
            coord[0] = alX+1.88499999046326;
            coord[2] = alZ+0.88499999046326;
        case 3:
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
        case 2:
            return pn;
        case 3:
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
        case 2:
            return pp;
        case 3:
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
    std::array<double,3> initL2 = initL2;

    while(true){
        std::array<double,3> initL2 = add(initL2,vec);
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

double pythag(double a1, double a2, double b1, double b2){
    return sqrt(pow(a1-a2, 2)+pow(b1-b2,2));
}