#include "data_manager.h"
#include "data_parser.h"
#include <algorithm>

// Формирование вектора из студентов
void DataManager::addStudentsFromFile(const std::string& filename) {
    std::vector<Student> fileStudents = DataParser::parseFile(filename);
    students.insert(students.end(), fileStudents.begin(), fileStudents.end());
}

// Слияние "повторок"
void DataManager::mergeDuplicates() {
    std::vector<Student> uniqueStudents;
    
    for (const auto& student : students) {
        auto it = std::find(uniqueStudents.begin(), uniqueStudents.end(), student);
        if (it == uniqueStudents.end()) {
            uniqueStudents.push_back(student);
        }
    }
    
    students = std::move(uniqueStudents);
}

// Интерфейс для получения вектора из студентов
std::vector<Student> DataManager::getStudents() const {
    return students;
}

// Сериализация вектора из студентов в строку
std::string DataManager::serializeStudents() const {
    std::string result;
    for (const auto& student : students) {
        result += student.toString() + "\n";
    }
    return result;
}