#ifndef SWAY_MATH_UTILS_HPP
#define SWAY_MATH_UTILS_HPP

#include <sway/core.hpp>

#include <algorithm>
#include <assert.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)
NAMESPACE_BEGIN(util)

constexpr f32_t PI = 3.14159265358979323846F;
constexpr f32_t EPSILON = 1.0e-05;

inline auto powerOf2(int val) -> int {
  // val |= (val >> 1);
  // val |= (val >> 2);
  // val |= (val >> 4);
  // val |= (val >> 8);
  // val |= (val >> 16);
  // val |= (val >> 32);
  // return val + 1;

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
