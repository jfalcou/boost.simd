//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/cumsum.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>

STF_CASE_TPL (" cumsum real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;

  using bs::cumsum;

  // return type conformity test
  STF_EXPR_IS(cumsum(T()), T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(cumsum(bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(cumsum(bs::Minf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(cumsum(bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(cumsum(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(cumsum(bs::One<T>()), bs::One<T>());
  STF_EQUAL(cumsum(bs::Zero<T>()), bs::Zero<T>());
} // end of test for floating_

STF_CASE_TPL (" cumsum unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::cumsum;
  // return type conformity test
  STF_EXPR_IS(cumsum(T()), T);


  // specific values tests
  STF_EQUAL(cumsum(bs::One<T>()), bs::One<T>());
  STF_EQUAL(cumsum(bs::Zero<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" cumsum signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;

  using bs::cumsum;

  // return type conformity test
  STF_EXPR_IS(cumsum(T()), T);

  // specific values tests
  STF_EQUAL(cumsum(bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(cumsum(bs::One<T>()), bs::One<T>());
  STF_EQUAL(cumsum(bs::Zero<T>()), bs::Zero<T>());
} // end of test for signed_int_



