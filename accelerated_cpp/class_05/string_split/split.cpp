#include <iostream>
#include "split.h"

using namespace std;

vector<string> split(string& s){
  typedef string::size_type string_size;
  vector<string> ret_string;
  string_size i = 0;

  while( i != s.size())
  {
    while (i != s.size() && isspace(s[i]))
      ++i;
    string_size j = i;
    while (j != s.size() && !isspace(s[j]))
      ++j;

    if (i != j){
      ret_string.push_back(s.substr(i,j-i));
      i = j;
    }
  }
  return ret_string;
}
