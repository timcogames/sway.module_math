#ifndef SWAY_MATH_POINT_H
#define SWAY_MATH_POINT_H

#include <sway/core.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/*!
 * \brief
 *    Шаблонный класс представления точки.
 */
template <typename TYPE>
class TPoint {
public:
	/*!
	 * \brief 
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
	 * 
	 * \sa
	 *    TPoint(TYPE)
	 *    TPoint(TYPE, TYPE)
	 */
	TPoint() {
		set((TYPE) 0, (TYPE) 0);
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
	 *    TPoint(TYPE, TYPE)
	 */
	TPoint(TYPE scalar) {
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
	 *    TPoint(TYPE)
	 */
	TPoint(TYPE x, TYPE y) {
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
	void set(TYPE x, TYPE y) {
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
	void setX(TYPE x) {
		_x = x;
	}

	/*!
	 * \brief 
	 *    Получает значение координаты по оси X.
	 *
	 * \sa 
	 *    getY() const
	 */
	TYPE getX() const {
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
	void setY(TYPE y) {
		_y = y;
	}

	/*!
	 * \brief 
	 *    Получает значение координаты по оси Y.
	 *
	 * \sa 
	 *    getX() const
	 */
	TYPE getY() const {
		return _y;
	}

	/*!
	 * \brief 
	 *    Оператор равенства. 
	 */
	template<typename OTHER>
	bool operator==(const TPoint<OTHER> & compare) const {
		return _x == compare.getX() && _y == compare.getY();
	}

	/*!
	 * \brief 
	 *    Оператор неравенства. 
	 */
	template<typename OTHER>
	bool operator!=(const TPoint<OTHER> & compare) const {
		return !operator==(compare);
	}

protected:
	TYPE _x, _y;
};

typedef TPoint<s32_t> point2i_t;
typedef TPoint<f32_t> point2f_t;
typedef TPoint<f64_t> point2d_t;

static const point2i_t point2i_zero(0, 0);
static const point2i_t point2i_one(1, 1);

static const point2f_t point2f_zero(0.0f, 0.0f);
static const point2f_t point2f_one(1.0f, 1.0f);

static const point2d_t point2d_zero(0.0, 0.0);
static const point2d_t point2d_one(1.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif // SWAY_MATH_POINT_H
