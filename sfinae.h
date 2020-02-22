#include<stdio.h>

using namespace std;

template<class T>
int sfinae(typename T::N n)
{
  cout <<" thiss" << endl;
}

template<class T>
int sfinae(T t)
{
  cout <<"that" <<endl;
}
