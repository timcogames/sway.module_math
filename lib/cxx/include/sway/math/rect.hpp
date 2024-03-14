#ifndef SWAY_MATH_RECT_HPP
#define SWAY_MATH_RECT_HPP

#include <sway/core.hpp>
#include <sway/math/border.hpp>
#include <sway/math/point.hpp>
#include <sway/math/rectedges.hpp>
#include <sway/math/size.hpp>
#include <sway/math/vector4.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType>
class Size;

/**
 * @brief Шаблонный класс представления прямоугольной области.
 */
template <typename TValueType>
class Rect final : public Vector4<TValueType> {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Rect(const std::array<TValueType, 4> &),
   *     Rect(TValueType, TValueType, TValueType, TValueType)
   */
  Rect()
      : Vector4<TValueType>() {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] data Данные координат.
   * @sa Rect(),
   *     Rect(TValueType, TValueType, TValueType, TValueType)
   */
  Rect(const std::array<TValueType, 4> &data)
      : Vector4<TValueType>(data) {}

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
  Rect(TValueType x, TValueType y, TValueType xw, TValueType yh)
      : Vector4<TValueType>(x, y, xw, yh) {}

  virtual ~Rect() = default;

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   * @sa set(const std::array<TValueType, 4> &)
   */
  void set(TValueType x, TValueType y, TValueType xw, TValueType yh) { Vector4<TValueType>::set(x, y, xw, yh); }

  void set(TValueType x, TValueType y, const Size<TValueType> &size) {
    this->set(x, y, x + size.getW(), y + size.getH());
  }

  /**
   * @brief Устанавливает смещение прямоугольной области.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   */
  auto offset(TValueType x, TValueType y) -> Rect<TValueType> {
    this->data_[RectEdge::IDX_L] += x;
    this->data_[RectEdge::IDX_T] += y;
    this->data_[RectEdge::IDX_R] += x;
    this->data_[RectEdge::IDX_B] += y;

    return *this;
  }

  auto offset(Point<TValueType> pos) -> Rect<TValueType> {
    this->offset(pos.getX(), pos.getY());
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
  void setL(TValueType x) { this->data_[RectEdge::IDX_L] = x; }

  auto getL() const -> TValueType { return this->data_[RectEdge::IDX_L]; }

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
  void setT(TValueType y) { this->data_[RectEdge::IDX_T] = y; }

  auto getT() const -> TValueType { return this->data_[RectEdge::IDX_T]; }

  void setR(TValueType w) { this->data_[RectEdge::IDX_R] = w; }

  auto getR() const -> TValueType { return this->data_[RectEdge::IDX_R]; }

  void setB(TValueType h) { this->data_[RectEdge::IDX_B] = h; }

  auto getB() const -> TValueType { return this->data_[RectEdge::IDX_B]; }

  /**
   * @brief Получает ширину прямоугольной области.
   *
   * @sa getL() const,
   *     getT() const,
   *     getR() const,
   *     getB() const,
   *     getH() const
   */
  auto getW() const -> TValueType { return this->data_[RectEdge::IDX_R] - this->data_[RectEdge::IDX_L]; }

  /**
   * @brief Получает высоту прямоугольной области.
   *
   * @sa getL() const,
   *     getT() const,
   *     getR() const,
   *     getB() const,
   *     getW() const
   */
  auto getH() const -> TValueType { return this->data_[RectEdge::IDX_B] - this->data_[RectEdge::IDX_T]; }

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
    // clang-format off
    return ((this->data_[RectEdge::IDX_T] > this->data_[RectEdge::IDX_B]) ||
            (this->data_[RectEdge::IDX_L] > this->data_[RectEdge::IDX_R])) ? false : false;
    // clang-format on
  }

  auto contains(const Point<TValueType> &point) const -> bool {
    return this->data_[RectEdge::IDX_L] <= point.getX() && this->data_[RectEdge::IDX_R] >= point.getX() &&
           this->data_[RectEdge::IDX_T] <= point.getY() && this->data_[RectEdge::IDX_B] >= point.getY();
  }

  void reduce(Border<TValueType> border) {
    this->data_[RectEdge::IDX_L] += border.getL();
    this->data_[RectEdge::IDX_T] += border.getT();
    this->data_[RectEdge::IDX_R] -= border.getL() + border.getR();
    this->data_[RectEdge::IDX_B] -= border.getT() + border.getB();
  }
};

using rect4i_t = Rect<s32_t>;
using rect4f_t = Rect<f32_t>;
using rect4d_t = Rect<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#include <sway/math/rect.inl>

#endif  // SWAY_MATH_RECT_HPP
