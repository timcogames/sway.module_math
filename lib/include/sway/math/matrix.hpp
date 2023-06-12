#ifndef SWAY_MATH_MATRIX_HPP
#define SWAY_MATH_MATRIX_HPP

#include <sway/core.hpp>
#include <sway/math/vector4.hpp>

#include <array>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/**
 * @brief Шаблонный класс представления матрицы.
 */
template <int TRows, int TColumns, typename TValueType, int TMatrixSize = TRows *TColumns>
class Matrix {
public:
  static Matrix<TRows, TColumns, TValueType> fromArray(const std::array<TValueType, TMatrixSize> &arr) {
    Matrix<TRows, TColumns, TValueType> mtx;
    mtx.setData(arr);
    return mtx;
  }

  Matrix() { this->makeZero(); }

  Matrix(const Matrix<TRows, TColumns, TValueType> &mtx)
      : data_(mtx.getData()) {}

  auto makeZero() -> Matrix<TRows, TColumns, TValueType> & {
    data_.fill(0);
    return *this;
  }

  void setData(const std::array<TValueType, TMatrixSize> &arr) { data_ = arr; }

  auto getData() const -> std::array<TValueType, TMatrixSize> { return data_; }

  /**
   * @brief Устанавливает новое значение элемента матрицы.
   *
   * @param[in] row Номер ряда.
   * @param[in] col Номер колонки.
   * @param[in] val Значения элемента матрицы.
   */
  void setValue(u32_t row, u32_t col, TValueType val) { data_[col * TColumns + row] = val; }

  /**
   * @brief Получает значение элемента матрицы.
   *
   * @param[in] row Номер ряда.
   * @param[in] col Номер колонки.
   * @return Значения элемента.
   */
  auto getValue(u32_t row, u32_t col) const -> TValueType { return data_[col * TColumns + row]; }

  auto getValue(u32_t elm) const -> TValueType { return data_[elm]; }

protected:
  template <int TInner>
  auto multiply_(const std::array<TValueType, TRows * TColumns> &arr) -> Matrix<TRows, TColumns, TValueType> {
    std::array<TValueType, TRows *TColumns> result = {};
    for (int row = 0; row < TRows; ++row) {
      for (int col = 0; col < TColumns; ++col) {
        for (int i = 0; i < TInner; ++i) {
          result[row * TRows + col] += this->getValue(row, i) * arr[i * TInner + col];
        }
      }
    }

    this->setData(result);
    return *this;
  }

  std::array<TValueType, TMatrixSize> data_;  // Элементы матрицы.
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_MATRIX_HPP
