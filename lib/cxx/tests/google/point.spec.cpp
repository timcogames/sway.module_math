#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(Point, DefaultCtor) {
  math::point2i_t pnt;

  ASSERT_EQ(pnt.getX(), 0);
  ASSERT_EQ(pnt.getY(), 0);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(Point, ComponentCtor) {
  const auto x = 1, y = 2;
  math::point2i_t pnt(x, y);

  ASSERT_EQ(pnt.getX(), x);
  ASSERT_EQ(pnt.getY(), y);
}

TEST(Point, ScalarConstructor) {
  math::point2i_t pnt(math::point2i_one);

  ASSERT_EQ(pnt.getX(), 1);
  ASSERT_EQ(pnt.getY(), 1);
}

/**
 * @brief Тест для оператора равенства.
 */
TEST(Point, EqualityOperator) {
  math::point2i_t pnt(0, 0);

  EXPECT_TRUE(pnt == math::point2i_zero);
  EXPECT_FALSE(pnt == math::point2i_one);
}

/**
 * @brief Тест для оператора неравенства.
 */
TEST(Point, NonEqualityOperator) {
  math::point2i_t pnt(1, 1);

  EXPECT_TRUE(pnt != math::point2i_zero);
  EXPECT_FALSE(pnt != math::point2i_one);
}
