#ifndef SWAY_MATH_VECTOR4_HPP
#define SWAY_MATH_VECTOR4_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

#include <iomanip>  // setprecision

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
      data[Vector<TYPE, 3>::IDX_X], 
      data[Vector<TYPE, 3>::IDX_Y], 
      data[Vector<TYPE, 3>::IDX_Z], 
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
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setW(w);
  }

  auto add(const Vector4<TYPE> &vec) -> Vector4<TYPE> {
    return Vector4<TYPE>(
        this->getX() + vec.getX(), this->getY() + vec.getY(), this->getZ() + vec.getZ(), this->getW() + vec.getW());
  }

  auto operator+(const Vector4<TYPE> &vec) -> Vector4<TYPE> { return add(vec); }

  [[nodiscard]] auto subtract(const Vector4<TYPE> &vec) const -> Vector4<TYPE> {
    return Vector4<TYPE>(
        this->getX() - vec.getX(), this->getY() - vec.getY(), this->getZ() - vec.getZ(), this->getW() - vec.getW());
  }

  auto operator-(const Vector4<TYPE> &vec) -> Vector4<TYPE> { return subtract(vec); }

  auto operator-(const Vector4<TYPE> &vec) const -> Vector4<TYPE> { return subtract(vec); }

  auto operator-=(const Vector4<TYPE> &vec) -> Vector4<TYPE> & {
    *this = subtract(vec);
    return *this;
  }

  auto multiply(const Vector4<TYPE> &vec) const -> Vector4<TYPE> {
    return Vector4<TYPE>(
        this->getX() * vec.getX(), this->getY() * vec.getY(), this->getZ() * vec.getZ(), this->getW() * vec.getW());
  }

  auto operator*(const Vector4<TYPE> &vec) const -> Vector4<TYPE> { return multiply(vec); }

  auto multiply(TYPE scalar) const -> Vector4<TYPE> {
    return Vector4<TYPE>(this->getX() * scalar, this->getY() * scalar, this->getZ() * scalar, this->getW() * scalar);
  }

  auto operator*(TYPE scalar) const -> Vector4<TYPE> { return multiply(scalar); }

  auto operator*=(TYPE scalar) -> Vector4<TYPE> {
    *this = multiply(scalar);
    return *this;
  }

  auto divide(TYPE scalar) -> Vector4<TYPE> {
    return Vector4<TYPE>(this->getX() / scalar, this->getY() / scalar, this->getZ() / scalar, this->getW() / scalar);
  }

  auto operator/(TYPE scalar) -> Vector4<TYPE> { return divide(scalar); }

  auto operator/=(TYPE scalar) -> Vector4<TYPE> & {
    *this = divide(scalar);
    return *this;
  }

  friend auto operator<<(std::ostream &out, const Vector4<TYPE> &vec) -> std::ostream & {
    return out << std::fixed << std::setprecision(3) << "{"
               << "x:" << vec.getX() << ", "
               << "y:" << vec.getY() << ", "
               << "z:" << vec.getZ() << ", "
               << "w:" << vec.getW() << "}";
  }
};

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
