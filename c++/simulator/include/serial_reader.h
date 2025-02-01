#pragma once 

#ifndef SERIAL_READER_H
#define SERIAL_READER_H

#include <string>
#include <sensor_simulator.h>

class SerialReader {

private:
    int serialPort;
    int baudrate;
    std::string device;

public:

    SerialReader(const std::string& device, int baudrate);
    ~SerialReader();

    SensorSimulator::SensorData readData();

};

#endif