/*
____________________________________________
FOUR MOMENTUM CLASS
(Part of PHYS30762 Assignment 4)
____________________________________________
This header file defines a class for a particle.

Created by Kuba Kane (ID: 11019699)
Created on Sun 22 Mar 2026
*/

//Include guard
#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include<iostream>
#include<vector>
#include<memory> //to use unique_ptr
using std::vector;

class FourMomentum
{
private:
    std::unique_ptr<vector<double>> four_momentum_ptr;
    //Declare "four_momentum_ptr" as a unique pointer to a vector of doubles
public:
    //Default constructor
    FourMomentum()
    {
        //Initialise unique pointer, pointing to a vector of 4 doubles each allocated as "0.0" 
        four_momentum_ptr = std::make_unique<vector<double>>(4, 0.0);
    }
    //BETTER TO USE NIEL'S WAY OF DOING THIS

    //Paramterised constructor
    FourMomentum(const double energy_in, const double x_momentum_in, const double y_momentum_in, const double z_momentum_in)
    {
        //Check energy is not less than 0

        four_momentum_ptr = std::make_unique<vector<double>>();
        (*four_momentum_ptr).push_back(energy_in);
        (*four_momentum_ptr).push_back(x_momentum_in);
        (*four_momentum_ptr).push_back(y_momentum_in);
        (*four_momentum_ptr).push_back(z_momentum_in);
    }

    //Destructor
    ~FourMomentum() {}

    //Setters
    void set_E(const double energy_in)
    {
        //Check energy is not less than 0

        (*four_momentum_ptr)[0] = energy_in;
    }

    void set_px(const double x_momentum_in) {(*four_momentum_ptr)[1] = x_momentum_in;}
    void set_py(const double z_momentum_in) {(*four_momentum_ptr)[1] = z_momentum_in;}
    void set_pz(const double y_momentum_in) {(*four_momentum_ptr)[1] = y_momentum_in;}
    //Not const funcs as four momentum is modified

    //Getters
    double get_E() const {return (*four_momentum_ptr)[0];}
    double get_px() const {return (*four_momentum_ptr)[1];}
    double get_py() const {return (*four_momentum_ptr)[2];}
    double get_pz() const {return (*four_momentum_ptr)[3];}

    //Assignment operator

    //Copy constructor
    //Unique pointer does not allow copy

    //Destructor

    //Move constructor 

    //Move assignment operator

    //Member functions (overload operators)

};


#endif