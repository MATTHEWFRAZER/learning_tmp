#pragma once
#include<boost/mpl/placeholders.hpp>
#include<boost/mpl/int.hpp>
#include "place_holders.h"

using namespace boost;

struct test_driver_place_holders
{
    typename  apply_on_arbitrary_args<trinary, typename mpl::int_<1>::type>::type type;
    typename type::apply<typename mpl::int_<2>::type>::type type2;
    int final_answer = type2::apply<typename mpl::int_<3>::type>::type::value;
};
