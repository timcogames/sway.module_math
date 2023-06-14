#ifndef SWAY_MATH_RAY_HPP
#define SWAY_MATH_RAY_HPP

#include <sway/core.hpp>
#include <sway/math/vector3.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType>
class Ray {
public:
  Ray(const Vector3<TValueType> &start, const Vector3<TValueType> &end)
      : origin_(start)
      , direction_(Vector3<TValueType>::normalize(end - start)) {}

  auto at(TValueType distance) const -> Vector3<TValueType> { return direction_ * distance + origin_; }

  auto getOrigin() const -> Vector3<TValueType> { return origin_; }

  auto getDirection() const -> Vector3<TValueType> { return direction_; }

private:
  Vector3<TValueType> origin_;
  Vector3<TValueType> direction_;
};

using ray3f_t = Ray<f32_t>;
using ray3d_t = Ray<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_RAY_HPP
