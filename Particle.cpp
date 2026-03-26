/*
____________________________________________
PARTICLE IMPLEMENTATION
(Part of PHYS30762 Assignment 4)
____________________________________________
This implementation file defines setters, constructors, and assignment
operators for the "Particle" class.

Created by Kuba Kane (ID: 11019699)
Created on Wed 25 Mar 2026
*/

#include<iostream>
#include "Particle.h"


//CONSTRUCTORS
//Paramterised constructor
Particle::Particle(const string& name_in, const FourMomentum& momentum_in)
{
    //Name check is done via setter to avoid code repetition
    set_name(name_in);
    set_four_momentum(momentum_in);
    //four_momentum_in can be passed in by the user using paramterised constructor FourMomentum(E, px, py, pz)
}


//Copy constructor
//Move constructor

//ASSIGNMENT OPERATORS


//SETTERS
//Setter for particle name
void Particle::set_name(const string name_in)
{
    //Check name is valid
    name = name_in;
}
