#include <boost/test/unit_test.hpp>
#include <sway/math.h>

using namespace sway;

BOOST_AUTO_TEST_SUITE(TRect_TestSuite)

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
BOOST_AUTO_TEST_CASE(TRect_TestCase_DefaultConstructor) {
	const math::rect4i_t rect;

	BOOST_CHECK_EQUAL(rect.getL(), 0);
	BOOST_CHECK_EQUAL(rect.getT(), 0);
	BOOST_CHECK_EQUAL(rect.getR(), 0);
	BOOST_CHECK_EQUAL(rect.getB(), 0);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те, 
 *    которые были заданы.
 */
BOOST_AUTO_TEST_CASE(TRect_TestCase_ComponentConstructor) {
	const s32_t x = 8, y = 16, w = 32, h = 64;
	const math::rect4i_t rect(x, y, w, h);

	BOOST_CHECK_EQUAL(rect.getL(), x);
	BOOST_CHECK_EQUAL(rect.getT(), y);
	BOOST_CHECK_EQUAL(rect.getR(), x + w);
	BOOST_CHECK_EQUAL(rect.getB(), y + h);
	BOOST_CHECK_EQUAL(rect.getW(), w);
	BOOST_CHECK_EQUAL(rect.getH(), h);
}

BOOST_AUTO_TEST_CASE(TRect_TestCase_Offset) {
	const s32_t x = 8, y = 16, w = 32, h = 64;
	const s32_t xoffset = 2, yoffset = 4;

	math::rect4i_t rect(x, y, w, h);
	rect.offset(xoffset, yoffset);

	BOOST_CHECK_EQUAL(rect.getL(), x + xoffset);
	BOOST_CHECK_EQUAL(rect.getT(), y + yoffset);
	BOOST_CHECK_EQUAL(rect.getR(), x + xoffset + w);
	BOOST_CHECK_EQUAL(rect.getB(), y + yoffset + h);
	BOOST_CHECK_EQUAL(rect.getW(), w);
	BOOST_CHECK_EQUAL(rect.getH(), h);
}

/*!
 * \brief
 *    Убеждаемся, что преобразование в TSize<type> проходит правильно.
 */
BOOST_AUTO_TEST_CASE(TRect_TestCase_ConvertToSize) {
	const s32_t x = 8, y = 16, w = 32, h = 64;

	math::rect4i_t rect(x, y, w, h);
	math::size2i_t size = rect.toSize();

	BOOST_CHECK_EQUAL(size.getW(), w);
	BOOST_CHECK_EQUAL(size.getH(), h);
}

BOOST_AUTO_TEST_CASE(TRect_TestCase_IsEmpty) {
	BOOST_CHECK(math::TRect<s32_t>(0, 0, 0, 32).isEmpty());
	BOOST_CHECK(math::TRect<s32_t>(0, 0, 32, 0).isEmpty());
	BOOST_CHECK_EQUAL(math::TRect<s32_t>(0, 0, 32, 32).isEmpty(), false);
}

BOOST_AUTO_TEST_SUITE_END()
