#ifndef SWAY_MATH_AXISES_HPP
#define SWAY_MATH_AXISES_HPP

#include <sway/core.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(math)

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

DECLARE_ENUM(Axis, RIGHT, LEFT, UP, DOWN, FORWARD, BACKWARD);

NS_END()  // namespace math
NS_END()  // namespace sway

#endif  // SWAY_MATH_AXISES_HPP
