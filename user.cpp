#include "user.h"

User::User(std::string name, int age) {
    this->name = name;
    this->age = age;
}

User::~User() {
}

void User::setName(std::string name) {
    this->name = name;
}

void User::setAge(int age) {
    this->age = age;
}

std::string User::getName() {
    return name;
}

int User::getAge() {
    return age;
}

void User::printInfo() {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}
