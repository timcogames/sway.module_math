#ifndef SWAY_MATH_COLOR_HPP
#define SWAY_MATH_COLOR_HPP

#include <sway/core.hpp>
#include <sway/math/vector4.hpp>
#include <sway/namespacemacros.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TYPE>
class TVector4;

/**
 * @brief Шаблонный класс представления цвета.
 */
template <typename TYPE>
class TColor final {
public:
  /**
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса.
   * @sa TColor(TYPE, TYPE, TYPE, TYPE)
   */
  TColor() {
    r_ = g_ = b_ = (TYPE)0;
    a_ = (TYPE)1;
  }

  /**
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса.
   * @param[in] r Значение канала красного цвета.
   * @param[in] g Значение канала зеленого цвета.
   * @param[in] b Значение канала синего цвета.
   * @param[in] a Значение альфа-канала.
   * @sa TColor()
   */
  TColor(TYPE r, TYPE g, TYPE b, TYPE a = (TYPE)1) { set(r, g, b, a); }

  /**
   * @brief Устанавливает новые значения.
   * @param[in] r Значение канала красного цвета.
   * @param[in] g Значение канала зеленого цвета.
   * @param[in] b Значение канала синего цвета.
   * @param[in] a Значение альфа-канала.
   */
  void set(TYPE r, TYPE g, TYPE b, TYPE a = (TYPE)1) {
    r_ = r;
    g_ = g;
    b_ = b;
    a_ = a;
  }

  /**
   * @brief Получает значение канала красного цвета.
   * @sa getG() const,
   *     getB() const,
   *     getA() const
   */
  auto getR() const -> TYPE { return r_; }

  /**
   * @brief Получает значение канала зеленого цвета.
   * @sa getR() const,
   *     getB() const,
   *     getA() const
   */
  auto getG() const -> TYPE { return g_; }

  /**
   * @brief Получает значение канала синего цвета.
   * @sa getR() const,
   *     getG() const,
   *     getA() const
   */
  auto getB() const -> TYPE { return b_; }

  /**
   * @brief Получает значение альфа-канала.
   * @sa getR() const,
   *     getG() const,
   *     getB() const
   */
  auto getA() const -> TYPE { return a_; }

  /**
   * @brief Преобразовывает в TVector4<TYPE> класс.
   */
  auto toVec4() const -> TVector4<TYPE> { return TVector4<TYPE>(r_, g_, b_, a_); }

private:
  TYPE r_, g_, b_, a_;
};

using col4i_t = TColor<s32_t>;
using col4f_t = TColor<f32_t>;
using col4d_t = TColor<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_COLOR_HPP
