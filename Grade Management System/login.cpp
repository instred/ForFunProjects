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

std::vector<Course> Login::loadCourses(std::vector<Teacher>& teachers, std::vector<Student>& students, std::vector<std::pair<std::string, Course>>& teacherCourses){
    std::ifstream file("courses.txt");
    std::string teacher_log, c_name, txt_ids, tmp;
    std::vector<Course> courses;
    Student* courseStudent;
    Course* teacherCourse;
    while(file >> teacher_log >> c_name >> txt_ids){
        Course course(c_name);
        std::vector<int> student_ids;
        std::stringstream numbers_in(txt_ids);
        while(std::getline(numbers_in, tmp, ',')){
            int n = stoi(tmp);
            student_ids.push_back(n);
        }
        for (auto& id : student_ids){
            courseStudent = &students[id-1];
            course.addStudent(courseStudent);
        }
        teacherCourses.push_back(std::make_pair(teacher_log, course));
        courses.push_back(course);
    }
    //check later if you can improve logic on it
    for (auto& tmp : teacherCourses){
        for (auto& t : teachers){
            if(tmp.first == t.getLogin()){
                t.addCourse(&tmp.second);
            }
        }
    }
    
    if (file.fail() && !file.eof()) {
        std::cerr << "Error: Failed to read data from courses.txt\n";
        // Handle the error appropriately (e.g., return an empty vector or throw an exception)
    }
    

    return courses;
}


std::vector<Grade> Login::loadGrades(std::vector<Teacher>& teachers, std::vector<Student>& students, std::vector<Course>& courses, std::vector<std::pair<std::string, Grade>>& teacherGrades){
    std::ifstream file("grades.txt");
    std::string course, description, teacher_log;
    double grade_value;
    int weight, student_id;
    Student* gradeStudent;
    Course* gradeCourse;
    std::vector<Grade> grades;
    while(file >> teacher_log >> student_id >> course >> grade_value >> weight >> description){
        gradeStudent = &students[student_id-1];
        for (auto& c : courses){
            if(c.GetName() == course){
                gradeCourse = &c;
            }     
        }
        Grade grade(gradeStudent, gradeCourse, grade_value, weight, description);
        teacherGrades.push_back(std::make_pair(teacher_log, grade));
        grades.push_back(grade);
    }
    //check later if you can improve logic on it
    for (auto& tmp : teacherGrades){
        for (auto& t : teachers){
            if(tmp.first == t.getLogin()){
                t.addGrade(&tmp.second);
            }
        }
    }
}

// test
void Login::initData(){
    FileManage::fillFile();
    std::vector<std::pair<std::string, Course>> teacherCourses;
    std::vector<std::pair<std::string, Grade>> teacherGrades;
    std::vector<Teacher> teachers = Login::loadTeachers();
    std::vector<Student> students = Login::loadStudents();
    std::vector<Course> courses = Login::loadCourses(teachers, students, teacherCourses);
    std::vector<Grade> grades = Login::loadGrades(teachers, students, courses, teacherGrades);
    Course* dupa = teachers[0].getCourses()[1];
    std::cout << teachers[0].getLogin() << ": ";
    std::cout << dupa->GetName() << " ";
    std::cout << dupa->GetStudents()[0]->ShowStudent() << "\n";
    for (auto x : dupa->GetStudents()[0]->GetGrades()){
        if (dupa->GetName() == x->GetCourse()->GetName()){
            std::cout << x->ShowGrade() << "\n";
        }
        
    }

    

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