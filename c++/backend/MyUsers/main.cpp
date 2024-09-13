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
#include <cppconn/exception.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <memory>
#include <cppconn/statement.h>
#include "config.h"
#include <string>


int main(){
    
    // create driver and con.
    sql::mysql::MySQL_Driver *driver;
    std::unique_ptr<sql::Connection> con;

try {
    driver = sql::mysql::get_mysql_driver_instance();
    con.reset();

    // Choose DB.
    con->setSchema(DB_NAME);

    // Create statement 
    std::unique_ptr<sql::Statement> statement(con->createStatement());

    // Get input from the user
    
    std::string PersonID, DeviceName, DeviceStatus, DeviceNewStatus;

    std::cout <<"Enter the PersonID: "<< std::endl;
    std::getline(std::cin,PersonID);

    std::cout << "Enter the Device name: " << std::endl;
    std::getline(std::cin, DeviceName);

    std::cout << "Enter Device Status: " << std::endl;
    std::getline(std::cin, DeviceStatus);

    std::cout << "Enter device new status: " << std::endl;
    std::getline(std::cin,DeviceNewStatus);

    // Insert a new device. litrally write the SQL Query.
    std::string insertQuery = "INSERT INTO Devices (PersonID, DeviceName, DeviceStatus) VALUES (" +
                                  PersonID + ", '" + DeviceName + "', '" + DeviceStatus + "')";
    statement->execute(insertQuery);
    
    // Update device status.
    std::string updateQuery = "UPDATE Devices SET DeviceStatus = '" + DeviceNewStatus + "' WHERE DeviceName = '" + DeviceName + "'";
    statement->execute(updateQuery);

    // Update query.

} catch (sql::SQLException &e){
    std::cerr << "Exception: " << e.what() << std::endl;
}

    return 0;
}