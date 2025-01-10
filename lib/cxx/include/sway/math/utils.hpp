#ifndef SWAY_MATH_UTIL_HPP
#define SWAY_MATH_UTIL_HPP

#include <sway/core.hpp>

#include <algorithm>  // random_shuffle
#include <assert.h>
#include <random>

NS_BEGIN_SWAY()
NS_BEGIN(math)
NS_BEGIN(util)

constexpr f32_t PI = 3.141592654F;
constexpr f32_t HALF_PI = 1.570796327F;

constexpr f64_t EPSILON = 1.0e-05;  // aka 0.00001
constexpr i32_t INDEFINITE = -1;

FORCE_INLINE auto randomInt(const i32_t nbr) -> std::vector<i32_t> {
  std::vector<i32_t> result;
  for (auto i = 0; i < nbr; ++i) {
    result.push_back(i);
  }

  std::random_device rng;
  std::mt19937 urng(rng());

  std::shuffle(result.begin(), result.end(), urng);
  return result;
}

FORCE_INLINE auto powerOf2(int val) -> int {
  auto result = 1;
  while (result < val) {
    result <<= 1;
  }

  return result;
}

template <typename TYPE>
FORCE_INLINE auto lerp(TYPE from, TYPE to, TYPE step) -> TYPE {
  return from + step * (to - from);
}

template <typename TYPE>
FORCE_INLINE auto clamp(const TYPE &val, const TYPE &lower, const TYPE &upper) -> TYPE {
  return std::max(lower, std::min(val, upper));
}

template <typename TYPE>
FORCE_INLINE auto abs(const TYPE &val) -> TYPE {
  if constexpr (std::is_integral_v<TYPE>) {
    return std::abs(val);
  } else if constexpr (std::is_floating_point_v<TYPE>) {
    return std::fabsf(val);
  } else /* double */ {
    assert(sizeof(TYPE) == 8);
    return std::fabs(val);
  }
}

NS_END()  // namespace util
NS_END()  // namespace math
NS_END()  // namespace sway

#endif  // SWAY_MATH_UTIL_HPP
