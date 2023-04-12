#ifndef SWAY_MATH_RECT_HPP
#define SWAY_MATH_RECT_HPP

#include <sway/core.hpp>
#include <sway/math/point.hpp>
#include <sway/math/size.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType>
class Size;

/**
 * @brief Шаблонный класс представления прямоугольной области.
 */
template <typename TValueType>
class Rect final {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Rect(TValueType, TValueType, TValueType, TValueType)
   */
  Rect() { left_ = top_ = right_ = bottom_ = (TValueType)0; }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   * @sa Rect()
   */
  Rect(TValueType x, TValueType y, TValueType w, TValueType h) { set(x, y, w, h); }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   */
  void set(TValueType x, TValueType y, TValueType w, TValueType h) {
    left_ = x;
    top_ = y;
    right_ = x + w;
    bottom_ = y + h;
  }

  /**
   * @brief Устанавливает смещение прямоугольной области.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   */
  void offset(TValueType x, TValueType y) {
    left_ += x;
    top_ += y;
    right_ += x;
    bottom_ += y;
  }

  /**
   * @brief Устанавливает новое значение позиции прямоугольной области по оси X.
   *
   * @param[in] x Значение координаты позиции по оси X.
   * @sa setT() const,
   *     setR() const,
   *     setB() const,
   *     setW() const,
   *     setH() const
   */
  void setL(TValueType x) { left_ = x; }

  auto getL() const -> TValueType { return left_; }

  /**
   * @brief Устанавливает новое значение позиции прямоугольной области по оси Y.
   *
   * @param[in] x Значение координаты позиции по оси Y.
   * @sa setL() const,
   *     setR() const,
   *     setB() const,
   *     setW() const,
   *     setH() const
   */
  void setT(TValueType y) { top_ = y; }

  auto getT() const -> TValueType { return top_; }

  void setR(TValueType w) { right_ = w; }

  auto getR() const -> TValueType { return right_; }

  void setB(TValueType h) { bottom_ = h; }

  auto getB() const -> TValueType { return bottom_; }

  /**
   * @brief Получает ширину прямоугольной области.
   *
   * @sa getL() const,
   *     getT() const,
   *     getR() const,
   *     getB() const,
   *     getH() const
   */
  auto getW() const -> TValueType { return right_ - left_; }

  /**
   * @brief Получает высоту прямоугольной области.
   *
   * @sa getL() const,
   *     getT() const,
   *     getR() const,
   *     getB() const,
   *     getW() const
   */
  auto getH() const -> TValueType { return bottom_ - top_; }

  /**
   * @brief Преобразовывает в Size<TValueType> класс.
   */
  auto toSize() const -> Size<TValueType> { return Size<TValueType>(getW(), getH()); }

  [[nodiscard]] auto isEmpty() const -> bool { return ((getW() <= (TValueType)0) || (getH() <= (TValueType)0)); }

  [[nodiscard]] auto isValid() const -> bool { return ((top_ > bottom_) || (left_ > right_)) ? false : false; }

  auto contains(const math::Point<TValueType> &point) const -> bool {
    return left_ <= point.getX() && right_ >= point.getX() && top_ <= point.getY() && bottom_ >= point.getY();
  }

private:
  TValueType left_, top_, right_, bottom_;
};

using rect4i_t = Rect<s32_t>;
using rect4f_t = Rect<f32_t>;
using rect4d_t = Rect<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_RECT_HPP
