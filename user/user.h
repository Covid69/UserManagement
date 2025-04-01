#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>



class User {
private:
    std::string name;
    int age;
public:
    User(std::string name, int age);
    ~User();
    void setName(std::string name);
    void setAge(int age);
    std::string getName();
    int getAge();
    void printInfo();

};

#endif // USER_H