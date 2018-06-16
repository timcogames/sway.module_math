#ifndef SWAY_MATH_SIZE_H
#define SWAY_MATH_SIZE_H

#include <sway/math/rect.h>
#include <sway/core.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename type_t> class TRect;

/*!
 * \brief
 *    Шаблонный класс представления размера.
 */
template <typename type_t>
class TSize final {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса с нулевыми размерами.
	 * 
	 * \sa
	 *    TSize(type_t)
	 *    TSize(type_t, type_t)
	 */
	TSize() {
		_w = _h = (type_t) 0;
	}

	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса с заданными размерами.
	 *
	 * \param[in] scalar
	 *    Значение для ширины и высоты.
	 * 
	 * \sa
	 *    TSize()
	 *    TSize(type_t, type_t)
	 */

	TSize(type_t scalar) {
		set(scalar, scalar);
	}

	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса с заданными размерами.
	 *
	 * \param[in] w
	 *    Значение ширины.
	 * 
	 * \param[in] h
	 *    Значение высоты.
	 * 
	 * \sa
	 *    TSize()
	 *    TSize(type_t)
	 */
	TSize(type_t w, type_t h) {
		set(w, h);
	}

	/*!
	 * \brief
	 *    Устанавливает новые значения.
	 *
	 * \param[in] w
	 *    Значение ширины.
	 * 
	 * \param[in] h
	 *    Значение высоты.
	 */
	void set(type_t w, type_t h) {
		_w = w;
		_h = h;
	}

	/*!
	 * \brief
	 *    Устанавливает значение ширины.
	 * 
	 * \param[in] w
	 *    Новое значение ширины.
	 *
	 * \sa
	 *    setH(type_t)
	 */
	void setW(type_t w) {
		_w = w;
	}

	/*!
	 * \brief
	 *    Получает значение ширины.
	 *
	 * \sa
	 *    getH()
	 */
	type_t getW() const {
		return _w;
	}

	/*!
	 * \brief
	 *    Устанавливает значение высоты.
	 * 
	 * \param[in] h
	 *    Новое значение высоты.
	 *
	 * \sa
	 *    setW(type_t)
	 */
	void setH(type_t h) {
		_h = h;
	}

	/*!
	 * \brief
	 *    Получает значение высоты.
	 *
	 * \sa
	 *    getW()
	 */
	type_t getH() const {
		return _h;
	}

	/*!
	 * \brief
	 *    Преобразовывает в TRect<type_t> класс.
	 */
	TRect<type_t> toRect() const {
		return TRect<type_t>((type_t) 0, (type_t) 0, _w, _h);
	}

	/*!
	 * \brief 
	 *    Оператор равенства. 
	 */
	template <typename other>
	bool operator==(const TSize<other> & compare) const {
		return _w == compare.getW() && _h == compare.getH();
	}

	/*!
	 * \brief 
	 *    Оператор неравенства. 
	 */
	template <typename other>
	bool operator!=(const TSize<other> & compare) const {
		return !operator==(compare);
	}

private:
	type_t _w, _h;
};

typedef TSize<s32_t> size2i_t;
typedef TSize<f32_t> size2f_t;
typedef TSize<f64_t> size2d_t;

static const size2i_t size2i_zero(0, 0);
static const size2i_t size2i_one(1, 1);

static const size2f_t size2f_zero(0.0f, 0.0f);
static const size2f_t size2f_one(1.0f, 1.0f);

static const size2d_t size2d_zero(0.0, 0.0);
static const size2d_t size2d_one(1.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#include <sway/math/size.inl>

#endif // SWAY_MATH_SIZE_H
