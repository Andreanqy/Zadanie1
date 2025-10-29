#include "student.h"
#include <regex>

// Конструктор
Student::Student(const std::string& firstName, const std::string& lastName, const std::string& birthDate) : firstName(firstName), lastName(lastName), birthDate(birthDate) {}

// Перегрузка оператора сравнения ==
bool Student::operator==(const Student& other) const {
    return firstName == other.firstName && lastName == other.lastName && birthDate == other.birthDate;
}

// Перегрузка оператора сравнения <
bool Student::operator<(const Student& other) const {
    if (firstName != other.firstName) return firstName < other.firstName;
    else return lastName < other.lastName;
}

// Преобразование объекта Студент в строку
std::string Student::toString() const {
    return firstName + " " + lastName + " " + birthDate;
}

// Валидация даты
bool Student::isValid() const {
    if (firstName.empty() || lastName.empty() || birthDate.empty()) return false;
    
    std::regex dateRegex(R"((\d{1,2})\.(\d{1,2})\.(\d{4}))");
    std::smatch match;
    
    if (!std::regex_match(birthDate, match, dateRegex)) return false;

    int day = std::stoi(match[1]);
    int month = std::stoi(match[2]);
        
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    return true;
}