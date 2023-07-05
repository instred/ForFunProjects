#include <iostream>
#include <string>
#include "fileManage.hpp"
#include "student.hpp"
#include "course.hpp"
#include "grade.hpp"
#include "teacher.hpp"

class Login{

    public:
        static void initData();
        static std::string loginAccess();
        static void userLoop();
};

