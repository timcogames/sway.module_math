#ifndef SWAY_MATH_COORDINATESYSTEMUTILS_HPP
#define SWAY_MATH_COORDINATESYSTEMUTILS_HPP

#include <sway/core.hpp>
#include <sway/math/matrix4.hpp>
#include <sway/math/point.hpp>
#include <sway/math/size.hpp>
#include <sway/math/vector2.hpp>
#include <sway/math/vector3.hpp>
#include <sway/math/vector4.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

struct NDC {
  // [0..1] -> [-1,+1]
  static auto convFromScreen(const point2f_t &point, const size2i_t &scr) -> vec2f_t {
    auto xpos = (point.getX() / static_cast<float>(scr.getW())) * 2.0F - 1.0F;
    auto ypos = 1.0F - 2.0F * (point.getY() / static_cast<float>(scr.getH()));

    return vec2f_t(xpos, ypos);
  }

  // [-1,+1] -> [0..1]
  static auto convToScreen(const vec2f_t &ndc) -> point2f_t {
    auto xpos = (ndc.getX() + 1.0F) * +0.5f;
    auto ypos = (ndc.getY() - 1.0F) * -0.5f;

    return point2f_t(xpos, fabsf(ypos));
  }
};

struct CoordinateSystemUtils {
  static auto convScreenToWorldSpace(const vec4f_t &ndc, const mat4f_t &vpInv) -> vec3f_t {
    auto ptWorld = mat4f_t::transform(vpInv, ndc);
    ptWorld /= ptWorld.getW();
    return vec3f_t::from(ptWorld.array());
  }
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_COORDINATESYSTEMUTILS_HPP
