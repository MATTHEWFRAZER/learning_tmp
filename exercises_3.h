#pragma once
#include<boost/mpl/transform.hpp>
#include<boost/mpl/placeholders.hpp>
#include<boost/mpl/plus.hpp>
#include<boost/mpl/int.hpp>
#include<boost/mpl/vector_c.hpp>

using namespace boost;
using namespace mpl;
using namespace placeholders;

struct ap
{
    template<class A1, long A2, long A3, long A4>
    struct apply
    {
       typedef vector_c<long, A2, A3, A4> type;
    };
};

struct uno
{
public:
    typename transform<vector_c<int, 1, 2, 3>, ap, plus<_1, _2> >::type type;
};
