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
        void addGrade(Grade* newGrade);
        std::vector<Course*> getCourses();
        std::vector<Grade*> getGrades();
        std::pair<std::string, std::string> getData();
};




#endif // TEACHER_HPP