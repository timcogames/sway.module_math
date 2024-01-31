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
  // clang-format off
  enum : u32_t { IDX_L = 0, IDX_T, IDX_R, IDX_B };
  enum : u32_t {
    IDX_TL = 0,
    IDX_TR,
    IDX_BL,
    IDX_BR
  };  // clang-format on

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
    data_[IDX_L] = x;
    data_[IDX_T] = y;
    data_[IDX_R] = x + w;
    data_[IDX_B] = y + h;
  }

  /**
   * @brief Устанавливает смещение прямоугольной области.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   */
  auto offset(TValueType x, TValueType y) -> Rect<TValueType> {
    data_[IDX_L] += x;
    data_[IDX_T] += y;
    data_[IDX_R] += x;
    data_[IDX_B] += y;

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
  void setL(TValueType x) { data_[IDX_L] = x; }

  auto getL() const -> TValueType { return data_[IDX_L]; }

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
  void setT(TValueType y) { data_[IDX_T] = y; }

  auto getT() const -> TValueType { return data_[IDX_T]; }

  void setR(TValueType w) { data_[IDX_R] = w; }

  auto getR() const -> TValueType { return data_[IDX_R]; }

  void setB(TValueType h) { data_[IDX_B] = h; }

  auto getB() const -> TValueType { return data_[IDX_B]; }

  /**
   * @brief Получает ширину прямоугольной области.
   *
   * @sa getL() const,
   *     getT() const,
   *     getR() const,
   *     getB() const,
   *     getH() const
   */
  auto getW() const -> TValueType { return data_[IDX_R] - data_[IDX_L]; }

  /**
   * @brief Получает высоту прямоугольной области.
   *
   * @sa getL() const,
   *     getT() const,
   *     getR() const,
   *     getB() const,
   *     getW() const
   */
  auto getH() const -> TValueType { return data_[IDX_B] - data_[IDX_T]; }

  [[nodiscard]]
  auto position() const -> Point<TValueType> {
    return Point<TValueType>(getL(), getT());
  }

  [[nodiscard]]
  auto size() const -> Size<TValueType> {
    return Size<TValueType>(getW(), getH());
  }

  [[nodiscard]]
  auto empty() const -> bool {
    return ((getW() <= (TValueType)0) || (getH() <= (TValueType)0));
  }

  [[nodiscard]]
  auto isValid() const -> bool {
    return ((data_[IDX_T] > data_[IDX_B]) || (data_[IDX_L] > data_[IDX_R])) ? false : false;
  }

  auto contains(const math::Point<TValueType> &point) const -> bool {
    return data_[IDX_L] <= point.getX() && data_[IDX_R] >= point.getX() && data_[IDX_T] <= point.getY() &&
           data_[IDX_B] >= point.getY();
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
