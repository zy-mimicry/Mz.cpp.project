#ifndef _MIMICRY_STUDENT_INFO_H_
#define _MIMICRY_STUDENT_INFO_H_

#include <vector>
#include <iostream>
#include <string>

// struct Student_info {
//   std::string name;
//   double midterm_grade, final_grade;
//   std::vector<double> homework;
// };

class Student_info {
public:
  Student_info();
  Student_info(std::istream& in);

  std::string getname() const {return name;}
  std::istream& read(std::istream& in);
  double median(std::vector<double>& h);
  bool valid(){ return !homework.empty();}
  double grade();
  double grade(double m, double f, std::vector<double>& h){
    return grade(m, f, median(h));
  }
  double grade(double m, double f, double h){
    return m * 0.2 + f * 0.4 + h * 0.4;
  }

private:
  double midterm_grade, final_grade;
  std::vector<double> homework;
  std::string name;
};

// std::istream& read(std::istream& in, Student_info& s);
std::istream& read_hw(std::istream& in, std::vector<double>& h);

bool compare(const Student_info& s1 , const Student_info& s2);

#endif
