#include <cstddef>
#include <cstring>
#include <iostream>


class MyString {

private:
    char* data;
    size_t length;

public:
    
    // Default constructor
    MyString(): data(nullptr), length(0){}

    // parametrized constructor
    MyString(const char* str){
        if(str) {
            length = std::strlen(str);            
            data = new char [length + 1];
            std::strcpy(data,str);
        } else {
            str = nullptr;
            length = 0;
        }
    }

    // Copy constructor


    // Destructor
    ~MyString(){};

    // Copy assignment constructor

    // Size()
    const char size(){
        return length;
    }

    // Operator []
     char& operator[](size_t index){
        return data[index];
     } 

     // Operator []  // only for reading.
     const char& operator[](size_t index)const {
        return data[index];
     } 

    // c_str



};


int main(){

    return 0;
}