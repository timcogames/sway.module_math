#ifndef SWAY_MATH_MATRIX4_HPP
#define SWAY_MATH_MATRIX4_HPP

#include <sway/core.hpp>
#include <sway/math/vector4.hpp>

#include <array>

constexpr int MAXTRIX_SIZE = 16;

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType>
class TVector4;

/**
 * @brief Шаблонный класс представления матрицы.
 */
template <typename TValueType>
class Matrix4 final {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса.
   */
  Matrix4() { makeIdentity(); }

  /**
   * @brief Устанавливает новое значение элемента матрицы.
   *
   * @param[in] row Номер ряда.
   * @param[in] col Номер колонки.
   * @param[in] val Значения элемента матрицы.
   */
  void set(u32_t row, u32_t col, TValueType val) { values_[row * 4 + col] = val; }

  /**
   * @brief Получает значение элемента матрицы.
   *
   * @param[in] row Номер ряда.
   * @param[in] col Номер колонки.
   * @return Значения элемента.
   */
  auto get(u32_t row, u32_t col) const -> TValueType { return values_[row * 4 + col]; }

  /**
   * @brief Устанавливает новые значения элементов матрицы в указанном ряду.
   *
   * @param[in] nbr Номер ряда.
   * @param[in] val Значения для установки.
   * @sa setCol(u32_t, const TVector4<TValueType> &)
   */
  void setRow(u32_t nbr, const TVector4<TValueType> &val) {
    set(nbr, 0, value.getX());
    set(nbr, 1, value.getY());
    set(nbr, 2, value.getZ());
    set(nbr, 3, value.getW());
  }

  /**
   * @brief Получает значения элементов матрицы в указанном ряду.
   *
   * @param[in] nbr Номер ряда.
   * @return Значения элементов.
   * @sa getCol(u32_t) const
   */
  auto getRow(u32_t nbr) const -> TVector4<TValueType> {
    return TVector4<TValueType>(get(nbr, 0), get(nbr, 1), get(nbr, 2), get(nbr, 3));
  }

  /**
   * @brief Устанавливает новые значения элементов матрицы в указанной колонке.
   *
   * @param[in] nbr Номер колонки.
   * @param[in] val Значения для установки.
   * @sa setRow(u32_t, const TVector4<TValueType> &)
   */
  void setCol(u32_t nbr, const TVector4<TValueType> &val) {
    set(0, nbr, value.getX());
    set(1, nbr, value.getY());
    set(2, nbr, value.getZ());
    set(3, nbr, value.getW());
  }

  /**
   * @brief Получает значения элементов матрицы в указанной колонке.
   *
   * @param[in] nbr Номер колонки.
   * @return Значения элементов.
   * @sa getRow(u32_t) const
   */
  auto getCol(u32_t nbr) const -> TVector4<TValueType> {
    return TVector4<TValueType>(get(0, nbr), get(1, nbr), get(2, nbr), get(3, nbr));
  }

  /**
   * @brief Обнуляет все элементы матрицы.
   */
  auto makeZero() -> Matrix4<TValueType> & {
    values_.fill(0);
    return *this;
  }

  /**
   * @brief Приводит к единичной матрице.
   */
  auto makeIdentity() -> Matrix4<TValueType> & {
    makeZero();
    set(0, 0, (TValueType)1);
    set(1, 1, (TValueType)1);
    set(2, 2, (TValueType)1);
    set(3, 3, (TValueType)1);

    return *this;
  }

  auto get() -> std::array<TValueType, MAXTRIX_SIZE> { return values_; }

private:
  std::array<TValueType, MAXTRIX_SIZE> values_;  // Элементы матрицы.
};

using mat4i_t = Matrix4<s32_t>;
using mat4f_t = Matrix4<f32_t>;
using mat4d_t = Matrix4<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_MATRIX4_HPP
