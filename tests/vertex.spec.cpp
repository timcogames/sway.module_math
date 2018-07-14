#include <boost/test/unit_test.hpp>
#include <sway/math.h>

using namespace sway;

BOOST_AUTO_TEST_SUITE(Vertex_TestSuite)

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
BOOST_AUTO_TEST_CASE(VertexPosition_TestCase_DefaultConstructor) {
	const math::VertexPosition vertex;

	BOOST_CHECK_EQUAL(vertex.x, 0.0f);
	BOOST_CHECK_EQUAL(vertex.y, 0.0f);
	BOOST_CHECK_EQUAL(vertex.z, 0.0f);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те, 
 *    которые были заданы.
 */
BOOST_AUTO_TEST_CASE(VertexPosition_TestCase_ComponentConstructor) {
	const math::VertexPosition vertex(math::vec3f_t(1.0f, 2.0f, 3.0f));
	const math::vec3f_t position = vertex.getPosition();

	BOOST_CHECK_EQUAL(position.getX(), 1.0f);
	BOOST_CHECK_EQUAL(position.getY(), 2.0f);
	BOOST_CHECK_EQUAL(position.getZ(), 3.0f);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
BOOST_AUTO_TEST_CASE(VertexColor_TestCase_DefaultConstructor) {
	const math::VertexColor vertex;
	
	BOOST_CHECK_EQUAL(vertex.x, 0.0f);
	BOOST_CHECK_EQUAL(vertex.y, 0.0f);
	BOOST_CHECK_EQUAL(vertex.z, 0.0f);

	BOOST_CHECK_EQUAL(vertex.r, 0.0f);
	BOOST_CHECK_EQUAL(vertex.g, 0.0f);
	BOOST_CHECK_EQUAL(vertex.b, 0.0f);
	BOOST_CHECK_EQUAL(vertex.a, 0.0f);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те, 
 *    которые были заданы.
 */
BOOST_AUTO_TEST_CASE(VertexColor_TestCase_ComponentConstructor) {
	const math::VertexColor vertex(math::vec3f_t(1.0f, 2.0f, 3.0f), math::col4f_t(0.1f, 0.2f, 0.3f));
	const math::vec3f_t position = vertex.getPosition();
	const math::col4f_t color = vertex.getColor();

	BOOST_CHECK_EQUAL(position.getX(), 1.0f);
	BOOST_CHECK_EQUAL(position.getY(), 2.0f);
	BOOST_CHECK_EQUAL(position.getZ(), 3.0f);

	BOOST_CHECK_EQUAL(color.getR(), 0.1f);
	BOOST_CHECK_EQUAL(color.getG(), 0.2f);
	BOOST_CHECK_EQUAL(color.getB(), 0.3f);
	BOOST_CHECK_EQUAL(color.getA(), 1.0f);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
BOOST_AUTO_TEST_CASE(VertexTexCoord_TestCase_DefaultConstructor) {
	const math::VertexTexCoord vertex;
	
	BOOST_CHECK_EQUAL(vertex.x, 0.0f);
	BOOST_CHECK_EQUAL(vertex.y, 0.0f);
	BOOST_CHECK_EQUAL(vertex.z, 0.0f);

	BOOST_CHECK_EQUAL(vertex.u, 0.0f);
	BOOST_CHECK_EQUAL(vertex.v, 0.0f);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те, 
 *    которые были заданы.
 */
BOOST_AUTO_TEST_CASE(VertexTexCoord_TestCase_ComponentConstructor) {
	const math::VertexTexCoord vertex(math::vec3f_t(1.0f, 2.0f, 3.0f), math::vec2f_t(0.1f, 0.2f));
	const math::vec3f_t position = vertex.getPosition();
	const math::vec2f_t texcoord = vertex.getTexCoord();

	BOOST_CHECK_EQUAL(position.getX(), 1.0f);
	BOOST_CHECK_EQUAL(position.getY(), 2.0f);
	BOOST_CHECK_EQUAL(position.getZ(), 3.0f);

	BOOST_CHECK_EQUAL(texcoord.getX(), 0.1f);
	BOOST_CHECK_EQUAL(texcoord.getY(), 0.2f);
}

BOOST_AUTO_TEST_SUITE_END()
