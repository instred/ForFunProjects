#include "grade.hpp"

#include <iomanip>


Grade::Grade(Student* student, Course* course, double g_value, int g_weight, std::string desc) : student(student), course(course), 
grade_value(g_value), grade_weight(g_weight), grade_description(desc){
};


std::string Grade::ShowGrade(){
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << this->grade_value << " W:" << this->grade_weight << " | " << this->grade_description << " ";
    return oss.str();
}

Course* Grade::GetCourse(){
    return this->course;
}

Student* Grade::GetStudent(){
    return this->student;
}

double Grade::GetValue(){
    return this->grade_value;
}

int Grade::GetWeight(){
    return this->grade_weight;
}