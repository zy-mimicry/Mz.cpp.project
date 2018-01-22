#include "Vec.h"
//#include <iterator>
using namespace std;


//默认构造
template<class T>
Vec<T>::Vec(){ create();}

//其他需要明确指定的构造
template<class T>
Vec<T>::Vec(typename Vec<T>::size_type n, const T& t){}

//复制构造
template<class T>
Vec<T>::Vec(const Vec& v) {}

//析构
template<class T>
Vec<T>::~Vec(){
  uncreate();
}

//赋值操作
template<class T>
Vec<T>& Vec<T>::operator= (const Vec<T>& v){}

//索引操作
template<class T>
T& Vec<T>::operator[] (typename Vec<T>::size_type i){
  return data[i];
}

template<class T>
const T& Vec<T>::operator[] (typename Vec<T>::size_type i) const {
  return data[i];
}

//通用接口操作

template<class T>
typename Vec<T>::iterator Vec<T>::begin(){
  return data;
}

template<class T>
typename Vec<T>::const_iterator Vec<T>::begin() const {
  return data;
}

template<class T>
typename Vec<T>::iterator Vec<T>::end() {
  return avail;
}

template<class T>
typename Vec<T>::const_iterator Vec<T>::end() const {
  return avail;
}

template<class T>
typename Vec<T>::size_type Vec<T>::size() const {
  return avail-data;
}

template<class T>
void Vec<T>::push_back(T& t){
}


//内存操作函数
template<class T>
void Vec<T>::uncreate(){
  if (data){
    iterator it = avail;
    while (it != data)
      alloc.destory(--it); //看到这里的--it就是为了实现逆序删除元素.
    alloc.deallocate(data,limit-data);
  }
  data = limit = avail = 0;
}

template<class T>
void Vec<T>::grow(){
  size_type new_size = max(ptrdiff_t(1), 2*(limit-data));
  iterator new_data = alloc.allocate(new_size);
  iterator new_avail = uninitialized_copy(data,limit,new_data); //这里的返回值?
  uncreate();
  data = new_data;
  avail = new_avail;
  limit = new_data + new_size;
}

template<class T>
void Vec<T>::unchecked_append(const T& val){
  alloc.construct(avail++, val);
}

//重载 create函数
template<class T>
void Vec<T>::create(){
  return data = avail = limit = 0;
}

template<class T>
void Vec<T>::create(typename Vec<T>::size_type n, const T& val){ //这里的typename可以不用
  data = alloc.allocate(n);
  avail = limit = data + n;
  uninitialized_fill(data, avail, val);
}

template<class T>
void Vec<T>::create(Vec::const_iterator i, Vec::const_iterator j){
  data = alloc.allocate(j - i);
  uninitialized_copy(i, j, data);
}
