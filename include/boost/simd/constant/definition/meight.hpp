//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MEIGHT_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MEIGHT_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct meight_ : boost::dispatch::constant_value_<meight_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,meight_,boost::dispatch::constant_value_<meight_>);
      BOOST_SIMD_REGISTER_CONSTANT(-8, 0xc1000000UL,0xc020000000000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,meight_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::meight_,meight);
  }

  template<typename T> BOOST_FORCEINLINE auto Meight() BOOST_NOEXCEPT
  -> decltype(functional::meight( boost::dispatch::as_<T>{}))
  {
    return functional::meight( boost::dispatch::as_<T>{} );
  }
} }

#endif
