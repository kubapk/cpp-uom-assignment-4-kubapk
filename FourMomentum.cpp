/*
____________________________________________
FOUR MOMENTUM IMPLEMENTATION
(Part of PHYS30762 Assignment 4)
____________________________________________
This implementation file defines member functions for the "FourMomentum" class, 
as well as its constructor and assignment operator for copy and move operations.

Created by Kuba Kane (ID: 11019699)
Created on Tue 24 Mar 2026
*/

#include<iostream>
#include "FourMomentum.h"


//Copy constructor
FourMomentum::FourMomentum(const FourMomentum& fm) : 
    //Unique pointer does not allow copy so need to extend  copy semantics to implement 
    //copy constructor manually - use deep copy
    //fm is a reference to FourMomentum, whose only data member is a unique pointer
    //to a vector of 4 doubles
    //Unique pointer does not require memory to be dynamically allocated, and then
    //have elements copied 1 by 1
    //Can instead use copy constructor from vector class

    //Initialise unique_ptr called "four_momentum_ptr" (just like default constructor), using 
    //make_unique, and in the brackets put the vector which it should copy
    //To get this vector, note fm is FourMomentum object, we just want pointer to four momentum
    //class
    four_momentum_ptr{std::make_unique<vector<double>>(*fm.four_momentum_ptr)} 
    {std::cout<<"Calling FourMomentum copy constructor"<<std::endl;}
    //copy constructor uses initialisation rather than assignment


//Copy assignment operator
FourMomentum& FourMomentum::operator=(const FourMomentum& fm)
{
    std::cout<<"Calling FourMomentum assignment operator"<<std::endl;
    //Check for self-assignment
    if(&fm == this) return *this;
    //if fm as FourMomentum object (i.e. dereferenced fm) is same as object calling assignment
    //operator ("this"), then just return "this"

    //Smart pointers handle dynamic memory allocation and so delete is not needed, we use vector
    //copy constructor
    four_momentum_ptr = std::make_unique<vector<double>>(*fm.four_momentum_ptr);
    return *this;
}


//Move constructor
FourMomentum::FourMomentum(FourMomentum&& fm) :
    four_momentum_ptr{std::move(fm.four_momentum_ptr)} 
    {std::cout<<"Calling FourMomentum move constructor"<<std::endl;}
    //Standard library unique pointers allow us to transfer ownership (to a different object) using
    //std::move - this transfers the pointers with each other, so the new four_momentum_ptr becomes
    //the four_momentum_ptr of "fm"


//Move assignment operator
FourMomentum& FourMomentum::operator=(FourMomentum&& fm)
{
    std::cout<<"Calling FourMomentum move assignment operator"<<std::endl;
    if(&fm == this) return *this;

    four_momentum_ptr = std::move(fm.four_momentum_ptr);
    return *this; //returns dereferenced four_momentum_ptr
}

