#pragma once

#include <string>
#include <iostream>

struct Student {
    std::string firstName;
    std::string lastName;
    std::string birthDate;
    
    Student(const std::string& firstName, const std::string& lastName, const std::string& birthDate);
    
    bool operator==(const Student& other) const;
    bool operator<(const Student& other) const;
    
    std::string toString() const;
    bool isValid() const;
};