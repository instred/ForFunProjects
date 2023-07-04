#ifndef GRADE_HPP
#define GRADE_HPP

#include <string>
#include <iomanip>

class Course;
class Student;

class Grade{

    protected:
        Student* student;
        Course* course;
        double grade_value;
        int grade_weight;

    public:
        std::string grade_description;
        Grade(Student* student, Course* course, double g_value, int g_weight, std::string desc);
        std::string GetGrades();
        Course* GetCourse();
};




#endif // GRADE_HPP