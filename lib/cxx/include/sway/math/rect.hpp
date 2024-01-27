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
   * @sa Rect(const std::array<TValueType, 4> &),
   *     Rect(TValueType, TValueType, TValueType, TValueType)
   */
  Rect() { data_.fill((TValueType)0); }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] data Данные координат.
   * @sa Rect(),
   *     Rect(TValueType, TValueType, TValueType, TValueType)
   */
  Rect(const std::array<TValueType, 4> &data) { set(data); }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   * @sa Rect(),
   *     Rect(const std::array<TValueType, 4> &)
   */
  Rect(TValueType x, TValueType y, TValueType w, TValueType h) { set(x, y, w, h); }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] data Значения координат.
   * @sa set(TValueType, TValueType, TValueType, TValueType)
   */
  void set(const std::array<TValueType, 4> &data) { data_ = data; }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   * @sa set(const std::array<TValueType, 4> &)
   */
  void set(TValueType x, TValueType y, TValueType w, TValueType h) {
    data_[0 /* L */] = x;
    data_[1 /* T */] = y;
    data_[2 /* R */] = x + w;
    data_[3 /* B */] = y + h;
  }

  /**
   * @brief Устанавливает смещение прямоугольной области.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   */
  auto offset(TValueType x, TValueType y) -> Rect<TValueType> {
    data_[0 /* L */] += x;
    data_[1 /* T */] += y;
    data_[2 /* R */] += x;
    data_[3 /* B */] += y;

    return *this;
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
  void setL(TValueType x) { data_[0 /* L */] = x; }

  auto getL() const -> TValueType { return data_[0 /* L */]; }

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
  void setT(TValueType y) { data_[1 /* T */] = y; }

  auto getT() const -> TValueType { return data_[1 /* T */]; }

  void setR(TValueType w) { data_[2 /* R */] = w; }

  auto getR() const -> TValueType { return data_[2 /* R */]; }

  void setB(TValueType h) { data_[3 /* B */] = h; }

  auto getB() const -> TValueType { return data_[3 /* B */]; }

  /**
   * @brief Получает ширину прямоугольной области.
   *
   * @sa getL() const,
   *     getT() const,
   *     getR() const,
   *     getB() const,
   *     getH() const
   */
  auto getW() const -> TValueType { return data_[2 /* R */] - data_[0 /* L */]; }

  /**
   * @brief Получает высоту прямоугольной области.
   *
   * @sa getL() const,
   *     getT() const,
   *     getR() const,
   *     getB() const,
   *     getW() const
   */
  auto getH() const -> TValueType { return data_[3 /* B */] - data_[1 /* T */]; }

  /**
   * @brief Преобразовывает в Size<TValueType> класс.
   */
  auto toSize() const -> Size<TValueType> { return Size<TValueType>(getW(), getH()); }

  [[nodiscard]]
  auto isEmpty() const -> bool {
    return ((getW() <= (TValueType)0) || (getH() <= (TValueType)0));
  }

  [[nodiscard]]
  auto isValid() const -> bool {
    return ((data_[1 /* T */] > data_[3 /* B */]) || (data_[0 /* L */] > data_[2 /* R */])) ? false : false;
  }

  auto contains(const math::Point<TValueType> &point) const -> bool {
    return data_[0 /* L */] <= point.getX() && data_[2 /* R */] >= point.getX() && data_[1 /* T */] <= point.getY() &&
           data_[3 /* B */] >= point.getY();
  }

private:
  std::array<TValueType, 4> data_;
};

using rect4i_t = Rect<s32_t>;
using rect4f_t = Rect<f32_t>;
using rect4d_t = Rect<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_RECT_HPP
