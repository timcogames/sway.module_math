#include <boost/test/unit_test.hpp>
#include <sway/math.h>

using namespace sway;

BOOST_AUTO_TEST_SUITE(TSize_TestSuite)

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
BOOST_AUTO_TEST_CASE(TSize_TestCase_DefaultConstructor) {
	const math::size2i_t size;

	BOOST_CHECK_EQUAL(size.getW(), 0);
	BOOST_CHECK_EQUAL(size.getH(), 0);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те, 
 *    которые были заданы.
 */
BOOST_AUTO_TEST_CASE(TSize_TestCase_ComponentConstructor) {
	const s32_t w = 1, h = 2;
	const math::size2i_t size(w, h);

	BOOST_CHECK_EQUAL(size.getW(), w);
	BOOST_CHECK_EQUAL(size.getH(), h);
}

BOOST_AUTO_TEST_CASE(TSize_TestCase_ScalarConstructor) {
	const s32_t w = 1, h = 2;
	const math::size2i_t size(math::TSize<s32_t>(w, h));

	BOOST_CHECK_EQUAL(size.getW(), w);
	BOOST_CHECK_EQUAL(size.getH(), h);
}

/*!
 * \brief
 *    Тест для оператора равенства.
 */
BOOST_AUTO_TEST_CASE(TSize_TestCase_EqualityOperator) {
	const math::size2i_t size(1, 2);

	BOOST_CHECK_EQUAL(size == math::size2i_t(1, 2), true);
	BOOST_CHECK_EQUAL(size == math::size2i_one, false);
}

/*!
 * \brief
 *    Тест для оператора неравенства.
 */
BOOST_AUTO_TEST_CASE(TSize_TestCase_NonEqualityOperator) {
	const math::size2i_t size(2, 1);

	BOOST_CHECK_EQUAL(size != math::size2i_one, true);
	BOOST_CHECK_EQUAL(size != math::size2i_t(2, 1), false);
}

BOOST_AUTO_TEST_SUITE_END()
