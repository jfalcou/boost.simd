//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS
  Copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#define BOOST_SIMD_ENABLE_DIAG
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/false.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/if_one_else_zero.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>

template <typename T, int N, typename Env>
void test(Env& $)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(int i = 0; i < N; ++i)
  {
     a1[i] = (i%2) ? T(2) : T(0);
    b[i] = a1[i] ? bs::One<T>():bs::Zero<T>();
   }
  p_t aa1(&a1[0], &a1[N]);
  p_t bb(&b[0], &b[N]);
  STF_IEEE_EQUAL(bs::if_one_else_zero(aa1), bb);
}

STF_CASE_TPL("Check if_one_else_zero on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

template <typename T, int N, typename Env>
void testl(Env& $)
{
  namespace bs = boost::simd;
  using lT =  bs::logical<T>;
  using p_t = bs::pack<T, N>;
  using pl_t = bs::pack<lT, N>;

  lT a1[N];
  T  b[N];
  for(int i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? bs::True<lT>() : bs::False<lT>();
    b[i] = a1[i] ? bs::One<T>():bs::Zero<T>();
  }
  pl_t aa1(&a1[0], &a1[N]);
  p_t bb(&b[0], &b[N]);
  STF_IEEE_EQUAL(bs::if_one_else_zero(aa1), bb);
}

STF_CASE_TPL("Check if_one_else_zero on pack of logical" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  testl<T, N>($);
  testl<T, N/2>($);
  testl<T, N*2>($);
}
