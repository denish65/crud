// Database.h

#ifndef DATABASE_H
#define DATABASE_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <iostream>
#include <string>

class Database {
protected:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

public:
    Database() {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "denish*48");  // Use your MySQL credentials here
        con->setSchema("crud_cpp");
    }

    virtual ~Database() {
        delete con;
    }
};

#endif
