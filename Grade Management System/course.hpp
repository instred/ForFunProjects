#ifndef COURSE_HPP
#define COURSE_HPP

#include "student.hpp"
#include <vector>
#include <string>


class Course{
    protected:
        std::vector<Student*> students;
        std::string course_name;
        

    public:
        Course(const std::string &name);
        void addStudent(Student* student);
        std::vector<Student*> GetStudents();
        std::string GetName();
};

#endif // COURSE_HPP