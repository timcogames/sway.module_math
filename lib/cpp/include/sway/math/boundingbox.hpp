#ifndef SWAY_MATH_BOUNDINGBOX_HPP
#define SWAY_MATH_BOUNDINGBOX_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <std::size_t TSize>
struct BoundingBox {
  math::Vector<f32_t, TSize> min;
  math::Vector<f32_t, TSize> max;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_BOUNDINGBOX_HPP
