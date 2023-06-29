#include "course.hpp"

Course::Course(const std::string &name) : course_name(name){
    //todo : error handling
}

void Course::add_student(Student * student){
    this->students.push_back(student);
}

std::vector<Student*> Course::show_students(){
    return this->students;
}