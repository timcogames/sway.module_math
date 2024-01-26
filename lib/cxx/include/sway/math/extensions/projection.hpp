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
  f32_t znear;
  f32_t zfar;
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
    auto d = desc_.zfar - desc_.znear;

    auto x = desc_.rect.getW() / (2.0F * desc_.aspect);
    auto y = desc_.rect.getH() / (2.0F * desc_.aspect);
    auto z = d / -2.0F;

    mtx_.makeIdentity();
    mtx_.setValue(0, 0, x);
    mtx_.setValue(1, 1, y);
    mtx_.setValue(2, 2, z);
    mtx_.setValue(3, 0, -(desc_.rect.getR() + desc_.rect.getL()) / desc_.rect.getW());
    mtx_.setValue(3, 1, -(desc_.rect.getT() + desc_.rect.getB()) / desc_.rect.getH());
    mtx_.setValue(3, 2, -(desc_.zfar + desc_.znear) / d);

    return mtx_.getData();
  }

  void makePersp() {
    mtx_.makeIdentity();
    mtx_.setValue(0, 0, 1 / tan(desc_.fov / 2) / desc_.aspect);
    mtx_.setValue(1, 1, 1 / tan(desc_.fov / 2));
    mtx_.setValue(2, 2, (desc_.znear + desc_.zfar) / (desc_.znear - desc_.zfar));
    mtx_.setValue(2, 3, -1);
    mtx_.setValue(3, 2, (2 * desc_.znear * desc_.zfar) / (desc_.znear - desc_.zfar));
    mtx_.setValue(3, 3, 0);
  }

  [[nodiscard]] auto getDescription() const -> ProjectionDescription { return desc_; }

  [[nodiscard]] auto getData() const -> std::array<f32_t, 16> { return mtx_.getData(); }

private:
  ProjectionDescription desc_;
  mat4f_t mtx_;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_PROJECTION_HPP
