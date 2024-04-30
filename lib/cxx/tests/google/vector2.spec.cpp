#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(vec2i, default_ctor) {
  math::vec2i_t vec;

  ASSERT_EQ(vec.getX(), 0);
  ASSERT_EQ(vec.getY(), 0);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(vec2i, component_ctor) {
  const auto x = 1, y = 2;
  math::vec2i_t vec(x, y);

  ASSERT_EQ(vec.getX(), x);
  ASSERT_EQ(vec.getY(), y);
}

TEST(vec2i, equals) {
  const auto x = 1, y = 2;
  math::vec2i_t vec(x, y);

  ASSERT_TRUE(vec.equals(math::vec2i_t(x, y)));
}

TEST(vec2i, size) {
  ASSERT_EQ(math::vec2i_t::DataElementCount_t, 2);
  ASSERT_EQ(math::vec2i_t::DataSize_t, 8);
}

TEST(vec2f, lerp) {
  const auto step = 0.5F;
  math::vec2f_t from(2.0F, -2.0F);
  math::vec2f_t to(4.0F, 4.0F);

  ASSERT_EQ(from.lerp(to, step).array(), math::vec2f_t(3.0F, 1.0F).array());
}
