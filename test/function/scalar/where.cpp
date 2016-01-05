//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/where.hpp>
#include <simd_test.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
// #include <boost/simd/constant/true.hpp>
// #include <boost/simd/constant/false.hpp>
//TODO LOGICAL

STF_CASE_TPL (" where integer",  STF_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::where;
  using bs::logical;
  using r_t = decltype(where(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(where( bs::One<T>(), bs::One<T>(), bs::One<T>()), bs::One<r_t>());
  STF_EQUAL(where( bs::One<T>(), bs::Zero<T>(),bs::Two<T>()), bs::Zero<r_t>());
  STF_EQUAL(where( bs::Zero<T>(), bs::One<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for integer_

STF_CASE_TPL (" where real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::where;

  using bs::logical;
  using r_t = decltype(where(T(),T(),T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef STF_NO_INVALIDS
  STF_IEEE_EQUAL(where( bs::One<T>(), bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
#endif
  STF_EQUAL(where( bs::One<T>(),bs::Zero<T>(),bs::Two<T>()), bs::Zero<r_t>());
  STF_EQUAL(where( bs::Zero<T>(), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
} // end of test for floating_


// STF_CASE_TPL (" where integer",  STF_INTEGRAL_TYPES)
// {
//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;
//   using bs::where;
//   using bs::logical;
//   using r_t = decltype(where(logical<T>(),T(),T()));

//   // return type conformity test
//   STF_TYPE_IS(r_t, T);

//   // specific values tests
//   STF_EQUAL(where( bs::True< logical<T> >(), bs::One<T>(), bs::One<T>()), bs::One<r_t>());
//   STF_EQUAL(where( bs::True< logical<T> >(), bs::Zero<T>(),bs::Two<T>()), bs::Zero<r_t>());
//   STF_EQUAL(where( bs::False< logical<T> >(), bs::One<T>(), bs::Zero<T>()), bs::Zero<r_t>());
// } // end of test for integer_

// STF_CASE_TPL (" where real",  STF_IEEE_TYPES)
// {
//   namespace bs = boost::simd;
//   namespace bd = boost::dispatch;

//   using bs::where;

//   using bs::logical;
//   using r_t = decltype(where(logical<T>(),T(),T()));

//   // return type conformity test
//   STF_TYPE_IS(r_t, T);

//   // specific values tests
// #ifndef STF_NO_INVALIDS
//   STF_EQUAL(where( bs::True< logical<T> >(), bs::Nan<T>(), bs::Nan<T>()), bs::Nan<r_t>());
// #endif
//   STF_EQUAL(where( bs::True< logical<T> >(),bs::Zero<T>(),bs::Two<T>()), bs::Zero<r_t>());
//   STF_EQUAL(where( bs::False< logical<T> >(), bs::Zero<T>(), bs::Zero<T>()), bs::Zero<r_t>());
// } // end of test for floating_
