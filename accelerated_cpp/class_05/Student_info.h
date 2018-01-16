#ifndef _MIMICRY_STUDENT_INFO_H_
#define _MIMICRY_STUDENT_INFO_H_

#include <vector>
#include <iostream>
#include <string>
#include <list>

struct Student_info {
  std::string name;
  double midterm_grade, final_grade;
  std::vector<double> homework;
};

std::istream& read(std::istream& in, Student_info& s);
std::istream& read_hw(std::istream& in, std::vector<double>& h);
bool compare(const Student_info& s1 , const Student_info& s2);

//bool fgrade(Student_info& s);
std::vector<Student_info> extract_fails(std::vector<Student_info>& s);
std::vector<Student_info> extract_fails_v2(std::vector<Student_info>& s);
std::vector<Student_info> extract_fails_v3(std::vector<Student_info>& s);
std::list<Student_info> extract_fails_v4(std::list<Student_info>& s);
std::vector<Student_info> extract_fails_v5(std::vector<Student_info>& s);
std::vector<Student_info> extract_fails_v6(std::vector<Student_info>& s);

#endif
