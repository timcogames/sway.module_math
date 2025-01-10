#ifndef SWAY_MATH_VECTOR3_HPP
#define SWAY_MATH_VECTOR3_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

#include <cmath>

NS_BEGIN_SWAY()
NS_BEGIN(math)

/**
 * @brief Шаблонный класс представления вектора из трех компонентов.
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
    auto len = vec.getLengthSquared();
    if (len > (TYPE)0) {
      return vec.multiply((TYPE)1 / (TYPE)sqrt(len));
    }

    return Vector3<TYPE>();
  }

  static auto dot(const Vector3<TYPE> &lhs, const Vector3<TYPE> &rhs) -> f32_t {
    return (lhs.getX() * rhs.getX()) + (lhs.getY() * rhs.getY()) + (lhs.getZ() * rhs.getZ());
  }

#pragma endregion

#pragma region "Ctors/Dtor"
  /** \~english @name Constructor & Destructor */ /** \~russian @name Конструктор и Деструктор */
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
    this->setX(x);
    this->setY(y);
    this->setZ(z);
  }

  auto getLengthSquared() const -> TYPE {
    return this->getX() * this->getX() + this->getY() * this->getY() + this->getZ() * this->getZ();
  }

  auto add(const Vector3<TYPE> &vec) -> Vector3<TYPE> {
    return Vector3<TYPE>(this->getX() + vec.getX(), this->getY() + vec.getY(), this->getZ() + vec.getZ());
  }

  auto operator+(const Vector3<TYPE> &vec) -> Vector3<TYPE> { return add(vec); }

  auto operator+=(const Vector3<TYPE> &vec) -> Vector3<TYPE> & { return *this = add(vec); }

  [[nodiscard]] auto subtract(const Vector3<TYPE> &vec) const -> Vector3<TYPE> {
    return Vector3<TYPE>(this->getX() - vec.getX(), this->getY() - vec.getY(), this->getZ() - vec.getZ());
  }

  auto operator-(const Vector3<TYPE> &vec) -> Vector3<TYPE> { return subtract(vec); }

  auto operator-(const Vector3<TYPE> &vec) const -> Vector3<TYPE> { return subtract(vec); }

  auto operator-=(const Vector3<TYPE> &vec) -> Vector3<TYPE> & {
    *this = subtract(vec);
    return *this;
  }

  auto multiply(const Vector3<TYPE> &vec) const -> Vector3<TYPE> {
    return Vector3<TYPE>(this->getX() * vec.getX(), this->getY() * vec.getY(), this->getZ() * vec.getZ());
  }

  auto operator*(const Vector3<TYPE> &vec) const -> Vector3<TYPE> { return multiply(vec); }

  auto operator*=(const Vector3<TYPE> &vec) -> Vector3<TYPE> & {
    *this = multiply(vec);
    return *this;
  }

  auto multiply(TYPE scalar) const -> Vector3<TYPE> {
    return Vector3<TYPE>(this->getX() * scalar, this->getY() * scalar, this->getZ() * scalar);
  }

  auto operator*(TYPE scalar) const -> Vector3<TYPE> { return multiply(scalar); }

  auto operator*=(TYPE scalar) -> Vector3<TYPE> & {
    *this = multiply(scalar);
    return *this;
  }

  auto divide(const Vector3<TYPE> &vec) -> Vector3<TYPE> {
    // clang-format off
    return {
      this->data_[Vector<TYPE, 3>::IDX_X] /= vec.getX(),
      this->data_[Vector<TYPE, 3>::IDX_Y] /= vec.getY(),
      this->data_[Vector<TYPE, 3>::IDX_Z] /= vec.getZ()
    };
    // clang-format on
  }

  auto operator/(const Vector3<TYPE> &vec) -> Vector3<TYPE> { return divide(vec); }

  auto operator/=(const Vector3<TYPE> &vec) -> Vector3<TYPE> & {
    *this = divide(vec);
    return *this;
  }

  auto divide(TYPE scalar) -> Vector3<TYPE> {
    // clang-format off
    return {
      this->data_[Vector<TYPE, 3>::IDX_X] /= scalar,
      this->data_[Vector<TYPE, 3>::IDX_Y] /= scalar,
      this->data_[Vector<TYPE, 3>::IDX_Z] /= scalar
    };
    // clang-format on
  }

  auto operator/(TYPE scalar) -> Vector3<TYPE> { return divide(scalar); }

  auto operator/=(TYPE scalar) -> Vector3<TYPE> & {
    *this = divide(scalar);
    return *this;
  }

  friend auto operator<<(std::ostream &out, const Vector3<TYPE> &vec) -> std::ostream & {
    return out << std::fixed << std::setprecision(3) << "{"
               << "x:" << vec.getX() << ", "
               << "y:" << vec.getY() << ", "
               << "z:" << vec.getZ() << "}";
  }
};

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

NS_END()  // namespace math
NS_END()  // namespace sway

#endif  // SWAY_MATH_VECTOR3_HPP
