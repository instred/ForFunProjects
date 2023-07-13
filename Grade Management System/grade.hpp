#ifndef GRADE_HPP
#define GRADE_HPP

#include <string>

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
        std::string ShowGrade();
        Course* GetCourse();
        Student* GetStudent();
        double GetValue();
        int GetWeight();
        friend std::ostream& operator<<(std::ostream& output, Grade g);
};




#endif // GRADE_HPP