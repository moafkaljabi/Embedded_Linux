#include <string>
#include "carAPI.cpp"


int main() {
    // Add some cars
    addCar(car("Ford", "Mustang", 2023, "Red"));
    addCar(car("Toyota", "Camry", 2021));
    addCar(car("Honda", "Civic", 2022, "Blue"));

    toPrint("Initial car list:");
    printCars();

    // Delete a car
    deleteCar(1);


    toPrint("After deletion:");
    
    printCars();

    return 0;
}
