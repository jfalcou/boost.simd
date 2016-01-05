//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEFINITION_COMPARE_GE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEFINITION_COMPARE_GE_HPP_INCLUDED

#include <boost/simd/function/definition/compare_greater_equal.hpp>
#include <boost/simd/detail/dispatch.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    using compare_ge_ = compare_greater_equal_;
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::compare_ge_,compare_ge);
  }
  BOOST_DISPATCH_FUNCTION_DEFINITION(tag::compare_ge_,compare_ge);
} }

#endif
