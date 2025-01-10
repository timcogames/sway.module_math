#ifndef SWAY_MATH_PROJECTION_HPP
#define SWAY_MATH_PROJECTION_HPP

#include <sway/core.hpp>
#include <sway/math/matrix4.hpp>
#include <sway/math/rect.hpp>

#include <math.h>  // tan

NS_BEGIN_SWAY()
NS_BEGIN(math)

struct ProjectionDescription {
  rect4f_t rect;
  f32_t fov;
  f32_t aspect;
  f32_t znear;
  f32_t zfar;
};

class Projection final {
public:
#pragma region "Ctors/Dtor"

  Projection() = default;

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   */
  Projection(const ProjectionDescription &desc)
      : desc_(desc) {}

#pragma endregion

  void setRect(const rect4f_t &rect) { desc_.rect = rect; }

  void setAspect(f32_t aspect) { desc_.aspect = aspect; }

  auto makeOrtho() -> std::array<f32_t, 16> {
    auto d = desc_.zfar - desc_.znear;
    auto r = desc_.rect;

    r.multiply(desc_.aspect);

    // clang-format off
    auto x =  2.0F / (r.getR() - r.getL());
    auto y =  2.0F / (r.getT() - r.getB());
    auto z = -2.0F / d;
    // clang-format on

    mtx_.makeIdentity();
    mtx_.setValue(0, 0, x);
    mtx_.setValue(1, 1, y);
    mtx_.setValue(2, 2, z);
    mtx_.setValue(3, 0, -(r.getR() + r.getL()) / (r.getR() - r.getL()));
    mtx_.setValue(3, 1, -(r.getT() + r.getB()) / (r.getT() - r.getB()));
    mtx_.setValue(3, 2, -(desc_.zfar + desc_.znear) / d);

    return mtx_.asArray();
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

  [[nodiscard]] auto asArray() const -> std::array<f32_t, 16> { return mtx_.asArray(); }

private:
  ProjectionDescription desc_;
  mat4f_t mtx_;
};

NS_END()  // namespace math
NS_END()  // namespace sway

#endif  // SWAY_MATH_PROJECTION_HPP
