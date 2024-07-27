#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <string>

void readRecords(sql::Connection *con);
void addRecord(sql::Connection *con);
void deleteRecord(sql::Connection *con);
void updateRecord(sql::Connection *con);

int main() {
    // Initialize MySQL driver
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    try {
        // Create a MySQL driver
        driver = sql::mysql::get_mysql_driver_instance();

        // Establish a connection to the MySQL database
        con = driver->connect("tcp://127.0.0.1:3306", "root", "2222");

        // Select the database
        con->setSchema("Parks_and_Recreation");

        int choice;

        do {
            std::cout << "Menu:\n";
            std::cout << "1. Read Records\n";
            std::cout << "2. Add Record\n";
            std::cout << "3. Delete Record\n";
            std::cout << "4. Update Record\n";
            std::cout << "5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    readRecords(con);
                    break;
                case 2:
                    addRecord(con);
                    break;
                case 3:
                    deleteRecord(con);
                    break;
                case 4:
                    updateRecord(con);
                    break;
                case 5:
                    std::cout << "Exiting...\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 5);

        // Clean up
        delete con;
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "MySQL error code: " << e.getErrorCode() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }

    return 0;
}

void readRecords(sql::Connection *con) {
    try {
        sql::Statement *stmt = con->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * FROM employee_demographics");

        while (res->next()) {
            std::cout << "Age: " << res->getInt("age") << ", "
                      << "Birth Date: " << res->getString("birth_date") << ", "
                      << "Employee ID: " << res->getInt("employee_id") << ", "
                      << "First Name: " << res->getString("first_name") << ", "
                      << "Gender: " << res->getString("gender") << ", "
                      << "Last Name: " << res->getString("last_name") << std::endl;
        }

        delete res;
        delete stmt;
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "MySQL error code: " << e.getErrorCode() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}

void addRecord(sql::Connection *con) {
    try {
        std::string firstName, lastName, birthDate, gender;
        int age, employeeId;

        std::cout << "Enter Employee ID: ";
        std::cin >> employeeId;
        std::cout << "Enter First Name: ";
        std::cin >> firstName;
        std::cout << "Enter Last Name: ";
        std::cin >> lastName;
        std::cout << "Enter Age: ";
        std::cin >> age;
        std::cout << "Enter Birth Date (YYYY-MM-DD): ";
        std::cin >> birthDate;
        std::cout << "Enter Gender: ";
        std::cin >> gender;

        sql::PreparedStatement *pstmt = con->prepareStatement("INSERT INTO employee_demographics (employee_id, first_name, last_name, age, birth_date, gender) VALUES (?, ?, ?, ?, ?, ?)");

        pstmt->setInt(1, employeeId);
        pstmt->setString(2, firstName);
        pstmt->setString(3, lastName);
        pstmt->setInt(4, age);
        pstmt->setString(5, birthDate);
        pstmt->setString(6, gender);

        pstmt->executeUpdate();
        delete pstmt;

        std::cout << "Record added successfully.\n";
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "MySQL error code: " << e.getErrorCode() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}

void deleteRecord(sql::Connection *con) {
    try {
        int employeeId;
        std::cout << "Enter Employee ID to delete: ";
        std::cin >> employeeId;

        sql::PreparedStatement *pstmt = con->prepareStatement("DELETE FROM employee_demographics WHERE employee_id = ?");
        pstmt->setInt(1, employeeId);

        pstmt->executeUpdate();
        delete pstmt;

        std::cout << "Record deleted successfully.\n";
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "MySQL error code: " << e.getErrorCode() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}

void updateRecord(sql::Connection *con) {
    try {
        std::string firstName, lastName, birthDate, gender;
        int age, employeeId;

        std::cout << "Enter Employee ID to update: ";
        std::cin >> employeeId;
        std::cout << "Enter New First Name: ";
        std::cin >> firstName;
        std::cout << "Enter New Last Name: ";
        std::cin >> lastName;
        std::cout << "Enter New Age: ";
        std::cin >> age;
        std::cout << "Enter New Birth Date (YYYY-MM-DD): ";
        std::cin >> birthDate;
        std::cout << "Enter New Gender: ";
        std::cin >> gender;

        sql::PreparedStatement *pstmt = con->prepareStatement("UPDATE employee_demographics SET first_name = ?, last_name = ?, age = ?, birth_date = ?, gender = ? WHERE employee_id = ?");

        pstmt->setString(1, firstName);
        pstmt->setString(2, lastName);
        pstmt->setInt(3, age);
        pstmt->setString(4, birthDate);
        pstmt->setString(5, gender);
        pstmt->setInt(6, employeeId);

        pstmt->executeUpdate();
        delete pstmt;

        std::cout << "Record updated successfully.\n";
    } catch (sql::SQLException &e) {
        std::cerr << "SQLException: " << e.what() << std::endl;
        std::cerr << "MySQL error code: " << e.getErrorCode() << std::endl;
        std::cerr << "SQLState: " << e.getSQLState() << std::endl;
    }
}
