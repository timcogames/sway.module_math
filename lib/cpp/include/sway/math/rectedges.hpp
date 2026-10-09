#ifndef SWAY_MATH_RECTEDGES_HPP
#define SWAY_MATH_RECTEDGES_HPP

#include <sway/core.hpp>

namespace sway::math {

// clang-format off
#define RECT_EDGE_LIST(ITEM) \
  ITEM(IDX_L, 0) \
  ITEM(IDX_T, 1) \
  ITEM(IDX_R, 2) \
  ITEM(IDX_B, 3)
// clang-format on

DECLARE_ENUM_IDX(RectEdge, RECT_EDGE_LIST)

}  // namespace sway::math

#define NUM_OF_EDGES (sway::math::RectEdge::EnumInfo::getCountWithoutNone())

#endif  // SWAY_MATH_RECTEDGES_HPP
