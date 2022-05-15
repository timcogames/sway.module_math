#ifndef SWAY_MATH_RECT_HPP
#define SWAY_MATH_RECT_HPP

#include <sway/core.hpp>
#include <sway/math/size.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TYPE>
class TSize;

/*!
 * \brief
 *    Шаблонный класс представления прямоугольной области.
 */
template <typename TYPE>
class TRect final {
public:
  /*!
   * \brief
   *    Конструктор класса.
   *    Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * \sa
   *    TRect(TYPE, TYPE, TYPE, TYPE)
   */
  TRect() { _l = _t = _r = _b = (TYPE)0; }

  /*!
   * \brief
   *    Конструктор класса.
   *    Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * \param[in] x
   *    Значение координаты по оси X.
   *
   * \param[in] y
   *    Значение координаты по оси Y.
   *
   * \param[in] w
   *    Значение ширины.
   *
   * \param[in] h
   *    Значение высоты.
   *
   * \sa
   *    TRect()
   */
  TRect(TYPE x, TYPE y, TYPE w, TYPE h) { set(x, y, w, h); }

  /*!
   * \brief
   *    Устанавливает новые значения.
   *
   * \param[in] x
   *    Значение координаты по оси X.
   *
   * \param[in] y
   *    Значение координаты по оси Y.
   *
   * \param[in] w
   *    Значение ширины.
   *
   * \param[in] h
   *    Значение высоты.
   */
  void set(TYPE x, TYPE y, TYPE w, TYPE h) {
    _l = x;
    _t = y;
    _r = x + w;
    _b = y + h;
  }

  /*!
   * \brief
   *    Устанавливает смещение прямоугольной области.
   *
   * \param[in] x
   *    Значение координаты по оси X.
   *
   * \param[in] y
   *    Значение координаты по оси Y.
   */
  void offset(TYPE x, TYPE y) {
    _l += x;
    _t += y;
    _r += x;
    _b += y;
  }

  /*!
   * \brief
   *    Устанавливает новое значение позиции прямоугольной области по оси X.
   *
   * \param[in] x
   *    Значение координаты позиции по оси X.
   *
   * \sa
   *    setT() const
   *    setR() const
   *    setB() const
   *    setW() const
   *    setH() const
   */
  void setL(TYPE x) { _l = x; }

  TYPE getL() const { return _l; }

  /*!
   * \brief
   *    Устанавливает новое значение позиции прямоугольной области по оси Y.
   *
   * \param[in] x
   *    Значение координаты позиции по оси Y.
   *
   * \sa
   *    setL() const
   *    setR() const
   *    setB() const
   *    setW() const
   *    setH() const
   */
  void setT(TYPE y) { _t = y; }

  TYPE getT() const { return _t; }

  void setR(TYPE w) { _r = w; }

  TYPE getR() const { return _r; }

  void setB(TYPE h) { _b = h; }

  TYPE getB() const { return _b; }

  /*!
   * \brief
   *    Получает ширину прямоугольной области.
   *
   * \sa
   *    getL() const
   *    getT() const
   *    getR() const
   *    getB() const
   *    getH() const
   */
  TYPE getW() const { return _r - _l; }

  /*!
   * \brief
   *    Получает высоту прямоугольной области.
   *
   * \sa
   *    getL() const
   *    getT() const
   *    getR() const
   *    getB() const
   *    getW() const
   */
  TYPE getH() const { return _b - _t; }

  /*!
   * \brief
   *    Преобразовывает в TSize<TYPE> класс.
   */
  TSize<TYPE> toSize() const { return TSize<TYPE>(getW(), getH()); }

  bool isEmpty() const { return ((getW() <= (TYPE)0) || (getH() <= (TYPE)0)); }

  bool isValid() const { return ((_t > _b) || (_l > _r)) ? false : false; }

private:
  TYPE _l, _t, _r, _b;
};

using rect4i_t = TRect<s32_t>;
using rect4f_t = TRect<f32_t>;
using rect4d_t = TRect<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif
