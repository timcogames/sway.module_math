#ifndef SWAY_MATH_COLOREQUAL_HPP
#define SWAY_MATH_COLOREQUAL_HPP

#include <sway/core.hpp>
#include <sway/math/color.hpp>

namespace sway::math {

struct ColorEqual {
  auto operator()(const Color<u8_t> &a, const Color<u8_t> &b) const -> bool { return a == b; }
};

}  // namespace sway::math

#endif  // SWAY_MATH_COLOREQUAL_HPP
