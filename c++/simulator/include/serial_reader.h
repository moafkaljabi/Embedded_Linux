// Reads data from the UART

#pragma once 

#include <string>


struct SensorData {
    float accelX, accelY, accelZ;
};

class SerialReader {

private:
    int serialPort;
    int baudrate;
    std::string device;

public:
 
    SerialReader(const std::string& device, int baudrate);
    ~SerialReader();

    SensorData readData();
    SensorData readRawData();

};

