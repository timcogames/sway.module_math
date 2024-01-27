#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(Vector4, DefaultConstructor) {
  math::vec4i_t vec4;

  ASSERT_EQ(vec4.getX(), 0);
  ASSERT_EQ(vec4.getY(), 0);
  ASSERT_EQ(vec4.getZ(), 0);
  ASSERT_EQ(vec4.getW(), 0);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(Vector4, ComponentConstructor) {
  s32_t x = 1, y = 2, z = 3, w = 4;
  math::vec4i_t vec4(x, y, z, w);

  ASSERT_EQ(vec4.getX(), x);
  ASSERT_EQ(vec4.getY(), y);
  ASSERT_EQ(vec4.getZ(), z);
  ASSERT_EQ(vec4.getW(), w);
}

TEST(Vector4, Size) { ASSERT_EQ(math::vec4i_t::DataElementCount_t, 4); }
