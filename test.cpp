#include<iostream>
#include<vector>
#include <stdexcept>
#include "Particle.h"
#include "FourMomentum.h"
using std::vector;


int main()
{
    try
    {
        //Create new particle
        Particle electron_test{Particle("electron", FourMomentum(10, 2, 3, 1))};

        //Print out particle
        std::cout<<electron_test<<"\n"<<std::endl;

        //Change momentum
        electron_test.get_four_momentum().set_px(5);
        std::cout<<electron_test<<"\n"<<std::endl;

        //Change particle name
        electron_test.set_name("muon");
        std::cout<<electron_test<<"\n"<<std::endl;

        //Change momentum
        electron_test.set_four_momentum(FourMomentum(0, 1, 1, 1));
        std::cout<<electron_test<<"\n"<<std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
        return 1;
    }

    return 0;
}