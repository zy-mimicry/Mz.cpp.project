#include "frame.h"

#include <iostream>
#include <algorithm>

using std::vector;
using std::string;

using std::cout;
using std::endl;
using std::max;

string::size_type width(vector<string>& s){
  string::size_type width = 0, i = 0;
  string::size_type max_len = 0;
  while (i != s.size()){
    max_len = max(max_len, s[i].size());
    ++i;
  }
  return max_len;
}

vector<string> frame(vector<string>& s){
  vector<string> ret;
  string context;
  string::size_type max_width = width(s);

  string boarder(max_width+4, '*');
  ret.push_back(boarder);

  for (string::size_type i = 0;
       i != s.size();
       ++i){
    context = "* " + s[i] + string(max_width-s[i].size(), ' ') + " *";
    ret.push_back(context);
  }

  ret.push_back(boarder);
  return ret;
}

vector<string> hcat(vector<string>& top, vector<string>& bottom){
  vector<string> ret;
  for (string::size_type i = 0;
       i != top.size();
       ++i){
    ret.push_back(top[i]);
  }
  for (string::size_type j = 0;
       j != bottom.size();
       ++j){
    ret.push_back(bottom[j]);
  }
  return ret;
}

vector<string> vcat(vector<string>& left, vector<string>& right){
  vector<string> ret;
  string context;
  string::size_type max_width = width(left) + 1;
  vector<string>::size_type i = 0 , j = 0;

  while (i != left.size() || j != right.size()){
    if (i != left.size()){
      context = left[i];
      ++i;
    }

    context += string(max_width - context.size(), ' ');

    if (j != right.size()){
      context += right[j];
      ++j;
    }
    ret.push_back(context);
  }
  return ret;
}

void display(vector<string>& s){
  for (string::size_type i = 0;
       i != s.size();
       ++i){
    cout << s[i] << endl;
  }
}
