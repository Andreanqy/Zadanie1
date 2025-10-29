#pragma once

#include <vector>
#include <string>
#include "../common/student.h"

class DataSorter {
public:
    static std::vector<Student> parseStudents(const std::string& data);
    static void sortStudents(std::vector<Student>& students);
    static void displayStudents(const std::vector<Student>& students);
};