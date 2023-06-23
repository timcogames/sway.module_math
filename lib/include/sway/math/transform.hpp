#ifndef SWAY_MATH_TRANSFORM_HPP
#define SWAY_MATH_TRANSFORM_HPP

#include <sway/core.hpp>
#include <sway/math/matrix4.hpp>
#include <sway/math/vector4.hpp>

#include <array>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/**
 * @brief Шаблонный класс представления матрицы.
 */
template <typename TValueType>
class Transform {
public:
  static auto translate(Matrix4<TValueType> const &mat, TValueType x, TValueType y, TValueType z)
      -> Matrix4<TValueType> {
    Matrix4<TValueType> result(mat);
    result.setCol(3, Vector4<TValueType>(x, y, z, mat.getValue(3, 3)));
    return result;
  }

  static auto scale(Matrix4<TValueType> const &mat, TValueType x, TValueType y, TValueType z) -> Matrix4<TValueType> {
    Matrix4<TValueType> result(mat);
    result.setValue(0, 0, x);
    result.setValue(1, 1, y);
    result.setValue(2, 2, z);
    return result;
  }
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_TRANSFORM_HPP
