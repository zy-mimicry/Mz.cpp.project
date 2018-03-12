#ifndef MM_Student_info_h
#define MM_Student_info_h

#include <memory>
#include <cstddef>
#include <string>

template <class T>
class Vec {
public:
  //统一别名.
  typedef T* iterator;
  typedef const T* const_iterator;
  typedef size_t size_type;
  typedef T value_type;

  //默认构造,加上三位一体
  Vec();
  // Vec(){create();}
  explicit Vec(size_type n, const T& = T());
  Vec(const Vec&);
  ~Vec();
  Vec& operator= (const Vec&); // 这个返回值可以没有的,但是为了统一可以加上.

  //索引操作.
  T& operator[] (size_type i);
  const T& operator[] (size_type i) const;

  //通用接口
  iterator begin();
  const_iterator begin () const;
  iterator end();
  const_iterator end () const;
  size_type size  () const;
  void push_back(T&);


private:
  //容器中的迭代器
  iterator data;
  iterator avail;
  iterator limit;

  std::allocator<T> alloc;

  void create();
  void create(size_type , const T&);
  void create(const_iterator, const_iterator);

  void uncreate();

  void grow();
  void unchecked_append(const T&);

};

#endif
