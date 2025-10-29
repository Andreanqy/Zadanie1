#pragma once

#include <vector>
#include <string>
#include "../common/student.h"

class DataManager {
public:
    void addStudentsFromFile(const std::string& filename);
    void mergeDuplicates();
    std::vector<Student> getStudents() const;
    std::string serializeStudents() const;
    
private:
    std::vector<Student> students;
};