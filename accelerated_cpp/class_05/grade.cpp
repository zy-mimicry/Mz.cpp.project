#include "grade.h"
#include "median.h"

double grade(Student_info& s){
  return grade(s.midterm_grade, s.final_grade, s.homework);
}

double grade(double m, double f, std::vector<double>& h){
  return grade(m, f, median(h));
}

double grade(double m, double f, double h){
  return m * 0.2 + f * 0.4 + h * 0.4;
}
