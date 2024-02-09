#ifndef SWAY_MATH_SIZE_HPP
#define SWAY_MATH_SIZE_HPP

#include <sway/core.hpp>
#include <sway/math/rect.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType>
class Rect;

/**
 * @brief Шаблонный класс представления размера.
 */
template <typename TValueType>
class Size : public Vector<TValueType, 2> {
public:
  enum : u32_t { IDX_WDT = 0, IDX_HGT };

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми размерами.
   *
   * @sa Size(TValueType),
   *     Size(TValueType, TValueType)
   */
  Size()
      : Vector<TValueType, Size<TValueType>::DataElementCount_t>() {}

  Size(const Vector<TValueType, Size<TValueType>::DataElementCount_t> &copy) {
    for (auto i = 0; i != Size<TValueType>::DataElementCount_t; ++i) {
      this->data_[i] = (TValueType)copy[i];
    }
  }

  Size(const std::array<TValueType, Size<TValueType>::DataElementCount_t> &arr)
      : Vector<TValueType, Size<TValueType>::DataElementCount_t>(arr) {}

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными размерами.
   *
   * @param[in] scalar Значение для ширины и высоты.
   * @sa Size(),
   *     Size(TValueType, TValueType)
   */
  Size(TValueType scalar) { set(scalar, scalar); }

  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с заданными размерами.
   *
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   * @sa Size(),
   *     Size(TValueType)
   */
  Size(TValueType w, TValueType h) { set(w, h); }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   */
  void set(TValueType w, TValueType h) {
    this->data_[IDX_WDT] = w;
    this->data_[IDX_HGT] = h;
  }

  /**
   * @brief Устанавливает значение ширины.
   *
   * @param[in] w Новое значение ширины.
   * @sa setH(TValueType)
   */
  void setW(TValueType w) { this->data_[IDX_WDT] = w; }

  /**
   * @brief Получает значение ширины.
   * @sa getH()
   */
  [[nodiscard]]
  auto getW() const -> TValueType {
    return this->data_[IDX_WDT];
  }

  /**
   * @brief Устанавливает значение высоты.
   *
   * @param[in] h Новое значение высоты.
   * @sa setW(TValueType)
   */
  void setH(TValueType h) { this->data_[IDX_HGT] = h; }

  /**
   * @brief Получает значение высоты.
   *
   * @sa getW()
   */
  [[nodiscard]]
  auto getH() const -> TValueType {
    return this->data_[IDX_HGT];
  }

  [[nodiscard]]
  auto area() const -> TValueType {
    return getW() * getH();
  }

  /**
   * @brief Преобразовывает в Rect<TValueType> класс.
   */
  [[nodiscard]]
  auto toRect() const -> Rect<TValueType> {
    return Rect<TValueType>((TValueType)0, (TValueType)0, this->data_[IDX_WDT], this->data_[IDX_HGT]);
  }

  auto operator*(const TValueType &rvalue) const -> Size<TValueType> {
    return Size<TValueType>(this->data_[IDX_WDT] * rvalue, this->data_[IDX_HGT] * rvalue);
  }
};

using size2i_t = Size<s32_t>;
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
