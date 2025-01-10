#ifndef SWAY_MATH_POINT_HPP
#define SWAY_MATH_POINT_HPP

#include <sway/core.hpp>
#include <sway/math/vector2.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(math)

/**
 * @brief Шаблонный класс представления точки.
 */
template <typename TYPE>
class Point {
public:
#pragma region "Ctors/Dtor"

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Point(TYPE),
   *     Point(TYPE, TYPE)
   */
  Point() { set((TYPE)0, (TYPE)0); }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] scalar Значение для координат по оси X и Y.
   * @sa Point(),
   *     Point(TYPE, TYPE)
   */
  Point(TYPE scalar) { set(scalar, scalar); }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   * @sa Point(),
   *     Point(TYPE)
   */
  Point(TYPE x, TYPE y) { set(x, y); }

#pragma endregion

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   */
  void set(TYPE x, TYPE y) {
    x_ = x;
    y_ = y;
  }

  /**
   * @brief Устанавливает новое значение координаты по оси X.
   *
   * @param[in] x Значение координаты по оси X.
   * @sa setY() const
   */
  void setX(TYPE x) { x_ = x; }

  /**
   * @brief Получает значение координаты по оси X.
   *
   * @sa getY() const
   */
  [[nodiscard]] auto getX() const -> TYPE { return x_; }

  /**
   * @brief Устанавливает новое значение координаты по оси Y.
   *
   * @param[in] y Значение координаты по оси Y.
   * @sa setX() const
   */
  void setY(TYPE y) { y_ = y; }

  /**
   * @brief Получает значение координаты по оси Y.
   *
   * @sa getX() const
   */
  [[nodiscard]] auto getY() const -> TYPE { return y_; }

  [[nodiscard]] auto asVec() const -> Vector2<TYPE> { return Vector2<TYPE>(x_, y_); }

  /**
   * @brief Оператор равенства.
   */
  template <typename OTHER>
  auto operator==(const Point<OTHER> &compare) const -> bool {
    return x_ == compare.getX() && y_ == compare.getY();
  }

  /**
   * @brief Оператор неравенства.
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

NS_END()  // namespace math
NS_END()  // namespace sway

#endif  // SWAY_MATH_POINT_HPP
