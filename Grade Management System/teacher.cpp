#include "teacher.hpp"

Teacher::Teacher(std::string log, std::string pwd) : login(log), password(pwd){
    if(!(FileManage::findLogin(log, pwd))){
        FileManage::saveLogin(log, pwd);
    }
};



void Teacher::addGrade(Student* student, Course* course, double g_value, int g_weight, std::string g_desc){
    Grade* newGrade = new Grade(student, course, g_value, g_weight, g_desc);
    this->grades.push_back(newGrade);
    student->addGrade(newGrade);
};

void Teacher::addCourse(Course* newCourse){
    this->courses.push_back(newCourse);
};

std::vector<Course*> Teacher::getCourses(){
    return this->courses;
}

std::vector<Grade*> Teacher::getGrades(){
    return this->grades;
};