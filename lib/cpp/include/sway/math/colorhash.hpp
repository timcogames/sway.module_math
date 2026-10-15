#ifndef SWAY_MATH_COLORHASH_HPP
#define SWAY_MATH_COLORHASH_HPP

#include <sway/core.hpp>
#include <sway/math/color.hpp>

namespace sway::math {

struct ColorHash {
  auto operator()(const Color<u8_t> &color) const -> std::size_t{
    std::hash<u32_t> result;
    // Упаковываем RGBA в 32-битное число
    uint32_t value = (color.getR() << 24) | (color.getG() << 16) | (color.getB() << 8) | color.getA();
    return result(value);
  }
};

}  // namespace sway::math

#endif  // SWAY_MATH_COLORHASH_HPP
