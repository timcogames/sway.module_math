#ifndef SWAY_MATH_POINT_HPP
#define SWAY_MATH_POINT_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/**
 * @brief Шаблонный класс представления точки.
 */
template <typename TValueType>
class Point {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Point(TValueType),
   *     Point(TValueType, TValueType)
   */
  Point() { set((TValueType)0, (TValueType)0); }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] scalar Значение для координат по оси X и Y.
   * @sa Point(),
   *     Point(TValueType, TValueType)
   */
  Point(TValueType scalar) { set(scalar, scalar); }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   * @sa Point(),
   *     Point(TValueType)
   */
  Point(TValueType x, TValueType y) { set(x, y); }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   */
  void set(TValueType x, TValueType y) {
    x_ = x;
    y_ = y;
  }

  /**
   * @brief Устанавливает новое значение координаты по оси X.
   *
   * @param[in] x Значение координаты по оси X.
   * @sa setY() const
   */
  void setX(TValueType x) { x_ = x; }

  /**
   * @brief Получает значение координаты по оси X.
   *
   * @sa getY() const
   */
  auto getX() const -> TValueType { return x_; }

  /**
   * @brief Устанавливает новое значение координаты по оси Y.
   *
   * @param[in] y Значение координаты по оси Y.
   * @sa setX() const
   */
  void setY(TValueType y) { y_ = y; }

  /**
   * @brief Получает значение координаты по оси Y.
   *
   * @sa getX() const
   */
  auto getY() const -> TValueType { return y_; }

  /**
   * @brief Оператор равенства.
   */
  template <typename TOther>
  auto operator==(const Point<TOther> &compare) const -> bool {
    return x_ == compare.getX() && y_ == compare.getY();
  }

  /**
   * @brief Оператор неравенства.
   */
  template <typename TOther>
  auto operator!=(const Point<TOther> &compare) const -> bool {
    return !operator==(compare);
  }

protected:
  TValueType x_, y_;
};

using point2i_t = Point<s32_t>;
using point2f_t = Point<f32_t>;
using point2d_t = Point<f64_t>;

static const point2i_t point2i_zero(0, 0);
static const point2i_t point2i_one(1, 1);

static const point2f_t point2f_zero(0.0F, 0.0F);
static const point2f_t point2f_one(1.0F, 1.0F);

static const point2d_t point2d_zero(0.0, 0.0);
static const point2d_t point2d_one(1.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_POINT_HPP
