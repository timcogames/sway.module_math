#ifndef SWAY_MATH_BOUNDINGBOX_HPP
#define SWAY_MATH_BOUNDINGBOX_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType, std::size_t TSize>
struct BoundingBox {
  math::Vector<TValueType, TSize> min;
  math::Vector<TValueType, TSize> max;

  BoundingBox(math::Vector<TValueType, TSize> min, math::Vector<TValueType, TSize> max) {
    this->min = min;
    this->max = max;
  }
};

using bbox2i_t = BoundingBox<s32_t, 2>;
using bbox3i_t = BoundingBox<s32_t, 3>;

using bbox2f_t = BoundingBox<f32_t, 2>;
using bbox3f_t = BoundingBox<f32_t, 3>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_BOUNDINGBOX_HPP
