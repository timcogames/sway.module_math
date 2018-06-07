#include <boost/test/unit_test.hpp>

#include <sway/math.h>

using namespace sway;

BOOST_AUTO_TEST_SUITE(TPointTestSuite)

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
BOOST_AUTO_TEST_CASE(TPointTestCase_DefaultConstructor) {
	const math::TPoint<s32_t> point;

	BOOST_CHECK_EQUAL(point.getX(), 0);
	BOOST_CHECK_EQUAL(point.getY(), 0);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те, 
 *    которые были заданы.
 */
BOOST_AUTO_TEST_CASE(TPointTestCase_ComponentConstructor) {
	const s32_t x = 1, y = 2;
	const math::TPoint<s32_t> point(x, y);

	BOOST_CHECK_EQUAL(point.getX(), x);
	BOOST_CHECK_EQUAL(point.getY(), y);
}

BOOST_AUTO_TEST_CASE(TPointTestCase_ScalarConstructor) {
	const s32_t x = 1, y = 2;
	const math::TPoint<s32_t> size(math::TPoint<s32_t>(x, y));

	BOOST_CHECK_EQUAL(size.getX(), x);
	BOOST_CHECK_EQUAL(size.getY(), y);
}

/*!
 * \brief
 *    Тест для оператора равенства.
 */
BOOST_AUTO_TEST_CASE(TPointTestCase_EqualityOperator1) {
	const math::TPoint<s32_t> point1(0, 0), point2(0, 0);

	BOOST_CHECK_EQUAL(point1 == point2, true);
}

/*!
 * \brief
 *    Тест для оператора равенства.
 */
BOOST_AUTO_TEST_CASE(TPointTestCase_EqualityOperator2) {
	const math::TPoint<s32_t> point1(1, 0), point2(0, 0);

	BOOST_CHECK_EQUAL(point1 == point2, false);
}

/*!
 * \brief
 *    Тест для оператора равенства.
 */
BOOST_AUTO_TEST_CASE(TPointTestCase_EqualityOperator3) {
	const math::TPoint<s32_t> point1(0, 0), point2(0, 2);

	BOOST_CHECK_EQUAL(point1 == point2, false);
}

/*!
 * \brief
 *    Тест для оператора неравенства.
 */
BOOST_AUTO_TEST_CASE(TPointTestCase_NonEqualityOperator1) {
	const math::TPoint<s32_t> point1(1, 2), point2(1, 2);

	BOOST_CHECK_EQUAL(point1 != point2, false);
}

/*!
 * \brief
 *    Тест для оператора неравенства.
 */
BOOST_AUTO_TEST_CASE(TPointTestCase_NonEqualityOperator2) {
	const math::TPoint<s32_t> point1(1, 2), point2(0, 2);

	BOOST_CHECK_EQUAL(point1 != point2, true);
}

/*!
 * \brief
 *    Тест для оператора неравенства.
 */
BOOST_AUTO_TEST_CASE(TPointTestCase_NonEqualityOperator3) {
	const math::TPoint<s32_t> point1(1, 2), point2(1, 0);

	BOOST_CHECK_EQUAL(point1 != point2, true);
}

BOOST_AUTO_TEST_SUITE_END()
