//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_TWOTOMNMBO_3_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_TWOTOMNMBO_3_HPP_INCLUDED

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
    struct twotomnmbo_3_ : boost::dispatch::constant_value_<twotomnmbo_3_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,twotomnmbo_3_,boost::dispatch::constant_value_<twotomnmbo_3_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x3ba14518LL, 0x3ed428a2f98d7286ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,twotomnmbo_3_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::twotomnmbo_3_,twotomnmbo_3);
  }

  template<typename T> BOOST_FORCEINLINE auto Twotomnmbo_3() BOOST_NOEXCEPT
  -> decltype(functional::twotomnmbo_3( boost::dispatch::as_<T>{}))
  {
    return functional::twotomnmbo_3( boost::dispatch::as_<T>{} );
  }
} }

#endif
