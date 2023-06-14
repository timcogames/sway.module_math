#ifndef SWAY_MATH_RAY_HPP
#define SWAY_MATH_RAY_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType, std::size_t TSize>
class Ray {
public:
  Ray(const Vector<TValueType, TSize> &org, const Vector<TValueType, TSize> &dir)
      : origin_(org)
      , direction_(dir) {}

  // auto at(TValueType distance) const -> Vector<TValueType, TSize> { return direction_ * distance + origin_; }

  auto getOrigin() const -> Vector<TValueType, TSize> { return origin_; }

  auto getDirection() const -> Vector<TValueType, TSize> { return direction_; }

private:
  Vector<TValueType, TSize> origin_;
  Vector<TValueType, TSize> direction_;
};

using ray3f_t = Ray<f32_t, 3>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_RAY_HPP
