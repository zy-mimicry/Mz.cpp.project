#include "Student_info.h"

using std::istream;
using std::cout;
using std::endl;
using std::vector;

istream& read(istream& in, Student_info& s){

  cout << "please input your name :";
  in >> s.name;
  cout << endl;

  cout << "pleae input final grade and midterm:";
  in >> s.final_grade >> s.midterm_grade;
  cout << endl;

  return read_hw(in, s.homework);
}

istream& read_hw(istream& in, vector<double>& h){

  double k;
  if (in){
    h.clear();

    cout << "please input your homework grade:" << endl;
    while (cout << ">> " ,in >> k){
      cout << endl;
      h.push_back(k);
    }

    in.clear();
  }
  return in;
}
