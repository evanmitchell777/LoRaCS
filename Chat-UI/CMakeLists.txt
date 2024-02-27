cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

# Enable C++ language
enable_language(CXX)

# Find FTXUI package
find_package(ftxui CONFIG REQUIRED)

# Add your executable
add_executable(your_executable main.cpp)

# Link against FTXUI
target_link_libraries(your_executable PRIVATE ftxui::component)

