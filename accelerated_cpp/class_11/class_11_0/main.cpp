#include <iostream>
#include <string>
#include "Vec.h"

using namespace std;

int main (int argc, char** argv){
  Vec<string> names ;

  string name;
  while (cin >> name)
    names.push_back(name);

  Vec<string>::iterator i = names.begin();

  while (i != names.end()-1){
    cout << *i << ",";
    ++i;
  }
  cout << *i << endl;
  return 0;
}
