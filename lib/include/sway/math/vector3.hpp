#ifndef SWAY_MATH_VECTOR3_HPP
#define SWAY_MATH_VECTOR3_HPP

#include <sway/core.hpp>
#include <sway/math/vector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/**
 * @brief Шаблонный класс представления вектора из трех компонентов.
 */
template <typename TValueType>
class Vector3 final : public Vector<TValueType, 3> {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
   *
   * @sa Vector3(TValueType, TValueType, TValueType)
   */
  Vector3()
      : Vector<TValueType, 3>() {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными координатами.
   *
   * @param[in] x Компонент X вектора.
   * @param[in] y Компонент Y вектора.
   * @param[in] z Компонент Z вектора.
   * @sa Vector3()
   */
  Vector3(TValueType x, TValueType y, TValueType z) { set(x, y, z); }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] x Значение X компонента.
   * @param[in] y Значение Y компонента.
   * @param[in] z Значение Z компонента.
   */
  void set(TValueType x, TValueType y, TValueType z) {
    this->data_[0] = x;
    this->data_[1] = y;
    this->data_[2] = z;
  }

  /**
   * @brief Получает значение X компонента.
   *
   * @sa getY() const,
   *     getZ() const
   */
  auto getX() const -> TValueType { return this->data_[0]; }

  /**
   * @brief Получает значение Y компонента.
   *
   * @sa getX() const,
   *     getZ() const
   */
  auto getY() const -> TValueType { return this->data_[1]; }

  /**
   * @brief Получает значение Z компонента.
   *
   * @sa getX() const,
   *     getY() const
   */
  auto getZ() const -> TValueType { return this->data_[2]; }

  auto add(const Vector3<TValueType> &vec) const -> Vector3<TValueType> {
    return Vector3<TValueType>(this->data_[0] + vec.getX(), this->data_[1] + vec.getY(), this->data_[2] + vec.getZ());
  }

  auto operator+(const Vector3<TValueType> &vec) const -> Vector3<TValueType> { return add(vec); }

  auto operator+=(const Vector3<TValueType> &vec) -> Vector3<TValueType> & { return *this = add(vec); }
};

using vec3i_t = Vector3<s32_t>;
using vec3f_t = Vector3<f32_t>;
using vec3d_t = Vector3<f64_t>;

static const vec3i_t vec3i_zero(0, 0, 0);
static const vec3i_t vec3i_one(1, 1, 1);
static const vec3i_t vec3i_unitX(1, 0, 0);
static const vec3i_t vec3i_unitY(0, 1, 0);
static const vec3i_t vec3i_unitZ(0, 0, 1);

static const vec3f_t vec3f_zero(0.0F, 0.0F, 0.0F);
static const vec3f_t vec3f_one(1.0F, 1.0F, 1.0F);
static const vec3f_t vec3f_unitX(1.0F, 0.0F, 0.0F);
static const vec3f_t vec3f_unitY(0.0F, 1.0F, 0.0F);
static const vec3f_t vec3f_unitZ(0.0F, 0.0F, 1.0F);

static const vec3d_t vec3d_zero(0.0, 0.0, 0.0);
static const vec3d_t vec3d_one(1.0, 1.0, 1.0);
static const vec3d_t vec3d_unitX(1.0, 0.0, 0.0);
static const vec3d_t vec3d_unitY(0.0, 1.0, 0.0);
static const vec3d_t vec3d_unitZ(0.0, 0.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_VECTOR3_HPP
