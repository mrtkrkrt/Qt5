#include <QCoreApplication>

/* In software engineering, the singleton pattern is a software design pattern that restricts the instantiation of a
 * class to one "single" instance. This is useful when exactly one object is needed to coordinate actions across the system.
*/
/*Use a Singleton if:
    You need to have one and only one object of a type in system

Do not use a Singleton if:
    You want to save memory
    You want to try something new
    You want to show off how much you know
    Because everyone else is doing it (See cargo cult programmer in wikipedia)
    In user interface widgets
    It is supposed to be a cache
    In strings
    In Sessions
    I can go all day long

How to create the best singleton:
    The smaller, the better. I am a minimalist
    Make sure it is thread safe
    Make sure it is never null
    Make sure it is created only once
    Lazy or system initialization? Up to your requirements
    Sometimes the OS or the JVM creates singletons for you (e.g. in Java every class definition is a singleton)
    Provide a destructor or somehow figure out how to dispose resources
    Use little memory */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
