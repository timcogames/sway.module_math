#ifndef SWAY_MATH_RECTEDGES_HPP
#define SWAY_MATH_RECTEDGES_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

enum class RectEdge : u32_t { IDX_L = 0, IDX_B, IDX_R, IDX_T, Latest };

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_RECTEDGES_HPP
