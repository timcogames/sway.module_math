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

template <typename TYPE>
class Ray {
public:
#pragma region "Static methods"

  static auto convFromScreenPoint(
      math::Point<TYPE> point, const math::size2i_t &scr, const math::Matrix4<TYPE> &vpInv) -> Ray<TYPE> {
    auto ndc = math::NDC::convFromScreen(point, scr);

    auto start = math::vec4f_t(ndc.getX(), ndc.getY(), 0.0F, 1.0F);
    auto end = math::vec4f_t(ndc.getX(), ndc.getY(), 1.0F, 1.0F);

    return Ray<TYPE>(CoordinateSystemUtils::convScreenToWorldSpace(start, vpInv),
        CoordinateSystemUtils::convScreenToWorldSpace(end, vpInv));
  }

#pragma endregion

#pragma region "Ctors/Dtor"

  Ray(const Vector3<TYPE> &start, const Vector3<TYPE> &end)
      : origin_(start)
      , direction_(Vector3<TYPE>::normalize(end - start)) {}

#pragma endregion

  auto at(TYPE distance) const -> Vector3<TYPE> { return direction_ * distance + origin_; }

  auto getOrigin() const -> Vector3<TYPE> { return origin_; }

  auto getDirection() const -> Vector3<TYPE> { return direction_; }

private:
  Vector3<TYPE> origin_;
  Vector3<TYPE> direction_;
};

using ray3f_t = Ray<f32_t>;
using ray3d_t = Ray<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_RAY_HPP
