#ifndef SWAY_MATH_RECTEDGES_HPP
#define SWAY_MATH_RECTEDGES_HPP

#include <sway/core.hpp>

namespace sway::math {

DECLARE_ENUM_IDX(RectEdge, IDX_L = GLOB_IDX_INITIAL, IDX_T, IDX_R, IDX_B);

}  // namespace sway::math

#define NUM_OF_EDGES (sway::core::detail::toBase(sway::math::RectEdge::Enum::Latest))

#endif  // SWAY_MATH_RECTEDGES_HPP
