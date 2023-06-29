#ifndef GRADE_HPP
#define GRADE_HPP

#include "course.hpp"

class Grade{

    protected:
        double grade_value;
        Course* course;

    public:
        Grade(Course* course, double g_value);
        int GetGradeValue();
};







#endif // GRADE_HPP