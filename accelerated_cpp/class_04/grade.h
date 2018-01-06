#ifndef _MIMICRY_GRADE_H_
#define _MIMICRY_GRADE_H_

#include "Student_info.h"
#include <vector>

double grade(Student_info& s);
double grade(double m, double f, std::vector<double>& h);
double grade(double m, double f, double h);

#endif
