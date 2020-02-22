#include <iostream>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/is_same.hpp>
#include "test_driver_exercises_2.h"
#include "head.hpp"
#include "tail.hpp"
#include "sfinae.h"
//#include "crtp.h"
#include "is_p.h"
#include "exercises_6.h"

//#include "applicative.h"
//#include "test_driver_exercises_3.h"
//#include "test_driver_place_holders.h"

using namespace std;
using namespace boost;
using namespace mpl;
using namespace placeholders;

template<class X, class Y>
struct metafunc
{
  typedef X type_x;
  typedef Y type_y;
};

#define EXPANDO metafunc<int, int>, metafunc<char, char>, metafunc<long, long>
typedef tail<int, char, long>::apply::type ttail;
bool s = boost::is_same<long, ttail>::value;

struct X
{
  typedef int N;
};

template < int x >
struct my_int
{
  static const int value = x;
};

typedef mpl::vector<int, char, long> sequence;
typedef smallest< sequence >::type a_type;
static const bool is_char = boost::is_same<a_type , char>::value;

typedef tree<my_int<7>, terminal_child, terminal_child> test_tree;
typedef insert_into_tree<test_tree,   my_int<3> >::type insert_1;
typedef insert_into_tree<insert_1, my_int<5> >::type insert_2;
typedef insert_into_tree<insert_2, my_int<6> >::type insert_3;
typedef insert_into_tree<insert_3, my_int<1> >:: type insert_4;
typedef insert_into_tree<insert_4, my_int<11> >:: type insert_5;
typedef insert_into_tree<insert_5, my_int<2> >:: type insert_6;

//typedef reduce<vec_test, vector<metafunc<int, int> >, metafunc<char, char>, metafunc<long, long> >::type local_testing;
//int equalz = mpl::equal<local_testing, vector<EXPANDO> >;

//typedef vector<int, char, long> vec;
//typedef transform<vec, vec, metafunc<_1, _2> >::type result;
//int is_equal = mpl::equal<result, vector<EXPANDO > >::value;

int main( int argc, const char* argv[] )
{
  //A a;
  //B b;
  cout << s << endl;
  answer_getter<int&> t1;
  answer_getter<int> t2;
  cout << "ref: " << t1.value << endl;
  cout << "non ref: " << t2.value << endl;
  sfinae<int>(0);
  sfinae<X>(9);
  insert_6 inserted_6;
  //  in_order_traversal(inserted_6);
  //cout << " " << x << endl;
  //test_driver_place_holders tdh;
  //cout << "place holder test: "<< tdh.final_answer << endl;
  //cout << r::value << endl;
  //final_answer fa;
  //cout << fa.type.val_1 << endl;
  //cout << fa.type.val_2 << endl;
  //cout << fa.type.val_3 << endl;
  //cout << is_equal << endl;
  //cout << equalz << endl;
  //int x = 9;
  //cout << a.predicate(a) << endl;
  //cout << b.predicate(true) << endl;
  cout << is_p<int*>::value << endl;
  cout << is_p<int>::value <<endl;
  cout << is_char << endl;
}
