#ifndef SWAY_MATH_PROJECTION_HPP
#define SWAY_MATH_PROJECTION_HPP

#include <sway/core.hpp>
#include <sway/math/matrix4.hpp>
#include <sway/math/rect.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

class Projection final {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   */
  Projection() = default;

  auto ortho(f32_t left, f32_t top, f32_t right, f32_t bottom, f32_t nearPlane, f32_t farPlane) -> mat4f_t {
    mat4f_t projmat;
    projmat.setValue(0, 0, 2.0 / (right - left));
    projmat.setValue(1, 1, 2.0 / (top - bottom));
    projmat.setValue(2, 2, -(2.0) / (farPlane - nearPlane));
    projmat.setValue(3, 0, -(right + left) / (right - left));
    projmat.setValue(3, 1, -(top + bottom) / (top - bottom));
    projmat.setValue(3, 2, -((farPlane + nearPlane) / (farPlane - nearPlane)));

    return projmat;
  }
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_PROJECTION_HPP
