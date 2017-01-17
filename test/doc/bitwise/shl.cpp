//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [shl]
#include <boost/simd/bitwise.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>


namespace bs =  boost::simd;
using iT = std::int32_t;
using pack_it = bs::pack<iT, 4>;

int main()
{
  pack_it pi = {1, 2, -1, 3};
  pack_it qi = {1, 2,  4, 3};

  std::cout
    << "---- simd" << '\n'
    << "<- pi =              " << pi << '\n'
    << "<- qi =              " << qi << '\n'
    << "-> bs::shl(pi, qi) = " << bs::shl(pi, qi) << '\n';

  iT xi = 2, yi = 3;

  std::cout
    << "---- scalar"  << '\n'
    << "<- xi =              " << xi << '\n'
    << "<- yi =              " << yi << '\n'
    << "-> bs::shl(xi, yi) = " << bs::shl(xi, yi) << '\n';
  return 0;
}
//! [shl]
