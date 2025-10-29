#include "data_parser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

// Парсинг файла с исходными данными
std::vector<Student> DataParser::parseFile(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename);
    std::string line;
    
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return students;
    }
    
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        try {
            Student student = parseLine(line);
            if (validateStudentData(student)) students.push_back(student);
        } catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << " - " << e.what() << std::endl;
        }
    }
    
    file.close();
    return students;
}

// Парсинг строки с информацией о студенте
Student DataParser::parseLine(const std::string& line) {
    std::istringstream iss(line);
    std::string firstName, lastName, birthDate;
    
    if (!(iss >> firstName >> lastName >> birthDate)) {
        throw std::runtime_error("Invalid line format");
    }
    
    return Student(firstName, lastName, birthDate);
}

// Валидация даты рождения студента
bool DataParser::validateStudentData(const Student& student) {
    return student.isValid();
}