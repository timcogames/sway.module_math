#ifndef SWAY_MATH_RECT_HPP
#define SWAY_MATH_RECT_HPP

#include <sway/core.hpp>
#include <sway/math/point.hpp>
#include <sway/math/rectedges.hpp>
#include <sway/math/size.hpp>
#include <sway/math/utils.hpp>
#include <sway/math/vector4.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(math)

template <typename TYPE>
class Size;

/**
 * @brief Шаблонный класс представления прямоугольной области.
 */
template <typename TYPE>
class Rect final : public Vector4<TYPE> {
public:
#pragma region "Ctors/Dtor"

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Rect(const std::array<TYPE, 4> &),
   *     Rect(TYPE, TYPE, TYPE, TYPE)
   *     Rect(TYPE, TYPE, const Size<TYPE> &)
   */
  Rect()
      : Vector4<TYPE>() {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] data Данные координат.
   * @sa Rect(),
   *     Rect(TYPE, TYPE, TYPE, TYPE)
   *     Rect(TYPE, TYPE, const Size<TYPE> &)
   */
  Rect(const std::array<TYPE, 4> &data)
      : Vector4<TYPE>(data) {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] x Значение левой координаты по оси X.
   * @param[in] y Значение нижней/верхней (зависит от системы координат) координаты по оси Y.
   * @param[in] xw Значение правой координаты по оси X.
   * @param[in] yh Значение верхней/нижней (зависит от системы координат) координаты по оси Y.
   * @sa Rect(),
   *     Rect(const std::array<TYPE, 4> &),
   *     Rect(TYPE, TYPE, const Size<TYPE> &)
   */
  Rect(TYPE x, TYPE y, TYPE xw, TYPE yh)
      : Vector4<TYPE>(x, y, xw, yh) {}

  Rect(TYPE x, TYPE y, const Size<TYPE> &size)
      : Vector4<TYPE>(x, y, x + size.getW(), y + size.getH()) {}

  virtual ~Rect() = default;

#pragma endregion

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение левой координаты по оси X.
   * @param[in] y Значение нижней/верхней (зависит от системы кординат) координаты по оси Y.
   * @param[in] xw Значение правой координаты по оси X.
   * @param[in] yh Значение верхней/нижней (зависит от системы координат) координаты по оси Y.
   * @sa set(const std::array<TYPE, 4> &)
   */
  void set(TYPE x, TYPE y, TYPE xw, TYPE yh) { Vector4<TYPE>::set(x, y, xw, yh); }

  void set(TYPE x, TYPE y, const Size<TYPE> &size) { set(x, y, x + size.getW(), y + size.getH()); }

  auto at(RectEdge::Enum edge) const -> const TYPE & { return this->data_[core::detail::toBase(edge)]; }

  auto at(RectEdge::Enum edge) -> TYPE & { return this->data_[core::detail::toBase(edge)]; }

  /**
   * @brief Устанавливает смещение прямоугольной области.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   */
  auto offset(TYPE x, TYPE y) -> Rect<TYPE> {
    at(RectEdge::Enum::IDX_L) += x;
    at(RectEdge::Enum::IDX_T) += y;
    at(RectEdge::Enum::IDX_R) += x;
    at(RectEdge::Enum::IDX_B) += y;

    return *this;
  }

  auto offset(Point<TYPE> pos) -> Rect<TYPE> {
    offset(pos.getX(), pos.getY());
    return *this;
  }

  void reduce(const Rect<TYPE> &other) {
    at(RectEdge::Enum::IDX_L) += other.getL();
    at(RectEdge::Enum::IDX_T) += other.getT();
    at(RectEdge::Enum::IDX_R) -= other.getR();
    at(RectEdge::Enum::IDX_B) -= other.getB();
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
  void setL(TYPE x) { at(RectEdge::Enum::IDX_L) = x; }

  auto getL() const -> TYPE { return at(RectEdge::Enum::IDX_L); }

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
  void setT(TYPE y) { at(RectEdge::Enum::IDX_T) = y; }

  auto getT() const -> TYPE { return at(RectEdge::Enum::IDX_T); }

  void setR(TYPE w) { at(RectEdge::Enum::IDX_R) = w; }

  auto getR() const -> TYPE { return at(RectEdge::Enum::IDX_R); }

  void setB(TYPE h) { at(RectEdge::Enum::IDX_B) = h; }

  auto getB() const -> TYPE { return at(RectEdge::Enum::IDX_B); }

  /**
   * @brief Получает ширину прямоугольной области.
   *
   * @sa getL() const,
   *     getT() const,
   *     getR() const,
   *     getB() const,
   *     getH() const
   */
  auto getW() const -> TYPE {
    if ((getL() >= getR())) {
      return 0;
    }

    return util::abs(getR() - getL());
  }

  /**
   * @brief Получает высоту прямоугольной области.
   *
   * @sa getL() const,
   *     getT() const,
   *     getR() const,
   *     getB() const,
   *     getW() const
   */
  auto getH() const -> TYPE {
    if (getT() >= getB()) {
      return 0;
    }

    return util::abs(getB() - getT());
  }

  [[nodiscard]]
  auto asPoint() const -> Point<TYPE> {
    return Point<TYPE>(getL(), getT());
  }

  [[nodiscard]]
  auto asSize() const -> Size<TYPE> {
    return Size<TYPE>(getW(), getH());
  }

  [[nodiscard]]
  auto empty() const -> bool {
    return ((getW() <= (TYPE)0) || (getH() <= (TYPE)0));
  }

  [[nodiscard]]
  auto isValid() const -> bool {
    return ((getL() < getR()) && (getT() < getB())) ? true : false;
  }

  auto contains(const Point<TYPE> &point) const -> bool {
    return getL() <= point.getX() && getR() >= point.getX() && getT() <= point.getY() && getB() >= point.getY();
  }
};

using rect4i_t = Rect<i32_t>;
using rect4f_t = Rect<f32_t>;
using rect4d_t = Rect<f64_t>;

NS_END()  // namespace math
NS_END()  // namespace sway

#include <sway/math/rect.inl>

#endif  // SWAY_MATH_RECT_HPP
