#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cctype>

using namespace std;

bool not_space(char c){
  return !isspace(c);
}

bool is_space(char c){
  return !not_space(c);
}

template<class Out>
void split(const string& s, Out out)
{
  typedef string::const_iterator iter;

  iter i = s.begin();
  while (i != s.end()){
    i = find_if(i, s.end(), not_space);
    iter j = find_if(i, s.end(), is_space);
    if (i != s.end())
      *out++ = string(i,j);
    i = j;
  }
}

int main (int argc, char** argv){

  string s ;
  vector<string> m_string;
  while (getline(cin, s))
    split(s, back_inserter(m_string));

  copy(m_string.begin(), m_string.end(), ostream_iterator<string>(cout, ","));
  cout << endl;

  return 0;
}
