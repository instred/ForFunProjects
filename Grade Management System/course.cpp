#include "course.hpp"

Course::Course(const std::string &name) : course_name(name){
    //todo : error handling
}

void Course::addStudent(Student * student){
    this->students.push_back(student);
}

std::vector<Student*> Course::GetStudents(){
    return this->students;
}

std::string Course::GetName(){
    return this->course_name;
}

std::ostream& operator<<(std::ostream& output, Course c){
    output << c.course_name;
    return output;
}