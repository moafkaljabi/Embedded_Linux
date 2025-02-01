#include <iostream>
#include "main.h"

int main(){

SerialReader stringReader("/dev/ttyACM0", 115200);

stringReader.readRawData();

}