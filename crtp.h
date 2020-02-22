#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_same.hpp>

struct A;

template<typename T>
bool _predicate(T x)
{
  return x.value == 4;
}

template<bool>
bool _predicate(bool x)
{
  return x;
}

template <typename T>
struct TestCRTP
{
  static const bool value = boost::is_same<A,T>::value;
  typedef typename if_c<value,bool,A&>::type type;
public:
   bool predicate(type x)
   {
     return _predicate<type>(x);
   }
};

struct A : TestCRTP<A>
{
  int value = 4;
};

struct B : TestCRTP<B>
{
};
