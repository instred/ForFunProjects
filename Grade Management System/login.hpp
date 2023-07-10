#include <iostream>
#include <string>
#include <sstream>
#include "fileManage.hpp"
#include "student.hpp"
#include "course.hpp"
#include "grade.hpp"
#include "teacher.hpp"

class Login{

    public:
        static void initData();
        static std::string loginAccess(std::vector<Teacher*> teachers);
        static void userLoop();
        static std::vector<Teacher*> loadLogin();
        static bool findLogin(std::vector<Teacher*> teachers, std::string login, std::string pwd);
        static std::vector<Teacher> loadTeachers();
        static std::vector<Student> loadStudents();
        static std::vector<Course> loadCourses(std::vector<Teacher>& teachers, std::vector<Student>& students, std::vector<std::pair<std::string, Course>>& test);
        static std::vector<Grade> loadGrades(std::vector<Teacher>& teachers, std::vector<Student>& students, std::vector<Course>& courses, std::vector<std::pair<std::string, Grade>>& teacherGrades);
};

