//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INEARBYINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_INEARBYINT_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/is_greater.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/splat.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/simd/is_nan.hpp>
#include <boost/simd/function/simd/if_zero_else.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD_IF(inearbyint_
                          , (typename A0, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::single_<A0>, X>
                          )
   {
      using result = bd::as_integer_t<A0>;
      BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        using sr_t = bd::scalar_of_t<result>;
        static const A0 Vax =  splat<A0>(bs::Valmax<sr_t>());
        static const A0 Vix =  splat<A0>(bs::Valmin<sr_t>());
      #ifndef BOOST_SIMD_NO_NANS
        A0 aa0 = if_zero_else(is_nan(a0), a0);
        return if_else(bs::is_less(aa0, Vix), Valmin<result>(),
                       if_else(bs::is_greater(aa0, Vax), Valmax<result>(),
                               bs::fast_(inearbyint)(aa0)
                              )
                      );
      #else
        return if_else(bs::is_less(a0, Vix), Valmin<result>(),
                       if_else(bs::is_greater(a0, Vax), Valmax<result>(),
                               bs::fast_(inearbyint(a0))
                              )
                      );
      #endif
      }
   };

} } }


#endif

