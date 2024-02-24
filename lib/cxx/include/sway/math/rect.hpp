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
class Rect final : public Vector<TValueType, 4> {
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
  Rect()
      : Vector<TValueType, 4>() {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] data Данные координат.
   * @sa Rect(),
   *     Rect(TValueType, TValueType, TValueType, TValueType)
   */
  Rect(const std::array<TValueType, 4> &data)
      : Vector<TValueType, 4>(data) {}

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
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   * @sa set(const std::array<TValueType, 4> &)
   */
  void set(TValueType x, TValueType y, TValueType w, TValueType h) {
    this->data_[IDX_L] = x;
    this->data_[IDX_T] = y;
    this->data_[IDX_R] = x + w;
    this->data_[IDX_B] = y + h;
  }

  void set(TValueType x, TValueType y, const Size<TValueType> &size) {
    this->data_[IDX_L] = x;
    this->data_[IDX_T] = y;
    this->data_[IDX_R] = x + size.getW();
    this->data_[IDX_B] = y + size.getH();
  }

  /**
   * @brief Устанавливает смещение прямоугольной области.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   */
  auto offset(TValueType x, TValueType y) -> Rect<TValueType> {
    this->data_[IDX_L] += x;
    this->data_[IDX_T] += y;
    this->data_[IDX_R] += x;
    this->data_[IDX_B] += y;

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
  void setL(TValueType x) { this->data_[IDX_L] = x; }

  auto getL() const -> TValueType { return this->data_[IDX_L]; }

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
  void setT(TValueType y) { this->data_[IDX_T] = y; }

  auto getT() const -> TValueType { return this->data_[IDX_T]; }

  void setR(TValueType w) { this->data_[IDX_R] = w; }

  auto getR() const -> TValueType { return this->data_[IDX_R]; }

  void setB(TValueType h) { this->data_[IDX_B] = h; }

  auto getB() const -> TValueType { return this->data_[IDX_B]; }

  /**
   * @brief Получает ширину прямоугольной области.
   *
   * @sa getL() const,
   *     getT() const,
   *     getR() const,
   *     getB() const,
   *     getH() const
   */
  auto getW() const -> TValueType { return this->data_[IDX_R] - this->data_[IDX_L]; }

  /**
   * @brief Получает высоту прямоугольной области.
   *
   * @sa getL() const,
   *     getT() const,
   *     getR() const,
   *     getB() const,
   *     getW() const
   */
  auto getH() const -> TValueType { return this->data_[IDX_B] - this->data_[IDX_T]; }

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
    return ((this->data_[IDX_T] > this->data_[IDX_B]) || (this->data_[IDX_L] > this->data_[IDX_R])) ? false : false;
  }

  auto contains(const math::Point<TValueType> &point) const -> bool {
    return this->data_[IDX_L] <= point.getX() && this->data_[IDX_R] >= point.getX() &&
           this->data_[IDX_T] <= point.getY() && this->data_[IDX_B] >= point.getY();
  }

  friend auto operator<<(std::ostream &out, const Rect<TValueType> &rect) -> std::ostream & {
    return out << std::fixed << std::setprecision(6) << "{"
               << "x: " << rect.getX() << ","
               << "y: " << rect.getY() << ","
               << "w: " << rect.getZ() << ","
               << "h: " << rect.getW() << "}";
  }
};

using rect4i_t = Rect<s32_t>;
using rect4f_t = Rect<f32_t>;
using rect4d_t = Rect<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_RECT_HPP
