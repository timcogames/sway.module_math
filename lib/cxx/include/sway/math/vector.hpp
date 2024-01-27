#ifndef SWAY_MATH_VECTOR_HPP
#define SWAY_MATH_VECTOR_HPP

#include <sway/core.hpp>

#include <assert.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType, std::size_t TElementCount>
class Vector {
  static_assert(TElementCount != 0, "Вектор не может иметь нулевой размер");

public:
  using DataElementType_t = TValueType;
  enum : std::size_t { DataElementCount_t = TElementCount, DataSize_t = sizeof(TValueType) * TElementCount };

  Vector() {
    for (std::size_t i = 0; i != DataElementCount_t; ++i) {
      data_[i] = (TValueType)0;
    }
  }

  void set(const std::array<TValueType, TElementCount> &arr) { data_ = arr; }

  auto array() const -> std::array<TValueType, TElementCount> { return data_; }

  auto data() const -> void * { return data_.data(); }

#pragma region "Access operators"

  /**
   * @brief Возвращает значение в заданной позиции.
   *
   * @param[in] position Позиция значения.
   * @sa operator[](std::size_t) const
   */
  auto operator[](std::size_t position) -> TValueType & {
    assert(position >= 0 && position <= DataElementCount_t);
    return data_[position];
  }

  /**
   * @brief Возвращает значение в заданной позиции.
   *
   * @param[in] position Позиция значения.
   * @sa operator[](std::size_t)
   */
  auto operator[](std::size_t position) const -> const TValueType {
    assert(position >= 0 && position <= DataElementCount_t);
    return data_[position];
  }

#pragma endregion

#pragma region "Equality"

  /**
   * @brief Сравнивает два вектора на наличие равенства.
   *
   * @param[in] other Вектор с которым следует сравнить.
   * @sa operator==(const Vector<TValueType, TElementCount> &) const,
   *     operator!=(const Vector<TValueType, TElementCount> &) const
   */
  auto equals(const Vector<TValueType, TElementCount> &other) const -> bool {
    for (auto i = 0; i < DataElementCount_t; ++i) {
      if (data_[i] != other[i]) {
        return false;
      }
    }

    return true;
  }

  auto operator==(const Vector<TValueType, TElementCount> &other) const -> bool { return equals(other); }

  auto operator!=(const Vector<TValueType, TElementCount> &other) const -> bool { return !equals(other); }

#pragma endregion

#pragma region "Arithmetic operations"

  /**
   * @brief Делит указанный вектор на заданный вектор.
   *
   * @param[in] other Вектор на который следует разделит.
   * @sa operator/(const Vector<TValueType, TElementCount> &) const
   */
  auto divide(const Vector<TValueType, TElementCount> &other) -> const Vector<TValueType, TElementCount> & {
    for (std::size_t i = 0; i < DataElementCount_t; ++i) {
      data_[i] /= other[i];
    }

    return *this;
  }

  auto operator/(const Vector<TValueType, TElementCount> &other) const -> const Vector<TValueType, TElementCount> {
    return divide(other);
  }

  /**
   * @brief Делит указанный вектор на заданный скаляр.
   *
   * @param[in] scalar Скаляр на который следует разделит.
   * @sa operator/(TValueType) const
   */
  auto divide(TValueType scalar) -> const Vector<TValueType, TElementCount> & {
    for (std::size_t i = 0; i < DataElementCount_t; ++i) {
      data_[i] /= scalar;
    }

    return *this;
  }

  auto operator/(TValueType scalar) const -> const Vector<TValueType, TElementCount> { return divide(scalar); }

#pragma endregion

protected:
  std::array<TValueType, DataElementCount_t> data_;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_VECTOR_HPP
