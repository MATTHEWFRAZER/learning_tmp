#include <boost/mpl/vector.hpp>

using namespace boost;
using namespace mpl;

template<typename A0, typename... Args>
struct head
{
  typename vector<A0>::type type;
};
