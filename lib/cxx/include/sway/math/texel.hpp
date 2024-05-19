#ifndef SWAY_MATH_TEXEL_HPP
#define SWAY_MATH_TEXEL_HPP

#include <sway/core.hpp>
#include <sway/math/size.hpp>
#include <sway/math/vector2.hpp>

#include <type_traits>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

struct Texel {
  // clang-format off
  template <typename TReturnType>
  static auto convFromTexCoords(const sizef_t &coords) -> TReturnType {
    static_assert(std::is_base_of<sizef_t, TReturnType>::value ||
                  std::is_base_of<vec2f_t, TReturnType>::value, "TReturnType must inherit from Vector2<TValueType>");
    return TReturnType(1.0F / coords.getW(), 1.0F / coords.getH());
  }
  // clang-format on

  template <typename TReturnType>
  static auto convFromTexCoords(f32_t wdt, f32_t hgt) -> TReturnType {
    return Texel::convFromTexCoords<TReturnType>(sizef_t(wdt, hgt));
  }
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_TEXEL_HPP
