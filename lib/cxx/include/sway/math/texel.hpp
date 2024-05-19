#ifndef SWAY_MATH_TEXEL_HPP
#define SWAY_MATH_TEXEL_HPP

#include <sway/core.hpp>
#include <sway/math/size.hpp>
#include <sway/math/vector2.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

struct Texel {
  // clang-format off
  template <typename RETURN_TYPE,
            typename std::enable_if<std::is_base_of<sizef_t, RETURN_TYPE>::value ||
                                    std::is_base_of<vec2f_t, RETURN_TYPE>::value>::type>
  static auto convFromTexCoords(const sizef_t &coords) -> RETURN_TYPE {
    return RETURN_TYPE(1.0F / coords.getW(), 1.0F / coords.getH());
  }
  // clang-format on

  template <typename RETURN_TYPE>
  static auto convFromTexCoords(f32_t wdt, f32_t hgt) -> RETURN_TYPE {
    return Texel::convFromTexCoords<RETURN_TYPE>(sizef_t(wdt, hgt));
  }
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_TEXEL_HPP
