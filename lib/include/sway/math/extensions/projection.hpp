#ifndef SWAY_MATH_PROJECTION_HPP
#define SWAY_MATH_PROJECTION_HPP

#include <sway/core.hpp>
#include <sway/math/matrix4.hpp>
#include <sway/math/rect.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

struct ProjectionDescription {
  f32_t left;
  f32_t top;
  f32_t right;
  f32_t bottom;
  f32_t fov;
  f32_t aspect;
  f32_t near;
  f32_t far;
  // f32_t zoom;
};

class Projection final {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   */
  Projection(const ProjectionDescription &desc)
      : desc_(desc) {}

  void ortho() {
    auto w = desc_.right - desc_.left;
    auto h = desc_.top - desc_.bottom;
    auto d = desc_.far - desc_.near;

    auto x = w / 2.0F;
    auto y = h / 2.0F;
    auto z = d / -2.0F;

    mat_.setValue(0, 0, x);
    mat_.setValue(1, 1, y);
    mat_.setValue(2, 2, z);
    mat_.setValue(3, 0, -(desc_.left + desc_.right) / w);
    mat_.setValue(3, 1, -(desc_.top + desc_.bottom) / h);
    mat_.setValue(3, 2, -(desc_.far + desc_.near) / d);
  }

  void pers() {
    mat_.setValue(0, 0, 1 / tan(desc_.fov / 2) / desc_.aspect);
    mat_.setValue(1, 1, 1 / tan(desc_.fov / 2));
    mat_.setValue(2, 2, (desc_.near + desc_.far) / (desc_.near - desc_.far));
    mat_.setValue(2, 3, -1);
    mat_.setValue(3, 2, (2 * desc_.near * desc_.far) / (desc_.near - desc_.far));
    mat_.setValue(3, 3, 0);
  }

  auto getDescription() const -> ProjectionDescription { return desc_; }

  auto getData() const -> std::array<f32_t, 16> { return mat_.getData(); }

private:
  ProjectionDescription desc_;
  mat4f_t mat_;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_PROJECTION_HPP
