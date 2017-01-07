//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-arithmetic
    This function object returns the inverse (reciprocal) of the entry.

    @par Notes

    The call to `rec(x)` is similar to  `One(as(x))/x`

    For integral typed entries the result is always in the set \f$\{0,  \pm1, Valmax \}\f$

    @par Decorators

     - raw_ Many simd architectures provide an intrinsic that computes some bits of the inverse (at least 12)
            and don't care of denormals or limiting values. If it exists this is obtained by the raw_ decorator.
            As usual if it doesn't the plain rec is called.
  **/
  Value rec(Value const & v0);
} }
#endif

#include <boost/simd/function/scalar/rec.hpp>
#include <boost/simd/function/simd/rec.hpp>

#endif
