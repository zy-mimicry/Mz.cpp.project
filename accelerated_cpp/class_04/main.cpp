#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

#include "Student_info.h"
#include "grade.h"

using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::vector;
using std::sort;

bool compare(const Student_info& s1 , const Student_info& s2);

int main (int argc, char ** argv){
  Student_info student;
  vector<Student_info> students;
  char flag;

  while (cout << "\nStudent: @_@" <<endl, read(cin, student)){
    students.push_back(student);
  unknow:
    cout << "Continue ? [y/n]" ;
    cin >> flag;
    if (flag == 'y')
      continue;
    else if (flag == 'n')
      break;
    else{
      cout << "Unknow answer." << endl;
      goto unknow;
    }
  }

  sort(students.begin(), students.end(), compare);

  try{
    vector<Student_info>::size_type i;
    double score;
    for (i=0; i<students.size(); i++){
      score = grade(students[i]);
      cout << "\n{Students} ^>-<^" << endl;
      cout << "[name]: " << students[i].name << "\t";
      cout << "[score]: " << score << endl;
    }
  }catch(domain_error e){
    e.what();
    return 1;
  }

  return 0;
}
