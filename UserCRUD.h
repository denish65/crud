// UserCRUD.h

#ifndef USERCRUD_H
#define USERCRUD_H

#include "Database.h"

class BaseCRUD : public Database {
public:
    virtual void create() = 0;
    virtual void read() = 0;
    virtual void update() = 0;
    virtual void deleteRecord() = 0;
};

class UserCRUD : public BaseCRUD {
public:
    void create() override {
        std::string name, email;
        int age;
        std::cout << "Enter Name: ";
        std::cin >> name;
        std::cout << "Enter Email: ";
        std::cin >> email;
        std::cout << "Enter Age: ";
        std::cin >> age;

        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("INSERT INTO users(name, email, age) VALUES (?, ?, ?)");
        pstmt->setString(1, name);
        pstmt->setString(2, email);
        pstmt->setInt(3, age);
        pstmt->execute();
        std::cout << "User created successfully!" << std::endl;
    }

    void read() override {
        sql::Statement *stmt = con->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * FROM users");

        while (res->next()) {
            std::cout << "ID: " << res->getInt("id") << ", Name: " << res->getString("name") 
                      << ", Email: " << res->getString("email") 
                      << ", Age: " << res->getInt("age") << std::endl;
        }
    }

    void update() override {
        int id, age;
        std::string name, email;
        std::cout << "Enter ID of user to update: ";
        std::cin >> id;
        std::cout << "Enter new Name: ";
        std::cin >> name;
        std::cout << "Enter new Email: ";
        std::cin >> email;
        std::cout << "Enter new Age: ";
        std::cin >> age;

        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("UPDATE users SET name = ?, email = ?, age = ? WHERE id = ?");
        pstmt->setString(1, name);
        pstmt->setString(2, email);
        pstmt->setInt(3, age);
        pstmt->setInt(4, id);
        pstmt->execute();
        std::cout << "User updated successfully!" << std::endl;
    }

    void deleteRecord() override {
        int id;
        std::cout << "Enter ID of user to delete: ";
        std::cin >> id;

        sql::PreparedStatement *pstmt;
        pstmt = con->prepareStatement("DELETE FROM users WHERE id = ?");
        pstmt->setInt(1, id);
        pstmt->execute();
        std::cout << "User deleted successfully!" << std::endl;
    }
};

#endif
