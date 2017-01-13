//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/slice_high.hpp>
#include <boost/simd/logical.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bm = boost::nsm;

template<typename T, std::size_t N, typename Env>
void test( Env&, bm::bool_<false> const& )
{}

template<typename T, std::size_t N, typename Env>
void test( Env& $, bm::bool_<true> const& = {} )
{
  std::array<bs::logical<T>,N> ref;
  for(std::size_t i=0;i<N;++i) ref[i] = (i%3) ? true : false;

  bs::pack<bs::logical<T>,N>   value (&ref[0]  , &ref[0]+N   );
  bs::pack<bs::logical<T>,N/2> second(&ref[0]+N/2, &ref[0]+N );

  STF_EQUAL( bs::slice_high(value), second);
}

STF_CASE_TPL("slice_high pack<T,N> into a pack<T,N/2>", STF_NUMERIC_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;

  test<T,N>($);
  test<T,N/2>($, bm::bool_<(N/2 > 1)>{});
  test<T,N*2>($);
}
