#ifndef SWAY_MATH_COLOR_HPP
#define SWAY_MATH_COLOR_HPP

#include <sway/core.hpp>
#include <sway/math/vector4.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType>
class Vector4;

/**
 * @brief Шаблонный класс представления цвета.
 */
template <typename TValueType>
class Color final {
public:
  /**
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса.
   *
   * @sa Color(TValueType, TValueType, TValueType, TValueType)
   */
  Color() {
    r_ = g_ = b_ = (TValueType)0;
    a_ = (TValueType)1;
  }

  /**
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса.
   *
   * @param[in] r Значение канала красного цвета.
   * @param[in] g Значение канала зеленого цвета.
   * @param[in] b Значение канала синего цвета.
   * @param[in] a Значение альфа-канала.
   * @sa Color()
   */
  Color(TValueType r, TValueType g, TValueType b, TValueType a = (TValueType)1) { set(r, g, b, a); }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] r Значение канала красного цвета.
   * @param[in] g Значение канала зеленого цвета.
   * @param[in] b Значение канала синего цвета.
   * @param[in] a Значение альфа-канала.
   */
  void set(TValueType r, TValueType g, TValueType b, TValueType a = (TValueType)1) {
    r_ = r;
    g_ = g;
    b_ = b;
    a_ = a;
  }

  /**
   * @brief Получает значение канала красного цвета.
   *
   * @sa getG() const,
   *     getB() const,
   *     getA() const
   */
  [[nodiscard]] auto getR() const -> TValueType { return r_; }

  /**
   * @brief Получает значение канала зеленого цвета.
   * @sa getR() const,
   *     getB() const,
   *     getA() const
   */
  [[nodiscard]] auto getG() const -> TValueType { return g_; }

  /**
   * @brief Получает значение канала синего цвета.
   *
   * @sa getR() const,
   *     getG() const,
   *     getA() const
   */
  [[nodiscard]] auto getB() const -> TValueType { return b_; }

  /**
   * @brief Получает значение альфа-канала.
   *
   * @sa getR() const,
   *     getG() const,
   *     getB() const
   */
  [[nodiscard]] auto getA() const -> TValueType { return a_; }

  /**
   * @brief Преобразовывает в Vector4<TValueType> класс.
   */
  [[nodiscard]] auto toVec4() const -> Vector4<TValueType> { return Vector4<TValueType>(r_, g_, b_, a_); }

private:
  TValueType r_, g_, b_, a_;
};

using col4i_t = Color<s32_t>;
using col4f_t = Color<f32_t>;
using col4d_t = Color<f64_t>;

#define COL4F_WHITE math::col4f_t(1.0F, 1.0F, 1.0F, 1.0F)
#define COL4F_BLACK math::col4f_t(0.0F, 0.0F, 0.0F, 1.0F)
#define COL4F_RED math::col4f_t(1.0F, 0.0F, 0.0F, 1.0F)
#define COL4F_GREEN math::col4f_t(0.0F, 1.0F, 0.0F, 1.0F)
#define COL4F_BLUE math::col4f_t(0.0F, 0.0F, 1.0F, 1.0F)

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_COLOR_HPP
