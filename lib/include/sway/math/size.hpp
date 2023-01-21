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
class Size final {
public:
  /**
   * @brief Конструктор класса.
   *        Выполняет инициализацию нового экземпляра класса с нулевыми размерами.
   *
   * @sa Size(TValueType),
   *     Size(TValueType, TValueType)
   */
  Size() { w_ = h_ = (TValueType)0; }

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
    w_ = w;
    h_ = h;
  }

  /**
   * @brief Устанавливает значение ширины.
   *
   * @param[in] w Новое значение ширины.
   * @sa setH(TValueType)
   */
  void setW(TValueType w) { w_ = w; }

  /**
   * @brief Получает значение ширины.
   * @sa getH()
   */
  auto getW() const -> TValueType { return w_; }

  /**
   * @brief Устанавливает значение высоты.
   *
   * @param[in] h Новое значение высоты.
   * @sa setW(TValueType)
   */
  void setH(TValueType h) { h_ = h; }

  /**
   * @brief Получает значение высоты.
   *
   * @sa getW()
   */
  auto getH() const -> TValueType { return h_; }

  /**
   * @brief Преобразовывает в Rect<TValueType> класс.
   */
  auto toRect() const -> Rect<TValueType> { return Rect<TValueType>((TValueType)0, (TValueType)0, w_, h_); }

  /**
   * @brief Оператор равенства.
   */
  template <typename TOther>
  bool operator==(const Size<TOther> &compare) const {
    return w_ == compare.getW() && h_ == compare.getH();
  }

  /**
   * @brief Оператор неравенства.
   */
  template <typename TOther>
  bool operator!=(const Size<TOther> &compare) const {
    return !operator==(compare);
  }

private:
  TValueType w_, h_;
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
