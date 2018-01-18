#include <iostream>
#include <string>

using namespace std;

string printfm(string& name){
  return name;
}

class Student_info{
public:
  Student_info(){}
  Student_info(istream& in){read(in);}
  string printfm(){
    return ::printfm(n);
  }
  string name(){
    return n;
  }
  void set_name(string& s){
    n = s;
  }
  istream& read(istream& in){
    in >> n ;
    return in;
  }
private:
  string n;
};

int main (int argc, char** argv){

  Student_info student;
  string name = "Tom";
  student.set_name(name);
  cout << student.name() << endl;
  cout << student.printfm() << endl;
  Student_info ss(cin);
  cout << ss.name() << endl;
  return 0;
}
