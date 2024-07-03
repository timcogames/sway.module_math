#ifndef SWAY_MATH_VECTOR4_HPP
#define SWAY_MATH_VECTOR4_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

#include <iomanip>  // setprecision

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/**
 * @brief Шаблонный класс представления вектора из четырех компонентов.
 */
template <typename TValueType>
class Vector4 : public Vector<TValueType, 4> {
public:
  static auto from(std::array<TValueType, 3> data, TValueType w) {
    // clang-format off
    return Vector4<TValueType>(
      data[Vector<TValueType, 3>::IDX_X], 
      data[Vector<TValueType, 3>::IDX_Y], 
      data[Vector<TValueType, 3>::IDX_Z], 
      w);
    // clang-format on
  }

  static auto from(std::array<TValueType, 4> data) {
    // clang-format off
    return Vector4<TValueType>(
      data[Vector<TValueType, 4>::IDX_X], 
      data[Vector<TValueType, 4>::IDX_Y], 
      data[Vector<TValueType, 4>::IDX_Z], 
      data[Vector<TValueType, 4>::IDX_W]);
    // clang-format on
  }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Vector4(TValueType, TValueType, TValueType, TValueType)
   */
  Vector4()
      : Vector<TValueType, 4>() {}

  Vector4(const std::array<TValueType, 4> &data)
      : Vector<TValueType, 4>(data) {}

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
  Vector4(TValueType x, TValueType y, TValueType z, TValueType w) { set(x, y, z, w); }

  virtual ~Vector4() = default;

  /**
   * @brief Получает значение X компонента.
   *
   * @sa getY() const,
   *     getZ() const,
   *     getW() const
   */
  [[nodiscard]]
  auto getX() const -> TValueType {
    return this->data_[Vector<TValueType, 4>::IDX_X];
  }

  void setX(TValueType val) { this->data_[Vector<TValueType, 4>::IDX_X] = val; }

  /**
   * @brief Получает значение Y компонента.
   *
   * @sa getX() const,
   *     getZ() const,
   *     getW() const
   */
  [[nodiscard]]
  auto getY() const -> TValueType {
    return this->data_[Vector<TValueType, 4>::IDX_Y];
  }

  void setY(TValueType val) { this->data_[Vector<TValueType, 4>::IDX_Y] = val; }

  /**
   * @brief Получает значение Z компонента.
   *
   * @sa getX() const,
   *     getY() const,
   *     getW() const
   */
  [[nodiscard]]
  auto getZ() const -> TValueType {
    return this->data_[Vector<TValueType, 4>::IDX_Z];
  }

  void setZ(TValueType val) { this->data_[Vector<TValueType, 4>::IDX_Z] = val; }

  /**
   * @brief Получает значение W компонента.
   *
   * @sa getX() const,
   *     getY() const,
   *     getZ() const
   */
  [[nodiscard]]
  auto getW() const -> TValueType {
    return this->data_[Vector<TValueType, 4>::IDX_W];
  }

  void setW(TValueType val) { this->data_[Vector<TValueType, 4>::IDX_W] = val; }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение X компонента.
   * @param[in] y Значение Y компонента.
   * @param[in] z Значение Z компонента.
   * @param[in] w Значение W компонента.
   */
  void set(TValueType x, TValueType y, TValueType z, TValueType w) {
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setW(w);
  }

  auto add(const Vector4<TValueType> &vec) -> Vector4<TValueType> {
    return Vector4<TValueType>(
        this->getX() + vec.getX(), this->getY() + vec.getY(), this->getZ() + vec.getZ(), this->getW() + vec.getW());
  }

  auto operator+(const Vector4<TValueType> &vec) -> Vector4<TValueType> { return add(vec); }

  [[nodiscard]]
  auto subtract(const Vector4<TValueType> &vec) const -> Vector4<TValueType> {
    return Vector4<TValueType>(
        this->getX() - vec.getX(), this->getY() - vec.getY(), this->getZ() - vec.getZ(), this->getW() - vec.getW());
  }

  auto operator-(const Vector4<TValueType> &vec) -> Vector4<TValueType> { return subtract(vec); }

  auto operator-(const Vector4<TValueType> &vec) const -> Vector4<TValueType> { return subtract(vec); }

  auto operator-=(const Vector4<TValueType> &vec) -> Vector4<TValueType> & {
    *this = subtract(vec);
    return *this;
  }

  auto multiply(const Vector4<TValueType> &vec) const -> Vector4<TValueType> {
    return Vector4<TValueType>(
        this->getX() * vec.getX(), this->getY() * vec.getY(), this->getZ() * vec.getZ(), this->getW() * vec.getW());
  }

  auto operator*(const Vector4<TValueType> &vec) const -> Vector4<TValueType> { return multiply(vec); }

  auto multiply(TValueType scalar) const -> Vector4<TValueType> {
    return Vector4<TValueType>(
        this->getX() * scalar, this->getY() * scalar, this->getZ() * scalar, this->getW() * scalar);
  }

  auto operator*(TValueType scalar) const -> Vector4<TValueType> { return multiply(scalar); }

  auto operator*=(TValueType scalar) -> Vector4<TValueType> {
    *this = multiply(scalar);
    return *this;
  }

  auto divide(TValueType scalar) -> Vector4<TValueType> {
    return Vector4<TValueType>(
        this->getX() / scalar, this->getY() / scalar, this->getZ() / scalar, this->getW() / scalar);
  }

  auto operator/(TValueType scalar) -> Vector4<TValueType> { return divide(scalar); }

  auto operator/=(TValueType scalar) -> Vector4<TValueType> & {
    *this = divide(scalar);
    return *this;
  }

  friend auto operator<<(std::ostream &out, const Vector4<TValueType> &vec) -> std::ostream & {
    return out << std::fixed << std::setprecision(3) << "{"
               << "x:" << vec.getX() << ", "
               << "y:" << vec.getY() << ", "
               << "z:" << vec.getZ() << ", "
               << "w:" << vec.getW() << "}";
  }
};

using vec4i_t = Vector4<s32_t>;
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

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_VECTOR4_HPP
