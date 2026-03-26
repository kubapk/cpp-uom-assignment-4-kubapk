### Kuba Kane
# PHYS30762 Assignment 4 - Practising Overloading Special Functions/Operators in Classes


## User Guidelines
### Running the program as-is
This code was run on VSC using a Windows 11 device. The compilation line used was `g++ -std=c++17 main.cpp Particle.cpp FourMomentum.cpp -o main.exe`. The program can then be run by calling the file `main.exe`.


## Program Reasoning
### FourMomentum as a separate class
 - Having four momentum as a separate class makes more sense because it is a property of a particle with its own characteristics
 - A particle does not need the details of these characteristics, so particle need not be a class inherented from four momentum class
 - This project required four-momentum to be implemented as a pointer to a dynamically allocated vector 
   - Option 1: Implement FourMomentum class with members E, px, py, pz and then initialise a vector (with dynamically allocated memory) in
   the Particle class, which copies each member of FourMomentum using the getters inside the FourMomentum class and pushes them to the vector.
   - Option 2: Implement FourMomentum object as a vector storing E, px, py, pz, and keep this format 
   - Option 2 is better as option 1 forces a deep copy to be made of the members of the FourMomentum class, and can tberefore lead to issues
   since there are 2 copies of the data, e.g. if x momentum is updated in FourMomentum class, it does not update the x momentum for the 
  corresponding particle class.

### Passing by reference or by value
 - Passed by reference in constructor of Particle class as it takes in FourMomentum object which need not be copied, while passed by value in constructor of FourMomentum class as it takes in doubles which are not expensive to copy.

### Copy constructor
 - Instead of manually copying the four vector elements of FourMomentum, can use vector copy constructor, to initialise a vector by copying a given vector. The copy constructor takes in a FourMomentum object which is to be copied. We first need to access its private member, "four_momentum_ptr" to get the unique pointer to this object's vector containing 4 doubles (E, px, py, pz). This can be dereferenced to get the actual vector to be copied, which can be passed into a new vector and copied with the vector copy constructor. This can be then made into a unique pointer, which the object in the copy constructor (the object which the copy should go to) can be initialised with. This achieves the copy without manually copying each element of the vector (which would require a size data member of the FourMomentum class).

### Operator overloading
 - Should these be implemented as member functions, friend functions, or non-member functions? To keep in line with encapsulation, since the operations dot product and sum only deal with FourMomentum objects (and their data members), they should not be non-member functions. As such, there is also no need to consider them as friend functions - all the data members they need are in the FourMomentum class.
 - Issue with the + operator in FourMomentum class when I tried to have it return a pointer to a FourMomentum object, but inside the code it returned a FourMomentum object initiated inside the "+" operator function, which went out of scope and could not be pointed to. Resolved by enforcing the function to return FourMomentum object (not pointer), resulting in no need for initiation of object - it can be simply specified on return line.

 ### Paramterised constructor 
 - Use initialiser list or assignment inside parameterised constructor? To be more memory efficient, it is better to use initialisers where possible, since using assignment means the objects are initialised using default constructor first, and then the rvalues are assigned ("copied") to them. This costs an extra unecessary step.

 ### Constructors / assignment operators in Particle class
 - Use default? If print message required, need to define them manually


 ## References
 [1] https://www.studyplan.dev/pro-cpp/copy-semantics#using-unique-pointers
 [2] https://www.studyplan.dev/pro-cpp/move-semantics