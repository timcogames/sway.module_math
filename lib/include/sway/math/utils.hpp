#ifndef SWAY_MATH_UTILS_HPP
#define SWAY_MATH_UTILS_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

constexpr f32_t PI = 3.14159265358979323846F;

class Utils {
public:
  auto lerp(f32_t x, f32_t y, f32_t t) -> f32_t { return (1.0F - t) * x + t * y; }
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_UTILS_HPP
