#pragma once
#include<boost/mpl/transform.hpp>
#include<boost/mpl/placeholders.hpp>
#include<boost/mpl/plus.hpp>
#include<boost/mpl/int.hpp>
#include "exercises_3.h"

using namespace boost;
using namespace mpl;
using namespace placeholders;


template<long A1, long A2, long A3>
struct answer
{
public:
  long val_1 = A1;
  long val_2 = A2;
  long val_3 = A3;
};

struct final_answer
{
public:
  typedef typename transform<uno::type, answer, plus<_1, _2> >::type type;
};
