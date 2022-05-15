#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(TPoint, DefaultConstructor) {
  const math::point2i_t point;

  ASSERT_EQ(point.getX(), 0);
  ASSERT_EQ(point.getY(), 0);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *    которые были заданы.
 */
TEST(TPoint, ComponentConstructor) {
  const s32_t x = 1, y = 2;
  const math::point2i_t point(x, y);

  ASSERT_EQ(point.getX(), x);
  ASSERT_EQ(point.getY(), y);
}

TEST(TPoint, ScalarConstructor) {
  const math::point2i_t size(math::point2i_one);

  ASSERT_EQ(size.getX(), 1);
  ASSERT_EQ(size.getY(), 1);
}

/*!
 * \brief
 *    Тест для оператора равенства.
 */
TEST(TPoint, EqualityOperator) {
  const math::point2i_t point(0, 0);

  EXPECT_TRUE(point == math::point2i_zero);
  EXPECT_FALSE(point == math::point2i_one);
}

/*!
 * \brief
 *    Тест для оператора неравенства.
 */
TEST(TPoint, NonEqualityOperator) {
  const math::point2i_t point(1, 1);

  EXPECT_TRUE(point != math::point2i_zero);
  EXPECT_FALSE(point != math::point2i_one);
}
