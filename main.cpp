#include "user/user.h" // Include the User class header
#include "color/color.h" // Include the color definitions for terminal output
#include <limits> // Include for std::numeric_limits

int main() {
    int action = 0; // Variable to store the user's selected action
    std::vector<User> userlist; // Vector to store the list of users

    // Main loop to display the menu and handle user actions
    while (action != 5) { // Loop until the user selects "Exit"
        switch (action) {
            case 0:
                // Display the menu options
                std::cout << BOLD << MAGENTA << "Select actions:" << std::endl;
                std::cout << RESET << MAGENTA << "1. Create user" << std::endl;
                std::cout << MAGENTA << "2. Edit user information" << std::endl;
                std::cout << MAGENTA << "3. Print user information" << std::endl;
                std::cout << MAGENTA << "4. List users" << std::endl;
                std::cout << MAGENTA << "5. Exit" << std::endl;
                std::cout << MAGENTA << "Action:";
                std::cin >> action;

                // Handle invalid input (non-integer values)
                if (std::cin.fail()) {
                    std::cin.clear(); // Clear the error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                    std::cout << RED << "Invalid input, please enter a number." << std::endl;
                    action = 0; // Reset action to allow for another action
                    break;
                }
                break;

            case 1: {
                // Create a new user
                {
                    std::string username;
                    int age;

                    // Prompt for the user's name
                    std::cin.ignore(); // Clear the input buffer
                    std::cout << BOLD << GREEN << "Enter name: ";
                    std::cin >> username;

                    // Validate the name
                    if (username == "") {
                        std::cout << BOLD << RED << "Name cannot be empty!" << std::endl;
                        action = 0;
                        break;
                    }

                    // Prompt for the user's age
                    std::cin.ignore(); // Clear the input buffer
                    std::cout << BOLD << GREEN << "Enter age: ";
                    std::cin >> age;

                    // Validate the age
                    if (age <= 0) {
                        std::cout << BOLD << RED << "Age must be a positive integer!" << std::endl;
                        action = 0;
                        break;
                    }

                    // Add the new user to the user list
                    userlist.push_back(User(username, age));
                    std::cout << GREEN << "User created!" << std::endl;
                    action = 0; // Reset action to allow for another action
                }
                break;
            }

            case 2: {
                // Edit an existing user's information
                {
                    int userIndex;

                    // Prompt for the user index to edit
                    std::cout << BOLD << CYAN << "Enter user index to edit: ";
                    std::cin.ignore();
                    std::cin >> userIndex;

                    // Validate the user index
                    if (userIndex < 0 || userIndex >= userlist.size()) {
                        std::cout << "Invalid index!" << std::endl;
                        break;
                    }

                    // Prompt for the new name
                    std::cout << BOLD << CYAN << "Enter new name: ";
                    std::string newUsername;
                    std::cin.ignore();
                    getline(std::cin, newUsername);

                    // Update the user's name if provided
                    if (newUsername != "") {
                        userlist[userIndex].setName(newUsername);
                        std::cout << BLUE << "Changed name to " << newUsername << std::endl;
                    } else {
                        std::cout << YELLOW << "Name not changed." << std::endl;
                    }

                    // Prompt for the new age
                    int newAge;
                    std::cout << BOLD << CYAN << "Enter new age: ";
                    std::cin >> newAge;

                    // Update the user's age if valid
                    if (newAge > 0) {
                        userlist[userIndex].setAge(newAge);
                        std::cout << BLUE << "Changed age to " << newAge << std::endl;
                    } else {
                        std::cout << YELLOW << "Age not changed." << std::endl;
                    }

                    action = 0; // Reset action to allow for another action
                }
                break;
            }

            case 3: {
                // Print information about a specific user
                int userIndex;

                // Prompt for the user index to display
                std::cout << WHITE << "Enter user index to show information: ";
                std::cin.ignore();
                std::cin >> userIndex;

                // Validate the user index
                if (userIndex < 0 || userIndex >= userlist.size()) {
                    std::cout << "Invalid index!" << std::endl;
                    action = 0;
                    break;
                } else {
                    // Display the user's information
                    std::cout << WHITE << "User information:" << std::endl;
                    userlist[userIndex].printInfo();
                }

                action = 0; // Reset action to allow for another action
                break;
            }

            case 4:
                // List all users
                std::cout << BOLD << BLUE << "User list:" << std::endl;
                for (int i = 0; i < userlist.size(); i++) {
                    std::cout << BLUE << i << ". " << userlist[i].getName() << "  -  " << userlist[i].getAge() << std::endl;
                }
                action = 0; // Reset action to allow for another action
                break;

            case 5:
                // Exit the program
                std::cout << BOLD << GREEN << "Exiting the program. Goodbye!" << std::endl;
                break;

            default:
                // Handle invalid menu options
                std::cout << RED << "Invalid action, please try again." << std::endl;
                action = 0; // Reset action to allow for another action
                break;
        }
    }

    return 0;
}