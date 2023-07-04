#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "grade.hpp"


class Student{
    private:
        std::vector<int> available_ids;
        int id;
    
    protected:
        std::vector<Grade*> grades; 
    
    public:
        std::string first_name;
        std::string last_name;
        Student(const std::string &f_name, const std::string &l_name);
        std::string ShowStudent();
        std::string GetGrades(Course* c);
        void addGrade(Grade* grade);

};


#endif // STUDENT_HPP