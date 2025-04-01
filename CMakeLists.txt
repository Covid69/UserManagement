cmake_minimum_required(VERSION 3.10)

# Project name
project(UserManagement)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the library for the User class
add_library(user user/user.cpp)

# Specify the include directory for the User class
target_include_directories(user PUBLIC ${CMAKE_SOURCE_DIR}/user)

# Add the executable
add_executable(main main.cpp)

# Link the user library to the main executable
target_link_libraries(main user)