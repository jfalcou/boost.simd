//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_AVERAGE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_AVERAGE_HPP_INCLUDED

#include <boost/simd/constant/half.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( average_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          , bd::generic_< bd::arithmetic_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
    {
      return bitwise_and(a0, a1)+shift_right(bitwise_xor(a0, a1),1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( average_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
    {
      return fma(a0,Half<A0>(),a1*Half<A0>());
    }
  };
} } }


#endif
