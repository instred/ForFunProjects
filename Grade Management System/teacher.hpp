#ifndef TEACHER_HPP
#define TEACHER_HPP
#include "course.hpp"
#include "grade.hpp"


class Teacher{
    protected:
        std::string first_name;
        std::string last_name;
        std::vector<Course*> courses;
        std::vector<Grade*> grades;
    
    public:
        Teacher(std::string f_name, std::string l_name);
        void addCourse(Course* newCourse);
        void addGrade(Student* student, Course* course, double g_value, int g_weight, std::string desc);
        std::vector<Course*> getCourses();
        std::vector<Grade*> getGrades();
};




#endif // TEACHER_HPP