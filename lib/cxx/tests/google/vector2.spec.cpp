#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(Vector2, DefaultConstructor) {
  math::vec2i_t vec2;

  ASSERT_EQ(vec2.getX(), 0);
  ASSERT_EQ(vec2.getY(), 0);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(Vector2, ComponentConstructor) {
  s32_t x = 1, y = 2;
  math::vec2i_t vec2(x, y);

  ASSERT_EQ(vec2.getX(), x);
  ASSERT_EQ(vec2.getY(), y);
}

TEST(Vector2, Size) { ASSERT_EQ(math::vec2i_t::DataElementCount_t, 2); }
