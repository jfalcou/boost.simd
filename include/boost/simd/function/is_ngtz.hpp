//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NGTZ_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NGTZ_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True if x is not greater than zero else returns False.

    @par Semantic:

    @code
    as_logical_t<T> r = is_ngtz(x);
    @endcode

    is similar to:

    @code
    as_logical_t<T> r = !(x > 0);
    @endcode

    @par Note:

    Due to existence of nan, this is not equivalent to @c is_lez(x)
    for floating types


    @return a logical value

**/
  template<typename T> auto is_ngtz(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True if x is not greater than zero else returns False.


      Function object tied to simd::is_ngt

z      @see simd::is_ngt
z    **/
    const boost::dispatch::functor<tag::is_ngtz_> is_ngtz = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_ngtz.hpp>
#include <boost/simd/arch/common/scalar/function/is_ngtz.hpp>
//#include <boost/simd/arch/common/function/simd/is_ngtz.hpp>

#endif
