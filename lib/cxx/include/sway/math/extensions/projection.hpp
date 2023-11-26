#ifndef SWAY_MATH_PROJECTION_HPP
#define SWAY_MATH_PROJECTION_HPP

#include <sway/core.hpp>
#include <sway/math/matrix4.hpp>
#include <sway/math/rect.hpp>

#include <math.h>  // tan

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

struct ProjectionDescription {
  rect4f_t rect;
  f32_t fov;
  f32_t aspect;
  f32_t near;
  f32_t far;
};

class Projection final {
public:
  Projection() = default;

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   */
  Projection(const ProjectionDescription &desc)
      : desc_(desc) {}

  void setRect(const rect4f_t &rect) { desc_.rect = rect; }

  void setAspect(f32_t aspect) { desc_.aspect = aspect; }

  auto makeOrtho() -> std::array<f32_t, 16> {
    auto d = desc_.far - desc_.near;

    auto x = desc_.rect.getW() / (2.0F * desc_.aspect);
    auto y = desc_.rect.getH() / (2.0F * desc_.aspect);
    auto z = d / -2.0F;

    mat_.setValue(0, 0, x);
    mat_.setValue(1, 1, y);
    mat_.setValue(2, 2, z);
    mat_.setValue(3, 0, -(desc_.rect.getR() + desc_.rect.getL()) / desc_.rect.getW());
    mat_.setValue(3, 1, -(desc_.rect.getT() + desc_.rect.getB()) / desc_.rect.getH());
    mat_.setValue(3, 2, -(desc_.far + desc_.near) / d);

    return mat_.getData();
  }

  void makePersp() {
    mat_.setValue(0, 0, 1 / tan(desc_.fov / 2) / desc_.aspect);
    mat_.setValue(1, 1, 1 / tan(desc_.fov / 2));
    mat_.setValue(2, 2, (desc_.near + desc_.far) / (desc_.near - desc_.far));
    mat_.setValue(2, 3, -1);
    mat_.setValue(3, 2, (2 * desc_.near * desc_.far) / (desc_.near - desc_.far));
    mat_.setValue(3, 3, 0);
  }

  [[nodiscard]] auto getDescription() const -> ProjectionDescription { return desc_; }

  [[nodiscard]] auto getData() const -> std::array<f32_t, 16> { return mat_.getData(); }

private:
  ProjectionDescription desc_;
  mat4f_t mat_;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_PROJECTION_HPP
