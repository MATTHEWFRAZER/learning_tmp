#pragma once
#include<boost/mpl/plus.hpp>
#include<boost/mpl/placeholders.hpp>

using namespace boost;

template <class F, class A>
struct apply_on_arbitrary_args
{
    typedef typename F::template apply<A, mpl::_1, mpl::_2>::type type;
};

struct trinary
{
    template <class A1, class A2, class A3>
    struct apply
    {
        typename mpl::plus<typename mpl::plus<A1, A2>::type, A3>::type type;
    };
};
