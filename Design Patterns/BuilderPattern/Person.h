#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {

private:
    std::string name, surname, adress;

public:

    Person(Builder builder){
        this->name = builder.name;
        this->surname = builder.surname;
        this->adress = builder.adress;
    }

    std::string getName(){
        return this->name;
    }

    std::string getSurname(){
        return this->surname;
    }

    std::string getAdress(){
        return this->adress;
    }

    static class Builder{
    private:
        std::string name, surname, adress;
    public:
        Builder(){}
        Builder (std::string name){
            this->name = name;
        }

        Builder (std::string surname){
            this->surname = surname;
        }

        Builder (std::string adress){
            this->adress = adress;
        }
    };
};

#endif // PERSON_H
