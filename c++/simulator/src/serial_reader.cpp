#include "serial_reader.h"


SerialReader::SerialReader(const std::string &device, int baudrate)
: device(device), baudrate(baudrate)
{
    
}