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

std::string Student::GetGrades(){
    std::string show_grades = this->ShowStudent() + "'s grades:\n";
    for (Grade* grade : this->grades){
        show_grades += grade->GetGradeValue() + " ";
    }
    return show_grades;
}