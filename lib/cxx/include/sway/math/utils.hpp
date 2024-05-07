#ifndef SWAY_MATH_UTILS_HPP
#define SWAY_MATH_UTILS_HPP

#include <sway/core.hpp>

#include <algorithm>
#include <assert.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)
NAMESPACE_BEGIN(util)

constexpr f32_t PI = 3.14159265358979323846F;
constexpr f64_t EPSILON = 1e-05;  // aka 0.00001
constexpr s32_t INDEFINITE = -1;

inline auto powerOf2(int val) -> int {
  auto result = 1;
  while (result < val) {
    result <<= 1;
  }

  return result;
}

template <typename TValueType>
inline auto lerp(TValueType from, TValueType to, TValueType step) -> TValueType {
  return from + step * (to - from);
}

template <typename TValueType>
inline auto clamp(const TValueType &val, const TValueType &lower, const TValueType &upper) -> TValueType {
  return std::max(lower, std::min(val, upper));
}

template <typename TValueType>
inline auto abs(const TValueType &val) -> TValueType {
  if constexpr (std::is_integral_v<TValueType>) {
    return std::abs(val);
  } else if constexpr (std::is_floating_point_v<TValueType>) {
    return std::fabsf(val);
  } else /* double */ {
    assert(sizeof(TValueType) == 8);
    return std::fabs(val);
  }
}

NAMESPACE_END(util)
NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_UTILS_HPP
