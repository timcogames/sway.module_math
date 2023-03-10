#ifndef SWAY_MATH_MATRIX4_HPP
#define SWAY_MATH_MATRIX4_HPP

#include <sway/core.hpp>
#include <sway/math/matrix.hpp>
#include <sway/math/vector4.hpp>

#include <array>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType>
class Vector4;

/**
 * @brief Шаблонный класс представления матрицы.
 */
template <typename TValueType>
class Matrix4 final : public Matrix<4, 4, TValueType> {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   */
  Matrix4() { makeIdentity(); }

  /**
   * @brief Устанавливает новые значения элементов матрицы в указанном ряду.
   *
   * @param[in] nbr Номер ряда.
   * @param[in] val Значения для установки.
   * @sa setCol(u32_t, const Vector4<TValueType> &)
   */
  void setRow(u32_t nbr, const Vector4<TValueType> &val) {
    this->setValue(nbr, 0, val.getX());
    this->setValue(nbr, 1, val.getY());
    this->setValue(nbr, 2, val.getZ());
    this->setValue(nbr, 3, val.getW());
  }

  /**
   * @brief Получает значения элементов матрицы в указанном ряду.
   *
   * @param[in] nbr Номер ряда.
   * @return Значения элементов.
   * @sa getCol(u32_t) const
   */
  auto getRow(u32_t nbr) const -> Vector4<TValueType> {
    return Vector4<TValueType>(
        this->getValue(nbr, 0), this->getValue(nbr, 1), this->getValue(nbr, 2), this->getValue(nbr, 3));
  }

  /**
   * @brief Устанавливает новые значения элементов матрицы в указанной колонке.
   *
   * @param[in] nbr Номер колонки.
   * @param[in] val Значения для установки.
   * @sa setRow(u32_t, const Vector4<TValueType> &)
   */
  void setCol(u32_t nbr, const Vector4<TValueType> &val) {
    this->setValue(0, nbr, val.getX());
    this->setValue(1, nbr, val.getY());
    this->setValue(2, nbr, val.getZ());
    this->setValue(3, nbr, val.getW());
  }

  /**
   * @brief Получает значения элементов матрицы в указанной колонке.
   *
   * @param[in] nbr Номер колонки.
   * @return Значения элементов.
   * @sa getRow(u32_t) const
   */
  auto getCol(u32_t nbr) const -> Vector4<TValueType> {
    return Vector4<TValueType>(
        this->getValue(0, nbr), this->getValue(1, nbr), this->getValue(2, nbr), this->getValue(3, nbr));
  }

  /**
   * @brief Приводит к единичной матрице.
   */
  auto makeIdentity() -> Matrix4<TValueType> & {
    this->makeZero();
    this->setValue(0, 0, (TValueType)1);
    this->setValue(1, 1, (TValueType)1);
    this->setValue(2, 2, (TValueType)1);
    this->setValue(3, 3, (TValueType)1);

    return *this;
  }

  auto operator*(const Matrix4<TValueType> &mat) const -> const Matrix4<TValueType> {
    Matrix4<TValueType> result(*this);
    result.multiply(mat);
    return result;
  }
};

using mat4i_t = Matrix4<s32_t>;
using mat4f_t = Matrix4<f32_t>;
using mat4d_t = Matrix4<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_MATRIX4_HPP
