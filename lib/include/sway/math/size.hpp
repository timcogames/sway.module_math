#ifndef SWAY_MATH_SIZE_HPP
#define SWAY_MATH_SIZE_HPP

#include <sway/core.hpp>
#include <sway/math/rect.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TYPE>
class TRect;

/**
 * @brief Шаблонный класс представления размера.
 *
 */
template <typename TYPE>
class TSize final {
public:
  /**
   * @brief Конструктор класса.
   * Выполняет инициализацию нового экземпляра класса с нулевыми размерами.
   *
   * @sa TSize(TYPE), TSize(TYPE, TYPE)
   *
   */
  TSize() { w_ = h_ = (TYPE)0; }

  /**
   * @brief Конструктор класса.
   * Выполняет инициализацию нового экземпляра класса с заданными размерами.
   *
   * @param[in] scalar Значение для ширины и высоты.
   *
   * @sa TSize(), TSize(TYPE, TYPE)
   *
   */
  TSize(TYPE scalar) { set(scalar, scalar); }

  /**
   * @brief Конструктор класса.
   * Выполняет инициализацию нового экземпляра класса с заданными размерами.
   *
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   *
   * @sa TSize(), TSize(TYPE)
   *
   */
  TSize(TYPE w, TYPE h) { set(w, h); }

  /**
   * @brief Устанавливает новые значения.
   *
   * @param[in] w Значение ширины.
   * @param[in] h Значение высоты.
   *
   */
  void set(TYPE w, TYPE h) {
    w_ = w;
    h_ = h;
  }

  /**
   * @brief Устанавливает значение ширины.
   *
   * @param[in] w Новое значение ширины.
   *
   * @sa setH(TYPE)
   *
   */
  void setW(TYPE w) { w_ = w; }

  /**
   * @brief Получает значение ширины.
   *
   * @sa getH()
   *
   */
  auto getW() const -> TYPE { return w_; }

  /**
   * @brief Устанавливает значение высоты.
   *
   * @param[in] h Новое значение высоты.
   *
   * @sa setW(TYPE)
   *
   */
  void setH(TYPE h) { h_ = h; }

  /**
   * @brief Получает значение высоты.
   *
   * @sa getW()
   *
   */
  auto getH() const -> TYPE { return h_; }

  /**
   * @brief Преобразовывает в TRect<TYPE> класс.
   *
   */
  auto toRect() const -> TRect<TYPE> { return TRect<TYPE>((TYPE)0, (TYPE)0, w_, h_); }

  /**
   * @brief Оператор равенства.
   *
   */
  template <typename OTHER>
  bool operator==(const TSize<OTHER> &compare) const {
    return w_ == compare.getW() && h_ == compare.getH();
  }

  /**
   * @brief Оператор неравенства.
   *
   */
  template <typename OTHER>
  bool operator!=(const TSize<OTHER> &compare) const {
    return !operator==(compare);
  }

private:
  TYPE w_, h_;
};

using size2i_t = TSize<s32_t>;
using size2f_t = TSize<f32_t>;
using size2d_t = TSize<f64_t>;

static const size2i_t size2i_zero(0, 0);
static const size2i_t size2i_one(1, 1);

static const size2f_t size2f_zero(0.0, 0.0);
static const size2f_t size2f_one(1.0, 1.0);

static const size2d_t size2d_zero(0.0, 0.0);
static const size2d_t size2d_one(1.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#include <sway/math/size.inl>

#endif  // SWAY_MATH_SIZE_HPP
