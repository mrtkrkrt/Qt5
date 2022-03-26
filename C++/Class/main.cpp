#include <QCoreApplication>
#include "laptop.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    laptop mine(0, "my laptop");
    // nullpointer and zero pretty much same thing
    laptop yours(&a, "your laptop");

    // Friend functions -> A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class. 
        // Even though the prototypes for friend functions appear in the class definition, friends are not member functions.
        // A friend can be a function, function template, or member function, or a class or class template, in which case the entire class and all of its members are friends.

    // Inline function -> C++ inline function is powerful concept that is commonly used with classes. 
        // If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time.
    return a.exec();
}
