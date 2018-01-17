#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main (int argc, char** argv){

  map<string, int> temp;
  string world;

  while (cin >> world)
    temp[world]++;

  for (map<string, int>::iterator it = temp.begin();
       it != temp.end();
       ++it)
    cout << setw(10) << it->first << "\t:" << it->second << endl;
  return 0;
}
