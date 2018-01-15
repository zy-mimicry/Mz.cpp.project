#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

void display_urls(vector<string>& vec_str);
bool not_url_char(char c);
vector<string> find_urls(string& s);
string::iterator url_end(string::iterator b, string::iterator e);
string::iterator url_beg(string::iterator b, string::iterator e);


int main (int argc, char** argv){
  string input;
  string combo_string;
  vector<string> urls;

  while (getline(cin, input)){
    combo_string += input;
  }

  urls = find_urls(combo_string);

  display_urls(urls);

  return 0;
}

void display_urls(vector<string>& vec_str){
  cout << "\nUrls: " << endl;
  for (vector<string>::iterator it = vec_str.begin();
       it != vec_str.end();
       ++it){
    cout << *it << endl;
  }
}

vector<string> find_urls(string& s){
  vector<string> ret;
  typedef string::iterator iter;
  iter b = s.begin(), e = s.end();

  while (b != e){
    b = url_beg(b, e);
    if (b != e){
      iter after = url_end(b, e);
      ret.push_back(string(b, after));
      b = after;
    }
  }
  return ret;
}

bool not_url_char(char c){
  static const string url_chr = "~;/?:@=&$-_.+!'*(),";
  return !(isalnum(c) ||
           find(url_chr.begin(), url_chr.end(), c) != url_chr.end());
}

string::iterator url_end(string::iterator b, string::iterator e){
  return find_if(b, e, not_url_char);
}

string::iterator url_beg(string::iterator b, string::iterator e){
  typedef string::iterator iter;
  static const string sep = "://";

  iter i = b;
  while ((i = search(i, e, sep.begin(), sep.end())) != e){
    if (i != b &&
        i + sep.size() != e){
      iter beg = i;
      while (beg != b && isalpha(beg[-1]))
        --beg;
      if (beg != i &&
          beg+sep.size() != e &&
          !not_url_char(i[sep.size()]))
        return beg;
    }
    if (i != e){
      i += sep.size();
    }
  }
  return e;
}
