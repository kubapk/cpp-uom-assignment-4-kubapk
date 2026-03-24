/*
____________________________________________
FOUR MOMENTUM CLASS
(Part of PHYS30762 Assignment 4)
____________________________________________
This header file defines a class for a particle.

Created by Kuba Kane (ID: 11019699)
Created on Sun 22 Mar 2026
*/

//Include gaurd
#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;

class FourMomentum
{
private:
    vector<FourMomentum>* 
    //Four-momentum is as a pointer to a dynamically allocated vector
    //For now we use a vector pointer and when we allocate it we declare it as dynamically allocated
public:
    //Default constructor
    FourMomentum() = default;

    //Paramterised constructor
    FourMomentum(const double energy_in, const double x_momentum_in, const double y_momentum_in, const double z_momentum_in) :
        energy{energy_in}, x_momentum{x_momentum_in}, y_momentum{y_momentum_in}, z_momentum{z_momentum_in} {}

    //Destructor
    ~FourMomentum() {}
};


#endif