#ifndef SWAY_MATH_VECTOR3_HPP
#define SWAY_MATH_VECTOR3_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/**
 * @brief Шаблонный класс представления вектора из трех компонентов.
 */
template <typename TValueType>
class Vector3 final : public Vector<TValueType, 3> {
public:
  static auto from(std::array<TValueType, 4> data) { return Vector3<TValueType>(data[0], data[1], data[2]); }

  static auto from(std::array<TValueType, 3> data) { return Vector3<TValueType>(data[0], data[1], data[2]); }

  static auto normalize(const Vector3<TValueType> &vec) -> Vector3<TValueType> {
    auto len = vec.getLengthSquared();
    if (len > (TValueType)0) {
      return vec.multiply((TValueType)1 / (TValueType)sqrt(len));
    }

    return Vector3<TValueType>();
  }

  static auto dot(const Vector3<TValueType> &lhs, const Vector3<TValueType> &rhs) -> f32_t {
    return (lhs.getX() * rhs.getX()) + (lhs.getY() * rhs.getY()) + (lhs.getZ() * rhs.getZ());
  }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Vector3(TValueType, TValueType, TValueType)
   */
  Vector3()
      : Vector<TValueType, 3>() {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] x Компонент X вектора.
   * @param[in] y Компонент Y вектора.
   * @param[in] z Компонент Z вектора.
   * @sa Vector3()
   */
  Vector3(TValueType x, TValueType y, TValueType z) { set(x, y, z); }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение X компонента.
   * @param[in] y Значение Y компонента.
   * @param[in] z Значение Z компонента.
   */
  void set(TValueType x, TValueType y, TValueType z) {
    this->data_[0] = x;
    this->data_[1] = y;
    this->data_[2] = z;
  }

  /**
   * @brief Получает значение X компонента.
   *
   * @sa getY() const,
   *     getZ() const
   */
  [[nodiscard]] auto getX() const -> TValueType { return this->data_[0]; }

  void setX(TValueType val) { this->data_[0] = val; }

  /**
   * @brief Получает значение Y компонента.
   *
   * @sa getX() const,
   *     getZ() const
   */
  [[nodiscard]] auto getY() const -> TValueType { return this->data_[1]; }

  void setY(TValueType val) { this->data_[1] = val; }

  /**
   * @brief Получает значение Z компонента.
   *
   * @sa getX() const,
   *     getY() const
   */
  [[nodiscard]] auto getZ() const -> TValueType { return this->data_[2]; }

  void setZ(TValueType val) { this->data_[2] = val; }

  auto getLengthSquared() const -> TValueType {
    return this->data_[0] * this->data_[0] + this->data_[1] * this->data_[1] + this->data_[2] * this->data_[2];
  }

  auto add(const Vector3<TValueType> &vec) -> Vector3<TValueType> {
    return Vector3<TValueType>(this->data_[0] + vec.getX(), this->data_[1] + vec.getY(), this->data_[2] + vec.getZ());
  }

  auto operator+(const Vector3<TValueType> &vec) -> Vector3<TValueType> { return add(vec); }

  auto operator+=(const Vector3<TValueType> &vec) -> Vector3<TValueType> & { return *this = add(vec); }

  [[nodiscard]] auto subtract(const Vector3<TValueType> &vec) const -> Vector3<TValueType> {
    return Vector3<TValueType>(this->data_[0] - vec.getX(), this->data_[1] - vec.getY(), this->data_[2] - vec.getZ());
  }

  auto operator-(const Vector3<TValueType> &vec) -> Vector3<TValueType> { return subtract(vec); }

  auto operator-(const Vector3<TValueType> &vec) const -> Vector3<TValueType> { return subtract(vec); }

  auto operator-=(const Vector3<TValueType> &vec) -> Vector3<TValueType> & {
    *this = subtract(vec);
    return *this;
  }

  auto multiply(const Vector3<TValueType> &vec) const -> Vector3<TValueType> {
    return Vector3<TValueType>(this->data_[0] * vec.getX(), this->data_[1] * vec.getY(), this->data_[2] * vec.getZ());
  }

  auto operator*(const Vector3<TValueType> &vec) const -> Vector3<TValueType> { return multiply(vec); }

  auto operator*=(const Vector3<TValueType> &vec) -> Vector3<TValueType> & {
    *this = multiply(vec);
    return *this;
  }

  auto multiply(TValueType scalar) const -> Vector3<TValueType> {
    return Vector3<TValueType>(this->data_[0] * scalar, this->data_[1] * scalar, this->data_[2] * scalar);
  }

  auto operator*(TValueType scalar) const -> Vector3<TValueType> { return multiply(scalar); }

  auto operator*=(TValueType scalar) -> Vector3<TValueType> & {
    *this = multiply(scalar);
    return *this;
  }

  auto divide(const Vector3<TValueType> &vec) -> Vector3<TValueType> {
    return Vector3<TValueType>(
        this->data_[0] /= vec.getX(), this->data_[1] /= vec.getY(), this->data_[2] /= vec.getZ());
  }

  auto operator/(const Vector3<TValueType> &vec) -> Vector3<TValueType> { return divide(vec); }

  auto operator/=(const Vector3<TValueType> &vec) -> Vector3<TValueType> & {
    *this = divide(vec);
    return *this;
  }

  auto divide(TValueType scalar) -> Vector3<TValueType> {
    return Vector3<TValueType>(this->data_[0] /= scalar, this->data_[1] /= scalar, this->data_[2] /= scalar);
  }

  auto operator/(TValueType scalar) -> Vector3<TValueType> { return divide(scalar); }

  auto operator/=(TValueType scalar) -> Vector3<TValueType> & {
    *this = divide(scalar);
    return *this;
  }
};

using vec3i_t = Vector3<s32_t>;
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

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_VECTOR3_HPP
