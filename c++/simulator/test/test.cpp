#include <iostream>
#include <thread>

// 
std::jthread thread([] {
    std::cout << "Hello from thread!" << std::endl;
});

int main() {
    std::cout << "Hello, World!\n";
    return 0;
}