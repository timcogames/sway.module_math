#ifndef SWAY_MATH_RECTEDGES_HPP
#define SWAY_MATH_RECTEDGES_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

enum class RectEdge : i32_t { NONE = GLOB_IDX_INVALID, IDX_L = GLOB_IDX_INITIAL, IDX_T, IDX_R, IDX_B, Latest };

#define NUM_OF_EDGES (core::detail::toBase(RectEdge::Latest) - 1)

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_RECTEDGES_HPP
