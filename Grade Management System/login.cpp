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

bool Login::findLogin(std::vector<Teacher> teachers, std::string login, std::string pwd){
    for (auto& t : teachers){
        if(t.getData().first == login && t.getData().second == pwd){
            return true;
        }
    }
    return false;
}


std::string Login::loginAccess(std::vector<Teacher> teachers){
    std::string access;
    int tryCount = 0;
    std::string login, pwd;
    login:
        if (tryCount > 2){
            std::cout << "You entered wrong credentials 3 times, program will now exit";
            return "";
        }
        std::cout << "Enter login: ";
        std::cin >> login;
        std::cout << "Enter password: ";
        std::cin >> pwd;
    if (!(Login::findLogin(teachers, login, pwd))){
        std::cout << "Wrong credentials!\n";
        tryCount++;
        goto login;
        
    }
    else
        access = login;
    return access;
}

double Login::getAVG(Course* course, Student* student){
    double avg = 0;
    int weight = 0;
    for (auto& grade : student->GetGrades()){
        if(course->GetName() == grade->GetCourse()->GetName()){
            avg += (grade->GetValue() * grade->GetWeight());
            weight += grade->GetWeight();
        }
        
    }
    // NaN values comparision with themselves are always false for some reason
    if (avg/weight != avg/weight){
        return 0;
    }
    return avg/weight;
}


void Login::showGrades(Course* c_choice){
    for (auto& student : c_choice->GetStudents()){
        std::cout << student->ShowStudent() << "(AVG: " << Login::getAVG(c_choice, student) << ") grades:\n";
        for (auto& grade : student->GetGrades()){
            if (c_choice->GetName() == grade->GetCourse()->GetName()){
                std::cout << grade->ShowGrade() << "\n";
            }
        }
    }
}


void Login::userLoop(){
    std::cout << "Hi, Welcome to Grade Management System!\nPlease log in using your login and password:\n";
    while(true){
        FileManage::fillFile();
        std::vector<std::pair<std::string, Course>> teacherCourses;
        std::vector<std::pair<std::string, Grade>> teacherGrades;
        std::vector<Teacher> teachers = Login::loadTeachers();
        std::vector<Student> students = Login::loadStudents();
        std::vector<Course> courses = Login::loadCourses(teachers, students, teacherCourses);
        std::vector<Grade> grades = Login::loadGrades(teachers, students, courses, teacherGrades);
        std::string login = Login::loginAccess(teachers);
        if (login == ""){
            return;
        }
        Teacher* t_access;
        for (auto& teacher : teachers){
            if (teacher.getData().first == login){
                t_access = &teacher;
            }
        }
        std::cout << "Hi " << login << " Select your course:\n";
        int course_n = 1;
        for (auto& course : t_access->getCourses()){
            std::cout << course_n << ": " << course->GetName() << '\n';
            course_n ++; 
        }
        int c_id;
        std::cin >> c_id;
        Course* c_choice = t_access->getCourses()[c_id-1];
        std::cout << "Students on the list:\n";
        Login::showGrades(c_choice);
        std::cout << "What would you like to do?\n1 - Add Grade\n2 - Remove Grade\n3 - Add Student to the Course\n4 - Remove Student from the list\n5 - Exit";
        int mgmt_choice;
        std::cin >> mgmt_choice;
        switch (mgmt_choice)
        {
        case 1:
            std::cout << "Adding grade format - studentID, grade value, grade weight, short description";
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            return;
        } 
    }
}