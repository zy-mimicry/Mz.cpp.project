/*
 * 对每个学生而言
 * - grade
 * - - median
 * - - average
 * 对所有学生的成绩而言
 * - median
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iomanip>

using namespace std;

struct Student_info {
  std::string name;
  double midterm_grade, final_grade;
  std::vector<double> homework;
};

double median(const std::vector<double>& h){
  typedef std::vector<double>::size_type vec_size;
  vec_size size = h.size();

  if (size == 0)
    throw domain_error("Homework shouldn't be null.");

  return size % 2 == 0
    ? (h[size/2] + h[size/2 - 1])/2
    : (h[size/2]);
}

double grade(const double m, const double f, const double h){
  return m * 0.2 + f * 0.4 + h * 0.4;
}
double grade(const double m, const double f, const std::vector<double>& h){
  return grade(m, f, median(h));
}
double grade(const Student_info& s){
  return grade(s.midterm_grade, s.final_grade, s.homework);
}

istream& read_hw(istream& in, vector<double>& h){

  double k;
  if (in){
    h.clear();

    while (in >> k){
      h.push_back(k);
    }

    in.clear();
  }
  return in;
}

istream& read(istream& in, Student_info& s){

  in >> s.name;
  in >> s.final_grade >> s.midterm_grade;

  return read_hw(in, s.homework);
}


bool did_all_homework(Student_info& s){
  return (find(s.homework.begin(), s.homework.end(), 0)
          == s.homework.end());
}

double grade_aux(const Student_info& s){
  try{
    grade(s);
  }catch(domain_error e){
    return grade(s.midterm_grade, s.final_grade, 0);
  }
}

double median_analysis(const vector<Student_info>& s){
  vector<double> g;
  transform(s.begin(), s.end(), back_inserter(g), grade_aux);
  return median(g);
}

double average(const vector<double>& h){
  if (h.empty())
    return 0.0;
  else
    return accumulate(h.begin(), h.end(), 0.0) / h.size();
}

double average_grade(const Student_info& s){
  return grade(s.midterm_grade, s.final_grade, average(s.homework));
}

double average_analysis(const vector<Student_info>& s){
  vector<double> g;
  transform(s.begin(), s.end(), back_inserter(g), average_grade);
  return median(g);
}

double optimistic_median(const Student_info& s){
  vector<double> nozero;
  remove_copy(s.homework.begin(), s.homework.end(),
              back_inserter(nozero), 0);

  if (nozero.empty())
    return grade(s.midterm_grade, s.final_grade, 0);
  else
    return grade(s.midterm_grade, s.final_grade, median(nozero));
}

double optimistic_analysis(const vector<Student_info>& s){
  vector<double> g;
  transform(s.begin(), s.end(), back_inserter(g), optimistic_median);
  return median(g);
}

void write_analysis(ostream& out, const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt){
  out << setw(10) << name << "\t:(did) " << analysis(did)
      << "\t:(didnt) " << analysis(didnt) << endl;
}

int main (int argc, char** argv){

  vector<Student_info> did, didnt;
  Student_info student;

  while (read(cin, student)){
    if (did_all_homework(student))
      did.push_back(student);
    else
      didnt.push_back(student);
  }
  if (did.empty()){
    cout << "No student did all the homework!" << endl;
    return 1;
  }
  if (didnt.empty()){
    cout << "Every student did all the homework!" << endl;
    return 1;
  }

  write_analysis(cout, "median", median_analysis, did, didnt);
  write_analysis(cout, "average", average_analysis, did, didnt);
  write_analysis(cout, "optimistic", optimistic_analysis, did, didnt);

  return 0;
}
