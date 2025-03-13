/*

MySQL code.

M.A. 

steps: 
    1. include libs.
    2. connect ; create a driver and a connection.
    3. In a try catch, CRUD
    

    notes:

    Query is when we write litrally the SQL Query/ command.

*/

#include <cppconn/connection.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>

#include <string>
#include <iostream>
#include <memory>

#include "config.h"


int main() {

    // Define the Driver and connection. 

    sql::mysql::MySQL_Driver *driver; // Singleton, MySQL handles it internally, do not use smart pointer.
    std::unique_ptr<sql::Connection> connection;

try{

    // Try to connect.
    driver  = sql::mysql::get_mysql_driver_instance();
    connection.reset(driver->connect(DB_HOST, DB_NAME, DB_PASSWORD));

    connection->setSchema(DB_NAME);     // Select Database.


    std::unique_ptr<sql::Statement> statement(connection->createStatement()); // To perform SQL queries.

    // define the database columns.
    std::string PersonID, DeviceName, DeviceStatus, DeviceNewStatus;


    // Get input from the user.
    std::cout << "Enter the Personal ID: ";
    getline(std::cin,PersonID);

    std::cout << "Enter the Device name: ";
    getline(std::cin, DeviceName);

    std::cout << "Enter device status (on/off):  ";
    getline(std::cin, DeviceStatus);

    std::cout << "Enter device new status: ";
    getline(std::cin,DeviceNewStatus);


    // Create queries.
    std::string insertQuery = "Insert ";

    
    // Add device Querey.
    statement->execute(insertQuery);


    // Inform that the value added successfully.
    std::cout << "Device added successfully." << std::endl;

} catch (sql::SQLException &e){
    std::cerr << "Exception: " << e.what() << std::endl;

}

    return 0;
}