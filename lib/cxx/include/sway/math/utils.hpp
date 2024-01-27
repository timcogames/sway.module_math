#ifndef SWAY_MATH_UTILS_HPP
#define SWAY_MATH_UTILS_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

constexpr f32_t PI = 3.14159265358979323846F;

class Utils {
public:
  template <typename TValueType>
  static auto lerp(TValueType from, TValueType to, TValueType step) -> TValueType {
    return from + step * (to - from);
  }
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_UTILS_HPP
