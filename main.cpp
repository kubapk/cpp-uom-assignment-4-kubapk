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

void print_text_middle(const string text, const int length)
{
    std::cout<<string(length, '=')<<text<<string(length, '=')<<std::endl;
}

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

    //Print out all vectors
    for(size_t i{}; i<particles.size(); i++)
    {
        std::cout<<particles[i]<<"\n"<<std::endl;
    }


    std::cout<<"\nSum of the four momenta of the 2 electrons\n"<<string(60, '-')<<std::endl;
    std::cout<<particles[0].get_four_momentum()+particles[1].get_four_momentum()<<std::endl;
    std::cout<<string(60, '-')<<"\n"<<std::endl;


    std::cout<<"\nDot product of first two muons\n"<<string(60, '-')<<std::endl;
    std::cout<<particles[2].get_four_momentum().dotProduct(particles[3].get_four_momentum())<<std::endl;
    std::cout<<string(60, '-')<<"\n"<<std::endl;


    std::cout<<"\nAssignment operator of first electron to a new electron\n"<<string(60, '-')<<std::endl;
    //Assignmnent requires the new electron to already exist
    Particle new_electron("electron", FourMomentum()); //uses default FourMomentum
    new_electron = particles[0];
    std::cout<<"New electron is: \n" <<particles[0] <<std::endl;
    std::cout<<string(60, '-')<<"\n"<<std::endl;


    std::cout<<"\nCopy constructor of the first muon to a new muon\n"<<string(60, '-')<<std::endl;
    //Copy constructor declares new muon on same line as copy
    Particle new_muon = particles[2];
    std::cout<<"New muon is: \n" <<particles[2] <<std::endl;
    std::cout<<string(60, '-')<<"\n"<<std::endl;


    std::cout<<"\nMove electron using move constructor\n"<<string(60, '-')<<std::endl;
    //Copy constructor declares moved electron on same line as copy
    Particle moved_electron = std::move(particles[0]);
    std::cout<<string(60, '-')<<"\n"<<std::endl;


    std::cout<<"\nMove muon using move assignment\n"<<string(60, '-')<<std::endl;
    //Assignment declared moved muon first
    Particle moved_muon("muon", FourMomentum());
    moved_muon = std::move(particles[2]);
    std::cout<<string(60, '-')<<"\n"<<std::endl;

    return 0;
}