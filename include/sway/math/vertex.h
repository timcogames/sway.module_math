#ifndef SWAY_MATH_VERTEX_H
#define SWAY_MATH_VERTEX_H

#include <sway/math/vector2.h>
#include <sway/math/vector3.h>
#include <sway/math/color.h>
#include <sway/core.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

/*!
 * \brief
 *    Базовая структура представления вершины.
 * 
 * \node
 *    Содержит только позицию вершины.
 */
struct VertexPosition {
	f32_t x, y, z;

	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \sa
	 *    VertexPosition(const TVector3<f32_t> &)
	 */
	VertexPosition() {
		x = y = z = 0.0f;
	}

	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \sa
	 *    VertexPosition()
	 */
	VertexPosition(const TVector3<f32_t> & position) {
		setPosition(position);
	}

	/*!
	 * \brief
	 *    Устанавливает позицию вершины.
	 *
	 * \param[in] position 
	 *    Значение позиции вершины.
	 */
	void setPosition(const TVector3<f32_t> & position) {
		x = position.getX();
		y = position.getY();
		z = position.getZ();
	}

	/*!
	 * \brief
	 *    Получает позицию вершины.
	 */
	TVector3<f32_t> getPosition() const {
		return TVector3<f32_t>(x, y, z);
	}
};

/*!
 * \brief
 *    Структура представления вершины.
 * 
 * \node
 *    Содержит позицию и цвет вершины.
 */
struct VertexColor : public VertexPosition {
	f32_t r, g, b, a;

	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \sa
	 *    VertexColor(const TVector3<f32_t> &, const TColor<f32_t> &)
	 */
	VertexColor() {
		r = g = b = a = 0.0f;
	}

	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \sa
	 *    VertexColor()
	 */
	VertexColor(const TVector3<f32_t> & position, const TColor<f32_t> & color)
		: VertexPosition(position) {
		setColor(color);
	}

	/*!
	 * \brief
	 *    Устанавливает цвет вершины.
	 *
	 * \param[in] color 
	 *    Значение цвета вершины.
	 */
	void setColor(const TColor<f32_t> & color) {
		r = color.getR();
		g = color.getG();
		b = color.getB();
		a = color.getA();
	}

	/*!
	 * \brief
	 *    Получает цвет вершины.
	 */
	TColor<f32_t> getColor() const {
		return TColor<f32_t>(r, g, b, a);
	}
};

/*!
 * \brief
 *    Структура представления вершины.
 * 
 * \node
 *    Содержит позицию, цвет и текстурные координаты вершины.
 */
struct VertexTexCoord : public VertexPosition {
	f32_t u, v;

	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \sa
	 *    VertexTexCoord(const TVector3<f32_t> &, const TVector2<f32_t> &)
	 */
	VertexTexCoord() {
		u = v = 0.0f;
	}

	/*!
	 * \brief
	 *    Конструктор класса.
	 *
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \sa
	 *    VertexTexCoord()
	 */
	VertexTexCoord(const TVector3<f32_t> & position, const TVector2<f32_t> & texCoord)
		: VertexPosition(position) {
		setTexCoord(texCoord);
	}

	/*!
	 * \brief
	 *    Устанавливает текстурные координаты.
	 *
	 * \param[in] texCoord 
	 *    Значение текстурных координат.
	 */
	void setTexCoord(const TVector2<f32_t> & texCoord) {
		u = texCoord.getX();
		v = texCoord.getY();
	}

	/*!
	 * \brief
	 *    Получает текстурные координаты.
	 */
	TVector2<f32_t> getTexCoord() const {
		return TVector2<f32_t>(u, v);
	}
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif // SWAY_MATH_VERTEX_H
