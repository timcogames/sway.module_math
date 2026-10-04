#ifndef SWAY_MATH_VECTOR4_HPP
#define SWAY_MATH_VECTOR4_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

#include <iomanip>  // setprecision
#include <ostream>

namespace sway::math {

/**
 * @brief \~english Template class representing a vector of four components. \~russian Шаблонный класс представления
 * вектора из четырех компонентов.
 */
template <typename TYPE>
class Vector4 : public Vector<TYPE, 4> {
public:
#pragma region "Static methods"

  static auto from(std::array<TYPE, 3> data, TYPE w) {
    // clang-format off
    return Vector4<TYPE>(
      data[Vector<TYPE, 4>::IDX_X], 
      data[Vector<TYPE, 4>::IDX_Y], 
      data[Vector<TYPE, 4>::IDX_Z], 
      w);
    // clang-format on
  }

  static auto from(std::array<TYPE, 4> data) {
    // clang-format off
    return Vector4<TYPE>(
      data[Vector<TYPE, 4>::IDX_X], 
      data[Vector<TYPE, 4>::IDX_Y], 
      data[Vector<TYPE, 4>::IDX_Z], 
      data[Vector<TYPE, 4>::IDX_W]);
    // clang-format on
  }

    static auto dot(const Vector4<TYPE> &lhs, const Vector4<TYPE> &rhs) -> TYPE {
      return (lhs.getX() * rhs.getX()) + (lhs.getY() * rhs.getY()) + (lhs.getZ() * rhs.getZ()) + (lhs.getW() * rhs.getW());
    }

#pragma endregion

#pragma region "Ctors/Dtor"

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Vector4(TYPE, TYPE, TYPE, TYPE)
   */
  Vector4()
      : Vector<TYPE, 4>() {}

  Vector4(const std::array<TYPE, 4> &data)
      : Vector<TYPE, 4>(data) {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] x Компонент X вектора.
   * @param[in] y Компонент Y вектора.
   * @param[in] z Компонент Z вектора.
   * @param[in] w Компонент W вектора.
   * @sa Vector4()
   */
  Vector4(TYPE x, TYPE y, TYPE z, TYPE w) { set(x, y, z, w); }

  virtual ~Vector4() = default;

#pragma endregion

  /**
   * @brief Получает значение X компонента.
   *
   * @sa getY() const,
   *     getZ() const,
   *     getW() const
   */
  [[nodiscard]] auto getX() const -> TYPE { return this->data_[Vector<TYPE, 4>::IDX_X]; }

  void setX(TYPE val) { this->data_[Vector<TYPE, 4>::IDX_X] = val; }

  /**
   * @brief Получает значение Y компонента.
   *
   * @sa getX() const,
   *     getZ() const,
   *     getW() const
   */
  [[nodiscard]] auto getY() const -> TYPE { return this->data_[Vector<TYPE, 4>::IDX_Y]; }

  void setY(TYPE val) { this->data_[Vector<TYPE, 4>::IDX_Y] = val; }

  /**
   * @brief Получает значение Z компонента.
   *
   * @sa getX() const,
   *     getY() const,
   *     getW() const
   */
  [[nodiscard]] auto getZ() const -> TYPE { return this->data_[Vector<TYPE, 4>::IDX_Z]; }

  void setZ(TYPE val) { this->data_[Vector<TYPE, 4>::IDX_Z] = val; }

  /**
   * @brief Получает значение W компонента.
   *
   * @sa getX() const,
   *     getY() const,
   *     getZ() const
   */
  [[nodiscard]] auto getW() const -> TYPE { return this->data_[Vector<TYPE, 4>::IDX_W]; }

  void setW(TYPE val) { this->data_[Vector<TYPE, 4>::IDX_W] = val; }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение X компонента.
   * @param[in] y Значение Y компонента.
   * @param[in] z Значение Z компонента.
   * @param[in] w Значение W компонента.
   */
  void set(TYPE x, TYPE y, TYPE z, TYPE w) {
    setX(x);
    setY(y);
    setZ(z);
    setW(w);
  }

  [[nodiscard]] auto getLengthSquared() const -> TYPE {
    return getX() * getX() + getY() * getY() + getZ() * getZ() + getW() * getW();
  }

  [[nodiscard]] auto getLength() const -> TYPE {
    return static_cast<TYPE>(std::sqrt(getLengthSquared()));
  }

  [[nodiscard]] auto add(const Vector4<TYPE> &vec) const -> Vector4<TYPE> {
    return Vector4<TYPE>(
        getX() + vec.getX(), getY() + vec.getY(), getZ() + vec.getZ(), getW() + vec.getW());
  }

  auto operator+(const Vector4<TYPE> &vec) const -> Vector4<TYPE> { return add(vec); }

  auto operator+=(const Vector4<TYPE> &vec) -> Vector4<TYPE> & {
    *this = add(vec);
    return *this;
  }

  [[nodiscard]] auto subtract(const Vector4<TYPE> &vec) const -> Vector4<TYPE> {
    return Vector4<TYPE>(
        getX() - vec.getX(), getY() - vec.getY(), getZ() - vec.getZ(), getW() - vec.getW());
  }

  auto operator-(const Vector4<TYPE> &vec) const -> Vector4<TYPE> { return subtract(vec); }

  auto operator-=(const Vector4<TYPE> &vec) -> Vector4<TYPE> & {
    *this = subtract(vec);
    return *this;
  }

  auto multiply(const Vector4<TYPE> &vec) const -> Vector4<TYPE> {
    return Vector4<TYPE>(
        getX() * vec.getX(), getY() * vec.getY(), getZ() * vec.getZ(), getW() * vec.getW());
  }

  auto operator*(const Vector4<TYPE> &vec) const -> Vector4<TYPE> { return multiply(vec); }

  auto operator*=(const Vector4<TYPE> &vec) -> Vector4<TYPE> & {
    *this = multiply(vec);
    return *this;
  }

  auto multiply(TYPE scalar) const -> Vector4<TYPE> {
    return Vector4<TYPE>(getX() * scalar, getY() * scalar, getZ() * scalar, getW() * scalar);
  }

  auto operator*(TYPE scalar) const -> Vector4<TYPE> { return multiply(scalar); }

  auto operator*=(TYPE scalar) -> Vector4<TYPE> & {
    *this = multiply(scalar);
    return *this;
  }

  [[nodiscard]] auto divide(TYPE scalar) const -> Vector4<TYPE> {
    return Vector4<TYPE>(getX() / scalar, getY() / scalar, getZ() / scalar, getW() / scalar);
  }

  auto operator/(TYPE scalar) const -> Vector4<TYPE> { return divide(scalar); }

  auto operator/=(TYPE scalar) -> Vector4<TYPE> & {
    *this = divide(scalar);
    return *this;
  }

  [[nodiscard]] auto divide(const Vector4<TYPE> &vec) const -> Vector4<TYPE> {
    return Vector4<TYPE>(
        getX() / vec.getX(), getY() / vec.getY(), getZ() / vec.getZ(), getW() / vec.getW());
  }

  auto operator/(const Vector4<TYPE> &vec) const -> Vector4<TYPE> { return divide(vec); }

  auto operator/=(const Vector4<TYPE> &vec) -> Vector4<TYPE> & { *this = *this / vec; return *this; }

  friend auto operator<<(std::ostream &out, const Vector4<TYPE> &vec) -> std::ostream & {
    const auto flags = out.flags();
    const auto precision = out.precision();

    out << std::fixed << std::setprecision(3)
        << "{x:" << vec.getX() << ", y:" << vec.getY() << ", z:" << vec.getZ() << ", w:" << vec.getW() << "}";

    out.flags(flags);
    out.precision(precision);

    return out;
  }
};

template <typename TYPE>
inline auto operator*(TYPE scalar, const Vector4<TYPE> &vec) -> Vector4<TYPE> {
  return vec * scalar;
}

using vec4i_t = Vector4<i32_t>;
using vec4f_t = Vector4<f32_t>;
using vec4d_t = Vector4<f64_t>;

static const vec4i_t vec4i_zero(0, 0, 0, 0);
static const vec4i_t vec4i_one(1, 1, 1, 1);
static const vec4i_t vec4i_unitX(1, 0, 0, 0);
static const vec4i_t vec4i_unitY(0, 1, 0, 0);
static const vec4i_t vec4i_unitZ(0, 0, 1, 0);
static const vec4i_t vec4i_unitW(0, 0, 0, 1);

static const vec4f_t vec4f_zero(0.0F, 0.0F, 0.0F, 0.0F);
static const vec4f_t vec4f_one(1.0F, 1.0F, 1.0F, 1.0F);
static const vec4f_t vec4f_unitX(1.0F, 0.0F, 0.0F, 0.0F);
static const vec4f_t vec4f_unitY(0.0F, 1.0F, 0.0F, 0.0F);
static const vec4f_t vec4f_unitZ(0.0F, 0.0F, 1.0F, 0.0F);
static const vec4f_t vec4f_unitW(0.0F, 0.0F, 0.0F, 1.0F);

static const vec4d_t vec4d_zero(0.0, 0.0, 0.0, 0.0);
static const vec4d_t vec4d_one(1.0, 1.0, 1.0, 1.0);
static const vec4d_t vec4d_unitX(1.0, 0.0, 0.0, 0.0);
static const vec4d_t vec4d_unitY(0.0, 1.0, 0.0, 0.0);
static const vec4d_t vec4d_unitZ(0.0, 0.0, 1.0, 0.0);
static const vec4d_t vec4d_unitW(0.0, 0.0, 0.0, 1.0);

}  // namespace sway::math

#endif  // SWAY_MATH_VECTOR4_HPP
