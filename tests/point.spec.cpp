#include <boost/test/unit_test.hpp>
#include <sway/math.h>

using namespace sway;

BOOST_AUTO_TEST_SUITE(TPoint_TestSuite)

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
BOOST_AUTO_TEST_CASE(TPoint_TestCase_DefaultConstructor) {
	const math::point2i_t point;

	BOOST_CHECK_EQUAL(point.getX(), 0);
	BOOST_CHECK_EQUAL(point.getY(), 0);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те, 
 *    которые были заданы.
 */
BOOST_AUTO_TEST_CASE(TPoint_TestCase_ComponentConstructor) {
	const s32_t x = 1, y = 2;
	const math::point2i_t point(x, y);

	BOOST_CHECK_EQUAL(point.getX(), x);
	BOOST_CHECK_EQUAL(point.getY(), y);
}

BOOST_AUTO_TEST_CASE(TPoint_TestCase_ScalarConstructor) {
	const math::point2i_t size(math::point2i_one);

	BOOST_CHECK_EQUAL(size.getX(), 1);
	BOOST_CHECK_EQUAL(size.getY(), 1);
}

/*!
 * \brief
 *    Тест для оператора равенства.
 */
BOOST_AUTO_TEST_CASE(TPoint_TestCase_EqualityOperator) {
	const math::point2i_t point(0, 0);

	BOOST_CHECK_EQUAL(point == math::point2i_zero, true);
	BOOST_CHECK_EQUAL(point == math::point2i_one, false);
}

/*!
 * \brief
 *    Тест для оператора неравенства.
 */
BOOST_AUTO_TEST_CASE(TPoint_TestCase_NonEqualityOperator) {
	const math::point2i_t point(1, 1);

	BOOST_CHECK_EQUAL(point != math::point2i_zero, true);
	BOOST_CHECK_EQUAL(point != math::point2i_one, false);
}

BOOST_AUTO_TEST_SUITE_END()
