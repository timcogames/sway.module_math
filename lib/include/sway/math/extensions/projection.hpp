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
  Projection()
      : zoom_(1.0F) {}

  auto getZoom() const -> f32_t { return zoom_; }

  void setZoom(f32_t zoom) { zoom_ = zoom; }

  auto ortho(f32_t left, f32_t top, f32_t right, f32_t bottom, f32_t nearPlane, f32_t farPlane) -> mat4f_t {
    mat4f_t mtx;
    mtx.setValue(0, 0, (right - left) / (2.0F * zoom_));
    mtx.setValue(1, 1, (top - bottom) / (2.0F * zoom_));
    mtx.setValue(2, 2, -(2.0F) / (farPlane - nearPlane));
    mtx.setValue(3, 0, -(right + left) / (right - left));
    mtx.setValue(3, 1, -(top + bottom) / (top - bottom));
    mtx.setValue(3, 2, -((farPlane + nearPlane) / (farPlane - nearPlane)));

    return mtx;
  }

private:
  f32_t zoom_;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_PROJECTION_HPP
