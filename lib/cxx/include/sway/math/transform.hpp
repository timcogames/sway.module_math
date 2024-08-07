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
template <typename TYPE>
class Transform {
public:
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
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_TRANSFORM_HPP
