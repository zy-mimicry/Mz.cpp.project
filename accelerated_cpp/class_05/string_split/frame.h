#ifndef MM_frame_h
#define MM_frame_h

#include <vector>
#include <string>

void display(std::vector<std::string>& s);
std::vector<std::string> vcat(std::vector<std::string>& left, std::vector<std::string>& right);
std::vector<std::string> hcat(std::vector<std::string>& top, std::vector<std::string>& bottom);
std::vector<std::string> frame(std::vector<std::string>& s);
std::string::size_type width(std::vector<std::string>& s);

#endif
