//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/six.hpp>
#include <boost/simd/as.hpp>
#include <simd_test.hpp>

STF_CASE_TPL( "Check six behavior for integral types"
            , (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
              (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
              (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::six;
  using boost::simd::Six;

  STF_TYPE_IS(decltype(Six<T>()), T);
  STF_EQUAL(Six<T>(), T(6));
  STF_EQUAL(six( as(T{}) ),T(6));
}

