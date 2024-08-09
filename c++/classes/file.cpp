#include <iostream>
#include <string.h>



// class MyString {

// private:
//     char * data;
//     size_t length;

// public:


//     // default contructor
//     MyString() : data(nullptr), length(0) {}
//     // destructor ~
//     ~ MyString();

//     // Copy constructor 

//     // Copy assignment constructor 
// };


// int main() {

//     std::cout << "" << std::endl;

//     return 0;
// }


class Point{

private:
    int x;
    int y;

public:

// default constructor
Point(){};

// parametrized constructor 
Point(int i, int j) : x(i), y(j){};



int getX(){return x;};
int getY(){return y;};


};


int main(){

    Point p1(2,4);

    std::cout << "Value of x is: " <<  p1.getX() << std::endl << "Value of y is: " <<  p1.getY() << std::endl;
 


    return 0;
}