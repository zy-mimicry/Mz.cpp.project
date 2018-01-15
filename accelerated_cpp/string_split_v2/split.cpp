#include <iostream>
#include <algorithm>
#include "split.h"

using namespace std;

bool space(char c){
  return isspace(c);
}

bool not_space(char c){
  return !isspace(c);
}

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

vector<string> split_v2(string& s){
  typedef string::size_type string_size;
  typedef string::iterator iter;
  vector<string> ret_string;

  iter i = s.begin();

  while(i != s.end()){
    i = find_if(i, s.end(), not_space);
    iter j  = i;

    j = find_if(j, s.end(), space);

    if (i != j){
      ret_string.push_back(string(i,j));
    }
    i = j;
  }
  return ret_string;
}
