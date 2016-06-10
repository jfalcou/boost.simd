//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SATURATED_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SATURATED_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/decorator.hpp>
#include <boost/simd/detail/dispatch.hpp>
#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-decorator

   provides a saturated version of some functors which produce integral typed values on return.

    @par Semantic

    @code
    T r = saturated_(func)(< func parameters >);
    @endcode

    @see  decorator

  **/
  template<typename T> auto saturated_(T const& x) {}

} }
#endif

namespace boost { namespace simd
{
  struct saturated_tag : decorator_<saturated_tag>
  {
    using parent = decorator_<saturated_tag>;
  };

  const detail::decorator<saturated_tag> saturated_ = {};
} }

#endif
