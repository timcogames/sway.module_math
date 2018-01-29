#ifndef SWAY_MATH_POINT_H
#define SWAY_MATH_POINT_H

#include <sway/core.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/*!
 * \brief
 *    Шаблонный класс представления точки.
 */
template <typename type_t>
class TPoint {
public:
	/*!
	 * \brief 
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
	 * 
	 * \sa
	 *    TPoint(type_t)
	 *    TPoint(type_t, type_t)
	 */
	TPoint() {
		set((type_t) 0, (type_t) 0);
	}

	/*!
	 * \brief 
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса с заданными координатами.
	 *
	 * \param[in] scalar
	 *    Значение для координат по оси X и Y.
	 * 
	 * \sa
	 *    TPoint()
	 *    TPoint(type_t, type_t)
	 */
	TPoint(type_t scalar) {
		set(scalar, scalar);
	}

	/*!
	 * \brief 
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса с заданными координатами.
	 *
	 * \param[in] x
	 *    Значение координаты по оси X.
	 * 
	 * \param[in] y
	 *    Значение координаты по оси Y.
	 * 
	 * \sa
	 *    TPoint()
	 *    TPoint(type_t)
	 */
	TPoint(type_t x, type_t y) {
		set(x, y);
	}

	/*!
	 * \brief 
	 *    Устанавливает новые значения.
	 *
	 * \param[in] x 
	 *    Значение координаты по оси X.
	 * 
	 * \param[in] y 
	 *    Значение координаты по оси Y.
	 */
	void set(type_t x, type_t y) {
		_x = x;
		_y = y;
	}

	/*!
	 * \brief 
	 *    Устанавливает новое значение координаты по оси X.
	 *
	 * \param[in] x 
	 *    Значение координаты по оси X.
	 *
	 * \sa 
	 *    setY() const
	 */
	void setX(type_t x) {
		_x = x;
	}

	/*!
	 * \brief 
	 *    Получает значение координаты по оси X.
	 *
	 * \sa 
	 *    getY() const
	 */
	type_t getX() const {
		return _x;
	}

	/*!
	 * \brief 
	 *    Устанавливает новое значение координаты по оси Y.
	 *
	 * \param[in] y 
	 *    Значение координаты по оси Y.
	 *
	 * \sa 
	 *    setX() const
	 */
	void setY(type_t y) {
		_y = y;
	}

	/*!
	 * \brief 
	 *    Получает значение координаты по оси Y.
	 *
	 * \sa 
	 *    getX() const
	 */
	type_t getY() const {
		return _y;
	}

	/*!
	 * \brief 
	 *    Оператор равенства. 
	 */
	template <typename other>
	bool operator==(const TPoint<other> & compare) const {
		return _x == compare.getX() && _y == compare.getY();
	}

	/*!
	 * \brief 
	 *    Оператор неравенства. 
	 */
	template <typename other>
	bool operator!=(const TPoint<other> & compare) const {
		return !operator==(compare);
	}

protected:
	type_t _x, _y;
};

typedef TPoint<s32_t> point2i_t;
typedef TPoint<f32_t> point2f_t;
typedef TPoint<f64_t> point2d_t;

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif // SWAY_MATH_POINT_H
