#include "grade.hpp"


Grade::Grade(Student* student, Course* course, double g_value, int g_weight, std::string desc) : student(student), course(course), 
grade_value(g_value), grade_weight(g_weight), grade_description(desc){
};


std::string Grade::GetGrades(){
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << this->grade_value << " W:" << this->grade_weight << " | " << this->grade_description << '\n';
    return oss.str();
}

Course* Grade::GetCourse(){
    return this->course;
}