#include <iostream>
#include <stdexcept>

using namespace std;

int main(){
  string name("hello");
  try{
    throw domain_error("??? are you kinding me?");
  }catch(domain_error e){
    cout << e.what() << endl;
    return 1;
  }
  return 0;
}
