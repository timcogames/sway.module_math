#ifndef SWAY_MATH_SIZE_HPP
#define SWAY_MATH_SIZE_HPP

#include <sway/core.hpp>
#include <sway/math/rect.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TYPE>
class Rect;

/**
 * @brief Шаблонный класс представления размера.
 */
template <typename TYPE>
class Size : public Vector<TYPE, 2> {
public:
  enum : u32_t { IDX_WDT = 0, IDX_HGT };

#pragma region "Ctors/Dtor"

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми размерами.
   *
   * @sa Size(TYPE),
   *     Size(TYPE, TYPE)
   */
  Size()
      : Vector<TYPE, Size<TYPE>::DataElementCount_t>() {}

  Size(const Vector<TYPE, Size<TYPE>::DataElementCount_t> &copy) {
    for (auto i = 0; i != Size<TYPE>::DataElementCount_t; ++i) {
      this->data_[i] = (TYPE)copy[i];
    }
  }

  Size(const std::array<TYPE, Size<TYPE>::DataElementCount_t> &arr)
      : Vector<TYPE, Size<TYPE>::DataElementCount_t>(arr) {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными размерами.
   *
   * @param[in] scalar Значение для ширины и высоты.
   * @sa Size(),
   *     Size(TYPE, TYPE)
   */
  Size(TYPE scalar) { set(scalar, scalar); }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными размерами.
   *
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   * @sa Size(),
   *     Size(TYPE)
   */
  Size(TYPE w, TYPE h) { set(w, h); }

  virtual ~Size() = default;

#pragma endregion

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   */
  void set(TYPE w, TYPE h) {
    this->data_[IDX_WDT] = w;
    this->data_[IDX_HGT] = h;
  }

  /**
   * @brief Устанавливает значение ширины.
   *
   * @param[in] w Новое значение ширины.
   * @sa setH(TYPE)
   */
  void setW(TYPE w) { this->data_[IDX_WDT] = w; }

  /**
   * @brief Получает значение ширины.
   * @sa getH()
   */
  [[nodiscard]]
  auto getW() const -> TYPE {
    return this->data_[IDX_WDT];
  }

  /**
   * @brief Устанавливает значение высоты.
   *
   * @param[in] h Новое значение высоты.
   * @sa setW(TYPE)
   */
  void setH(TYPE h) { this->data_[IDX_HGT] = h; }

  /**
   * @brief Получает значение высоты.
   *
   * @sa getW()
   */
  [[nodiscard]]
  auto getH() const -> TYPE {
    return this->data_[IDX_HGT];
  }

  [[nodiscard]]
  auto area() const -> TYPE {
    return getW() * getH();
  }

  /**
   * @brief Преобразовывает в Rect<TYPE> класс.
   */
  [[nodiscard]]
  auto asRect() const -> Rect<TYPE> {
    return Rect<TYPE>((TYPE)0, (TYPE)0, this->data_[IDX_WDT], this->data_[IDX_HGT]);
  }

  auto add(const Size<TYPE> &size) -> Size<TYPE> { return Size<TYPE>(getW() + size.getW(), getH() + size.getH()); }

  auto operator+(const Size<TYPE> &size) -> Size<TYPE> { return add(size); }

  auto operator+=(const Size<TYPE> &size) -> Size<TYPE> & { return *this = add(size); }

  auto operator*(const TYPE &rvalue) const -> Size<TYPE> {
    return Size<TYPE>(this->data_[IDX_WDT] * rvalue, this->data_[IDX_HGT] * rvalue);
  }
};

using sizei_t = Size<i32_t>;
using sizef_t = Size<f32_t>;
using sized_t = Size<f64_t>;

using size2i_t = Size<i32_t>;
using size2f_t = Size<f32_t>;
using size2d_t = Size<f64_t>;

static const size2i_t size2i_zero(0, 0);
static const size2i_t size2i_one(1, 1);

static const size2f_t size2f_zero(0.0F, 0.0F);
static const size2f_t size2f_one(1.0F, 1.0F);

static const size2d_t size2d_zero(0.0, 0.0);
static const size2d_t size2d_one(1.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#include <sway/math/size.inl>

#endif  // SWAY_MATH_SIZE_HPP
