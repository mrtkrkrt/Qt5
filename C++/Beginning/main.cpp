#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // VARIABLES

    // signed, unsigned, long, short -> integer
    // signed, unsigned -> char
    // long -> double (apply)

    // You can simply use the word unsigned, short, or long, without int.
    unsigned x;
    unsigned int y;

    // Difference between signed and unsigned
        // The unsigned terms means we can only hıold positive numbers
        // The term signed in computer code indicates that a variable can hold negative and positive values
        // For char's, the rane of unsigned char is to 0 to 256, while signed char range is -127 to 127
    short int i;
    short unsigned j;

    j = 50000;
    i = j;

    cout << i << " " << j << endl; // -15536 50000


    // VARIABLE TYPES
        // Const -> cannot change in program
        // Volatile -> prevent the compiler from optimizing code. In other saying, variable's value may be changed in ways not explicitly specified by the program.
        // Restrict -> A pointer qualified by restrict is initially the only means by which the object it points to can be accessed ?


    // STORAGE CLASSES
        // auto ->  storage class is the default storage class for all local variables.
        int mount; 
        auto int mount; // Two variables with the same storage class, auto can only use within func, local variables etc.

        // register -> storage class is used to define local variables that should be stored in a register instead of RAM
        // This means that the variable has a maximum size equal to the register size (usually one word) and can't have the unary '&' operator applied to it (as it does not have a memory location)
        register int mount; // register should only be use for variables that require quick access. 

        // The static storage class instructs the compiler to keep a local variable in existence during the life-time of the program instead of creating and destroying it each time it comes into and goes out of scope. 
        // Therefore, making local variables static allows them to maintain their values between function calls.
        static int count = 10;
        
        // extern -> storage class is used to give a reference of a global variable that is visible to ALL the program files. 
        // When you use 'extern' the variable cannot be initialized as all it does is point the variable name at a storage location that has been previously defined.
        // The extern modifier is most commonly used when there are two or more files sharing the same global variables or functions
}
