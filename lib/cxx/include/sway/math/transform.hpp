#ifndef SWAY_MATH_TRANSFORM_HPP
#define SWAY_MATH_TRANSFORM_HPP

#include <sway/core.hpp>
#include <sway/math/matrix4.hpp>
#include <sway/math/vector4.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(math)

template <class NODE, typename TYPE>
class Transform : public NODE {
public:
#pragma region "Static methods"

  static auto translate(Matrix4<TYPE> const &mat, TYPE x, TYPE y, TYPE z) -> Matrix4<TYPE> {
    Matrix4<TYPE> result(mat);
    result.setCol(3, mat.getCol(0) * x + mat.getCol(1) * y + mat.getCol(2) * z + mat.getCol(3));
    return result;
  }

  static auto scale(Matrix4<TYPE> const &mat, TYPE x, TYPE y, TYPE z) -> Matrix4<TYPE> {
    Matrix4<TYPE> result(mat);
    result.setCol(0, mat.getCol(0) * x);
    result.setCol(1, mat.getCol(1) * y);
    result.setCol(2, mat.getCol(2) * z);
    return result;
  }

#pragma endregion

#pragma region "Ctors/Dtor"

  Transform();

  virtual ~Transform() = default;

#pragma endregion

  auto getModelMatrix() -> Matrix4<TYPE>;

  void setPosition(TYPE x, TYPE y, TYPE z);

  void setPosition(const Vector3<TYPE> &pos);

  auto getPosition() -> Vector3<TYPE>;

  void setTranslate(TYPE x, TYPE y, TYPE z);

  void setTranslate(const Vector3<TYPE> &pos);

  void setScale(TYPE x, TYPE y, TYPE z);

private:
  [[nodiscard]]
  auto getInternalMatrix_() const -> Matrix4<TYPE>;

  Vector3<TYPE> position_;
  Vector3<TYPE> scale_;
};

struct Dummy {};
using xform3i_t = Transform<Dummy, i32_t>;
using xform3f_t = Transform<Dummy, f32_t>;
using xform3d_t = Transform<Dummy, f64_t>;

NS_END()  // namespace math
NS_END()  // namespace sway

#include <sway/math/transform.inl>

#endif  // SWAY_MATH_TRANSFORM_HPP
