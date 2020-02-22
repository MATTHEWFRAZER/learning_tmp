#pragma once
#include<boost/type_traits/is_reference.hpp>
#include "exercises_2.h"

using namespace boost;

template<class T>
struct answer_getter
{
public:
  bool const value = is_reference<T>::value;
};
