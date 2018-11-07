#include <boost/test/unit_test.hpp>
#include <sway/math.h>

using namespace sway;

BOOST_AUTO_TEST_SUITE(TVector3_TestSuite)

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
BOOST_AUTO_TEST_CASE(TVector3_TestCase_DefaultConstructor) {
	math::vec3i_t vec3;

	BOOST_CHECK_EQUAL(vec3.getX(), 0);
	BOOST_CHECK_EQUAL(vec3.getY(), 0);
	BOOST_CHECK_EQUAL(vec3.getZ(), 0);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те, 
 *    которые были заданы.
 */
BOOST_AUTO_TEST_CASE(TVector3_TestCase_ComponentConstructor) {
	s32_t x = 1, y = 2, z = 3;
	math::vec3i_t vec3(x, y, z);

	BOOST_CHECK_EQUAL(vec3.getX(), x);
	BOOST_CHECK_EQUAL(vec3.getY(), y);
	BOOST_CHECK_EQUAL(vec3.getZ(), z);
}

BOOST_AUTO_TEST_CASE(TVector3_TestCase_Size) {
	BOOST_CHECK_EQUAL(math::vec3i_t::size, 3);
}

BOOST_AUTO_TEST_SUITE_END()
