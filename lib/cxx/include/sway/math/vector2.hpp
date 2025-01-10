#ifndef SWAY_MATH_VECTOR2_HPP
#define SWAY_MATH_VECTOR2_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(math)

/**
 * @brief \~english Template class representing a 2D vector. Class that holds position in 2D coordinates, allows to
 * manipulate them and perform vector operations. \~russian Шаблонный класс, представляющий двумерный вектор. Класс,
 * который хранит позицию в 2D-координатах, позволяет манипулировать ими, а также выполнять векторные операции.
 */
template <typename TYPE>
class Vector2 final : public Vector<TYPE, 2> {
public:
#pragma region "Static methods"

  static auto from(std::array<TYPE, 2> data) {
    return Vector2<TYPE>(data[Vector<TYPE, 2>::IDX_X], data[Vector<TYPE, 2>::IDX_Y]);
  }

#pragma endregion

#pragma region "Ctors/Dtor"

  /**
   * @brief \~english Constructor class. Initializes a new instance of the class with zero coordinates. \~russian
   * Конструктор класса. Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Vector2(TYPE, TYPE)
   */
  Vector2()
      : Vector<TYPE, 2>() {}

  /**
   * \~english
   * @brief Constructor class. Initializes a new instance of the class with specified coordinates.
   * @param[in] x Component X vector.
   * @param[in] y Component Y vector.
   *
   * \~russian
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса с заданными координатами.
   * @param[in] x Компонент X вектора.
   * @param[in] y Компонент Y вектора.
   *
   * \~
   * @sa Vector2()
   */
  Vector2(TYPE x, TYPE y) { set(x, y); }

  virtual ~Vector2() = default;

#pragma endregion

  /**
   * @brief Получает значение X компонента.
   *
   * @sa getY() const
   */
  [[nodiscard]] auto getX() const -> TYPE { return this->data_[Vector<TYPE, 2>::IDX_X]; }

  void setX(TYPE val) { this->data_[Vector<TYPE, 2>::IDX_X] = val; }

  /**
   * @brief Получает значение Y компонента.
   *
   * @sa getX() const
   */
  [[nodiscard]] auto getY() const -> TYPE { return this->data_[Vector<TYPE, 2>::IDX_Y]; }

  void setY(TYPE val) { this->data_[Vector<TYPE, 2>::IDX_Y] = val; }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение X компонента.
   * @param[in] y Значение Y компонента.
   */
  void set(TYPE x, TYPE y) {
    setX(x);
    setY(y);
  }

  auto add(const Vector2<TYPE> &vec) -> Vector2<TYPE> {
    return Vector2<TYPE>(getX() + vec.getX(), getY() + vec.getY());
  }

  auto operator+(const Vector2<TYPE> &vec) -> Vector2<TYPE> { return add(vec); }

  auto operator+=(const Vector2<TYPE> &vec) -> Vector2<TYPE> & { return *this = add(vec); }

  [[nodiscard]] auto subtract(const Vector2<TYPE> &vec) const -> Vector2<TYPE> {
    return Vector2<TYPE>(getX() - vec.getX(), getY() - vec.getY());
  }

  auto operator-(const Vector2<TYPE> &vec) -> Vector2<TYPE> { return subtract(vec); }

  auto operator-(const Vector2<TYPE> &vec) const -> Vector2<TYPE> { return subtract(vec); }

  auto operator-=(const Vector2<TYPE> &vec) -> Vector2<TYPE> & {
    *this = subtract(vec);
    return *this;
  }

  auto multiply(const Vector2<TYPE> &vec) const -> Vector2<TYPE> {
    return Vector2<TYPE>(getX() * vec.getX(), getY() * vec.getY());
  }

  auto operator*(const Vector2<TYPE> &vec) const -> Vector2<TYPE> { return multiply(vec); }

  auto operator*=(const Vector2<TYPE> &vec) -> Vector2<TYPE> & {
    *this = multiply(vec);
    return *this;
  }

  auto multiply(TYPE scalar) const -> Vector2<TYPE> { return Vector2<TYPE>(getX() * scalar, getY() * scalar); }

  auto operator*(TYPE scalar) const -> Vector2<TYPE> { return multiply(scalar); }

  auto operator*=(TYPE scalar) -> Vector2<TYPE> & {
    *this = multiply(scalar);
    return *this;
  }

  friend auto operator<<(std::ostream &out, const Vector2<TYPE> &vec) -> std::ostream & {
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

NS_END()  // namespace math
NS_END()  // namespace sway

#endif  // SWAY_MATH_VECTOR2_HPP
