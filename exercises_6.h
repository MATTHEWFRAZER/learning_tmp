#include <boost/mpl/copy.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/size.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_same.hpp>

using namespace boost;
using namespace mpl;
using namespace placeholders;

//################################################################################
//Question 1
//################################################################################
#define IS_SIZE_ZERO size<Sequence>::value == 0
#define IS_SIZE_ONE_OR_ZERO size<Sequence>::value == 1 || IS_SIZE_ZERO

struct return_smaller
{
  template<typename A1, typename A2>
  struct apply : if_c<sizeof(A1) <= sizeof(A2), A1, A2>
  {};
};

template<typename State, typename Operator>
struct my_inserter
{
    typedef State state;
    typedef Operator _operator;
};

template<bool has_one, typename Inserter, typename Sequence>
struct smallest_inner
{};

template<typename Inserter, typename Sequence>
struct smallest_inner<false, Inserter, Sequence>
{
private:
  typedef typename at_c<Sequence, 0>::type type_at;
  typedef typename Inserter::_operator::template apply<typename Inserter::state, type_at>::type result;
  typedef my_inserter<result, typename Inserter::_operator > new_inserter;
  typedef typename pop_front<Sequence>::type new_sequence;
public:
  typedef typename smallest_inner< IS_SIZE_ONE_OR_ZERO, new_inserter, new_sequence>::type type;
};

template<typename Inserter, typename Sequence>
struct smallest_inner<true, Inserter, Sequence>
{
private:
  typedef typename at_c<Sequence, 0>::type type_at;
public:
  typedef typename Inserter::_operator::template apply<typename Inserter::state, type_at>::type type;
};


template<typename Sequence>
struct smallest
{
private:
  typedef typename at_c<Sequence, 0>::type start;
  typedef my_inserter<start, return_smaller > inserter;
public:
  //BOOST_STATIC_ASSERT(!IS_SIZE_ZERO);
  typedef typename smallest_inner<IS_SIZE_ONE_OR_ZERO, inserter, Sequence>::type type;
};

//################################################################################
//Question 3
//################################################################################
struct terminal_child
{};

template<typename Root, typename Left, typename Right>
struct tree
{
    typedef Root root;
    typedef Left left;
    typedef Right right;
};

template<typename A1, typename A2>
struct insert_into_tree
{
private:
    static const bool root_is_defined = !boost::is_same<typename A1::root, terminal_child>::value;
    static const bool insert_right = root_is_defined && A1::root::value >= A2::value;
    typedef typename if_c<insert_right, tree<typename A1::root, typename A1::left, insert_into_tree<typename A1::right, A2> >,
                          tree<typename A1::root, insert_into_tree<typename A1::left, A2>, typename A1::right> >::type prototype;
public:
    typedef typename if_c<root_is_defined, prototype, tree<A2, terminal_child, terminal_child> >::type type;
};

template<typename A2>
struct insert_into_tree<terminal_child, A2>
{
  typedef A2 type;
};

template<typename State, typename Operator>
struct tree_inserter
{
    typedef State state;
    typedef Operator _operator;
};

/*template<typename Tree>
void in_order_traversal(Tree tree)
{
  if (!is_same<tree::right, terminal_child>::value)
  {
      in_order_traversal(tree::right);
  }
  cout << tree::root::value << endl;
  if(!is_same<tree::left, terminal_child>::value)
  {
     in_order_traversal(tree::left);
  }
}
*/
