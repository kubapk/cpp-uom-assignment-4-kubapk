/*
____________________________________________
PARTICLE CLASS
(Part of PHYS30762 Assignment 4)
____________________________________________
This header file defines a class for a particle.

Created by Kuba Kane (ID: 11019699)
Created on Sun 22 Mar 2026
*/

//Include guard
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
    FourMomentum momentum;
    //FourMomentum is an object whose only data member is a unique_ptr, which need not be specified
    //as it is handled by the default constructor within FourMomentum class (which specifies the unique
    //ptr to a vector of four "0.0")

public:
    //Default constructor
    Particle() = default;

    //Paramterised constructor
    Particle(const string& name_in, const FourMomentum& four_momentum_in) :
    //Since the objects are large here, they are passed by reference to avoid uncessary copying
    //Use initialiser list wherever possible
    {
        momentum = four_momentum_in;

        //Check particle name is valid
        name = name_in;

    } 
    
    //Destructor
};


#endif