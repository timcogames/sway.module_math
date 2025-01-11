#ifndef SWAY_MATH_POINT_HPP
#define SWAY_MATH_POINT_HPP

#include <sway/core.hpp>
#include <sway/math/vector2.hpp>

namespace sway::math {

/**
 * @brief \~english Template class representing a point. \~russian Шаблонный класс представления точки.
 */
template <typename TYPE>
class Point {
public:
#pragma region "Ctors/Dtor"

  /**
   * @brief \~english Default constructor. Initializes a new instance of the class. \~russian Конструктор класса.
   * Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Point(TYPE),
   *     Point(TYPE, TYPE)
   */
  Point() { set((TYPE)0, (TYPE)0); }

  /**
   * \~english
   * @brief Constructor class. Initializes a new instance of the class with the specified coordinates.
   * @param[in] scalar Value for coordinates on the X and Y axes.
   *
   * \~russian
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса с заданными координатами.
   * @param[in] scalar Значение для координат по оси X и Y.
   *
   * \~
   * @sa Point(),
   *     Point(TYPE, TYPE)
   */
  Point(TYPE scalar) { set(scalar, scalar); }

  /**
   * \~english
   * @brief Constructor class. Initializes a new instance of the class with the specified coordinates.
   * @param[in] x Value of the coordinate on the X axis.
   * @param[in] y Value of the coordinate on the Y axis.
   *
   * \~russian
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса с заданными координатами.
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   *
   * \~
   * @sa Point(),
   *     Point(TYPE)
   */
  Point(TYPE x, TYPE y) { set(x, y); }

#pragma endregion

  /**
   * \~english
   * @brief Sets new values.
   * @param[in] x Value of the coordinate on the X axis.
   * @param[in] y Value of the coordinate on the Y axis.
   *
   * \~russian
   * @brief Устанавливает новые значения.
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   */
  void set(TYPE x, TYPE y) {
    x_ = x;
    y_ = y;
  }

  /**
   * \~english
   * @brief Sets a new value of the coordinate on the X axis.
   * @param[in] x Value of the coordinate on the X axis.
   *
   * \~russian
   * @brief Устанавливает новое значение координаты по оси X.
   * @param[in] x Значение координаты по оси X.
   *
   * \~
   * @sa setY() const
   */
  void setX(TYPE x) { x_ = x; }

  /**
   * @brief \~english Gets the value of the coordinate on the X axis. \~russian Получает значение координаты по оси X.
   *
   * @sa getY() const
   */
  [[nodiscard]] auto getX() const -> TYPE { return x_; }

  /**
   * \~english
   * @brief Sets a new value of the coordinate on the Y axis.
   * @param[in] y Value of the coordinate on the Y axis.
   *
   * \~russian
   * @brief Устанавливает новое значение координаты по оси Y.
   * @param[in] y Значение координаты по оси Y.
   *
   * \~
   * @sa setX() const
   */
  void setY(TYPE y) { y_ = y; }

  /**
   * @brief \~english Gets the value of the coordinate on the Y axis. \~russian Получает значение координаты по оси Y.
   *
   * @sa getX() const
   */
  [[nodiscard]] auto getY() const -> TYPE { return y_; }

  [[nodiscard]] auto asVec() const -> Vector2<TYPE> { return Vector2<TYPE>(x_, y_); }

  /**
   * @brief \~english Returns a value indicating whether this instance is equal to a specified object. \~russian
   * Возвращает значение, указывающее, равен ли этот экземпляр указанному объекту.
   */
  template <typename OTHER>
  auto operator==(const Point<OTHER> &compare) const -> bool {
    return x_ == compare.getX() && y_ == compare.getY();
  }

  /**
   * @brief \~english Returns a value indicating whether this instance is not equal to a specified object. \~russian
   * Возвращает значение, указывающее, не равен ли этот экземпляр указанному объекту.
   */
  template <typename OTHER>
  auto operator!=(const Point<OTHER> &compare) const -> bool {
    return !operator==(compare);
  }

  friend auto operator<<(std::ostream &out, const Point<TYPE> &pt2) -> std::ostream & {
    return out << std::fixed << std::setprecision(3) << "{x:" << pt2.getX() << ", y:" << pt2.getY() << "}";
  }

protected:
  TYPE x_, y_;
};

using point2i_t = Point<i32_t>;
using point2f_t = Point<f32_t>;
using point2d_t = Point<f64_t>;

static const point2i_t point2i_zero(0, 0);
static const point2i_t point2i_one(1, 1);

static const point2f_t point2f_zero(0.0F, 0.0F);
static const point2f_t point2f_one(1.0F, 1.0F);

static const point2d_t point2d_zero(0.0, 0.0);
static const point2d_t point2d_one(1.0, 1.0);

}  // namespace sway::math

#endif  // SWAY_MATH_POINT_HPP
