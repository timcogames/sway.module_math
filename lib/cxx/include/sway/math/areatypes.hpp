#ifndef SWAY_MATH_AREATYPES_HPP
#define SWAY_MATH_AREATYPES_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

enum class AreaType : u32_t { NONE = 0, MGN, PAD, BRD, CNT, Latest };

#define NUM_OF_AREAS (core::detail::toBase(AreaType::Latest) - 1)

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_AREATYPES_HPP
