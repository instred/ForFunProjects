#ifndef COURSE_HPP
#define COURSE_HPP

#include "student.hpp"
#include <vector>
#include <string>


class Course{
    protected:
        std::vector<Student*> students;

    public:
        std::string course_name;
        Course(const std::string &name);
        void add_student(Student * student);
        std::vector<Student*> Course::show_students();
};

#endif // COURSE_HPP