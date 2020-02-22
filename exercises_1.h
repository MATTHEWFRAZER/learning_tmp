#pragma once

template <class T, bool magnitude>
struct test
{
public:
  typedef T* type;
  static const int value;
};

template <class T>
struct test<T, true>
{
public:
  static const int value = 5;
};

template <class T>
struct test<T, false>
{
public:
  static const int value = 15;
};

class test2
{
public:
  template <template<class T, bool magnitude> class U>
  int give_me(){
       return U<int, false>::value;
  }
};
