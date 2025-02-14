#ifndef SWAY_MATH_COLOR_HPP
#define SWAY_MATH_COLOR_HPP

#include <sway/core.hpp>
#include <sway/math/vector4.hpp>

namespace sway::math {

template <typename TYPE>
class Vector4;

/**
 * @brief \~english Template class representing a color. \~russian Шаблонный класс представления цвета.
 */
template <typename TYPE>
class Color final {
public:
  enum : u32_t { IDX_R = 0, IDX_G, IDX_B, IDX_A };

#pragma region "Ctors/Dtor"

  /**
   * @brief \~english Default constructor. Initializes a new instance of the class. \~russian Конструктор класса.
   * Выполняет инициализацию нового экземпляра класса.
   *
   * @sa Color(TYPE, TYPE, TYPE, TYPE)
   */
  Color() {
    r_ = g_ = b_ = (TYPE)0;
    a_ = (TYPE)1;
  }

  /**
   * \~english
   * @brief Constructor class. Initializes a new instance of the class.
   * @param[in] r Value of the red color channel.
   * @param[in] g Value of the green color channel.
   * @param[in] b Value of the blue color channel.
   * @param[in] a Value of the alpha channel.
   *
   * \~russian
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса.
   * @param[in] r Значение канала красного цвета.
   * @param[in] g Значение канала зеленого цвета.
   * @param[in] b Значение канала синего цвета.
   * @param[in] a Значение альфа-канала.
   *
   * \~
   * @sa Color()
   */
  Color(TYPE r, TYPE g, TYPE b, TYPE a = (TYPE)1) { set(r, g, b, a); }

#pragma endregion

  /**
   * \~english
   * @brief Sets new values.
   * @param[in] r Value of the red color channel.
   * @param[in] g Value of the green color channel.
   * @param[in] b Value of the blue color channel.
   * @param[in] a Value of the alpha channel.
   *
   * \~russian
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
   * @brief \~english Returns the value of the red color channel. \~russian Получает значение канала красного цвета.
   *
   * @sa getG() const,
   *     getB() const,
   *     getA() const
   */
  [[nodiscard]] auto getR() const -> TYPE { return r_; }

  /**
   * @brief \~english Returns the value of the green color channel. \~russian Получает значение канала зеленого цвета.
   * @sa getR() const,
   *     getB() const,
   *     getA() const
   */
  [[nodiscard]] auto getG() const -> TYPE { return g_; }

  /**
   * @brief \~english Returns the value of the blue color channel. \~russian Получает значение канала синего цвета.
   *
   * @sa getR() const,
   *     getG() const,
   *     getA() const
   */
  [[nodiscard]] auto getB() const -> TYPE { return b_; }

  /**
   * @brief \~english Returns the value of the alpha channel. \~russian Получает значение альфа-канала.
   *
   * @sa getR() const,
   *     getG() const,
   *     getB() const
   */
  [[nodiscard]] auto getA() const -> TYPE { return a_; }

  /**
   * @brief \~english Converts to Vector4<TYPE> class. \~russian Преобразовывает в Vector4<TYPE> класс.
   */
  [[nodiscard]] auto asVec4() const -> Vector4<TYPE> { return Vector4<TYPE>(r_, g_, b_, a_); }

  auto add(const Color<TYPE> &vec) -> Color<TYPE> {
    return Color<TYPE>(this->r_ + vec.getR(), this->g_ + vec.getG(), this->b_ + vec.getB(), this->a_ + vec.getA());
  }

  auto operator+(const Color<TYPE> &vec) -> Color<TYPE> { return add(vec); }

  auto multiply(TYPE scalar) const -> Color<TYPE> {
    return Color<TYPE>(this->r_ * scalar, this->g_ * scalar, this->b_ * scalar, this->a_ * scalar);
  }

  auto operator*(TYPE scalar) const -> Color<TYPE> { return multiply(scalar); }

private:
  TYPE r_, g_, b_, a_;
};

using col4i_t = Color<i32_t>;
using col4f_t = Color<f32_t>;
using col4d_t = Color<f64_t>;

#define COL4F_WHITE math::col4f_t(1.0F, 1.0F, 1.0F, 1.0F)
#define COL4F_BLACK math::col4f_t(0.0F, 0.0F, 0.0F, 1.0F)
#define COL4F_RED math::col4f_t(1.0F, 0.0F, 0.0F, 1.0F)
#define COL4F_GREEN math::col4f_t(0.0F, 1.0F, 0.0F, 1.0F)
#define COL4F_BLUE math::col4f_t(0.0F, 0.0F, 1.0F, 1.0F)

}  // namespace sway::math

#endif  // SWAY_MATH_COLOR_HPP
