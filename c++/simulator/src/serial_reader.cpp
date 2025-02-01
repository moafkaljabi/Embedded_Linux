// Reads data from the UART
#include "serial_reader.h"

#include <iostream>
#include <cstring>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>


SerialReader::SerialReader(const std::string &device, int baudrate)
    : device(device), baudrate(baudrate) 
    {
    serialPort = open(device.c_str(), O_RDWR | O_NOCTTY);


    if(serialPort == -1) {
        std::cerr << "Error openining device: " << device << std::endl;
    }

    struct termios tty;

    memset(&tty, 0, sizeof tty);
    tcgetattr(serialPort, &tty);

    cfsetospeed(&tty, baudrate);
    cfsetispeed(&tty, baudrate);

    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &=  ~PARENB;
    tty.c_cflag &= CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;

    tcsetattr(serialPort, TCSANOW, &tty);
}

SerialReader::~SerialReader() {
    if (serialPort != -1)
    {
        close(serialPort);
    }
}


SensorData SerialReader::readData() {
    SensorData data;

    char buffer[32];

    int bytesRead = read(serialPort, buffer, sizeof(buffer) -1);

    if (bytesRead > 1)
    {
        buffer[bytesRead] = '\n';
        sscanf(buffer, "%f,%f,%f", &data.accelX, &data.accelY, &data.accelZ);
    }
    
    else {
        std::cerr << "Error getting senesor data!" << std::endl;
    }

    return data;
    
}



SensorData SerialReader::readRawData() {
    char buffer[32];

    int bytesRead = read(serialPort, buffer, sizeof(buffer) - 1);

    if (bytesRead > 0) {
        buffer[bytesRead] = '\0';  // Null-terminate the string
        // Strip out newline or carriage return characters, if present
        if (bytesRead > 0 && (buffer[bytesRead - 1] == '\n' || buffer[bytesRead - 1] == '\r')) {
            buffer[bytesRead - 1] = '\0';
        }

        std::cout << "Received: " << buffer << std::endl;
    } else {
        std::cerr << "Error reading the raw data!" << std::endl;
    }

    return SensorData();
}






