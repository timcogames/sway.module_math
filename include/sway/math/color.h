#ifndef SWAY_MATH_COLOR_H
#define SWAY_MATH_COLOR_H

#include <sway/math/vector4.h>
#include <sway/core.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template<typename TYPE> class TVector4;

/*!
 * \brief
 *    Шаблонный класс представления цвета.
 */
template<typename TYPE>
class TColor final {
public:
	/*!
	 * \brief 
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \sa
	 *    TColor(TYPE, TYPE, TYPE, TYPE)
	 */
	TColor() {
		_r = _g = _b = (TYPE) 0;
		_a = (TYPE) 1;
	}

	/*!
	 * \brief 
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 *
	 * \param[in] r
	 *    Значение канала красного цвета.
	 * 
	 * \param[in] g
	 *    Значение канала зеленого цвета.
	 * 
	 * \param[in] b
	 *    Значение канала синего цвета.
	 * 
	 * \param[in] a
	 *    Значение альфа-канала.
	 * 
	 * \sa
	 *    TColor()
	 */
	TColor(TYPE r, TYPE g, TYPE b, TYPE a = (TYPE) 1) {
		set(r, g, b, a);
	}

	/*!
	 * \brief 
	 *    Устанавливает новые значения.
	 *
	 * \param[in] r
	 *    Значение канала красного цвета.
	 * 
	 * \param[in] g
	 *    Значение канала зеленого цвета.
	 * 
	 * \param[in] b
	 *    Значение канала синего цвета.
	 * 
	 * \param[in] a
	 *    Значение альфа-канала.
	 */
	void set(TYPE r, TYPE g, TYPE b, TYPE a = (TYPE) 1) {
		_r = r;
		_g = g;
		_b = b;
		_a = a;
	}

	/*!
	 * \brief
	 *    Получает значение канала красного цвета.
	 *
	 * \sa
	 *    getG() const
	 *    getB() const
	 *    getA() const
	 */
	TYPE getR() const {
		return _r;
	}

	/*!
	 * \brief
	 *    Получает значение канала зеленого цвета.
	 *
	 * \sa
	 *    getR() const
	 *    getB() const
	 *    getA() const
	 */
	TYPE getG() const {
		return _g;
	}

	/*!
	 * \brief
	 *    Получает значение канала синего цвета.
	 *
	 * \sa
	 *    getR() const
	 *    getG() const
	 *    getA() const
	 */
	TYPE getB() const {
		return _b;
	}

	/*!
	 * \brief
	 *    Получает значение альфа-канала.
	 *
	 * \sa
	 *    getR() const
	 *    getG() const
	 *    getB() const
	 */
	TYPE getA() const {
		return _a;
	}

	/*!
	 * \brief
	 *    Преобразовывает в TVector4<TYPE> класс.
	 */
	TVector4<TYPE> toVec4() const {
		return TVector4<TYPE>(_r, _g, _b, _a);
	}

private:
	TYPE _r, _g, _b, _a;
};

typedef TColor<s32_t> col4i_t;
typedef TColor<f32_t> col4f_t;
typedef TColor<f64_t> col4d_t;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif // SWAY_MATH_COLOR_H
