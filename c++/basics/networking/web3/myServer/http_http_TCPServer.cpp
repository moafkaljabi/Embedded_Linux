#include "http_TCPServer.h"

#include <iostream>
#include <sstream>
#include <unistd.h>


namespace {

    const int BUFFER_SIZE = 30720;

    void log(const std::string &message){
        std::cout << message << std::endl;
    }

    void exitWithError(const std::string &errorMessage){
        log("ERROR: " + errorMessage);
        exit(1);
    }
}

namespace http{

    TCPServer::TCPServer(std::String ip_address, int port) : 
}