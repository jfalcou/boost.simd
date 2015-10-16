//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEGATE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEGATE_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/function/scalar/is_nez.hpp>
#include <boost/simd/function/scalar/sign.hpp>
#include <boost/dispatch/function/overload.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( negate_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::signed_<A0> >
                          , bd::scalar_< bd::signed_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return a0*sign(a1);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( negate_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::unsigned_<A0> >
                          , bd::scalar_< bd::unsigned_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return bool(is_nez(a1))*a0;
    }
  };
} } }


#endif
