#include <iostream>
#include <string>
#include "split.h"
#include "frame.h"

using namespace std;

int main (int argc, char** argv){
  vector<string> frame_one, frame_two;
  vector<string> new_frame;
  vector<string> temp_frame;
  string in_string;
  double flag = 0;

  while (flag != 2 &&
         ( cout << "What's your frame?" << endl,
           getline(cin, in_string) )){
    //temp_frame = split(in_string);
    temp_frame = split_v2(in_string);
    vector<string>::size_type i = 0;
    if (flag == 0){
      frame_one = frame(temp_frame);
    }else{
      frame_two = frame(temp_frame);
    }
    flag++;
  }

  cout << "\nThe first picture:" << endl;
  display(frame_one);
  cout << "\nThe second picture:" << endl;
  display(frame_two);

  cout << "\nHcat picture:" << endl;
  new_frame = hcat(frame_one, frame_two);
  display(new_frame);

  cout << "\nVcat picture:" << endl;
  new_frame = vcat(frame_one, frame_two);
  display(new_frame);

  return 0;
}
