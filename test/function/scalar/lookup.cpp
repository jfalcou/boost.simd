//==================================================================================================
/*!

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/lookup.hpp>
#include <stf.hpp>
#include <boost/dispatch/meta/as_integer.hpp>


STF_CASE_TPL( "Check extract behavior with all types", STF_NUMERIC_TYPES )
{
  namespace bs = boost::simd;
  using bs::lookup;
  STF_EXPR_IS(lookup(T(1), 0), T);

  STF_EQUAL(lookup(T(1), 0),  T(1));
}

