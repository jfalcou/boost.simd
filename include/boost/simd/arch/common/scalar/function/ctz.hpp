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
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CTZ_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_CTZ_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/scalar/bitwise_cast.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <iostream>
#ifndef __GNUC__
#include <boost/simd/function/scalar/ffs.hpp>
#endif

#ifdef BOOST_MSVC
#include <intrin.h>
#endif
namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( ctz_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::type64_<A0> >
                          )
  {
    using result_t = bd::as_integer_t<A0>;
    BOOST_FORCEINLINE result_t operator() ( A0 a0) const
    {
      result_t that = bitwise_cast<result_t>(a0);
      BOOST_ASSERT_MSG( that, "ctz not defined for 0" );

    #if defined __GNUC__
      return __builtin_ctzll(that);
    #else
      return ffs(that)-1;
    #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( ctz_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::type32_<A0> >
                          )
  {
    using result_t = bd::as_integer_t<A0>;
    BOOST_FORCEINLINE result_t operator() ( A0 a0) const
    {
      result_t that = bitwise_cast<result_t>(a0);
      BOOST_ASSERT_MSG( that, "ctz not defined for 0" );

    #if defined __GNUC__
      return __builtin_ctz(that);
    #else
      return ffs(that)-1;
    #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( ctz_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::arithmetic_<A0> >
                          )
  {
    BOOST_FORCEINLINE bd::as_integer_t<A0> operator() ( A0 a0) const
    {
      return ctz(uint32_t(a0));
    }
  };
} } }


#endif
