#pragma once

#include <boost/mpl/equal.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/vector.hpp>
//apply: F(a -> b) -> F(a) -> F(b)

using namespace boost;
using namespace mpl;

struct functor
{
  template<class X>
  struct apply
  {
    typedef X type;
  };
};

struct end_sentinal2
{};

// counter
template <typename A1, typename... Args>
struct counter
{
    static const int count = 1 + counter<Args...>::count;
};

template <>
struct counter<end_sentinal2>
{
   static const int count = 0;
};


template<typename F, typename FAFB, typename FA>
struct applicative_apply
{
  typename FAFB::template apply<FA>::type type;
};

template<typename F, typename A>
struct pure
{
  typename F::template apply<A>::type type;
};

struct false_type_failed{};

template<bool init_is_empty, bool tail_is_empty, typename AGG, typename Start, typename Head, typename... Tail>
struct reduce_inner
{
   typename reduce_inner<init_is_empty, tail_is_empty, AGG, Start, Head, Tail... >::type type;
};

template<bool tail_is_empty, typename AGG, typename Start, typename Head, typename... Tail>
struct reduce_inner<true, tail_is_empty, AGG, Start, Head, Tail... >
{
   false_type_failed type;
};

template<typename AGG, typename Start, typename Head, typename... Tail>
struct reduce_inner<false, false, AGG, Start, Head, Tail... >
{
private:
    static const bool tail_is_empty = empty<vector<Tail... > >::value;
public:
    typename reduce_inner<false, tail_is_empty, AGG, typename AGG::template apply<Start, Head>, Tail... >::type type;
};

template<typename AGG, typename Start, typename Head, typename... Tail>
struct reduce_inner<false, true, AGG, Start, Head, Tail... >
{
    typename AGG::template apply<Start, Head>::type type;
};

template<typename AGG, typename Start, typename... Args>
struct reduce
{
private:
    static const bool args_is_empty = empty<vector<Args... > >::value;
public:
    typedef typename reduce_inner<args_is_empty, false, AGG, Start, Args... >::type type;
};


struct vec_test
{
  template<typename X, typename Y>
  struct apply
  {
     typename push_back<X, Y>::type type;
  };
};

template<typename A>
struct F
{
  typedef A type;
};

struct A1{};

struct AGG
{
    template<typename A, typename B, typename C>
    struct apply
    {
      typename A a;
      typename B b;
      typename C c;
    };
};

struct answer_app : reduce< applicative_apply<_1,_2> ,, pure<F, AGG> >
{};
