#ifndef SWAY_MATH_VECTOR4_H
#define SWAY_MATH_VECTOR4_H

#include <sway/core.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/*!
 * \brief
 *    Шаблонный класс представления вектора из четырех компонентов.
 */
template<typename TYPE>
class TVector4 final {
public:
	typedef TYPE rawtype_t;
	
	/*!
	 * \brief 
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
	 * 
	 * \sa
	 *    TVector4(TYPE, TYPE, TYPE, TYPE)
	 */
	TVector4() {
		_x = _y = _z = _w = (TYPE) 0;
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
	 * \param[in] z
	 *    Компонент Z вектора.
	 * 
	 * \param[in] w
	 *    Компонент W вектора.
	 * 
	 * \sa
	 *    TVector4()
	 */
	TVector4(TYPE x, TYPE y, TYPE z, TYPE w) {
		set(x, y, z, w);
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
	 * 
	 * \param[in] z
	 *    Значение Z компонента.
	 * 
	 * \param[in] w
	 *    Значение W компонента.
	 */
	void set(TYPE x, TYPE y, TYPE z, TYPE w) {
		_x = x;
		_y = y;
		_z = z;
		_w = w;
	}

	/*!
	 * \brief
	 *    Получает значение X компонента.
	 *
	 * \sa
	 *    getY() const
	 *    getZ() const
	 *    getW() const
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
	 *    getZ() const
	 *    getW() const
	 */
	TYPE getY() const {
		return _y;
	}

	/*!
	 * \brief
	 *    Получает значение Z компонента.
	 *
	 * \sa
	 *    getX() const
	 *    getY() const
	 *    getW() const
	 */
	TYPE getZ() const {
		return _z;
	}

	/*!
	 * \brief
	 *    Получает значение W компонента.
	 *
	 * \sa
	 *    getX() const
	 *    getY() const
	 *    getZ() const
	 */
	TYPE getW() const {
		return _w;
	}

	/*!
	 * \brief
	 *    Возвращает количество компонентов.
	 */
	s32_t size() const {
		return 4;
	}

private:
	TYPE _x, _y, _z, _w;
};

typedef TVector4<s32_t> vec4i_t;
typedef TVector4<f32_t> vec4f_t;
typedef TVector4<f64_t> vec4d_t;

static const vec4i_t vec4i_zero(0, 0, 0, 0);
static const vec4i_t vec4i_one(1, 1, 1 ,1);
static const vec4i_t vec4i_unitX(1, 0, 0, 0);
static const vec4i_t vec4i_unitY(0, 1, 0, 0);
static const vec4i_t vec4i_unitZ(0, 0, 1, 0);
static const vec4i_t vec4i_unitW(0, 0, 0, 1);

static const vec4f_t vec4f_zero(0.0f, 0.0f, 0.0f, 0.0f);
static const vec4f_t vec4f_one(1.0f, 1.0f, 1.0f, 1.0f);
static const vec4f_t vec4f_unitX(1.0f, 0.0f, 0.0f, 0.0f);
static const vec4f_t vec4f_unitY(0.0f, 1.0f, 0.0f, 0.0f);
static const vec4f_t vec4f_unitZ(0.0f, 0.0f, 1.0f, 0.0f);
static const vec4f_t vec4f_unitW(0.0f, 0.0f, 0.0f, 1.0f);

static const vec4d_t vec4d_zero(0.0, 0.0, 0.0, 0.0);
static const vec4d_t vec4d_one(1.0, 1.0, 1.0, 1.0);
static const vec4d_t vec4d_unitX(1.0, 0.0, 0.0, 0.0);
static const vec4d_t vec4d_unitY(0.0, 1.0, 0.0, 0.0);
static const vec4d_t vec4d_unitZ(0.0, 0.0, 1.0, 0.0);
static const vec4d_t vec4d_unitW(0.0, 0.0, 0.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif // SWAY_MATH_VECTOR4_H
