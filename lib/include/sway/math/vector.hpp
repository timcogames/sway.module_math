#ifndef SWAY_MATH_VECTOR_HPP
#define SWAY_MATH_VECTOR_HPP

#include <sway/core.hpp>

#include <assert.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType, std::size_t TSize>
class Vector {
  static_assert(TSize != 0, "Вектор не может иметь нулевой размер");

public:
  using type_t = TValueType;  // Базовый тип данных.

  enum : std::size_t {
    size = TSize  // Размер вектора.
  };

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми значениями.
   */
  Vector() {
    for (std::size_t i = 0; i != size; ++i) {
      data_[i] = (TValueType)0;
    }
  }

  /**
   * @brief Возвращает необработанные данные.
   *
   * @sa data() const
   */
  auto data() -> TValueType * { return data_; }

  /**
   * @brief Возвращает необработанные данные.
   *
   * @sa data()
   */
  auto data() const -> const TValueType * { return data_; }

#pragma region "Доступ к массиву"

  /**
   * @brief Возвращает значение в заданной позиции.
   *
   * @param[in] position Позиция значения.
   * @sa operator[](std::size_t) const
   */
  auto operator[](std::size_t position) -> TValueType & {
    assert(position >= 0 && position <= TSize);
    return data_[position];
  }

  /**
   * @brief Возвращает значение в заданной позиции.
   *
   * @param[in] position Позиция значения.
   * @sa operator[](std::size_t)
   */
  auto operator[](std::size_t position) const -> const TValueType {
    assert(position >= 0 && position <= TSize);
    return data_[position];
  }

#pragma endregion

#pragma region "Равенство"

  /**
   * @brief Сравнивает два вектора на наличие равенства.
   *
   * @param[in] vector Вектор с которым следует сравнить.
   * @sa operator==(const Vector<TValueType, TSize> &) const,
   *     operator!=(const Vector<TValueType, TSize> &) const
   */
  auto equals(const Vector<TValueType, TSize> &vector) const -> int {
    for (int i = 0; i < TSize; ++i) {
      if (data_[i] != vector[i]) {
        return 0;
      }

      return 1;
    }
  }

  auto operator==(const Vector<TValueType, TSize> &vector) const -> int { return equals(vector); }

  auto operator!=(const Vector<TValueType, TSize> &vector) const -> int { return !equals(vector); }

#pragma endregion

#pragma region "Арифметические операции"

  /**
   * @brief Делит указанный вектор на заданный вектор.
   *
   * @param[in] vector Вектор на который следует разделит.
   * @sa operator/(const Vector<TValueType, TSize> &) const
   */
  auto divide(const Vector<TValueType, TSize> &vector) -> const Vector<TValueType, TSize> & {
    for (std::size_t i = 0; i < TSize; ++i) {
      data_[i] /= vector[i];
    }

    return *this;
  }

  auto operator/(const Vector<TValueType, TSize> &vector) const -> const Vector<TValueType, TSize> {
    return divide(vector);
  }

  /**
   * @brief Делит указанный вектор на заданный скаляр.
   *
   * @param[in] scalar Скаляр на который следует разделит.
   * @sa operator/(TValueType) const
   */
  auto divide(TValueType scalar) -> const Vector<TValueType, TSize> & {
    for (std::size_t i = 0; i < TSize; ++i) {
      data_[i] /= scalar;
    }

    return *this;
  }

  auto operator/(TValueType scalar) const -> const Vector<TValueType, TSize> { return divide(scalar); }

#pragma endregion

protected:
  TValueType data_[TSize];  // Данные вектора.
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_VECTOR_HPP
