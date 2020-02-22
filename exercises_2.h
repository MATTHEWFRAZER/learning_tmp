#pragma once

#include<boost/type_traits/is_reference.hpp>
#include<boost/type_traits/add_const.hpp>
#include<boost/type_traits/add_pointer.hpp>

using namespace boost;

template<class T, bool b>
struct add_const_ref_inner
{
};

template<class T>
struct add_const_ref_inner<T, true>
{
  T type;
};

template<class T>
struct add_const_ref_inner<T, false>
{
  typename add_pointer<add_const<T> >::type type;
};


template<class T>
struct add_const_ref
{
  typename add_const_ref_inner<T, is_reference<T>::value >::type type;
};
