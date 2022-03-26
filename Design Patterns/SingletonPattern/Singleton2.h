#ifndef SINGLETON2_H
#define SINGLETON2_H

class Singleton2{
    static Singleton2 *instance;
    int data = 0;

    Singleton2(){
        data = 0;
    }

public:
    static Singleton2 *getInstance(){
        if(!instance){
            instance = new Singleton2();
        }
        return instance;
    }
};

#endif // SINGLETON2_H
