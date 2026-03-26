/*
_____________________________TITLE_____________________________
PHYS30762 Assignment 4 - Practising Overloading Special 
Functions/Operators in Classes
_______________________________________________________________
This C++ script...

Created by Kuba Kane (ID: 11019699)
Created on Wed 25 Mar 2026
*/

#include<iostream>
#include<vector>
#include "Particle.h"
#include "FourMomentum.h"
using std::vector;


int main()
{
    //Create empty vector of Particle objects
    vector<Particle> particles;

    //Add particles to vector
    particles.push_back(Particle("electron", FourMomentum(10, 1, 2, 3)));
    particles.push_back(Particle("electron", FourMomentum(20, 0, 1, 1)));
    particles.push_back(Particle("muon", FourMomentum(30, 1, 1, 1)));
    particles.push_back(Particle("muon", FourMomentum(25, 1, 0, 1)));
    particles.push_back(Particle("muon", FourMomentum(34, 1, 0, 1)));
    particles.push_back(Particle("muon", FourMomentum(15, 0, 2, 1)));
    particles.push_back(Particle("tau", FourMomentum(10, 1, 2, 1)));
    particles.push_back(Particle("tau", FourMomentum(25, 2, 3, 1)));
    //PUSH BACK OR emplace_back

    //Initialise a FourMomentum object using parameterised constructor
    FourMomentum neutron{10, 1, 2, 3};

    return 0;
}