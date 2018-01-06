#ifndef _MIMICRY_STUDENT_INFO_H_
#define _MIMICRY_STUDENT_INFO_H_

#include <vector>
#include <iostream>
#include <string>

struct Student_info {
  std::string name;
  double midterm_grade, final_grade;
  std::vector<double> homework;
};

std::istream& read(std::istream& in, Student_info& s);
std::istream& read_hw(std::istream& in, std::vector<double>& h);

#endif
