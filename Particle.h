/*
____________________________________________
PARTICLE CLASS
(Part of PHYS30762 Assignment 4)
____________________________________________
This header file defines a class for a particle.

Created by Kuba Kane (ID: 11019699)
Created on Sun 22 Mar 2026
*/

//Include gaurd
#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include "FourMomentum.h"
using std::string;

class Particle
{
private:
    string name{"unnamed"};
    FourMomentum momentum{0, 0, 0, 0};

public:
    //Default constructor
    //Paramterised constructor
    //Destructor
};


#endif