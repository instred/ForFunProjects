#include "login.hpp"

std::vector<Teacher> Login::loadTeachers(){
    std::ifstream file("login.txt");
    std::string l, p;
    std::vector<Teacher> teachers;
    while(file >> l >> p){
        Teacher teacher(l, p);
        teachers.push_back(teacher);
    }
    if (file.fail() && !file.eof()) {
        std::cerr << "Error: Failed to read data from teachers\n";
        // Handle the error appropriately (e.g., return an empty vector or throw an exception)
    }
    return teachers;
}

std::vector<Course> Login::loadCourses(std::vector<Teacher>& teachers){
    std::ifstream file("courses.txt");
    std::string teacher_log, c;
    std::vector<Course> courses;
    while(file >> teacher_log >> c){
        Course course(c);
        courses.push_back(course);
        for (auto t : teachers){
            if(t.getData().first == teacher_log){
                t.addCourse(&course);
            }
        }
    }
    if (file.fail() && !file.eof()) {
        std::cerr << "Error: Failed to read data from teachers\n";
        // Handle the error appropriately (e.g., return an empty vector or throw an exception)
    }
    return courses;
}

std::vector<Student> Login::loadStudents(){
    std::ifstream file("students.txt");
    std::string f_name, l_name;
    std::vector<Student> students;
    while(file >> f_name >> l_name){
        Student student(f_name, l_name);
        students.push_back(student);
    }
   
    if (file.fail() && !file.eof()) {
        std::cerr << "Error: Failed to read data from students.txt\n";
        // Handle the error appropriately (e.g., return an empty vector or throw an exception)
    }
    return students;
}

std::vector<Grade> Login::loadGrades(std::vector<Teacher>& teachers, std::vector<Student>& students, std::vector<Course>& courses){
    std::ifstream file("grades.txt");
    std::string course, description, teacher_log;
    double grade_value;
    int weight, student_id;
    Student* gradeStudent;
    Course* gradeCourse;
    std::vector<Grade> grades;
    while(file >> teacher_log >> student_id >> course >> grade_value >> weight >> description){
        gradeStudent = &students[student_id-1];
        for (auto c : courses){
            if(c.course_name == course){
                gradeCourse = &c;
            }     
        }
        Grade grade(gradeStudent, gradeCourse, grade_value, weight, description);
        grades.push_back(grade);
        for (auto t : teachers){
            if(t.getData().first == teacher_log){
                t.addGrade(&grade);
            }
        }
    }
}


void Login::initData(){
    FileManage::fillFile();
    std::vector<Teacher> teachers = Login::loadTeachers();
    std::vector<Student> students = Login::loadStudents();
    std::vector<Course> courses = Login::loadCourses(teachers);
    std::vector<Grade> grades = Login::loadGrades(teachers, students, courses);
    // on load add students to courses somehow
    // prob courses.txt need a change idk



}



// bool Login::findLogin(std::vector<Teacher*> teachers, std::string login, std::string pwd){
//     for (const auto& t : teachers){
//         if(t->getData().first == login && t->getData().second == pwd){
//             return true;
//         }
//     }
//     return false;
// }

// std::string Login::loginAccess(std::vector<Teacher*> teachers){
//     std::string access;
//     int tryCount = 0;
//     std::string login, pwd;
//     login:
//         if (tryCount > 2){
//             std::cout << "You entered wrong credentials 3 times, program will now exit";
//             return "";
//         }
//         std::cout << "Enter login: ";
//         std::cin >> login;
//         std::cout << "Enter password: ";
//         std::cin >> pwd;
//     if (!(Login::findLogin(teachers, login, pwd))){
//         std::cout << "Wrong credentials!\n";
//         tryCount++;
//         goto login;
        
//     }
//     else
//         access = login;
//     return access;
// }

// void Login::userLoop(){
//     Login::initData();
//     std::vector<Teacher*> teachers = Login::loadLogin();
//     std::string access = Login::loginAccess(teachers);
//     int pos = 0;
//     for (const auto& loginPair : teachers){
//         if (!(loginPair->getData().first == access)){
//             pos++;
//             std::cout << loginPair << '\n';
//         }
//     }
//     std::cout << teachers[pos]->getData().first;
//     while(access != ""){
//         std::cout << "Select your course\n";
//         int i = 0;
//         int choice;
//         Teacher t = *teachers[pos];
//         for (const auto& c : t.getCourses()){
//             std::cout << c;
//             std::cout << "dupa";
//         }
//         std::vector<Course*> courses = t.getCourses();
//         for (auto c : courses){
//             std::cout << i << ": " << c->course_name << '\n';
//             i++;
//         }
//         std::cin >> choice;
//         std::vector<Student*> students = courses[choice]->GetStudents();
//         for (auto s : students){
//             std::cout << s->ShowStudent() << "\n" << s->GetGrades(courses[choice]) << "\n";
//         }
//     }
// }