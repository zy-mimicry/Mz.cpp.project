#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;


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

void display(vector<string>& s){
  for (vector<string>::iterator it = s.begin();
       it != s.end();
       ++it){
    cout << *it << endl;
  }
}

void display_all_rules(Grammar& g){
  for (Grammar::iterator it = g.begin();
       it != g.end();
       ++it){
    cout << it->first << ": " ;
    Rule_collection& c = it->second;

    for (Rule_collection::iterator i = c.begin();
         i != c.end();
         ++i){
      cout << "R_c/ " ;
      for (Rule::iterator _i = (*i).begin();
           _i != (*i).end();
           ++_i){
        if (_i != (*i).begin())
          cout << "," << *_i;
        else
          cout << *_i;
      }
      cout << " " ;
    }
    cout << endl;
  }
}

Grammar read_grammar(istream& in)
{
  Grammar ret;
  string s;

  while (getline(in, s)){
    vector<string> v = split_v2(s);
    // display(v);
    if (!v.empty())
      ret[v[0]].push_back(Rule(v.begin()+1, v.end()));
  }

  display_all_rules(ret);

  return ret;
}

int nrand( int n){

  if (n < 0 || n >= RAND_MAX)
    throw domain_error("Argument to nrand is out of range.");

  int r;
  srand(std::time(0));
  const int size = RAND_MAX / n ;

  do
    r = rand() / size;
  while (r >= n);
  cout << r << " :rand" << endl;
  return r;
}

// template <class IO>
// IO nrand( IO io){

//   if (io < 0 || io >= RAND_MAX)
//     throw domain_error("Argument to nrand is out of range.");

//   IO r;
//   IO size = RAND_MAX / io ;

//   do
//     r = rand() / size;
//   while (r >= io);
//   cout << r << " :rand" << endl;

//   return r;
// }

bool is_backeted(const string& word){
  return (!word.empty() && word[0] == '<' && word[word.size()-1] == '>');
}

void gen_aux(const Grammar& g, string word, vector<string>& s_ret){
  if (!is_backeted(word)){
    s_ret.push_back(word);
  }else{
    Grammar::const_iterator it = g.find(word);
    if (it == g.end())
      throw domain_error("Empty Rules.");
    cout << "type: " << it->first << endl;

    const Rule_collection& c = it->second;

    const Rule& r = c[nrand(c.size())];

    for (Rule::const_iterator iter = r.begin();
         iter != r.end();
         ++iter){
      cout << "rule's:" << *iter << endl;
      gen_aux(g, *iter, s_ret);
    }
  }
}

vector<string> gen_sentence(const Grammar& g){
  vector<string> ret;
  gen_aux(g, "<sentence>", ret);
  return ret;
}

int main (int argc, char** argv)
{
  vector<string> sentence = gen_sentence(read_grammar(cin));
  vector<string>::const_iterator it = sentence.begin();

  if (it != sentence.end()){
    cout << *it ;
    ++it;
  }

  while (it != sentence.end()){
    cout << " " << *it;
    ++it;
  }

  cout << endl;
  return 0;
}
