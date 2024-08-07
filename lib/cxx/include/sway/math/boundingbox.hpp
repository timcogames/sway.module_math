#ifndef SWAY_MATH_BOUNDINGBOX_HPP
#define SWAY_MATH_BOUNDINGBOX_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TYPE, std::size_t SIZE>
struct BoundingBox {
  math::Vector<TYPE, SIZE> min;
  math::Vector<TYPE, SIZE> max;

  BoundingBox(math::Vector<TYPE, SIZE> min, math::Vector<TYPE, SIZE> max) {
    this->min = min;
    this->max = max;
  }
};

using bbox2i_t = BoundingBox<i32_t, 2>;
using bbox3i_t = BoundingBox<i32_t, 3>;

using bbox2f_t = BoundingBox<f32_t, 2>;
using bbox3f_t = BoundingBox<f32_t, 3>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_BOUNDINGBOX_HPP
