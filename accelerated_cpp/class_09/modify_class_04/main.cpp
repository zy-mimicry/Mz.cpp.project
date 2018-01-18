#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

#include "Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::vector;
using std::sort;

int main (int argc, char ** argv){
  Student_info student;
  vector<Student_info> students;
  char flag;

  while (student.read(cin)){
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
      cout << "here" << endl;
      if (students[i].valid()){
        cout << "??here" << endl;
        score = students[i].grade();
        cout << "\n{Students} ^>-<^" << endl;
        cout << "[name]: " << students[i].getname() << "\t";
        cout << "[score]: " << score << endl;
      }else{
        throw domain_error("students score is unvaled.");
      }
    }
  }catch(domain_error e){
    cout << e.what() << endl;
    return 1;
  }

  return 0;
}
