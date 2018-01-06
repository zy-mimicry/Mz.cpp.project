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

  while (cout << "Studeng @@" <<endl, read(cin, student)){
    students.push_back(student);
  }

  sort(students.begin(), students.end(), compare);

  try{
    int i ;
    double score;
    for (i=0; i<students.size(); i++){
      score = grade(students[i]);
      cout << "[name] --" << students[i].name << "\t";
      cout << "score: " << score << endl;
    }
  }catch(domain_error e){
    e.what();
    return 1;
  }

  return 0;
}

bool compare(const Student_info& s1 , const Student_info& s2){
  return s1.name > s2.name;
}
