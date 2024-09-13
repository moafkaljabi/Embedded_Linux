/*

M.A. 

*/

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h> // Include this for sql::Statement
#include "../config.h"
#include <memory> // For smart pointers

int main() {
    // Do not use smart pointer for the MySQL driver ; MySQL handles it internally.
    sql::mysql::MySQL_Driver *driver;
    std::unique_ptr<sql::Connection> con;

    try {
        driver = sql::mysql::get_mysql_driver_instance();  // Singleton, no smart pointer needed
        con.reset(driver->connect(DB_HOST, DB_USER, DB_PASSWORD));  // Use smart pointer for Connection

        con->setSchema(DB_NAME);  // database name

        // Create statement using smart pointer
        std::unique_ptr<sql::Statement> stmt(con->createStatement());

        // Get input from user
        int personID;
        std::string deviceName, deviceStatus, newDeviceStatus;
        std::cout << "Enter PersonID: ";
        std::cin >> personID;
        std::cout << "Enter Device Name: ";
        std::cin >> deviceName;
        std::cout << "Enter Device Status (on/off): ";
        std::cin >> deviceStatus;

        // Insert a new device
        std::string insertQuery = "INSERT INTO Devices (PersonID, DeviceName, DeviceStatus) VALUES (" +
                                  std::to_string(personID) + ", '" + deviceName + "', '" + deviceStatus + "')";
        stmt->execute(insertQuery);

        // Update device status
        std::cout << "Enter new Device Status (on/off) for device " << deviceName << ": ";
        std::cin >> newDeviceStatus;

        std::string updateQuery = "UPDATE Devices SET DeviceStatus = '" + newDeviceStatus + "' WHERE DeviceName = '" + deviceName + "'";
        stmt->execute(updateQuery);

        std::cout << "Device status updated successfully." << std::endl;
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }

    return 0;
}

