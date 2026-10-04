#ifndef SWAY_MATH_VECTOR3_HPP
#define SWAY_MATH_VECTOR3_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

#include <cmath>
#include <iomanip>
#include <ostream>
#include <type_traits>

namespace sway::math {

/**
 * @brief \~english Template class representing a vector with three components. \~russian Шаблонный класс представления
 * вектора из трех компонентов.
 */
template <typename TYPE>
class Vector3 final : public Vector<TYPE, 3> {
public:
#pragma region "Static methods"

  static auto from(std::array<TYPE, 4> data) {
    return Vector3<TYPE>(data[Vector<TYPE, 3>::IDX_X], data[Vector<TYPE, 3>::IDX_Y], data[Vector<TYPE, 3>::IDX_Z]);
  }

  static auto from(std::array<TYPE, 3> data) {
    return Vector3<TYPE>(data[Vector<TYPE, 3>::IDX_X], data[Vector<TYPE, 3>::IDX_Y], data[Vector<TYPE, 3>::IDX_Z]);
  }

  static auto normalize(const Vector3<TYPE> &vec) -> Vector3<TYPE> {
    static_assert(std::is_floating_point_v<TYPE>, "normalize is only defined for floating-point types");

    const TYPE len = vec.getLength();
    if (len > static_cast<TYPE>(0)) {
      return vec.multiply(static_cast<TYPE>(1) / len);
    }

    return Vector3<TYPE>();
  }

  static auto dot(const Vector3<TYPE> &lhs, const Vector3<TYPE> &rhs) -> TYPE {
    return (lhs.getX() * rhs.getX()) + (lhs.getY() * rhs.getY()) + (lhs.getZ() * rhs.getZ());
  }

#pragma endregion

#pragma region "Constructor(s) & Destructor"
  /** \~english @name Constructor(s) & Destructor */ /** \~russian @name Конструктор(ы) и Деструктор */
  /** @{ */

  /**
   * @brief \~english Constructor class. Initializes a new instance of the class with zero coordinates. \~russian
   * Конструктор класса. Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Vector3(TYPE, TYPE, TYPE)
   */
  Vector3()
      : Vector<TYPE, 3>() {}

  /**
   * \~english
   * @brief Constructor class. Initializes a new instance of the class with specified coordinates.
   * @param[in] x Component X vector.
   * @param[in] y Component Y vector.
   * @param[in] z Component Z vector.
   *
   * \~russian
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса с заданными координатами.
   * @param[in] x Компонент X вектора.
   * @param[in] y Компонент Y вектора.
   * @param[in] z Компонент Z вектора.
   *
   * \~
   * @sa Vector3()
   */
  Vector3(TYPE x, TYPE y, TYPE z) { set(x, y, z); }

  virtual ~Vector3() = default;

  /** @} */
#pragma endregion

  /**
   * @brief Получает значение X компонента.
   *
   * @sa getY() const,
   *     getZ() const
   */
  [[nodiscard]] auto getX() const -> TYPE { return this->data_[Vector<TYPE, 3>::IDX_X]; }

  void setX(TYPE val) { this->data_[Vector<TYPE, 3>::IDX_X] = val; }

  /**
   * @brief Получает значение Y компонента.
   *
   * @sa getX() const,
   *     getZ() const
   */
  [[nodiscard]] auto getY() const -> TYPE { return this->data_[Vector<TYPE, 3>::IDX_Y]; }

  void setY(TYPE val) { this->data_[Vector<TYPE, 3>::IDX_Y] = val; }

  /**
   * @brief Получает значение Z компонента.
   *
   * @sa getX() const,
   *     getY() const
   */
  [[nodiscard]] auto getZ() const -> TYPE { return this->data_[Vector<TYPE, 3>::IDX_Z]; }

  void setZ(TYPE val) { this->data_[Vector<TYPE, 3>::IDX_Z] = val; }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение X компонента.
   * @param[in] y Значение Y компонента.
   * @param[in] z Значение Z компонента.
   */
  void set(TYPE x, TYPE y, TYPE z) {
    setX(x);
    setY(y);
    setZ(z);
  }

  [[nodiscard]] auto getLengthSquared() const -> TYPE {
    return getX() * getX() + getY() * getY() + getZ() * getZ();
  }

  [[nodiscard]] auto getLength() const -> TYPE {
    return static_cast<TYPE>(std::sqrt(getLengthSquared()));
  }

  [[nodiscard]] auto add(const Vector3<TYPE> &vec) const -> Vector3<TYPE> {
    return Vector3<TYPE>(getX() + vec.getX(), getY() + vec.getY(), getZ() + vec.getZ());
  }

  auto operator+(const Vector3<TYPE> &vec) const -> Vector3<TYPE> { return add(vec); }

  auto operator+=(const Vector3<TYPE> &vec) -> Vector3<TYPE> & { return *this = add(vec); }

  [[nodiscard]] auto subtract(const Vector3<TYPE> &vec) const -> Vector3<TYPE> {
    return Vector3<TYPE>(getX() - vec.getX(), getY() - vec.getY(), getZ() - vec.getZ());
  }

  auto operator-(const Vector3<TYPE> &vec) const -> Vector3<TYPE> { return subtract(vec); }

  auto operator-=(const Vector3<TYPE> &vec) -> Vector3<TYPE> & {
    *this = subtract(vec);
    return *this;
  }

  auto multiply(const Vector3<TYPE> &vec) const -> Vector3<TYPE> {
    return Vector3<TYPE>(getX() * vec.getX(), getY() * vec.getY(), getZ() * vec.getZ());
  }

  auto operator*(const Vector3<TYPE> &vec) const -> Vector3<TYPE> { return multiply(vec); }

  auto operator*=(const Vector3<TYPE> &vec) -> Vector3<TYPE> & {
    *this = multiply(vec);
    return *this;
  }

  auto multiply(TYPE scalar) const -> Vector3<TYPE> {
    return Vector3<TYPE>(getX() * scalar, getY() * scalar, getZ() * scalar);
  }

  auto operator*(TYPE scalar) const -> Vector3<TYPE> { return multiply(scalar); }

  auto operator*=(TYPE scalar) -> Vector3<TYPE> & {
    *this = multiply(scalar);
    return *this;
  }

  [[nodiscard]] auto divide(const Vector3<TYPE> &vec) const -> Vector3<TYPE> {
    return Vector3<TYPE>(getX() / vec.getX(), getY() / vec.getY(), getZ() / vec.getZ());
  }

  auto operator/(const Vector3<TYPE> &vec) const -> Vector3<TYPE> { return divide(vec); }

  auto operator/=(const Vector3<TYPE> &vec) -> Vector3<TYPE> & {
    *this = *this / vec;
    return *this;
  }

  [[nodiscard]] auto divide(TYPE scalar) const -> Vector3<TYPE> {
    return Vector3<TYPE>(getX() / scalar, getY() / scalar, getZ() / scalar);
  }

  auto operator/(TYPE scalar) const -> Vector3<TYPE> { return divide(scalar); }

  auto operator/=(TYPE scalar) -> Vector3<TYPE> & {
    *this = divide(scalar);
    return *this;
  }

  friend auto operator<<(std::ostream &out, const Vector3<TYPE> &vec) -> std::ostream & {
    const auto flags = out.flags();
    const auto precision = out.precision();

    out << std::fixed << std::setprecision(3) 
        << "{x:" << vec.getX() << ", y:" << vec.getY() << ", z:" << vec.getZ() << "}";

    out.flags(flags);
    out.precision(precision);

    return out;
  }
};

/**
 * @brief Произведение вектора на скаляр (свободная функция).
 * 
 * @tparam TYPE 
 * @param[in] scalar 
 * @param[in] vec 
 * @return Vector3<TYPE> 
 */
template <typename TYPE>
inline auto operator*(TYPE scalar, const Vector3<TYPE> &vec) -> Vector3<TYPE> {
  return vec * scalar;
}

using vec3i_t = Vector3<i32_t>;
using vec3f_t = Vector3<f32_t>;
using vec3d_t = Vector3<f64_t>;

static const vec3i_t vec3i_zero(0, 0, 0);
static const vec3i_t vec3i_one(1, 1, 1);
static const vec3i_t vec3i_unitX(1, 0, 0);
static const vec3i_t vec3i_unitY(0, 1, 0);
static const vec3i_t vec3i_unitZ(0, 0, 1);

static const vec3f_t vec3f_zero(0.0F, 0.0F, 0.0F);
static const vec3f_t vec3f_one(1.0F, 1.0F, 1.0F);
static const vec3f_t vec3f_unitX(1.0F, 0.0F, 0.0F);
static const vec3f_t vec3f_unitY(0.0F, 1.0F, 0.0F);
static const vec3f_t vec3f_unitZ(0.0F, 0.0F, 1.0F);

static const vec3d_t vec3d_zero(0.0, 0.0, 0.0);
static const vec3d_t vec3d_one(1.0, 1.0, 1.0);
static const vec3d_t vec3d_unitX(1.0, 0.0, 0.0);
static const vec3d_t vec3d_unitY(0.0, 1.0, 0.0);
static const vec3d_t vec3d_unitZ(0.0, 0.0, 1.0);

}  // namespace sway::math

#endif  // SWAY_MATH_VECTOR3_HPP
