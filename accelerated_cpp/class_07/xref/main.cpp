#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool space(char c){
  return isspace(c);
}

bool not_space(char c){
  return !isspace(c);
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

map<string, vector<int> > xref(istream& in, vector<string> find_world (string& s) = split_v2){
  map<string, vector<int> > ret;
  vector<string> worlds;
  string line;
  int line_number = 0;

  while (getline(in, line)){
    ++line_number;

    worlds = find_world(line);

    for (vector<string>::iterator it = worlds.begin();
         it != worlds.end();
         ++it){
      ret[*it].push_back(line_number);
    }
  }
  return ret;
}


int main (int argc, char** argv){

  map<string, vector<int> > mm = xref(cin, split_v2);

  for (map<string, vector<int> >::iterator it = mm.begin();
       it != mm.end();
       ++it){
    cout << setw(10) << it->first ;
    vector<int>::iterator iter = it->second.begin();
    cout << ":" << *iter;
    ++iter;
    while (iter != it->second.end()){
      cout << "," << *iter;
      ++iter;
    }
    cout << endl;
  }
  return 0;
}
