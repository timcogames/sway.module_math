#ifndef SWAY_MATH_TEXEL_HPP
#define SWAY_MATH_TEXEL_HPP

#include <sway/core.hpp>
#include <sway/math/size.hpp>
#include <sway/math/vector2.hpp>

#include <type_traits>

NS_BEGIN_SWAY()
NS_BEGIN(math)

struct Texel {
  // clang-format off
  template <typename RETURN_TYPE>
  static auto convFromTexCoords(const sizef_t &coords) -> RETURN_TYPE {
    static_assert(std::is_base_of<sizef_t, RETURN_TYPE>::value ||
                  std::is_base_of<vec2f_t, RETURN_TYPE>::value, "RETURN_TYPE must inherit from Vector2<TYPE>");
    return RETURN_TYPE(1.0F / coords.getW(), 1.0F / coords.getH());
  }
  // clang-format on

  template <typename RETURN_TYPE>
  static auto convFromTexCoords(f32_t wdt, f32_t hgt) -> RETURN_TYPE {
    return Texel::convFromTexCoords<RETURN_TYPE>(sizef_t(wdt, hgt));
  }
};

NS_END()  // namespace math
NS_END()  // namespace sway

#endif  // SWAY_MATH_TEXEL_HPP
