#include "student.hpp"
#include "fileManage.hpp"

Student::Student(const std::string &f_name, const std::string &l_name) : first_name(f_name), last_name(l_name){
    //todo : error handling
    this->id = std::stoi(remove_line());
    this->available_ids.pop_back();
}

std::string Student::ShowStudent(){
    return "ID: " + std::to_string(this->id) + " Student: " + this->first_name + " " + this->last_name;
}

std::string Student::GetGrades(Course* c){
    std::string show_grades = "";
    for (Grade* grade : this->grades){
        if (grade->GetCourse() == c){
            show_grades += grade->GetGrades() + " ";
        }
    }
    return show_grades;
}

void Student::addGrade(Grade* grade){
    this->grades.push_back(grade);
}

