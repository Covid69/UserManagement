#include "user.h"
#include "color.h"
#include <limits>


int main(){
    int action = 0;
    std::vector<User> userlist;
    while(action != 5){

        switch(action){
            case 0:
                std::cout << BOLD << MAGENTA << "Select actions:" << std::endl;
                std::cout << RESET << MAGENTA << "1. Create user" << std::endl;
                std::cout << MAGENTA << "2. Edit user information" << std::endl;
                std::cout << MAGENTA << "3. Print user information" << std::endl;
                std::cout << MAGENTA << "4. List users" << std::endl;
                std::cout << MAGENTA << "5. Exit" << std::endl;
                std::cout << MAGENTA << "Action:";
                std::cin >> action;
                if (std::cin.fail()){
                    std::cin.clear(); // Clear the error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                    std::cout << RED << "Invalid input, please enter a number." << std::endl;
                    action = 0; // Reset action to allow for another action
                    break;
                }
            case 1: {
                // Create user
                {
                    std::string username;
                    int age;
                    std::cin.ignore();
                    std::cout << BOLD << GREEN << "Enter name: ";
                    std::cin >> username;
                    if (username == "") {
                        std::cout << BOLD << RED << "Name cannot be empty!" << std::endl;
                        action = 0; 
                        break;
                    }
                    std::cin.ignore(); // Clear the newline character from the input buffer
                    std::cout << BOLD << GREEN << "Enter age: ";
                    std::cin >> age;

                    if (age <= 0) {
                        std::cout << BOLD << RED << "Age must be a positive integer!" << std::endl;
                        action = 0;
                        break;
                    }
                    userlist.push_back(User(username, age));
                    std::cout << GREEN << "User created!" << std::endl;
                    action = 0; // Reset action to allow for another action
                }
                break;
            }
            case 2:{
                // Edit user information
                {
                    int userIndex;
                    std::cout << BOLD << CYAN << "Enter user index to edit: ";
                    std::cin.ignore();
                    std::cin >> userIndex;
                    if (userIndex < 0 || userIndex >= userlist.size()) {
                        std::cout << "Invalid index!" << std::endl;
                        break;
                    }
                    std::cout << BOLD << CYAN << "Enter new name: ";
                    std::string newUsername;
                    std::cin.ignore();
                    getline(std::cin, newUsername);
                    if (newUsername != "") {
                        userlist[userIndex].setName(newUsername);
                        std::cout << BLUE << "Changed name to " << newUsername << std::endl;
                    }
                    else{
                        std::cout << YELLOW << "Name not changed." << std::endl;
                    }
                    int newAge;
                    std::cout << BOLD << CYAN << "Enter new age: ";
                    // std::cin.ignore();
                    std::cin >> newAge;
                    if (newAge != 0){
                        userlist[userIndex].setAge(newAge);
                        std::cout << BLUE << "Changed age to " << newAge << std::endl;
                    }
                    else{
                        std::cout << YELLOW << "Age not changed." << std::endl;
                    }
                    action = 0;
                }
                break;
            }
            case 3:{
                // Print user information
                    int userIndex;
                    std::cout << WHITE << "Enter user index to show information: ";
                    std::cin.ignore();
                    std::cin >> userIndex;
                    if (userIndex < 0 || userIndex >= userlist.size()) {
                        std::cout << "Invalid index!" << std::endl;
                        action = 0;
                        break;
                    }
                    else{
                        std::cout << WHITE << "User information:" << std::endl;
                        userlist[userIndex].printInfo();
                    }
                action = 0;
                break;
            }
            case 4:
                // List users
                std::cout << BOLD << BLUE << "User list:" << std::endl;
                action = 0;
                for (int i = 0; i < userlist.size(); i++){
                    std::cout << BLUE << i << ". " << userlist[i].getName() << "  -  " << userlist[i].getAge() << std::endl; 
                }
                break;
            case 5:
                // Exit
                break;
            default:
                std::cout << RED << "Invalid action, please try again." << std::endl;
                action = 0; // Reset action to allow for another action
                break;
        }
    }

    return 0;
}