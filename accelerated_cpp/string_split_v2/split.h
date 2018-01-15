#ifndef MIMICRY_SPLIT_H
#define MIMICRY_SPLIT_H

#include <vector>
#include <string>

bool not_space(char c);
bool space(char c);
std::vector<std::string> split(std::string& s);
std::vector<std::string> split_v2(std::string& s);

#endif
