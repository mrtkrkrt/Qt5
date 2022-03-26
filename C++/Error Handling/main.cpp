#include <QCoreApplication>
#include <QDebug>
#include <iostream>

using namespace std;

//TRY - CATCH
bool doDivision(int max) {
    try {
        int value;
        qInfo() << "Enter a number";
        cin >> value;

        if(value == 0) throw "Can not divide by zero!";
        if(value > 5) throw 99;
        if(value == 1) throw std::runtime_error("Should be greater than 1 !!!");

        int result = max / value;
        qInfo() << "Result = " << result;


    } catch(std::exception const& e) {
        qWarning() << "We caught the STD way: " << e.what();
        return false;
    } catch(int e) {
        qWarning() << "We caught a number" << e;
        return false;
    } catch (char* e){
        qWarning() << "We caught a pointer to char* " << e;
        return false;
    } catch (...) {
        //Catch all = BAD BAD BAD
        qWarning() << "We know something went wrong, but we dont know what.";
       return false;
    }

    return true;
}

// QT-HANDLING
bool doDivision(int max) {

    int value;
    qInfo() << "Enter a number";
    cin >> value;

    //if(value == 0) throw "Can not divide by zero!";
    //if(value > 5) throw 99;
    //if(value == 1) throw std::runtime_error("Should be greater than 1 !!!");

    if(value == 0 || value == NULL) {
        qWarning() << "Can not be zero";
        return false;
    }

    if(value > 5) {
        qWarning() << "Should be less than 5";
        return false;
    }

    if(value == 1) {
        qWarning() << "Should be greater than 1";
        return false;
    }

    int result = max / value;
    qInfo() << "Result = " << result;

    return true;
}

// SANDART HANDLING
bool doDivision(int max) {

    try {
        int value;
        qInfo() << "Enter a number";
        cin >> value;

        if(value == 0 || value == NULL) throw std::invalid_argument( "Can not divide by zero!");
        if(value > 5) throw std::out_of_range( "Should be less than 5");


        int result = max / value;
        qInfo() << "Result = " << result;

        return true;
    } catch (std::exception &e ) {
        qWarning() << e.what();
        return false;
    }
}

// CUSTOM HANDLING
struct MyIssue : public exception {
    const char * description;
    const char * what()  const throw () {
        return "My Issue";
    }
};

bool doDivision(int max) {

    try {
        int value;
        qInfo() << "Enter a number";
        cin >> value;

        if(value == 0 || value == NULL) throw std::invalid_argument( "Can not divide by zero!");
        if(value > 5) throw std::out_of_range( "Should be less than 5");

        if(value ==1) {
            MyIssue e;
            e.description = "Can not be 1";
            throw e;
        }

        int result = max / value;
        qInfo() << "Result = " << result;

        return true;
    } catch(MyIssue &e) {
        qWarning() << e.what() << " " << e.description;

        return false;
    } catch (std::exception &e ) {
        qWarning() << e.what();

        return false;
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
