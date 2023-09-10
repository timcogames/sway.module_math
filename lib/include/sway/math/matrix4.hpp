#ifndef SWAY_MATH_MATRIX4_HPP
#define SWAY_MATH_MATRIX4_HPP

#include <sway/core.hpp>
#include <sway/math/matrix.hpp>
#include <sway/math/vector3.hpp>
#include <sway/math/vector4.hpp>

#include <array>
#include <string>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType>
class Vector4;

/**
 * @brief Шаблонный класс представления матрицы.
 */
template <typename TValueType>
class Matrix4 : public Matrix<TValueType, 4, 4> {
public:
  static auto transform(Matrix4<TValueType> lhs, const Vector4<TValueType> &rhs) -> Vector4<TValueType> {
    TValueType x, y, z, w;
    // clang-format off
    x = lhs.getValue(0, 0) * rhs.getX() +
        lhs.getValue(0, 1) * rhs.getY() +
        lhs.getValue(0, 2) * rhs.getZ() +
        lhs.getValue(0, 3) * rhs.getW();

    y = lhs.getValue(1, 0) * rhs.getX() +
        lhs.getValue(1, 1) * rhs.getY() +
        lhs.getValue(1, 2) * rhs.getZ() +
        lhs.getValue(1, 3) * rhs.getW();

    z = lhs.getValue(2, 0) * rhs.getX() +
        lhs.getValue(2, 1) * rhs.getY() +
        lhs.getValue(2, 2) * rhs.getZ() +
        lhs.getValue(2, 3) * rhs.getW();

    w = lhs.getValue(3, 0) * rhs.getX() +
        lhs.getValue(3, 1) * rhs.getY() +
        lhs.getValue(3, 2) * rhs.getZ() +
        lhs.getValue(3, 3) * rhs.getW();
    // clang-format on

    return Vector4<TValueType>(x, y, z, w);
  }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   */
  Matrix4() { makeIdentity(); }

  Matrix4(const Matrix<TValueType, 4, 4> &mat)
      : Matrix<TValueType, 4, 4>(mat) {}

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
    this->setValue(0, 0, (TValueType)1);
    this->setValue(1, 1, (TValueType)1);
    this->setValue(2, 2, (TValueType)1);
    this->setValue(3, 3, (TValueType)1);

    return *this;
  }

  auto inverse() const -> Matrix4<TValueType> {
    Matrix4<TValueType> mat(*this);
    Matrix4<TValueType> res;

    auto a00 = mat.getValue(0, 0);
    auto a01 = mat.getValue(0, 1);
    auto a02 = mat.getValue(0, 2);
    auto a03 = mat.getValue(0, 3);
    auto a10 = mat.getValue(1, 0);
    auto a11 = mat.getValue(1, 1);
    auto a12 = mat.getValue(1, 2);
    auto a13 = mat.getValue(1, 3);
    auto a20 = mat.getValue(2, 0);
    auto a21 = mat.getValue(2, 1);
    auto a22 = mat.getValue(2, 2);
    auto a23 = mat.getValue(2, 3);
    auto a30 = mat.getValue(3, 0);
    auto a31 = mat.getValue(3, 1);
    auto a32 = mat.getValue(3, 2);
    auto a33 = mat.getValue(3, 3);

    auto b00 = a00 * a11 - a01 * a10;
    auto b01 = a00 * a12 - a02 * a10;
    auto b02 = a00 * a13 - a03 * a10;
    auto b03 = a01 * a12 - a02 * a11;
    auto b04 = a01 * a13 - a03 * a11;
    auto b05 = a02 * a13 - a03 * a12;
    auto b06 = a20 * a31 - a21 * a30;
    auto b07 = a20 * a32 - a22 * a30;
    auto b08 = a20 * a33 - a23 * a30;
    auto b09 = a21 * a32 - a22 * a31;
    auto b10 = a21 * a33 - a23 * a31;
    auto b11 = a22 * a33 - a23 * a32;

    auto det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;
    if (det == 0.0F) {
      return res.makeZero();
    }

    det = 1.0F / det;

    res.setValue(0, 0, (a11 * b11 - a12 * b10 + a13 * b09) * det);
    res.setValue(0, 1, (a02 * b10 - a01 * b11 - a03 * b09) * det);
    res.setValue(0, 2, (a31 * b05 - a32 * b04 + a33 * b03) * det);
    res.setValue(0, 3, (a22 * b04 - a21 * b05 - a23 * b03) * det);
    res.setValue(1, 0, (a12 * b08 - a10 * b11 - a13 * b07) * det);
    res.setValue(1, 1, (a00 * b11 - a02 * b08 + a03 * b07) * det);
    res.setValue(1, 2, (a32 * b02 - a30 * b05 - a33 * b01) * det);
    res.setValue(1, 3, (a20 * b05 - a22 * b02 + a23 * b01) * det);
    res.setValue(2, 0, (a10 * b10 - a11 * b08 + a13 * b06) * det);
    res.setValue(2, 1, (a01 * b08 - a00 * b10 - a03 * b06) * det);
    res.setValue(2, 2, (a30 * b04 - a31 * b02 + a33 * b00) * det);
    res.setValue(2, 3, (a21 * b02 - a20 * b04 - a23 * b00) * det);
    res.setValue(3, 0, (a11 * b07 - a10 * b09 - a12 * b06) * det);
    res.setValue(3, 1, (a00 * b09 - a01 * b07 + a02 * b06) * det);
    res.setValue(3, 2, (a31 * b01 - a30 * b03 - a32 * b00) * det);
    res.setValue(3, 3, (a20 * b03 - a21 * b01 + a22 * b00) * det);

    return res;
  }

  [[nodiscard]] auto toStr() const -> std::string {
    std::stringstream stream;
    // clang-format off
    stream << std::fixed << std::setprecision(6) 
           << "mat4x4((" << this->getValue(0, 0) << ", " << this->getValue(1, 0) << ", " << this->getValue(2, 0) << ", " << this->getValue(3, 0) << "), "
           <<        "(" << this->getValue(0, 1) << ", " << this->getValue(1, 1) << ", " << this->getValue(2, 1) << ", " << this->getValue(3, 1) << "), "
           <<        "(" << this->getValue(0, 2) << ", " << this->getValue(1, 2) << ", " << this->getValue(2, 2) << ", " << this->getValue(3, 2) << "), "
           <<        "(" << this->getValue(0, 3) << ", " << this->getValue(1, 3) << ", " << this->getValue(2, 3) << ", " << this->getValue(3, 3) << "))";
    // clang-format on
    return stream.str();
  }

  auto operator*(const Matrix4<TValueType> &rhs) const -> const Matrix4<TValueType> {
    Matrix4<TValueType> mat(*this);
    mat.template multiply<4>(rhs.getData());
    return mat;
  }

  friend auto operator<<(std::ostream &out, const Matrix4<TValueType> &mat) -> std::ostream & {
    return out << mat.toStr();
  }
};

using mat4i_t = Matrix4<s32_t>;
using mat4f_t = Matrix4<f32_t>;
using mat4d_t = Matrix4<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_MATRIX4_HPP
