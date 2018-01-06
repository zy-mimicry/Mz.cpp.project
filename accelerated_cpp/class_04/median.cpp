#include "median.h"
#include <stdexcept>

using std::domain_error;

double median(std::vector<double>& h){
  typedef std::vector<double>::size_type vec_size;
  vec_size size = h.size();

  if (size == 0)
    throw domain_error("Homework shouldn't be null.");

  return size % 2 == 0
    ? (h[size/2] + h[size/2 - 1])/2
    : (h[size/2]);
}
