//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/idivceil.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/mzero.hpp>

STF_CASE_TPL (" idivceil real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::idivceil;
  using r_t = decltype(idivceil(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_EQUAL(idivceil(bs::Inf<T>(), bs::Inf<T>()), bs::Zero<r_t>());
  STF_EQUAL(idivceil(bs::Minf<T>(), bs::Minf<T>()), bs::Zero<r_t>());
  STF_IEEE_EQUAL(idivceil(bs::Nan<T>(), bs::Nan<T>()), bs::Zero<r_t>());
#endif
 STF_EQUAL(idivceil(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(idivceil(bs::Mone<T>(),bs::Zero<T>()), bs::Minf<r_t>());
  STF_EQUAL(idivceil(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(idivceil(bs::One<T>(),bs::Zero<T>()), bs::Valmax<r_t>());
  STF_EQUAL(idivceil(bs::One<T>(),bs::Mzero<T>()), bs::Valmin<r_t>());
  STF_EQUAL(idivceil(bs::Zero<T>(),bs::Zero<T>()), bs::Zero<r_t>());
  STF_EQUAL(idivceil(T(4),T(3)), r_t(2));
  STF_EQUAL(idivceil(T(-4),T(-3)), r_t(2));
  STF_EQUAL(idivceil(T(-4),T(3)), r_t(-1));
  STF_EQUAL(idivceil(T(4),T(-3)), r_t(-1));
} // end of test for floating_

STF_CASE_TPL (" idivceil unsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::idivceil;
  using r_t = decltype(idivceil(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<T, unsigned>));

  // specific values tests
  STF_EQUAL(idivceil(T(4),T(3)), T(2));
  STF_EQUAL(idivceil(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(idivceil(bs::One<T>(), bs::Zero<T>()), bs::Valmax<r_t>());
} // end of test for unsigned_int_

STF_CASE_TPL (" idivceil signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::idivceil;

  using r_t = decltype(idivceil(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, bd::as_integer_t<T>);

  // specific values tests
  STF_EQUAL(idivceil(T(4),T(3)), r_t(2));
  STF_EQUAL(idivceil(T(-4),T(-3)), r_t(2));
  STF_EQUAL(idivceil(T(-4),T(3)), r_t(-1));
  STF_EQUAL(idivceil(T(4),T(-3)), r_t(-1));
  STF_EQUAL(idivceil(bs::Mone<T>(), bs::Mone<T>()), bs::One<r_t>());
  STF_EQUAL(idivceil(bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(idivceil(bs::One<T>(), bs::Zero<T>()), bs::Valmax<r_t>());
  STF_EQUAL(idivceil(bs::Mone<T>(), bs::Zero<T>()), bs::Valmin<r_t>());
} // end of test for signed_int_


