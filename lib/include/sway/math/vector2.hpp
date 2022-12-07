#ifndef SWAY_MATH_VECTOR2_HPP
#define SWAY_MATH_VECTOR2_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/**
 * @brief Шаблонный класс, представляющий двумерный вектор.
 *        Класс, который хранит позицию в 2D-координатах,
 *        позволяет манипулировать ими, а также выполнять векторные операции.
 */
template <typename TYPE>
class TVector2 final : public TVector<TYPE, 2> {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa TVector2(TYPE, TYPE)
   */
  TVector2()
      : TVector<TYPE, 2>() {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] x Компонент X вектора.
   * @param[in] y Компонент Y вектора.
   * @sa TVector2()
   */
  TVector2(TYPE x, TYPE y) { set(x, y); }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение X компонента.
   * @param[in] y Значение Y компонента.
   */
  void set(TYPE x, TYPE y) {
    this->_data[0] = x;
    this->_data[1] = y;
  }

  /**
   * @brief Получает значение X компонента.
   *
   * @sa getY() const
   */
  TYPE getX() const { return this->_data[0]; }

  /**
   * @brief Получает значение Y компонента.
   *
   * @sa getX() const
   */
  TYPE getY() const { return this->_data[1]; }

#pragma region "Статические методы класса"

#pragma endregion
};

using vec2i_t = TVector2<s32_t>;
using vec2f_t = TVector2<f32_t>;
using vec2d_t = TVector2<f64_t>;

static const vec2i_t vec2i_zero(0, 0);
static const vec2i_t vec2i_one(1, 1);
static const vec2i_t vec2i_unitX(1, 0);
static const vec2i_t vec2i_unitY(0, 1);

static const vec2f_t vec2f_zero(0.0, 0.0);
static const vec2f_t vec2f_one(1.0, 1.0);
static const vec2f_t vec2f_unitX(1.0, 0.0);
static const vec2f_t vec2f_unitY(0.0, 1.0);

static const vec2d_t vec2d_zero(0.0, 0.0);
static const vec2d_t vec2d_one(1.0, 1.0);
static const vec2d_t vec2d_unitX(1.0, 0.0);
static const vec2d_t vec2d_unitY(0.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_VECTOR2_HPP
