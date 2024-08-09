#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h> // Include this for sql::Statement
#include "myKey.h"

int main() {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", username, password); // Update credentials if needed

        con->setSchema("Users"); // Replace with your database name

        sql::Statement *stmt = con->createStatement();

        // Example: Insert a new device
        std::string insertQuery = "INSERT INTO Devices (PersonID, DeviceName, DeviceStatus) VALUES (1, 'BLDC2 Motor', 'on')";
        stmt->execute(insertQuery);

        // Example: Update device status
        std::string updateQuery = "UPDATE Devices SET DeviceStatus = 'off' WHERE DeviceName = 'BLDC Motor'";
        stmt->execute(updateQuery);

        delete stmt;
        delete con;
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
    }

    return 0;
}
