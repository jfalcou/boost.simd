// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------
#define BOOST_SIMD_NO_DENORMALS
#define BOOST_SIMD_NO_INFINITIES
#include <simd_bench.hpp>
#include <boost/simd/function/simd/rec.hpp>
#include <boost/simd/pack.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_rec, bs::rec);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_rec, NS_BENCH_IEEE_TYPES>(-10, 10);
  nsb::for_each<simd_rec, float>(0.0f, 1.0e-45f);
  nsb::for_each<simd_rec, double>(0.0, 1.0e-308);  
  nsb::for_each<simd_rec, float>(0.0f, 10.0f);
  nsb::for_each<simd_rec, double>(0.0, 10.0);  
}
