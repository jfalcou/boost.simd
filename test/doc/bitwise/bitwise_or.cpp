//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [bitwise_or]
#include <boost/simd/bitwise.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/nan.hpp>
#include <iostream>

namespace bs =  boost::simd;
using pack_it =  bs::pack <std::uint32_t, 4>;

int main()
{
  pack_it pi = { 3,  6,  5,  27 };
  pack_it qi = { 4, -1,  2, ~0  };
  std::cout
    <<  "---- simd" << '\n'
    << " <- pi =                     " << pi << '\n'
    << " <- qi =                     " << qi << '\n'
    << " -> bs::bitwise_or(pi, qi) = " << bs::bitwise_or(pi, qi) << '\n';

  std::uint32_t xi = 3, yi = 4;

  std::cout
    << "---- scalar"  << '\n'
    << " xi =                        " << xi << '\n'
    << " yi =                        " << yi << '\n'
    << " -> bs::bitwise_or(xi, yi) = " << bs::bitwise_or(xi, yi) << '\n';
  return 0;
}
//! [bitwise_or]
