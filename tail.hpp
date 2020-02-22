#include <boost/mpl/vector.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/vector.hpp>

using namespace boost;
using namespace mpl;

template<typename... Args>
struct tail;

struct end_sentinal
{};

template<typename A0, typename... Args>
struct tail_impl : tail_impl<Args...>
{

};

template<typename A0>
struct tail_impl<A0, end_sentinal>
{
  typedef A0 type;
};



template<typename... Args>
struct tail
{
    //BOOST_STATIC_ASSERT_MSG(empty<vector<Args...>>::value, "Can not take tail of empty arguments");
    struct apply : tail_impl<Args..., end_sentinal>
    {
    };
};
