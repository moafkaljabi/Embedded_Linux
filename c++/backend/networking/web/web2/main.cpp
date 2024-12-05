#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <cstdio> // For popen and pclose
#include <memory> // For std::unique_ptr
#include <stdexcept> // For std::runtime_error
#include <array> // For std::array

using boost::asio::ip::tcp;


std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;

    // Open the process
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    // Read the output of the command
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return result;
}

void handleClient(tcp::socket& socket) {
    try {
        std::string message = "Welcome! You can now control the PC.\n";
        boost::asio::write(socket, boost::asio::buffer(message));

        for (;;) {
            char data[512];
            boost::system::error_code error;

            size_t length = socket.read_some(boost::asio::buffer(data), error);
            if (error == boost::asio::error::eof)
                break; // Connection closed cleanly by peer
            else if (error)
                throw boost::system::system_error(error); // Some other error

            std::string command(data, length);
            std::cout << "Command received: " << command << std::endl;

            // Prepare the command with DISPLAY
            std::string output;
            if (command == "open terminal") {
                output = exec("DISPLAY=:0 gnome-terminal");
            } else if (command == "open calculator") {
                output = exec("DISPLAY=:0 gnome-calculator");
            } else if (command == "open browser") {
                output = exec("DISPLAY=:0 firefox");
            }

            std::cout << "Command output: " << output << std::endl;
            boost::asio::write(socket, boost::asio::buffer("Command executed\n"));
        }
    } catch (std::exception& e) {
        std::cerr << "Exception in client handling: " << e.what() << std::endl;
    }
}

int main() {
    try {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 1313));

        std::cout << "Server is running. Waiting for client connection..." << std::endl;

        for (;;) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            std::cout << "Client connected!" << std::endl;

            handleClient(socket);
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
