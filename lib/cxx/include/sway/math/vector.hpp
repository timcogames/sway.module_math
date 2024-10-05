#ifndef SWAY_MATH_VECTOR_HPP
#define SWAY_MATH_VECTOR_HPP

#include <sway/core.hpp>
#include <sway/math/utils.hpp>

#include <assert.h>

NS_BEGIN_SWAY()
NS_BEGIN(math)

template <typename TYPE, std::size_t SIZE>
class Vector {
  static_assert(SIZE != 0, "Vector cannot have size zero");

public:
  using Self_t = Vector<TYPE, SIZE>;
  using DataElementType_t = TYPE;

  enum : u32_t { IDX_X = 0, IDX_Y, IDX_Z, IDX_W };
  enum : std::size_t { DataElementCount_t = SIZE, DataSize_t = sizeof(TYPE) * SIZE };

#pragma region "Ctors/Dtor"

  Vector() { data_.fill((TYPE)0); }

  Vector(const std::array<TYPE, SIZE> &arr) { set(arr); }

  virtual ~Vector() = default;

#pragma endregion

  void set(const std::array<TYPE, SIZE> &arr) { data_ = arr; }

  [[nodiscard]]
  auto asArray() const -> std::array<TYPE, SIZE> {
    return data_;
  }

  [[nodiscard]]
  auto asDataPtr() -> TYPE * {
    return data_.data();
  }

  auto lerp(const Vector<TYPE, SIZE> &other, TYPE step) const -> Vector<TYPE, SIZE> {
    Vector<TYPE, SIZE> result;
    for (auto i = 0; i != DataElementCount_t; ++i) {
      result[i] = util::lerp(data_[i], other[i], step);
    }

    return result;
  }

#pragma region "Access operators"

  /**
   * @brief Возвращает значение в заданной позиции.
   *
   * @param[in] idx Позиция значения.
   * @sa operator[](std::size_t) const
   */
  auto operator[](std::size_t idx) -> TYPE & {
    assert(idx >= 0 && idx <= DataElementCount_t);
    return data_[idx];
  }

  /**
   * @brief Возвращает значение в заданной позиции.
   *
   * @param[in] idx Позиция значения.
   * @sa operator[](std::size_t)
   */
  auto operator[](std::size_t idx) const -> const TYPE {
    assert(idx >= 0 && idx <= DataElementCount_t);
    return data_[idx];
  }

#pragma endregion

#pragma region "Equality"

  /**
   * @brief Сравнивает два вектора на наличие равенства.
   *
   * @param[in] other Вектор с которым следует сравнить.
   * @sa operator==(const Vector<TYPE, SIZE> &) const,
   *     operator!=(const Vector<TYPE, SIZE> &) const
   */
  auto equals(const Vector<TYPE, SIZE> &other) const -> bool {
    for (auto i = 0; i < DataElementCount_t; ++i) {
      if (data_[i] != other[i]) {
        return false;
      }
    }

    return true;
  }

  auto operator==(const Vector<TYPE, SIZE> &other) const -> bool { return equals(other); }

  auto operator!=(const Vector<TYPE, SIZE> &other) const -> bool { return !equals(other); }

#pragma endregion

#pragma region "Arithmetic operations"

  /**
   * @brief Делит указанный вектор на заданный вектор.
   *
   * @param[in] other Вектор на который следует разделит.
   * @sa operator/(const Vector<TYPE, SIZE> &) const
   */
  auto divide(const Vector<TYPE, SIZE> &other) -> const Vector<TYPE, SIZE> & {
    for (auto i = 0; i < DataElementCount_t; ++i) {
      data_[i] /= other[i];
    }

    return *this;
  }

  auto operator/(const Vector<TYPE, SIZE> &other) const -> const Vector<TYPE, SIZE> { return divide(other); }

  /**
   * @brief Делит указанный вектор на заданный скаляр.
   *
   * @param[in] scalar Скаляр на который следует разделит.
   * @sa operator/(TYPE) const
   */
  auto divide(TYPE scalar) -> const Vector<TYPE, SIZE> & {
    for (auto i = 0; i < DataElementCount_t; ++i) {
      data_[i] /= scalar;
    }

    return *this;
  }

  auto operator/(TYPE scalar) -> const Vector<TYPE, SIZE> { return divide(scalar); }

#pragma endregion

protected:
  std::array<TYPE, DataElementCount_t> data_;
};

NS_END()  // namespace math
NS_END()  // namespace sway

#endif  // SWAY_MATH_VECTOR_HPP
