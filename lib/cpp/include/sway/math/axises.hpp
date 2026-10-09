#ifndef SWAY_MATH_AXISES_HPP
#define SWAY_MATH_AXISES_HPP

#include <sway/core.hpp>

namespace sway::math {

/**
 * @var Axis::Enum::RIGHT
 * @brief Positive X axis
 */

/**
 * @var Axis::Enum::LEFT
 * @brief Negative X axis
 */

/**
 * @var Axis::Enum::UP
 * @brief Positive Y axis
 */

/**
 * @var Axis::Enum::DOWN
 * @brief Negative Y axis
 */

/**
 * @var Axis::Enum::FORWARD
 * @brief Positive Z axis
 */

/**
 * @var Axis::Enum::BACKWARD
 * @brief Negative Z axis
 */

// clang-format off
#define AXIS_LIST(ITEM) \
  ITEM(RIGHT, 1) \
  ITEM(LEFT, 2) \
  ITEM(UP, 3) \
  ITEM(DOWN, 4) \
  ITEM(FORWARD, 5) \
  ITEM(BACKWARD, 6)
// clang-format on

DECLARE_ENUM_U32(Axis, AXIS_LIST)

}  // namespace sway::math

#endif  // SWAY_MATH_AXISES_HPP
