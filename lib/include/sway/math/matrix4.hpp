#ifndef SWAY_MATH_MATRIX4_HPP
#define SWAY_MATH_MATRIX4_HPP

#include <sway/core.hpp>
#include <sway/math/vector4.hpp>

#include <array>

constexpr int MAXTRIX_SIZE = 16;

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TYPE>
class TVector4;

/**
 * @brief Шаблонный класс представления матрицы.
 *
 */
template <typename TYPE>
class TMatrix4 final {
public:
  /**
   * @brief Конструктор класса. Выполняет инициализацию нового экземпляра класса.
   *
   */
  TMatrix4() { makeIdentity(); }

  /**
   * @brief Устанавливает новое значение элемента матрицы.
   *
   * @param[in] row Номер ряда.
   * @param[in] col Номер колонки.
   * @param[in] value Значения для установки.
   *
   */
  void set(u32_t row, u32_t col, TYPE value) { values_[row * 4 + col] = value; }

  /**
   * @brief Получает значение элемента матрицы.
   *
   * @param[in] row Номер ряда.
   * @param[in] col Номер колонки.
   *
   * @return Значения элемента.
   *
   */
  auto get(u32_t row, u32_t col) const -> TYPE { return values_[row * 4 + col]; }

  /**
   * @brief Устанавливает новые значения элементов матрицы в указанном ряду.
   *
   * @param[in] nbr Номер ряда.
   * @param[in] value Значения для установки.
   *
   * @sa setCol(u32_t, const TVector4<TYPE> &)
   *
   */
  void setRow(u32_t nbr, const TVector4<TYPE> &value) {
    set(nbr, 0, value.getX());
    set(nbr, 1, value.getY());
    set(nbr, 2, value.getZ());
    set(nbr, 3, value.getW());
  }

  /**
   * @brief Получает значения элементов матрицы в указанном ряду.
   *
   * @param[in] nbr Номер ряда.
   *
   * @return Значения элементов.
   *
   * @sa TVector4<TYPE> getCol(u32_t) const
   *
   */
  auto getRow(u32_t nbr) const -> TVector4<TYPE> {
    return TVector4<TYPE>(get(nbr, 0), get(nbr, 1), get(nbr, 2), get(nbr, 3));
  }

  /**
   * @brief Устанавливает новые значения элементов матрицы в указанной колонке.
   *
   * @param[in] nbr Номер колонки.
   * @param[in] value Значения для установки.
   *
   * @sa setRow(u32_t, const TVector4<TYPE> &)
   *
   */
  void setCol(u32_t nbr, const TVector4<TYPE> &value) {
    set(0, nbr, value.getX());
    set(1, nbr, value.getY());
    set(2, nbr, value.getZ());
    set(3, nbr, value.getW());
  }

  /**
   * @brief Получает значения элементов матрицы в указанной колонке.
   *
   * @param[in] nbr Номер колонки.
   *
   * @return Значения элементов.
   *
   * @sa TVector4<TYPE> getRow(u32_t) const
   *
   */
  auto getCol(u32_t nbr) const -> TVector4<TYPE> {
    return TVector4<TYPE>(get(0, nbr), get(1, nbr), get(2, nbr), get(3, nbr));
  }

  /**
   * @brief Обнуляет все элементы матрицы.
   *
   */
  auto makeZero() -> TMatrix4<TYPE> & {
    values_.fill(0);
    return *this;
  }

  /**
   * @brief Приводит к единичной матрице.
   *
   */
  auto makeIdentity() -> TMatrix4<TYPE> & {
    makeZero();
    set(0, 0, (TYPE)1);
    set(1, 1, (TYPE)1);
    set(2, 2, (TYPE)1);
    set(3, 3, (TYPE)1);

    return *this;
  }

  auto get() -> std::array<TYPE, MAXTRIX_SIZE> { return values_; }

private:
  std::array<TYPE, MAXTRIX_SIZE> values_; /*!< Элементы матрицы. */
};

using mat4i_t = TMatrix4<s32_t>;
using mat4f_t = TMatrix4<f32_t>;
using mat4d_t = TMatrix4<f64_t>;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif
