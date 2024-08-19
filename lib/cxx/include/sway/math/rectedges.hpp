#ifndef SWAY_MATH_RECTEDGES_HPP
#define SWAY_MATH_RECTEDGES_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

enum class RectEdge : i32_t { NONE = GLOB_IDX_INVALID, IDX_L = GLOB_IDX_INITIAL, IDX_T, IDX_R, IDX_B, Latest };

NAMESPACE_END(math)
NAMESPACE_END(sway)

#define NUM_OF_EDGES (sway::core::detail::toBase(sway::math::RectEdge::Latest))

#endif  // SWAY_MATH_RECTEDGES_HPP
