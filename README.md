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
 
 - Option 2 is better as option 1 forces a deep copy to be made of the members of the FourMomentum class, and can tberefore lead to issues since there are 2 copies of the data, e.g. if x momentum is updated in FourMomentum class, it does not update the x momentum for the corresponding particle class.

### Passing by reference or by value
 - Passed by reference in constructor of Particle class as it takes in FourMomentum object which need not be copied, while passed by value in constructor of FourMomentum class as it takes in doubles which are not expensive to copy. CHECK THIS

### Copy constructor
 - Instead of manually copying the four vector elements of FourMomentum, can use vector copy constructor, to initialise a vector by copying a given vector. The copy constructor takes in a FourMomentum object which is to be copied. We first need to access its private member, "four_momentum_ptr" to get the unique pointer to this object's vector containing 4 doubles (E, px, py, pz). This can be dereferenced to get the actual vector to be copied, which can be passed into a new vector and copied with the vector copy constructor. This can be then made into a unique pointer, which the object in the copy constructor (the object which the copy should go to) can be initialised with. This achieves the copy without manually copying each element of the vector (which would require a size data member of the FourMomentum class).

### Operator overloading
 - Should these be implemented as member functions, friend functions, or non-member functions? To keep in line with encapsulation, since the operations dot product and sum only deal with FourMomentum objects (and their data members), they should not be non-member functions. As such, there is also no need to consider them as friend functions - all the data members they need are in the FourMomentum class.
 - Issue with the + operator in FourMomentum class when I tried to have it return a pointer to a FourMomentum object, because inside the code it returned a FourMomentum object which was initiated inside the + operator function. This went out of scope and could not be pointed to. This was resolved by enforcing the function to return FourMomentum object (not a pointer). It was also uncessary to initiate a temporary object inside the function - it can be simply specified on the return line.

### Paramterised constructor 
 - Use initialiser list or assignment inside parameterised constructor? To be more memory efficient, it is better to use initialisers where possible, since using assignment means the objects are initialised using default constructor first, and then the rvalues are assigned ("copied") to them. This costs an extra unecessary step.

### Minimising constructor / assignment operator calls
 - When performing the sum of the four momenta and the dot product, 2 copy constructors were called before the operation was performed. This is because the getters of the Particle and FourMomentum class were passed by value, which creates a deep copy as per the copy constructor. Both the sum and the four momenta (used in main) call .get_four_momentum() twice (one for both particles), hence calling copy constructor twice. This was resolved by passing all getters of both classes by reference. 
 
 - The sum of the four momenta calls the destructor as the + operator requires intialisation of a FourMomentum object on the return line which goes out of socpe when the function ends. The dot product does not require initialisation of a FourMomentum object as an object is passed into the DotProduct function, which is only destructed at the end of the program.

 - The copy assignment operator used in main (used to copy the first electron to a new electron) called the copy constructor first unecessarily. This occured because using the asisgnment operator required initialisation of a new electron via the Particle class parameterised constructor, which uses `set_four_momentum` to initialise the FourMomentum object as the user inputted FourMomentum object. This uses copy assignment operator, hence this line can be seen. However, an unecessary copy constructor was used because the `set_four_momentum` passed the user input by value. This was resolved by instead passing by reference.

### Constructors / assignment operators
 - The Particle class is set to use the default constructors and assignment operators for both copy and move operations, since the Particle class contains only string (`name`) and FourMomentum (`momentum`) objects. The string will use deep copy by default, and the FourMomentum object will use the constructors / assignment operators defined in the FourMomentum class.


 ## References
 [1] https://www.studyplan.dev/pro-cpp/copy-semantics#using-unique-pointers
 [2] https://www.studyplan.dev/pro-cpp/move-semantics
 [3] https://andreasfertig.com/blog/2023/04/push_back-vs-emplace_back-when-to-use-what/


 ##TO DO
 - Move all constructors & ops incl setters & getters to implementation file