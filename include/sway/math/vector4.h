#ifndef SWAY_MATH_VECTOR4_H
#define SWAY_MATH_VECTOR4_H

#include <sway/core.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/*!
 * \brief
 *    Шаблонный класс представления вектора из четырех компонентов.
 */
template <typename type_t>
class TVector4 final {
public:
	/*!
	 * \brief 
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
	 * 
	 * \sa
	 *    TVector4(type_t, type_t, type_t, type_t)
	 */
	TVector4() {
		_x = _y = _z = _w = (type_t) 0;
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
	TVector4(type_t x, type_t y, type_t z, type_t w) {
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
	void set(type_t x, type_t y, type_t z, type_t w) {
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
	type_t getX() const {
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
	type_t getY() const {
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
	type_t getZ() const {
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
	type_t getW() const {
		return _w;
	}

private:
	type_t _x, _y, _z, _w;
};

typedef TVector4<s32_t> vec4i_t;
typedef TVector4<f32_t> vec4f_t;
typedef TVector4<f64_t> vec4d_t;

static const vec4i_t kVec4i_Zero(0, 0, 0, 0);
static const vec4i_t kVec4i_One(1, 1, 1 ,1);
static const vec4i_t kVec4i_UnitX(1, 0, 0, 0);
static const vec4i_t kVec4i_UnitY(0, 1, 0, 0);
static const vec4i_t kVec4i_UnitZ(0, 0, 1, 0);
static const vec4i_t kVec4i_UnitW(0, 0, 0, 1);

static const vec4f_t kVec4f_Zero(0.0f, 0.0f, 0.0f, 0.0f);
static const vec4f_t kVec4f_One(1.0f, 1.0f, 1.0f, 1.0f);
static const vec4f_t kVec4f_UnitX(1.0f, 0.0f, 0.0f, 0.0f);
static const vec4f_t kVec4f_UnitY(0.0f, 1.0f, 0.0f, 0.0f);
static const vec4f_t kVec4f_UnitZ(0.0f, 0.0f, 1.0f, 0.0f);
static const vec4f_t kVec4f_UnitW(0.0f, 0.0f, 0.0f, 1.0f);

static const vec4d_t kVec4d_Zero(0.0, 0.0, 0.0, 0.0);
static const vec4d_t kVec4d_One(1.0, 1.0, 1.0, 1.0);
static const vec4d_t kVec4d_UnitX(1.0, 0.0, 0.0, 0.0);
static const vec4d_t kVec4d_UnitY(0.0, 1.0, 0.0, 0.0);
static const vec4d_t kVec4d_UnitZ(0.0, 0.0, 1.0, 0.0);
static const vec4d_t kVec4d_UnitW(0.0, 0.0, 0.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif // SWAY_MATH_VECTOR4_H
