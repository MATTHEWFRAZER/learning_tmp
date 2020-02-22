template<int x>
struct x_int
{
  static const int value = x;
};

template<typename T, typename I>
struct is_p_inner
{
  static const bool value = I::value != 0;
};

template<typename T, typename I>
struct is_p_inner<T*,  I>
{
    static const bool value = is_p_inner<T,x_int<I::value + 1> >::value;
};

template<typename T>
struct is_p : is_p_inner<T, x_int<0> >
{

};
