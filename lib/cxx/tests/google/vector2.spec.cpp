#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(Vector2, DefaultCtor) {
  math::vec2i_t vec2;

  ASSERT_EQ(vec2.getX(), 0);
  ASSERT_EQ(vec2.getY(), 0);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(Vector2, ComponentCtor) {
  auto x = 1, y = 2;
  math::vec2i_t vec2(x, y);

  ASSERT_EQ(vec2.getX(), x);
  ASSERT_EQ(vec2.getY(), y);
}

TEST(Vector2, Size) {
  ASSERT_EQ(math::vec2i_t::DataElementCount_t, 2);
  ASSERT_EQ(math::vec2i_t::DataSize_t, 8);
}

TEST(Vector2, Lerp) {
  auto step = 0.5F;
  math::vec2f_t from(2.0F, -2.0F);
  math::vec2f_t to(4.0F, 4.0F);

  ASSERT_EQ(from.lerp(to, step).array(), math::vec2f_t(3.0f, 1.0f).array());
}
