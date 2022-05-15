#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(TVector3, DefaultConstructor) {
  math::vec3i_t vec3;

  ASSERT_EQ(vec3.getX(), 0);
  ASSERT_EQ(vec3.getY(), 0);
  ASSERT_EQ(vec3.getZ(), 0);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *    которые были заданы.
 */
TEST(TVector3, ComponentConstructor) {
  s32_t x = 1, y = 2, z = 3;
  math::vec3i_t vec3(x, y, z);

  ASSERT_EQ(vec3.getX(), x);
  ASSERT_EQ(vec3.getY(), y);
  ASSERT_EQ(vec3.getZ(), z);
}

TEST(TVector3, Size) { ASSERT_EQ(math::vec3i_t::size, 3); }

TEST(TVector3, Divide) {
  math::vec3i_t vec3(4, 6, 8);
  vec3.divide(2);

  EXPECT_TRUE(vec3.equals(math::vec3i_t(2, 3, 4)));
}
