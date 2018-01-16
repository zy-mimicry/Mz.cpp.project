#include "Student_info.h"
#include "grade.h"
#include <algorithm>

using std::istream;
using std::cout;
using std::endl;
using std::vector;
using std::list;

istream& read(istream& in, Student_info& s){

  cout << "please input your name :";
  in >> s.name;
  in.clear();

  cout << "pleae input final grade and midterm:";
  in >> s.final_grade >> s.midterm_grade;
  in.clear();

  return read_hw(in, s.homework);
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
  return s1.name > s2.name;
}

static bool fgrade(Student_info& s){
  return grade(s) < 60 ;
}
static bool pgrade(Student_info& s){
  return !fgrade(s);
}

vector<Student_info> extract_fails(vector<Student_info>& s){
  vector<Student_info> fail, pass;
  for (vector<Student_info>::size_type i=0; i<s.size(); ++i){
    if (fgrade(s[i]))
      fail.push_back(s[i]);
    else
      pass.push_back(s[i]);
  }
  s = pass;
  return fail;
}

vector<Student_info> extract_fails_v2(vector<Student_info>& s){
  vector<Student_info> fail;
  vector<Student_info>::size_type i = 0;
  while(i != s.size()){
    if (fgrade(s[i])){
      fail.push_back(s[i]);
      s.erase(s.begin() + i);
    }else{
      ++i;
    }
  }
  return fail;
}

vector<Student_info> extract_fails_v3(vector<Student_info>& s){
  vector<Student_info> fail;
  vector<Student_info>::iterator iter = s.begin();
  while (iter != s.end()){
    if (fgrade(*iter)){
      fail.push_back(*iter);
      iter = s.erase(iter);
    }else
      ++iter;
  }
  return fail;
}

list<Student_info> extract_fails_v4(list<Student_info>& s){
  list<Student_info> fail;
  list<Student_info>::iterator iter = s.begin();
  while(iter != s.end()){
    if (fgrade(*iter)){
      fail.push_back(*iter);
      iter = s.erase(iter);
    }else
      ++iter;
  }
  return fail;
}


vector<Student_info> extract_fails_v5(vector<Student_info>& s){
  vector<Student_info> fail;
  remove_copy_if(s.begin(), s.end(), back_inserter(fail), pgrade);
  s.erase(remove_if(s.begin(), s.end(), fgrade), s.end());
  return fail;
}

vector<Student_info> extract_fails_v6(vector<Student_info>& s){
  vector<Student_info>::iterator iter=
    stable_partition(s.begin(), s.end(), pgrade);
  vector<Student_info> fail(iter, s.end());
  s.erase(iter,s.end());
  return fail;
}
