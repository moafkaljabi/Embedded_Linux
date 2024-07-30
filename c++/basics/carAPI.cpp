#include <iostream>
#include <string> 
#include <optional>  
#include <vector>

// Define the car class
class car {
public:
    std::string make;
    std::string model;
    int year;
    std::optional<std::string> color;  // Use std::optional for optional color

    // Constructor with optional color
    car(const std::string &make, const std::string &model, int year, std::optional<std::string> color = std::nullopt)
        : make(make), model(model), year(year), color(color) {}
};

// Define the global vector to store car objects after the car class definition
std::vector<car> cars;  

// Function to print a string (not used in the current main.cpp, but kept here for completeness)
void toPrint(const std::string &input) {
    std::cout << input << std::endl;
}

// Function to print all cars
void printCars() {
    for (const auto &c : cars) {
        std::cout << "Make: " << c.make << ", Model: " << c.model << ", Year: " << c.year;
        if (c.color) {
            std::cout << ", Color: " << *c.color;
        }
        std::cout << std::endl;
    }
}

// Function to add a car to the list
void addCar(const car &newCar) {
    cars.push_back(newCar);
}

// Function to delete a car from the list by index
void deleteCar(size_t index) {
    if (index < cars.size()) {
        cars.erase(cars.begin() + index);
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}
