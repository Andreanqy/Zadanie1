#include "data_sorter.h"
#include <sstream>
#include <iostream>
#include <algorithm>

// Парсинг студентов из строки в вектор
std::vector<Student> DataSorter::parseStudents(const std::string& data) {
    std::vector<Student> students;
    std::istringstream iss(data);
    std::string line;
    
    while (std::getline(iss, line)) {
        if (line.empty()) continue;
        
        try {
            std::istringstream lineStream(line);
            std::string firstName, lastName, birthDate;
            
            if (lineStream >> firstName >> lastName >> birthDate) {
                Student student(firstName, lastName, birthDate);
                if (student.isValid()) {
                    students.push_back(student);
                }
            }
        } catch (const std::exception& e) {
            std::cerr << "Error parsing student: " << e.what() << std::endl;
        }
    }
    
    return students;
}

// Сортировка студентов
void DataSorter::sortStudents(std::vector<Student>& students) {
    std::sort(students.begin(), students.end());
}

// Отображение студентов
void DataSorter::displayStudents(const std::vector<Student>& students) {
    std::cout << "\n=== Sorted Students List ===" << std::endl;
    for (const auto& student : students) {
        std::cout << student.toString() << std::endl;
    }
}