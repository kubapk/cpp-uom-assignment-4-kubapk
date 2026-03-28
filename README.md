### Kuba Kane
# PHYS30762 Assignment 4 - Practising Overloading Special Functions/Operators in Classes

> [!IMPORTANT]
> ### Program summary
> This program allows you to define particles with a name and a FourMomentum object, which consists of an energy, as well as a momentum in the x, y, and z directions. Four momenta of particles can be summed via the `+` operator, and their dot product can be found by calling `.dotProduct()`. This is called by a FourMomentum object, and takes in a FourMomentum object with which the dot product is to be performed.
>
> The following classes are defined in this program:
> - **FourMomentum:** Contains a unique smart pointer to a vector of 4 doubles, whose elements correspond to the energy, x momentum, y momentum, and z momentum. These elements are set to 0 if FourMomentum objects are intialised via the default constructor, and can be set to any doubles (as long as energy is not negative) via the parameterised constructors or setters. Each element of the vector can be retrieved using getters. Given the vector is intialised via a smart pointer, copy and move constructors and assignment operators are defined, making use of the vector copy constructor and `std::move`. This class also contains a private member method `validate_energy` used to check energy is not negative.
> - **Particle:** Contains a name (string) and FourMomentum object (from class above). The default constructor sets name to "electron" and uses default FourMomentum constructor to set energy and momentum values. The copy and move constructors and assignment operators are set to default, as string object will use the copy and move semantics required in this case, and the FourMomentum object will use the semantics defined in the FourMomentum class. The private member method `validate_name` returns the name as long as it is one of the 18 particles in the standard model.
>
> Both classes have friend functions which overload the `<<` operator to enable a Particle or FourMomentum object to be printed using `std::cout`.


## User Guidelines
### Running the program as-is
This code was run on VSC using a Windows 11 device. The compilation line used was `g++ -std=c++17 main.cpp Particle.cpp FourMomentum.cpp -o main.exe -Wall`. The program can then be run by calling the file `main.exe`.

### Modifying the main file, `main.cpp`
These guidelines are for a user who wishes to use the classes in this program, but modify the main file provided (or make their own). Intialising a particle is easiest via the parameterised constructor of the Particle and FourMomentum class, i.e. `Particle(<particle-name>, FourMomentum(<E>, <px>, <py>, <pz>))`, where E, px, py, pz are the energy and momenta in the x, y, z directions.

The particle name must be in the list of valid names (containted within a private member function in the Particle class). The valid particles are given below. Note that these are case-sensitive and must be entered exactly as seen below.

```
electron
muon
tau
electron neutrino
muon neutrino
tau neutrino
up
charm
top
down
strange
bottom
photon 
gluon
positive W boson
negative W boson
Z boson
Higgs bosson
```

You can check if the move semantics work by uncommenting the lines which print First muon and First electron (sections 5 and 6 in `main.cpp`). Doing so will return an error, given that it cannot print out the Particle object which has been moved from, as its pointer would have become null. This is handled by the smart pointer.

Within the main file, FourMomentum can be adjusted using setters after it is declared. If you wish to make changes to how four momenta works, any changes should be made within the FourMomentum class (and not in the main file) to adhere to encapsulation. An example idea of how FourMomentum could be changed is provided in the *Physics Behind the Program* section, modifying the constructors and getters/setters to disallow an energy input. Despite this, there is no instance when the non-negativity constraint on the energy should be removed.


## Physics Behind the Program
### Conventions used in the program
Each particle is described by a four vector, following the convention for four momentum in natural units (c=1), and enforcing the constraint that the energy should not be 0. The units of all components are MeV. To perform the dot product, the Minkowski metric is used with the (+, -, -, -) convention, such that $p \cdot q = E_p E_q - p_x q_x - p_y q_y - p_z q_z$.

### Making the program more physically accurate
The program could be improved by taking advantage of the equation $m^2 = E^2 - p^2$. Since all 18 particles in the standard model have a defined mass, a `std::map` could contain each particle name as the key and its mass as the value. When in the main file a Particle is initialised with a given name, this could be mapped to find the corresponding mass. As a result, the FourMomentum constructors would only require the 3 momenta inputs, and could push back the energy to the four momentum vector using the aforementioned equation. This would make the program more accurate in terms of the physics, as otherwise the user could enter E and p which breaks the equation. 


## Program Design & Reasoning
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

### Using implementation files
 - All constructors (default, parameterised, copy, move), assignment operators (copy, move), and setters and getters have been specified in the implementation file unless they are trivial (fit in one line, with no sub-scopes).


### Object input validation
 - Unlike assignment 3, it is not purposeful to use a validation file to check particles for their properties. Firstly, the energy and momentum of the particle is not a set value for a given particle, and there could many instances of the same particle with different energy or momenta. Secondly, there are only 17+1 particles in the Standard Model, and so only 18 possible names that should be allowed for the particles. Implementing these in a validation file would allow the user to edit them more easily, and also potentially break the program if the format was changed.
 - The valid particle names are therefore managed as a private static method in the Particle class, disallowing any setters or getters which could modify the list. This method checks if the inputted particle name is valid by comparing it to a valid particle name list. Static ensures that during run time the list inside the function cannot be modified - belongs to the class rather than any specific object of the class (so Particle cannot call it directly).
 - Use `std::unordered_set` to store the valid particles instead of `std::vector` as sets ensure the elements are unique, and unordered sets use average constant time O(1) for insert, search and delete operations (same as vectors).
 - Due to the requirement of pushing back the four-vector elements to the four momentum pointer in the parameterised constructor, it was not possible to use the energy setter within the parameterised constructor. This is because if the paramterised constructor is called before any other constructor, then the vector which `four_momentum_ptr` points to would be empty, while `set_E` requires the element to already exist (`(*four_momentum_ptr)[0]`). As a result, both the paramterised constructor and energy setter need to check the energy is not negative, hence the introduction of `validate_energy` private method in FourMomentum class (avoids repeating code for energy validation).
 - Originally had the Particle class default constructor set name to "unamed", but this was changed to "electron" so that it was a valid particle (as specified in unordered set of valid particles).


## Disclosure of Delegation to Generative AI
The author (Kuba Kane) declares the use of generative AI in the research and coding process. The following tasks were delegated to GAI tools under full human supervision:

- Idea generation
- Code generation
- Code optimisation
- Code debugging

The GAI tool used for these tasks was: ChatGPT-5.2.

The author declares that the work does not contain any AI-generated code. GAI was used as a source of information for explaining code only, and as an inspiration to write original code.

Responsibility for the final manuscript lies entirely with the author.

GAI tools are not listed as authors and do not bear responsibility for the final outcomes.


## References
The following sources were used in the research for this assignment.

[1] https://www.studyplan.dev/pro-cpp/copy-semantics#using-unique-pointers

[2] https://www.studyplan.dev/pro-cpp/move-semantics

[3] https://andreasfertig.com/blog/2023/04/push_back-vs-emplace_back-when-to-use-what/

[4] https://www.geeksforgeeks.org/cpp/unordered_set-in-cpp-stl/

[5] https://www.geeksforgeeks.org/cpp/difference-between-stdset-vs-stdvector-in-c-stl/

[6] https://www.geeksforgeeks.org/cpp/static-member-function-in-cpp/
