#ifndef SWAY_MATH_RECT_HPP
#define SWAY_MATH_RECT_HPP

#include <sway/core.hpp>
#include <sway/math/margin.hpp>
#include <sway/math/point.hpp>
#include <sway/math/rectedges.hpp>
#include <sway/math/size.hpp>
#include <sway/math/utils.hpp>
#include <sway/math/vector4.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

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

  void set(TYPE x, TYPE y, const Size<TYPE> &size) { this->set(x, y, x + size.getW(), y + size.getH()); }

  /**
   * @brief Устанавливает смещение прямоугольной области.
   *
   * @param[in] x Значение координаты по оси X.
   * @param[in] y Значение координаты по оси Y.
   */
  auto offset(TYPE x, TYPE y) -> Rect<TYPE> {
    this->at(RectEdge::IDX_L) += x;
    this->at(RectEdge::IDX_T) += y;
    this->at(RectEdge::IDX_R) += x;
    this->at(RectEdge::IDX_B) += y;

    return *this;
  }

  auto offset(Point<TYPE> pos) -> Rect<TYPE> {
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
  void setL(TYPE x) { this->at(RectEdge::IDX_L) = x; }

  auto getL() const -> TYPE { return this->at(RectEdge::IDX_L); }

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
  void setT(TYPE y) { this->at(RectEdge::IDX_T) = y; }

  auto getT() const -> TYPE { return this->at(RectEdge::IDX_T); }

  void setR(TYPE w) { this->at(RectEdge::IDX_R) = w; }

  auto getR() const -> TYPE { return this->at(RectEdge::IDX_R); }

  void setB(TYPE h) { this->at(RectEdge::IDX_B) = h; }

  auto getB() const -> TYPE { return this->at(RectEdge::IDX_B); }

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
    if ((this->at(RectEdge::IDX_L) >= this->at(RectEdge::IDX_R))) {
      return 0;
    }

    return util::abs(this->at(RectEdge::IDX_R) - this->at(RectEdge::IDX_L));
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
    if (this->at(RectEdge::IDX_T) >= this->at(RectEdge::IDX_B)) {
      return 0;
    }

    return util::abs(this->at(RectEdge::IDX_B) - this->at(RectEdge::IDX_T));
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
    // clang-format off
    return ((this->at(RectEdge::IDX_L) < this->at(RectEdge::IDX_R)) && 
            (this->at(RectEdge::IDX_T) < this->at(RectEdge::IDX_B))) ? true : false;
    // clang-format on
  }

  auto contains(const Point<TYPE> &point) const -> bool {
    return this->at(RectEdge::IDX_L) <= point.getX() && this->at(RectEdge::IDX_R) >= point.getX() &&
           this->at(RectEdge::IDX_T) <= point.getY() && this->at(RectEdge::IDX_B) >= point.getY();
  }

  void reduce(Margin<TYPE> margin) {
    this->at(RectEdge::IDX_L) += margin.getL();
    this->at(RectEdge::IDX_T) += margin.getT();
    this->at(RectEdge::IDX_R) -= margin.getR();
    this->at(RectEdge::IDX_B) -= margin.getB();
  }

  auto at(RectEdge edge) const -> const TYPE & { return this->data_[core::detail::toBase(edge)]; }

  auto at(RectEdge edge) -> TYPE & { return this->data_[core::detail::toBase(edge)]; }
};

using rect4i_t = Rect<i32_t>;
using rect4f_t = Rect<f32_t>;
using rect4d_t = Rect<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#include <sway/math/rect.inl>

#endif  // SWAY_MATH_RECT_HPP
