//

// main.cpp
// Programming Project 1
//
// Created by LeCorey Johnson on 8/27/23.
//
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
// structure to store employee information
struct Employee {
int employeeId;
std::string firstName;
std::string lastName;
std::string phoneNumber;
std::string emailAddress;
double salary;
};
// comparing employees based on ID
bool compareById(const Employee& emp1, const Employee& emp2) {
return emp1.employeeId < emp2.employeeId;
}
int main() {
std::list<Employee> employees;
std::ifstream inputFile("Week 1-employeeDataset_Project 1 (1).txt");
if (!inputFile.is_open()) {
std::cerr << "Failed to open the input file." << std::endl;
return 1;
}
std::string line;
while (std::getline(inputFile, line)) {
Employee emp;
std::istringstream iss(line);
if (!(iss >> emp.employeeId >> emp.firstName >> emp.lastName >>
emp.phoneNumber >> emp.emailAddress >> emp.salary)) {
std::cerr << "Error reading employee data from line: " << line <<
std::endl;
continue;
}
employees.insert(std::upper_bound(employees.begin(), employees.end(), emp,
compareById), emp);
}
inputFile.close();
// Display the sorted employee list
    for (const Employee& emp : employees) {
        std::cout << "Employee ID: " << emp.employeeId << "\n"
        << "First Name: " << emp.firstName << "\n"
        << "Last Name: " << emp.lastName << "\n"
        << "Phone Number: " << emp.phoneNumber << "\n"
        << "Email Address: " << emp.emailAddress << "\n"
        
        
        << "Salary: " << emp.salary << "\n"
        << "-------\n";
        }
        return 0;
        }
