#ifndef SWAY_MATH_PROJECTIONTYPES_HPP
#define SWAY_MATH_PROJECTIONTYPES_HPP

#include <sway/core.hpp>

namespace sway::math {

#define PROJECTION_TYPE_LIST(ITEM) \
  ITEM(ORTHO, 1) \
  ITEM(PERSP, 2)
// clang-format on

DECLARE_ENUM_U32(ProjectionType, PROJECTION_TYPE_LIST)

}  // namespace sway::math

#endif  // SWAY_MATH_PROJECTIONTYPES_HPP
