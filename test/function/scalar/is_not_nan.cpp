//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/is_not_nan.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/half.hpp>
#include <boost/simd/constant/quarter.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/logical.hpp>

STF_CASE_TPL (" is_not_nan  _real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_not_nan;
  using r_t = decltype(is_not_nan(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(is_not_nan(bs::Inf<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::Minf<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::Nan<T>()), r_t(false));
#endif
  STF_EQUAL(is_not_nan(bs::Mzero<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::Half<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::Mone<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::One<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::Quarter<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::Two<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::Zero<T>()), r_t(true));
}

STF_CASE_TPL (" is_not_nan _signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_not_nan;
   using r_t = decltype(is_not_nan(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_not_nan(bs::Mone<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::One<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::Two<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::Zero<T>()), r_t(true));
}

STF_CASE_TPL (" is_not_nan _unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_not_nan;
  using r_t = decltype(is_not_nan(T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bs::logical<T>);

  // specific values tests
  STF_EQUAL(is_not_nan(bs::One<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::Two<T>()), r_t(true));
  STF_EQUAL(is_not_nan(bs::Zero<T>()), r_t(true));
}

STF_CASE ( "is_not_nan _bool")
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::is_not_nan;
  using r_t = decltype(is_not_nan(bool()));

  // return type conformity test
  STF_TYPE_IS(r_t, bool);

  // specific values tests
  STF_EQUAL(is_not_nan(true), true);
  STF_EQUAL(is_not_nan(false), true);
}
