#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>

class Singleton {

protected:
    /**
     * The Singleton's constructor should always be private to prevent direct
     * construction calls with the `new` operator.
     */
    Singleton(const std::string value) {

    }

    static Singleton* singleton;
    std::string value_;

public:
    /**
     * Singletons should not be cloneable.
     */
    Singleton(Singleton &other) = delete;
    /**
     * Singletons should not be assignale.
     */
    void operator=(const Singleton &) = delete;
    static Singleton *GetInstance(const std::string& value);
    void SomeBusinessLogic()
    {
        // ...
    }

    std::string value() const{
        return value_;
    }
};

/**
 * Static methods should be defined outside the class.
 */
Singleton *Singleton::GetInstance(const std::string &value){
    Singleton* singleton_= new Singleton(value);
    return singleton_;
}

#endif // SINGLETON_H
