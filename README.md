### Kuba Kane
# PHYS30762 Assignment 4 - Practising Overloading Special Functions/Operators in Classes


## User Guidelines
### Running the program as-is
This code was run on VSC using a Windows 11 device. The compilation line used was tbc. The program can then be run by calling the file tbc.


## Program Reasoning
### FourMomentum as a separate class
 - Having four momentum as a separate class makes more sense because it is a property of a particle with its own characteristics
 - A particle does not need the details of these characteristics, so particle need not be a class inherented from four momentum class
 - This project required four-momentum to be implemented as a pointer to a dynamically allocated vector 
  - Option 1: Implement FourMomentum class with members E, px, py, pz and then initialise a vector (with dynamically allocated memory) in
  the Particle class, which copies each member of FourMomentum using the getters inside the FourMomentum class and pushes them to th vector.
  - Option 2: Implement FourMomentum object as a vector storing E, px, py, pz, and keep this format 
  - Option 2 is better as option 1 forces a deep copy to be made of the members of the FourMomentum class, and can tberefore lead to issues
  since there are 2 copies of the data, e.g. if x momentum is updated in FourMomentum class, it does not update the x momentum for the 
  corresponding particle class.

### Passing by reference or by value
 - Passed by reference in constructor of Particle class as it takes in FourMomentum object which need not be copied, while passed by value in 
 constructor of FourMomentum class as it takes in doubles which are not expensive to copy.