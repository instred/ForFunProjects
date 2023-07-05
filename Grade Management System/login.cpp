#include "login.hpp"

std::vector<Teacher*> teachers;

void Login::initData(){
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
    Teacher* tmp = &t;
    tmp->addCourse(&c);
    tmp->addCourse(&c2);
    tmp->addGrade(&s, &c, 4.5, 5, "sprawdzian przyrka");
    tmp->addGrade(&s, &c, 3.5, 3, "zadanie domowe");
    tmp->addGrade(&s3, &c2, 4.5, 4, "karkuwkia");
    tmp->addGrade(&s, &c2, 2, 4, "karkuwkia");
    tmp->addGrade(&s2, &c2, 1, 4, "karkuwkia");
    tmp->addGrade(&s2, &c2, 1, 1, "brak zadania");
    teachers.push_back(tmp);
}

std::string Login::loginAccess(){
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
    if (!(FileManage::findLogin(login, pwd))){
        std::cout << "Wrong credentials!\n";
        tryCount++;
        goto login;
        
    }
    else
        access = login;
    return access;
}

void Login::userLoop(){
    Login::initData();
    std::vector<std::pair<std::string, std::string>> creds = FileManage::loadLogin();
    std::string access = Login::loginAccess();
    int pos = 0;
    for (const auto& loginPair : creds){
        if (!(loginPair.first == access)){
            pos++;
        }
    }
    while(access != ""){
        std::cout << "Select your course\n";
        int i = 0;
        int choice;
        std::vector<Course*> courses = teachers[pos]->getCourses();
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