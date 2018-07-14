#include <boost/test/unit_test.hpp>
#include <sway/math.h>

using namespace sway;

BOOST_AUTO_TEST_SUITE(TColor_TestSuite)

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
BOOST_AUTO_TEST_CASE(TColor_TestCase_DefaultConstructor) {
	const math::col4f_t color;

	BOOST_CHECK_EQUAL(color.getR(), 0.0f);
	BOOST_CHECK_EQUAL(color.getG(), 0.0f);
	BOOST_CHECK_EQUAL(color.getB(), 0.0f);
	BOOST_CHECK_EQUAL(color.getA(), 1.0f);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те, 
 *    которые были заданы.
 */
BOOST_AUTO_TEST_CASE(TColor_TestCase_ComponentConstructor) {
	const f32_t r = 0.1f, g = 0.2f, b = 0.3f, a = 1.0f;
	const math::col4f_t color(r, g, b, a);

	BOOST_CHECK_EQUAL(color.getR(), r);
	BOOST_CHECK_EQUAL(color.getG(), g);
	BOOST_CHECK_EQUAL(color.getB(), b);
	BOOST_CHECK_EQUAL(color.getA(), a);
}

/*!
 * \brief
 *    Убеждаемся, что преобразование в TVector4<type> проходит правильно.
 */
BOOST_AUTO_TEST_CASE(TColor_TestCase_ConvertToVector4) {
	const f32_t r = 0.1f, g = 0.2f, b = 0.3f, a = 1.0f;

	math::col4f_t color(r, g, b, a);
	math::vec4f_t vec4 = color.toVec4();

	BOOST_CHECK_EQUAL(vec4.getX(), r);
	BOOST_CHECK_EQUAL(vec4.getY(), g);
	BOOST_CHECK_EQUAL(vec4.getZ(), b);
	BOOST_CHECK_EQUAL(vec4.getW(), a);
}

BOOST_AUTO_TEST_SUITE_END()
