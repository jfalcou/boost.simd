//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
//! [firstbitset]
#include <boost/simd/bitwise.hpp>
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;
using pack_it = bs::pack<std::uint32_t, 4>;

int main() {
  pack_it pi = {1, 2, 10, 1023};

  std::cout << "---- simd" << '\n'
            << "<- pi =                   " << pi << '\n'
            << "-> bs::firstbitset(pi) =  " << bs::firstbitset(pi) << '\n';

  std::uint32_t xi = 2;

  std::cout << "---- scalar" << '\n'
            << "<- xi =                   " << xi << '\n'
            << "-> bs::firstbitset(xi) =  " << bs::firstbitset(xi) << '\n';
  return 0;
}
//! [firstbitset]
