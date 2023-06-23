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
// clang-format off
template <typename TValueType,
          int TRows, int TColumns,
          int TMatrixSize = TRows * TColumns>  // clang-format on
class Matrix {
public:
  static auto fromArray(const std::array<TValueType, TMatrixSize> &arr) -> Matrix<TValueType, TRows, TColumns> {
    Matrix<TValueType, TRows, TColumns> mat;
    mat.setData(arr);
    return mat;
  }

  Matrix() { this->makeZero(); }

  Matrix(const Matrix<TValueType, TRows, TColumns> &mat)
      : data_(mat.getData()) {}

  auto makeZero() -> Matrix<TValueType, TRows, TColumns> & {
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

  void setValue(u32_t elm, TValueType val) { data_[elm] = val; }

  /**
   * @brief Получает значение элемента матрицы.
   *
   * @param[in] row Номер ряда.
   * @param[in] col Номер колонки.
   * @return Значения элемента.
   */
  auto getValue(u32_t row, u32_t col) const -> TValueType { return data_[col * TColumns + row]; }

  auto getValue(u32_t elm) const -> TValueType { return data_[elm]; }

  auto operator==(const Matrix<TValueType, TRows, TColumns> &other) const -> bool {
    for (auto i = 0; i < TRows * TColumns; ++i) {
      if (data_[i] != other.getValue(i)) {
        return false;
      }
    }

    return true;
  }

  template <int TInner>
  auto multiply(const std::array<TValueType, TRows * TColumns> &arr) -> Matrix<TValueType, TRows, TColumns> {
    // clang-format off
    std::array<TValueType, TRows * TColumns> result = {0};  // clang-format on
    for (auto y = 0; y < 4; y++) {
      for (auto x = 0; x < 4; x++) {
        for (auto i = 0; i < TInner; i++) {
          result[x + 4 * y] += this->getValue(x, i) * arr[i + TInner * y];
        }
      }
    }

    // for (auto row = 0; row < TRows; ++row) {
    //   for (auto col = 0; col < TColumns; ++col) {
    //     for (auto i = 0; i < TInner; ++i) {
    //       result[col * TRows + row] += this->getValue(i, col) * arr[i * TInner + row];
    //     }
    //   }
    // }

    this->setData(result);
    return *this;
  }

protected:
  std::array<TValueType, TMatrixSize> data_;  // Элементы матрицы (Column-major ordering).
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_MATRIX_HPP
