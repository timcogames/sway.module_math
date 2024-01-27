#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(Vector4, DefaultCtor) {
  math::vec4i_t vec;

  ASSERT_EQ(vec.getX(), 0);
  ASSERT_EQ(vec.getY(), 0);
  ASSERT_EQ(vec.getZ(), 0);
  ASSERT_EQ(vec.getW(), 0);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(Vector4, ComponentCtor) {
  const auto x = 1, y = 2, z = 3, w = 4;
  math::vec4i_t vec(x, y, z, w);

  ASSERT_EQ(vec.getX(), x);
  ASSERT_EQ(vec.getY(), y);
  ASSERT_EQ(vec.getZ(), z);
  ASSERT_EQ(vec.getW(), w);
}

TEST(Vector4, Size) { ASSERT_EQ(math::vec4i_t::DataElementCount_t, 4); }
