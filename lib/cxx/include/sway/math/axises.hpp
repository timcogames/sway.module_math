#ifndef SWAY_MATH_AXISES_HPP
#define SWAY_MATH_AXISES_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

enum class Axis : u32_t {
  NONE = 0,
  RIGHT,  // Positive X axis
  LEFT,  // Negative X axis
  UP,  // Positive Y axis
  DOWN,  // Negative Y axis
  FORWARD,  // Positive Z axis
  BACKWARD,  // Negative Z axis
  Latest
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_AXISES_HPP
