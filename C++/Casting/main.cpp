#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // IMPLICIT AND EXPLICIT CASTING
    double value = 43.08;
    qInfo() << "Value: " << value;

    int implicitValue = value;
    qInfo() << "Implicit Value: " << implicitValue; // It is an implicit conversion should not be trusted

    int explicitValue = (int)value; // CASTED OLD STYLE
    qInfo() << "Explicit Value: " << explicitValue; // It is an explicit conversion shouls be trusted

    // DYNAMIC CASTING
        // It can be used only with pointers and references to objects
        // Its purpose is to ensure that the result of the tyoe conversion is a valis complete object of the requested class
        // For ex. Child* child = dynamic_cast<Child*>(parent) parent is an instance of parent class

    // STATIC CASTING
        // THe static cast operator performs a nonpolyformphic cast
        // For ex. it can be used tı cast a base class pointer into a derived class pointer.
        // Upcasting -> going from the the car to the racecar
        // We can go from base back to the derived because the classes we created are polymorphic
        // Static cast should work fine -> This is the way to go from a base to a derived class  saftly!!!

    // REINTERPRET CAST
        // Unlike static_cast, but like const_cast, the reinterpret_cast expression does not compile t any CPU instructions
        // (except when converting between integers and pointers or on obscure architectures where pointer representation
        // depends on its type). It is purely a compile-time directive which instructs the compiler to treat expression as if
        // it had the type new_type.

    return a.exec();
}
