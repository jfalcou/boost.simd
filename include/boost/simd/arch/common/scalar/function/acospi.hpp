//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ACOSPI_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_ACOSPI_HPP_INCLUDED

#include <boost/simd/constant/invpi.hpp>
#include <boost/simd/function/acos.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( acospi_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0) const BOOST_NOEXCEPT
    {
      return Invpi<A0>()*acos(a0);
    }
  };
  BOOST_DISPATCH_OVERLOAD ( acospi_
                          , (typename A0)
                          , bd::cpu_
                          , bs::accurate_tag
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() (const accurate_tag &,  A0 a0) const BOOST_NOEXCEPT
    {
      return Invpi<A0>()*bs::accurate_(acos)(a0);
    }
  };
} } }


#endif