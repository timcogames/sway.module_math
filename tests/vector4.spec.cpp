#include <boost/test/unit_test.hpp>
#include <sway/math.h>

using namespace sway;

BOOST_AUTO_TEST_SUITE(TVector4_TestSuite)

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
BOOST_AUTO_TEST_CASE(TVector4_TestCase_DefaultConstructor) {
	math::vec4i_t vec4;

	BOOST_CHECK_EQUAL(vec4.getX(), 0);
	BOOST_CHECK_EQUAL(vec4.getY(), 0);
	BOOST_CHECK_EQUAL(vec4.getZ(), 0);
	BOOST_CHECK_EQUAL(vec4.getW(), 0);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те, 
 *    которые были заданы.
 */
BOOST_AUTO_TEST_CASE(TVector4_TestCase_ComponentConstructor) {
	s32_t x = 1, y = 2, z = 3, w = 4;
	math::vec4i_t vec4(x, y, z, w);

	BOOST_CHECK_EQUAL(vec4.getX(), x);
	BOOST_CHECK_EQUAL(vec4.getY(), y);
	BOOST_CHECK_EQUAL(vec4.getZ(), z);
	BOOST_CHECK_EQUAL(vec4.getW(), w);
}

BOOST_AUTO_TEST_CASE(TVector4_TestCase_Size) {
	BOOST_CHECK_EQUAL(math::vec4i_t::size(), 4);
}

BOOST_AUTO_TEST_SUITE_END()
