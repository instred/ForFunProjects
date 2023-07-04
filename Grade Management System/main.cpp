#include "student.hpp"
#include "course.hpp"
#include "grade.hpp"
#include "teacher.hpp"
#include "login.hpp"
#include <iostream>
#include <iomanip>


int main(){
    FileManage::fillFile();
    Student s = Student("jakub", "zulczyk");
    Student s2 = Student("dawid", "bonk");
    Student s3 = Student("ada", "kowal");
    Course c = Course("Przyrka");
    Course c2 = Course("Polski");
    c.add_student(&s);
    c.add_student(&s2);
    c.add_student(&s3);
    c2.add_student(&s);
    c2.add_student(&s2);
    c2.add_student(&s3);
    Teacher t = Teacher("login", "passwd");
    t.addCourse(&c);
    t.addCourse(&c2);
    t.addGrade(&s, &c, 4.5, 5, "sprawdzian przyrka");
    t.addGrade(&s, &c, 3.5, 3, "zadanie domowe");
    t.addGrade(&s3, &c2, 4.5, 4, "karkuwkia");
    t.addGrade(&s, &c2, 2, 4, "karkuwkia");
    t.addGrade(&s2, &c2, 1, 4, "karkuwkia");
    t.addGrade(&s2, &c2, 1, 1, "brak zadania");
    bool access = Login::loginAccess();
    if (!(access))
        return 0;
    while(access){
        std::cout << "Select your course\n";
        int i = 0;
        int choice;
        std::vector<Course*> courses = t.getCourses();
        for (auto c : courses){
            std::cout << i << ": " << c->course_name << '\n';
            i++;
        }
        std::cin >> choice;
        std::vector<Student*> students = courses[choice]->GetStudents();
        for (auto s : students){
            std::cout << s->ShowStudent() << "\n" << s->GetGrades(courses[choice]) << "\n";
        }
    }

}