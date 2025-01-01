// main.cpp

#include <iostream>
#include "UserCRUD.h"

int main() {
    UserCRUD userCRUD;

    int choice;
    do {
        std::cout << "1. Create User\n2. Read Users\n3. Update User\n4. Delete User\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                userCRUD.create();
                break;
            case 2:
                userCRUD.read();
                break;
            case 3:
                userCRUD.update();
                break;
            case 4:
                userCRUD.deleteRecord();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
