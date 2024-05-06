#ifndef SWAY_MATH_TEXEL_HPP
#define SWAY_MATH_TEXEL_HPP

#include <sway/core.hpp>
#include <sway/math/size.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

struct Texel {
  static auto convFromTexCoords(const size2f_t &coords) -> size2f_t {
    return size2f_t(1.0F / coords.getW(), 1.0F / coords.getH());
  }
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_TEXEL_HPP
