#ifndef SWAY_MATH_VECTOR3_H
#define SWAY_MATH_VECTOR3_H

#include <sway/core.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/*!
 * \brief
 *    Шаблонный класс представления вектора из трех компонентов.
 */
template <typename type_t>
class TVector3 final {
public:
	/*!
	 * \brief 
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса с нулевыми координатами.
	 * 
	 * \sa
	 *    TVector3(type_t, type_t, type_t)
	 */
	TVector3() {
		_x = _y = _z = (type_t) 0;
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
	 * \sa
	 *    TVector3()
	 */
	TVector3(type_t x, type_t y, type_t z) {
		set(x, y, z);
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
	 */
	void set(type_t x, type_t y, type_t z) {
		_x = x;
		_y = y;
		_z = z;
	}

	/*!
	 * \brief
	 *    Получает значение X компонента.
	 *
	 * \sa
	 *    getY() const
	 *    getZ() const
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
	 */
	type_t getZ() const {
		return _z;
	}

private:
	type_t _x, _y, _z;
};

typedef TVector3<s32_t> vec3i_t;
typedef TVector3<f32_t> vec3f_t;
typedef TVector3<f64_t> vec3d_t;

static const vec3i_t vec3i_zero(0, 0, 0);
static const vec3i_t vec3i_one(1, 1, 1);
static const vec3i_t vec3i_unitX(1, 0, 0);
static const vec3i_t vec3i_unitY(0, 1, 0);
static const vec3i_t vec3i_unitZ(0, 0, 1);

static const vec3f_t vec3f_zero(0.0f, 0.0f, 0.0f);
static const vec3f_t vec3f_one(1.0f, 1.0f, 1.0f);
static const vec3f_t vec3f_unitX(1.0f, 0.0f, 0.0f);
static const vec3f_t vec3f_unitY(0.0f, 1.0f, 0.0f);
static const vec3f_t vec3f_unitZ(0.0f, 0.0f, 1.0f);

static const vec3d_t vec3d_zero(0.0, 0.0, 0.0);
static const vec3d_t vec3d_one(1.0, 1.0, 1.0);
static const vec3d_t vec3d_unitX(1.0, 0.0, 0.0);
static const vec3d_t vec3d_unitY(0.0, 1.0, 0.0);
static const vec3d_t vec3d_unitZ(0.0, 0.0, 1.0);

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif // SWAY_MATH_VECTOR3_H
