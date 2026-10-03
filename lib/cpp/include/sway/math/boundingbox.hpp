#ifndef SWAY_MATH_BOUNDINGBOX_HPP
#define SWAY_MATH_BOUNDINGBOX_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

namespace sway::math {

template <typename TYPE, std::size_t SIZE>
struct BoundingBox {
  Vector<TYPE, SIZE> min;
  Vector<TYPE, SIZE> max;

  BoundingBox(Vector<TYPE, SIZE> min, Vector<TYPE, SIZE> max) {
    this->min = min;
    this->max = max;
  }
};

using bbox2i_t = BoundingBox<i32_t, 2>;
using bbox3i_t = BoundingBox<i32_t, 3>;

using bbox2f_t = BoundingBox<f32_t, 2>;
using bbox3f_t = BoundingBox<f32_t, 3>;

}  // namespace sway::math

#endif  // SWAY_MATH_BOUNDINGBOX_HPP
