#ifndef SWAY_MATH_ALIGNMENTS_HPP
#define SWAY_MATH_ALIGNMENTS_HPP

#include <sway/core.hpp>

namespace sway::math {
enum class HorzAlign : s8_t { CENTER = ENUM_BITMASK(1), LEFT = ENUM_BITMASK(2), RIGHT = ENUM_BITMASK(3) };

enum class VertAlign : s8_t { CENTER = ENUM_BITMASK(4), TOP = ENUM_BITMASK(5), BOTTOM = ENUM_BITMASK(6) };

template <auto VALUE>
constexpr auto ConvFromXAlign() -> s8_t {
  if constexpr (std::is_same_v<decltype(VALUE), HorzAlign>) {
    return core::toBase<HorzAlign>(VALUE);
  } else if constexpr (std::is_same_v<decltype(VALUE), VertAlign>) {
    return core::toBase<VertAlign>(VALUE);
  }
}

enum class Alignment : s8_t {
  LEFT_TOP = ConvFromXAlign<HorzAlign::LEFT>() | ConvFromXAlign<VertAlign::TOP>(),
  LEFT_CENTER = ConvFromXAlign<HorzAlign::LEFT>() | ConvFromXAlign<VertAlign::CENTER>(),
  LEFT_BOTTOM = ConvFromXAlign<HorzAlign::LEFT>() | ConvFromXAlign<VertAlign::BOTTOM>(),
  CENTER_TOP = ConvFromXAlign<HorzAlign::CENTER>() | ConvFromXAlign<VertAlign::TOP>(),
  CENTER = ConvFromXAlign<HorzAlign::CENTER>() | ConvFromXAlign<VertAlign::CENTER>(),
  CENTER_BOTTOM = ConvFromXAlign<HorzAlign::CENTER>() | ConvFromXAlign<VertAlign::BOTTOM>(),
  RIGHT_TOP = ConvFromXAlign<HorzAlign::RIGHT>() | ConvFromXAlign<VertAlign::TOP>(),
  RIGHT_CENTER = ConvFromXAlign<HorzAlign::RIGHT>() | ConvFromXAlign<VertAlign::CENTER>(),
  RIGHT_BOTTOM = ConvFromXAlign<HorzAlign::RIGHT>() | ConvFromXAlign<VertAlign::BOTTOM>()
};

}  // namespace sway::math

#endif  // SWAY_MATH_ALIGNMENTS_HPP
