#ifndef SWAY_MATH_VECTOR2_HPP
#define SWAY_MATH_VECTOR2_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/**
 * @brief Шаблонный класс, представляющий двумерный вектор.
 *        Класс, который хранит позицию в 2D-координатах,
 *        позволяет манипулировать ими, а также выполнять векторные операции.
 */
template <typename TValueType>
class Vector2 final : public Vector<TValueType, 2> {
public:
  static auto from(std::array<TValueType, 2> data) {
    return Vector2<TValueType>(data[Vector<TValueType, 2>::IDX_X], data[Vector<TValueType, 2>::IDX_Y]);
  }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Vector2(TValueType, TValueType)
   */
  Vector2()
      : Vector<TValueType, 2>() {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] x Компонент X вектора.
   * @param[in] y Компонент Y вектора.
   * @sa Vector2()
   */
  Vector2(TValueType x, TValueType y) { set(x, y); }

  virtual ~Vector2() = default;

  /**
   * @brief Получает значение X компонента.
   *
   * @sa getY() const
   */
  [[nodiscard]]
  auto getX() const -> TValueType {
    return this->data_[Vector<TValueType, 2>::IDX_X];
  }

  void setX(TValueType val) { this->data_[Vector<TValueType, 2>::IDX_X] = val; }

  /**
   * @brief Получает значение Y компонента.
   *
   * @sa getX() const
   */
  [[nodiscard]]
  auto getY() const -> TValueType {
    return this->data_[Vector<TValueType, 2>::IDX_Y];
  }

  void setY(TValueType val) { this->data_[Vector<TValueType, 2>::IDX_Y] = val; }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение X компонента.
   * @param[in] y Значение Y компонента.
   */
  void set(TValueType x, TValueType y) {
    this->setX(x);
    this->setY(y);
  }

  auto add(const Vector2<TValueType> &vec) -> Vector2<TValueType> {
    return Vector2<TValueType>(this->getX() + vec.getX(), this->getY() + vec.getY());
  }

  auto operator+(const Vector2<TValueType> &vec) -> Vector2<TValueType> { return add(vec); }

  auto operator+=(const Vector2<TValueType> &vec) -> Vector2<TValueType> & { return *this = add(vec); }

  [[nodiscard]]
  auto subtract(const Vector2<TValueType> &vec) const -> Vector2<TValueType> {
    return Vector2<TValueType>(this->getX() - vec.getX(), this->getY() - vec.getY());
  }

  auto operator-(const Vector2<TValueType> &vec) -> Vector2<TValueType> { return subtract(vec); }

  auto operator-(const Vector2<TValueType> &vec) const -> Vector2<TValueType> { return subtract(vec); }

  auto operator-=(const Vector2<TValueType> &vec) -> Vector2<TValueType> & {
    *this = subtract(vec);
    return *this;
  }

  auto multiply(const Vector2<TValueType> &vec) const -> Vector2<TValueType> {
    return Vector2<TValueType>(this->getX() * vec.getX(), this->getY() * vec.getY());
  }

  auto operator*(const Vector2<TValueType> &vec) const -> Vector2<TValueType> { return multiply(vec); }

  auto operator*=(const Vector2<TValueType> &vec) -> Vector2<TValueType> & {
    *this = multiply(vec);
    return *this;
  }

  auto multiply(TValueType scalar) const -> Vector2<TValueType> {
    return Vector2<TValueType>(this->getX() * scalar, this->getY() * scalar);
  }

  auto operator*(TValueType scalar) const -> Vector2<TValueType> { return multiply(scalar); }

  auto operator*=(TValueType scalar) -> Vector2<TValueType> & {
    *this = multiply(scalar);
    return *this;
  }

  friend auto operator<<(std::ostream &out, const Vector2<TValueType> &vec) -> std::ostream & {
    return out << std::fixed << std::setprecision(3) << "{" << "x:" << vec.getX() << ", " << "y:" << vec.getY() << "}";
  }
};

using vec2i_t = Vector2<i32_t>;
using vec2f_t = Vector2<f32_t>;
using vec2d_t = Vector2<f64_t>;

// NOLINTBEGIN(readability-identifier-naming)
static const vec2i_t vec2i_zero(0, 0);
static const vec2i_t vec2i_one(1, 1);
static const vec2i_t vec2i_unitX(1, 0);
static const vec2i_t vec2i_unitY(0, 1);

static const vec2f_t vec2f_zero(0.0F, 0.0F);
static const vec2f_t vec2f_one(1.0F, 1.0F);
static const vec2f_t vec2f_unitX(1.0F, 0.0F);
static const vec2f_t vec2f_unitY(0.0F, 1.0F);

static const vec2d_t vec2d_zero(0.0, 0.0);
static const vec2d_t vec2d_one(1.0, 1.0);
static const vec2d_t vec2d_unitX(1.0, 0.0);
static const vec2d_t vec2d_unitY(0.0, 1.0);
// NOLINTEND(readability-identifier-naming)

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_VECTOR2_HPP
