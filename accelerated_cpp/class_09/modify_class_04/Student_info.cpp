#include "Student_info.h"
//#include "grade.h"
#include <stdexcept>

using std::istream;
using std::cout;
using std::endl;
using std::vector;
using std::domain_error;


Student_info::Student_info (): midterm_grade(0), final_grade(0) {}
Student_info::Student_info (istream& in) {
  read(in);
}

double Student_info::median(vector<double>& h){

  typedef std::vector<double>::size_type vec_size;
  vec_size size = h.size();

  if (size == 0)
    throw domain_error("Homework shouldn't be null.");

  return size % 2 == 0
    ? (h[size/2] + h[size/2 - 1])/2
    : (h[size/2]);
}

double Student_info::grade(){
  return grade(midterm_grade, final_grade, homework);
}

istream& Student_info::read(istream& in){
  cout << "\nStudent: @_@" << endl;
  cout << "please input your name :";
  in >> name;
  in.clear();

  cout << "pleae input final grade and midterm:";
  in >> final_grade >> midterm_grade;
  in.clear();

  return ::read_hw(in, homework);
}

istream& read_hw(istream& in, vector<double>& h){

  double k;
  if (in){
    h.clear();

    cout << "please input your homework grade:" << endl;
    while (cout << ">> " ,in >> k){
      h.push_back(k);
    }

    in.clear();
  }
  return in;
}

bool compare(const Student_info& s1 , const Student_info& s2){
  return s1.getname() > s2.getname();
}
