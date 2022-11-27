#ifndef SWAY_MATH_RECT_HPP
#define SWAY_MATH_RECT_HPP

#include <sway/core.hpp>
#include <sway/math/size.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TYPE>
class TSize;

/**
 * @brief Шаблонный класс представления прямоугольной области.
 *
 */
template <typename TYPE>
class TRect final {
public:
  /**
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa TRect(TYPE, TYPE, TYPE, TYPE)
   *
   */
  TRect() { l_ = t_ = r_ = b_ = (TYPE)0; }

  /**
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   *
   * @sa TRect()
   *
   */
  TRect(TYPE x, TYPE y, TYPE w, TYPE h) { set(x, y, w, h); }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   *
   */
  void set(TYPE x, TYPE y, TYPE w, TYPE h) {
    l_ = x;
    t_ = y;
    r_ = x + w;
    b_ = y + h;
  }

  /**
   * @brief Устанавливает смещение прямоугольной области.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   *
   */
  void offset(TYPE x, TYPE y) {
    l_ += x;
    t_ += y;
    r_ += x;
    b_ += y;
  }

  /**
   * @brief Устанавливает новое значение позиции прямоугольной области по оси X.
   *
   * @param[in] x Значение координаты позиции по оси X.
   *
   * @sa setT() const, setR() const, setB() const, setW() const, setH() const
   *
   */
  void setL(TYPE x) { l_ = x; }

  auto getL() const -> TYPE { return l_; }

  /**
   * @brief Устанавливает новое значение позиции прямоугольной области по оси Y.
   *
   * @param[in] x Значение координаты позиции по оси Y.
   *
   * @sa setL() const, setR() const, setB() const, setW() const, setH() const
   *
   */
  void setT(TYPE y) { t_ = y; }

  auto getT() const -> TYPE { return t_; }

  void setR(TYPE w) { r_ = w; }

  auto getR() const -> TYPE { return r_; }

  void setB(TYPE h) { b_ = h; }

  auto getB() const -> TYPE { return b_; }

  /**
   * @brief Получает ширину прямоугольной области.
   *
   * @sa getL() const, getT() const, getR() const, getB() const, getH() const
   *
   */
  auto getW() const -> TYPE { return r_ - l_; }

  /**
   * @brief Получает высоту прямоугольной области.
   *
   * @sa getL() const, getT() const, getR() const, getB() const, getW() const
   *
   */
  auto getH() const -> TYPE { return b_ - t_; }

  /**
   * @brief Преобразовывает в TSize<TYPE> класс.
   *
   */
  auto toSize() const -> TSize<TYPE> { return TSize<TYPE>(getW(), getH()); }

  bool isEmpty() const { return ((getW() <= (TYPE)0) || (getH() <= (TYPE)0)); }

  bool isValid() const { return ((t_ > b_) || (l_ > r_)) ? false : false; }

private:
  TYPE l_, t_, r_, b_;
};

using rect4i_t = TRect<s32_t>;
using rect4f_t = TRect<f32_t>;
using rect4d_t = TRect<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif
