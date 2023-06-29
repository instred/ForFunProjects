#include "student.hpp"
#include "course.hpp"
#include "fileManage.hpp"
#include "grade.hpp"
#include <iostream>


int main(){
    fill_file();
    Student s = Student("jakub", "zulczyk");
    Student s2 = Student("dawid", "bonk");
    Student s3 = Student("ada", "kowal");
    Course c = Course("Przyrka");
    c.add_student(&s);
    c.add_student(&s2);
    c.add_student(&s3);
    Grade g = Grade(&c, 4.5);
    Grade g2 = Grade(&c, 3.5);
    Grade g3 = Grade(&c, 6);
}