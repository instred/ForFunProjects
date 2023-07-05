#ifndef TEACHER_HPP
#define TEACHER_HPP
#include "course.hpp"
#include "grade.hpp"
#include "fileManage.hpp"


class Teacher{
    
    private:
        std::string login;
        std::string password;
    protected:
        std::vector<Course*> courses;
        std::vector<Grade*> grades;
    
    public:
        Teacher(std::string log, std::string pwd);
        void addCourse(Course* newCourse);
        void addGrade(Student* student, Course* course, double g_value, int g_weight, std::string desc);
        std::vector<Course*> getCourses();
        std::vector<Grade*> getGrades();
};




#endif // TEACHER_HPP