#include "grade.hpp"

Grade::Grade(Course* course, double g_value) : course(course), grade_value(g_value){}

int Grade::GetGradeValue(){
    return this->grade_value;
}