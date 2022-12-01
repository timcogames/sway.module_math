#ifndef SWAY_MATH_VECTOR4_HPP
#define SWAY_MATH_VECTOR4_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/**
 * @brief Шаблонный класс представления вектора из четырех компонентов.
 */
template <typename TYPE>
class TVector4 final : public TVector<TYPE, 4> {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   * @sa TVector4(TYPE, TYPE, TYPE, TYPE)
   */
  TVector4()
      : TVector<TYPE, 4>() {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   * @param[in] x Компонент X вектора.
   * @param[in] y Компонент Y вектора.
   * @param[in] z Компонент Z вектора.
   * @param[in] w Компонент W вектора.
   * @sa TVector4()
   */
  TVector4(TYPE x, TYPE y, TYPE z, TYPE w) { set(x, y, z, w); }

  /**
   * @brief Устанавливает новые значения.
   * @param[in] x Значение X компонента.
   * @param[in] y Значение Y компонента.
   * @param[in] z Значение Z компонента.
   * @param[in] w Значение W компонента.
   */
  void set(TYPE x, TYPE y, TYPE z, TYPE w) {
    this->_data[0] = x;
    this->_data[1] = y;
    this->_data[2] = z;
    this->_data[3] = w;
  }

  /**
   * @brief Получает значение X компонента.
   * @sa getY() const
   *     getZ() const
   *     getW() const
   */
  TYPE getX() const { return this->_data[0]; }

  /**
   * @brief Получает значение Y компонента.
   * @sa getX() const
   *     getZ() const
   *     getW() const
   */
  TYPE getY() const { return this->_data[1]; }

  /**
   * @brief Получает значение Z компонента.
   * @sa getX() const
   *     getY() const
   *     getW() const
   */
  TYPE getZ() const { return this->_data[2]; }

  /**
   * @brief Получает значение W компонента.
   * @sa getX() const
   *     getY() const
   *     getZ() const
   */
  TYPE getW() const { return this->_data[3]; }
};

using vec4i_t = TVector4<s32_t>;
using vec4f_t = TVector4<f32_t>;
using vec4d_t = TVector4<f64_t>;

static const vec4i_t vec4i_zero(0, 0, 0, 0);
static const vec4i_t vec4i_one(1, 1, 1, 1);
static const vec4i_t vec4i_unitX(1, 0, 0, 0);
static const vec4i_t vec4i_unitY(0, 1, 0, 0);
static const vec4i_t vec4i_unitZ(0, 0, 1, 0);
static const vec4i_t vec4i_unitW(0, 0, 0, 1);

static const vec4f_t vec4f_zero(0.0, 0.0, 0.0, 0.0);
static const vec4f_t vec4f_one(1.0, 1.0, 1.0, 1.0);
static const vec4f_t vec4f_unitX(1.0, 0.0, 0.0, 0.0);
static const vec4f_t vec4f_unitY(0.0, 1.0, 0.0, 0.0);
static const vec4f_t vec4f_unitZ(0.0, 0.0, 1.0, 0.0);
static const vec4f_t vec4f_unitW(0.0, 0.0, 0.0, 1.0);

static const vec4d_t vec4d_zero(0.0, 0.0, 0.0, 0.0);
static const vec4d_t vec4d_one(1.0, 1.0, 1.0, 1.0);
static const vec4d_t vec4d_unitX(1.0, 0.0, 0.0, 0.0);
static const vec4d_t vec4d_unitY(0.0, 1.0, 0.0, 0.0);
static const vec4d_t vec4d_unitZ(0.0, 0.0, 1.0, 0.0);
static const vec4d_t vec4d_unitW(0.0, 0.0, 0.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_VECTOR4_HPP
