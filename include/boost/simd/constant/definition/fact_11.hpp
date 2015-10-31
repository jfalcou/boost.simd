//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_FACT_11_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_FACT_11_HPP_INCLUDED

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
    struct fact_11_ : boost::dispatch::constant_value_<fact_11_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,fact_11_,boost::dispatch::constant_value_<fact_11_>);
      BOOST_SIMD_REGISTER_CONSTANT(39916800,0x4c184540U,0x418308a800000000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,fact_11_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::fact_11_,fact_11);
  }

  template<typename T> BOOST_FORCEINLINE auto Fact_11() BOOST_NOEXCEPT
  -> decltype(functional::fact_11( boost::dispatch::as_<T>{}))
  {
    return functional::fact_11( boost::dispatch::as_<T>{} );
  }
} }

#endif
