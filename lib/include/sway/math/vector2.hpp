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
template <typename TValueType>
class Vector2 final : public Vector<TValueType, 2> {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Vector2(TValueType, TValueType)
   */
  Vector2()
      : Vector<TValueType, 2>() {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] x Компонент X вектора.
   * @param[in] y Компонент Y вектора.
   * @sa Vector2()
   */
  Vector2(TValueType x, TValueType y) { set(x, y); }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение X компонента.
   * @param[in] y Значение Y компонента.
   */
  void set(TValueType x, TValueType y) {
    this->data_[0] = x;
    this->data_[1] = y;
  }

  /**
   * @brief Получает значение X компонента.
   *
   * @sa getY() const
   */
  auto getX() const -> TValueType { return this->data_[0]; }

  /**
   * @brief Получает значение Y компонента.
   *
   * @sa getX() const
   */
  auto getY() const -> TValueType { return this->data_[1]; }

#pragma region "Статические методы класса"

#pragma endregion
};

using vec2i_t = Vector2<s32_t>;
using vec2f_t = Vector2<f32_t>;
using vec2d_t = Vector2<f64_t>;

static const vec2i_t vec2i_zero(0, 0);
static const vec2i_t vec2i_one(1, 1);
static const vec2i_t vec2i_unitX(1, 0);
static const vec2i_t vec2i_unitY(0, 1);

static const vec2f_t vec2f_zero(0.0F, 0.0F);
static const vec2f_t vec2f_one(1.0F, 1.0F);
static const vec2f_t vec2f_unitX(1.0F, 0.0F);
static const vec2f_t vec2f_unitY(0.0F, 1.0F);

static const vec2d_t vec2d_zero(0.0, 0.0);
static const vec2d_t vec2d_one(1.0, 1.0);
static const vec2d_t vec2d_unitX(1.0, 0.0);
static const vec2d_t vec2d_unitY(0.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_VECTOR2_HPP
