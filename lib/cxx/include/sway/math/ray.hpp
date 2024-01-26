#ifndef SWAY_MATH_RAY_HPP
#define SWAY_MATH_RAY_HPP

#include <sway/core.hpp>
#include <sway/math/extensions/coordinatesystemutils.hpp>
#include <sway/math/matrix4.hpp>
#include <sway/math/point.hpp>
#include <sway/math/size.hpp>
#include <sway/math/vector4.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType>
class Ray {
public:
  static auto convFromScreenPoint(math::Point<TValueType> point, const math::size2i_t &scr,
      const math::Matrix4<TValueType> &vpInv) -> Ray<TValueType> {
    auto ndc = math::NDC::convFromScreen(point, scr);

    auto start = math::vec4f_t(ndc.getX(), ndc.getY(), 0.0F, 1.0F);
    auto end = math::vec4f_t(ndc.getX(), ndc.getY(), 1.0F, 1.0F);

    return Ray<TValueType>(CoordinateSystemUtils::convScreenToWorldSpace(start, vpInv),
        CoordinateSystemUtils::convScreenToWorldSpace(end, vpInv));
  }

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
