#ifndef SWAY_MATH_VECTOR_HPP
#define SWAY_MATH_VECTOR_HPP

#include <sway/core.hpp>

#include <assert.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TYPE, std::size_t SIZE>
class TVector {
  static_assert(SIZE != 0, "Вектор не может иметь нулевой размер");

public:
  using type_t = TYPE;  // Базовый тип данных.

  enum : std::size_t {
    size = SIZE  // Размер вектора.
  };

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми значениями.
   */
  TVector() {
    for (std::size_t i = 0; i != size; ++i) {
      data_[i] = (TYPE)0;
    }
  }

  /**
   * @brief Возвращает необработанные данные.
   *
   * @sa data() const
   */
  auto data() -> TYPE * { return data_; }

  /**
   * @brief Возвращает необработанные данные.
   *
   * @sa data()
   */
  auto data() const -> const TYPE * { return data_; }

#pragma region "Доступ к массиву"

  /**
   * @brief Возвращает значение в заданной позиции.
   *
   * @param[in] position Позиция значения.
   * @sa operator[](std::size_t) const
   */
  TYPE &operator[](std::size_t position) {
    assert(position >= 0 && position <= SIZE);
    return data_[position];
  }

  /**
   * @brief Возвращает значение в заданной позиции.
   *
   * @param[in] position Позиция значения.
   * @sa operator[](std::size_t)
   */
  const TYPE operator[](std::size_t position) const {
    assert(position >= 0 && position <= SIZE);
    return data_[position];
  }

#pragma endregion

#pragma region "Равенство"

  /**
   * @brief Сравнивает два вектора на наличие равенства.
   *
   * @param[in] vector Вектор с которым следует сравнить.
   * @sa operator==(const TVector<TYPE, SIZE> &) const,
   *     operator!=(const TVector<TYPE, SIZE> &) const
   */
  int equals(const TVector<TYPE, SIZE> &vector) const {
    for (int i = 0; i < SIZE; ++i) {
      if (data_[i] != vector[i]) {
        return 0;
      }

      return 1;
    }
  }

  int operator==(const TVector<TYPE, SIZE> &vector) const { return equals(vector); }

  int operator!=(const TVector<TYPE, SIZE> &vector) const { return !equals(vector); }

#pragma endregion

#pragma region "Арифметические операции"

  /**
   * @brief Делит указанный вектор на заданный вектор.
   *
   * @param[in] vector Вектор на который следует разделит.
   * @sa operator/(const TVector<TYPE, SIZE> &) const
   */
  const TVector<TYPE, SIZE> &divide(const TVector<TYPE, SIZE> &vector) {
    for (std::size_t i = 0; i < SIZE; ++i) {
      data_[i] /= vector[i];
    }

    return *this;
  }

  const TVector<TYPE, SIZE> operator/(const TVector<TYPE, SIZE> &vector) const { return divide(vector); }

  /**
   * @brief Делит указанный вектор на заданный скаляр.
   *
   * @param[in] scalar Скаляр на который следует разделит.
   * @sa operator/(TYPE) const
   */
  const TVector<TYPE, SIZE> &divide(TYPE scalar) {
    for (std::size_t i = 0; i < SIZE; ++i) {
      data_[i] /= scalar;
    }

    return *this;
  }

  const TVector<TYPE, SIZE> operator/(TYPE scalar) const { return divide(scalar); }

#pragma endregion

protected:
  TYPE data_[SIZE];  // Данные вектора.
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_VECTOR_HPP
