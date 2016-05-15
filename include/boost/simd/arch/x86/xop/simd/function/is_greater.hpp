//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_XOP_SIMD_FUNCTION_IS_GREATER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_XOP_SIMD_FUNCTION_IS_GREATER_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/as_logical.hpp>

#if !defined(_MM_PCOMCTRL_GT)
#define _MM_PCOMCTRL_GT 2
#define BOOST_SIMD_MISSING_MM_PCOMCTRL_GT
#endif

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( is_greater_
                          , (typename A0)
                          , bs::xop_
                          , bs::pack_<bd::int8_<A0>, bs::sse_>
                          , bs::pack_<bd::int8_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE
    bs::as_logical_t<A0> operator()(const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      #if defined(__clang__)
      return _mm_com_epi8(a0,a1,_MM_PCOMCTRL_GT);
      #else
      return _mm_comgt_epi8(a0,a1);
      #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( is_greater_
                          , (typename A0)
                          , bs::xop_
                          , bs::pack_<bd::int16_<A0>, bs::sse_>
                          , bs::pack_<bd::int16_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE
    bs::as_logical_t<A0> operator()(const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      #if defined(__clang__)
      return _mm_com_epi16(a0,a1,_MM_PCOMCTRL_GT);
      #else
      return _mm_comgt_epi16(a0,a1);
      #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( is_greater_
                          , (typename A0)
                          , bs::xop_
                          , bs::pack_<bd::int32_<A0>, bs::sse_>
                          , bs::pack_<bd::int32_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE
    bs::as_logical_t<A0> operator()(const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      #if defined(__clang__)
      return _mm_com_epi32(a0,a1,_MM_PCOMCTRL_GT);
      #else
      return _mm_comgt_epi32(a0,a1);
      #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( is_greater_
                          , (typename A0)
                          , bs::xop_
                          , bs::pack_<bd::int64_<A0>, bs::sse_>
                          , bs::pack_<bd::int64_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE
    bs::as_logical_t<A0> operator()(const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      #if defined(__clang__)
      return _mm_com_epi64(a0,a1,_MM_PCOMCTRL_GT);
      #else
      return _mm_comgt_epi64(a0,a1);
      #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( is_greater_
                          , (typename A0)
                          , bs::xop_
                          , bs::pack_<bd::uint8_<A0>, bs::sse_>
                          , bs::pack_<bd::uint8_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE
    bs::as_logical_t<A0> operator()(const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      #if defined(__clang__)
      return _mm_com_epu8(a0,a1,_MM_PCOMCTRL_GT);
      #else
      return _mm_comgt_epu8(a0,a1);
      #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( is_greater_
                          , (typename A0)
                          , bs::xop_
                          , bs::pack_<bd::uint16_<A0>, bs::sse_>
                          , bs::pack_<bd::uint16_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE
    bs::as_logical_t<A0> operator()(const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      #if defined(__clang__)
      return _mm_com_epu16(a0,a1,_MM_PCOMCTRL_GT);
      #else
      return _mm_comgt_epu16(a0,a1);
      #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( is_greater_
                          , (typename A0)
                          , bs::xop_
                          , bs::pack_<bd::uint32_<A0>, bs::sse_>
                          , bs::pack_<bd::uint32_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE
    bs::as_logical_t<A0> operator()(const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      #if defined(__clang__)
      return _mm_com_epu32(a0,a1,_MM_PCOMCTRL_GT);
      #else
      return _mm_comgt_epu32(a0,a1);
      #endif
    }
  };

  BOOST_DISPATCH_OVERLOAD ( is_greater_
                          , (typename A0)
                          , bs::xop_
                          , bs::pack_<bd::uint64_<A0>, bs::sse_>
                          , bs::pack_<bd::uint64_<A0>, bs::sse_>
                          )
  {
    BOOST_FORCEINLINE
    bs::as_logical_t<A0> operator()(const A0& a0, const A0& a1) const BOOST_NOEXCEPT
    {
      #if defined(__clang__)
      return _mm_com_epu64(a0,a1,_MM_PCOMCTRL_GT);
      #else
      return _mm_comgt_epu64(a0,a1);
      #endif
    }
  };
} } }

#if defined(BOOST_SIMD_MISSING_MM_PCOMCTRL_GT)
#undef _MM_PCOMCTRL_GT
#undef BOOST_SIMD_MISSING_MM_PCOMCTRL_GT
#endif

#endif
