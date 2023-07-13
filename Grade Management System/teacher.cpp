#include "teacher.hpp"

Teacher::Teacher(std::string log, std::string pwd) : login(log), password(pwd){};



void Teacher::addGrade(Grade* newGrade){
    this->grades.push_back(newGrade);
    newGrade->GetStudent()->addGrade(newGrade);
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

std::pair<std::string, std::string> Teacher::getData(){
    return std::make_pair(this->login, this->password);
}

std::string Teacher::getLogin(){
    return this->login;
}

std::ostream& operator<<(std::ostream& output, Teacher t){
    output << t.login;
    return output;
}
