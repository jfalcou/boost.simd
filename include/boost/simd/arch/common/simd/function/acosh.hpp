//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ACOSH_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ACOSH_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/meta/as_logical.hpp>
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/constant/oneotwoeps.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_greater.hpp>
#include <boost/simd/function/simd/log1p.hpp>
#include <boost/simd/function/simd/minusone.hpp>
#include <boost/simd/function/simd/plus.hpp>
#include <boost/simd/function/simd/seladd.hpp>
#include <boost/simd/function/simd/sqr.hpp>
#include <boost/simd/function/simd/sqrt.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( acosh_
                          , (typename A0, typename X)
                          , bs::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        using bA0 =  bs::as_logical_t<A0>;
        A0 t = minusone(a0);
        bA0 test = gt(t,Oneotwoeps<A0>());
        A0 z = if_else(test, a0, t+sqrt(t+t+sqr(t)));
        return seladd(test, log1p(z), Log_2<A0>());
      }
   };

} } }

#endif
