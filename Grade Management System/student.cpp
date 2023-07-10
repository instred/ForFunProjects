#include "student.hpp"
#include "fileManage.hpp"

Student::Student(std::string f_name, std::string l_name) : first_name(f_name), last_name(l_name){
    //todo : error handling
    this->id = std::stoi(FileManage::removeLine());
}

std::string Student::ShowStudent(){
    return "ID: " + std::to_string(this->id) + " Student: " + this->first_name + " " + this->last_name;
}

std::vector<Grade*> Student::GetGrades(){
    return this->grades;
}

std::vector<Grade*> Student::FilterGrades(Course* course){
    std::vector<Grade*> filteredGrades;
    return filteredGrades;
}

void Student::addGrade(Grade* grade){
    this->grades.push_back(grade);
}

int Student::getID(){
    return this->id;
}
