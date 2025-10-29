#pragma once

#include <vector>
#include <string>
#include "../common/student.h"

class DataParser {
public:
    static std::vector<Student> parseFile(const std::string& filename);
    static Student parseLine(const std::string& line);
    
private:
    static bool validateStudentData(const Student& student);
};