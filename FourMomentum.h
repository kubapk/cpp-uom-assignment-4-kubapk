/*
____________________________________________
FOUR MOMENTUM CLASS
(Part of PHYS30762 Assignment 4)
____________________________________________
This header file (interface) defines a class for a particle.

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
    FourMomentum() :
        //Initialise unique pointer, pointing to a vector of 4 doubles each allocated as "0.0"
        four_momentum_ptr{std::make_unique<vector<double>>(4, 0.0)} {}
        //Uses intialiser list (in case of consts)

    //Declare paramterised constructor
    FourMomentum(const double energy_in, const double x_momentum_in, const double y_momentum_in, 
        const double z_momentum_in);

    //Destructor
    ~FourMomentum() {std::cout<<"Calling FourMomentum destructor"<<std::endl;}

    //Declare copy constructors
    FourMomentum(const FourMomentum&); //copy operation
    FourMomentum(FourMomentum&&); //move operation 
    //copy is const since copying should not change original copy
    //move is not const since FourMomentum pointer passed in will be given new pointer (null)

    //Declare assignment operators
    FourMomentum& operator=(const FourMomentum&); //copy operation
    FourMomentum& operator=(FourMomentum&&); //move operation

    //Setters
    void set_E(const double energy_in); //in implementation file
    void set_px(const double x_momentum_in) {(*four_momentum_ptr)[1] = x_momentum_in;}
    void set_py(const double z_momentum_in) {(*four_momentum_ptr)[1] = z_momentum_in;}
    void set_pz(const double y_momentum_in) {(*four_momentum_ptr)[1] = y_momentum_in;}
    //Not const funcs as four momentum is modified

    //Getters
    double get_E() const {return (*four_momentum_ptr)[0];}
    double get_px() const {return (*four_momentum_ptr)[1];}
    double get_py() const {return (*four_momentum_ptr)[2];}
    double get_pz() const {return (*four_momentum_ptr)[3];}

    //Prototyping member functions (overload operators)
    FourMomentum operator+(const FourMomentum& fm) const;
    double dotProduct(const FourMomentum& fm) const;
};


#endif