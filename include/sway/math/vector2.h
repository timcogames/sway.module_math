#ifndef SWAY_MATH_VECTOR2_H
#define SWAY_MATH_VECTOR2_H

#include <sway/core.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/*!
 * \brief
 *    Шаблонный класс, представляющий двумерный вектор.
 * 
 *    Класс, который хранит позицию в 2D-координатах, 
 *    позволяет манипулировать ими, а также выполнять векторные операции.
 */
template<typename TYPE>
class TVector2 final {
public:
	typedef TYPE rawtype_t;

	/*!
	 * \brief 
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
	 * 
	 * \sa
	 *    TVector2(TYPE, TYPE)
	 */
	TVector2() {
		_x = _y = (TYPE) 0;
	}

	/*!
	 * \brief 
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса с заданными координатами.
	 *
	 * \param[in] x
	 *    Компонент X вектора.
	 * 
	 * \param[in] y
	 *    Компонент Y вектора.
	 * 
	 * \sa
	 *    TVector2()
	 */
	TVector2(TYPE x, TYPE y) {
		set(x, y);
	}

	/*!
	 * \brief 
	 *    Устанавливает новые значения.
	 *
	 * \param[in] x
	 *    Значение X компонента.
	 * 
	 * \param[in] y
	 *    Значение Y компонента.
	 */
	void set(TYPE x, TYPE y) {
		_x = x;
		_y = y;
	}

	/*!
	 * \brief
	 *    Получает значение X компонента.
	 *
	 * \sa
	 *    getY() const
	 */
	TYPE getX() const {
		return _x;
	}

	/*!
	 * \brief
	 *    Получает значение Y компонента.
	 *
	 * \sa
	 *    getX() const
	 */
	TYPE getY() const {
		return _y;
	}

	/*!
	 * \brief
	 *    Возвращает количество компонентов.
	 */
	s32_t size() const {
		return 2;
	}

private:
	TYPE _x, _y;
};

typedef TVector2<s32_t> vec2i_t;
typedef TVector2<f32_t> vec2f_t;
typedef TVector2<f64_t> vec2d_t;

static const vec2i_t vec2i_zero(0, 0);
static const vec2i_t vec2i_one(1, 1);
static const vec2i_t vec2i_unitX(1, 0);
static const vec2i_t vec2i_unitY(0, 1);

static const vec2f_t vec2f_zero(0.0f, 0.0f);
static const vec2f_t vec2f_one(1.0f, 1.0f);
static const vec2f_t vec2f_unitX(1.0f, 0.0f);
static const vec2f_t vec2f_unitY(0.0f, 1.0f);

static const vec2d_t vec2d_zero(0.0, 0.0);
static const vec2d_t vec2d_one(1.0, 1.0);
static const vec2d_t vec2d_unitX(1.0, 0.0);
static const vec2d_t vec2d_unitY(0.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif // SWAY_MATH_VECTOR2_H
