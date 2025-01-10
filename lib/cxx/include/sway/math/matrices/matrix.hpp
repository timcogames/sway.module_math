#ifndef SWAY_MATH_MATRICES_MATRIX_HPP
#define SWAY_MATH_MATRICES_MATRIX_HPP

#include <sway/core.hpp>
#include <sway/math/vector4.hpp>

#include <array>

namespace sway::math {

/**
 * @ingroup matrices
 * @{
 */

/**
 * @brief \~english Template class representing a matrix. \~russian Шаблонный класс представления матрицы.
 */
// clang-format off
template <typename TYPE,
          int ROWS, int COLS,
          int SIZE = ROWS * COLS>  // clang-format on
class Matrix {
public:
#pragma region "Static methods"

  static auto fromArray(const std::array<TYPE, SIZE> &arr) -> Matrix<TYPE, ROWS, COLS> {
    Matrix<TYPE, ROWS, COLS> mat;
    mat.setData(arr);
    return mat;
  }

#pragma endregion

#pragma region "Ctors/Dtor"
  /** \~english @name Constructor & Destructor */ /** \~russian @name Конструктор и Деструктор */
  /** @{ */

  Matrix() { this->makeZero(); }

  Matrix(const Matrix<TYPE, ROWS, COLS> &mat)
      : data_(mat.asArray()) {}

  /** @} */
#pragma endregion

  auto makeZero() -> Matrix<TYPE, ROWS, COLS> & {
    data_.fill(0);
    return *this;
  }

  void setData(const std::array<TYPE, SIZE> &arr) { data_ = arr; }

  auto asArray() const -> std::array<TYPE, SIZE> { return data_; }

  /**
   * \~english
   * @brief Sets new value of matrix element.
   * @param[in] row Row number.
   * @param[in] col Column number.
   * @param[in] val Matrix element value.
   *
   * \~russian
   * @brief Устанавливает новое значение элемента матрицы.
   * @param[in] row Номер ряда.
   * @param[in] col Номер колонки.
   * @param[in] val Значения элемента матрицы.
   */
  void setValue(u32_t row, u32_t col, TYPE val) { data_[col * COLS + row] = val; }

  void setValue(u32_t elm, TYPE val) { data_[elm] = val; }

  /**
   * \~english
   * @brief Gets value of matrix element.
   * @param[in] row Row number.
   * @param[in] col Column number.
   * @return Matrix element value.
   *
   * \~russian
   * @brief Получает значение элемента матрицы.
   * @param[in] row Номер ряда.
   * @param[in] col Номер колонки.
   * @return Значения элемента.
   */
  auto getValue(u32_t row, u32_t col) const -> TYPE { return data_[col * COLS + row]; }

  auto getValue(u32_t elm) const -> TYPE { return data_[elm]; }

  auto operator==(const Matrix<TYPE, ROWS, COLS> &other) const -> bool {
    for (auto i = 0; i < ROWS * COLS; ++i) {
      if (data_[i] != other.getValue(i)) {
        return false;
      }
    }

    return true;
  }

  template <int INNER>
  auto multiply(const std::array<TYPE, ROWS * COLS> &arr) -> Matrix<TYPE, ROWS, COLS> {
    // clang-format off
    std::array<TYPE, ROWS * COLS> result = {0};  // clang-format on
    for (auto y = 0; y < 4; y++) {
      for (auto x = 0; x < 4; x++) {
        for (auto i = 0; i < INNER; i++) {
          result[x + 4 * y] += this->getValue(x, i) * arr[i + INNER * y];
        }
      }
    }

    // for (auto row = 0; row < ROWS; ++row) {
    //   for (auto col = 0; col < COLS; ++col) {
    //     for (auto i = 0; i < INNER; ++i) {
    //       result[col * ROWS + row] += this->getValue(i, col) * arr[i * INNER + row];
    //     }
    //   }
    // }

    this->setData(result);
    return *this;
  }

protected:
  std::array<TYPE, SIZE> data_; /*!< \~english Matrix elements (Column-major ordering).
    \~russian Элементы матрицы (Column-major ordering). */
};

/** @} */

}  // namespace sway::math

#endif  // SWAY_MATH_MATRICES_MATRIX_HPP
