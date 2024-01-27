#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(Vector3, DefaultConstructor) {
  math::vec3i_t vec3;

  ASSERT_EQ(vec3.getX(), 0);
  ASSERT_EQ(vec3.getY(), 0);
  ASSERT_EQ(vec3.getZ(), 0);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(Vector3, ComponentConstructor) {
  s32_t x = 1, y = 2, z = 3;
  math::vec3i_t vec3(x, y, z);

  ASSERT_EQ(vec3.getX(), x);
  ASSERT_EQ(vec3.getY(), y);
  ASSERT_EQ(vec3.getZ(), z);
}

TEST(Vector3, Size) { ASSERT_EQ(math::vec3i_t::DataElementCount_t, 3); }

TEST(Vector3, Divide) {
  math::vec3i_t vec3(4, 6, 8);
  vec3.divide(2);

  EXPECT_TRUE(vec3.equals(math::vec3i_t(2, 3, 4)));
}

TEST(Vector3, Added) {
  math::vec3i_t vec3(1, 2, 3);

  vec3 = vec3.add(math::vec3i_t(2, 1, 0));
  EXPECT_TRUE(vec3.equals(math::vec3i_t(3, 3, 3)));

  vec3 = vec3 + math::vec3i_t(1, 1, 1);
  EXPECT_TRUE(vec3.equals(math::vec3i_t(4, 4, 4)));

  vec3 += math::vec3i_t(1, 1, 1);
  EXPECT_TRUE(vec3.equals(math::vec3i_t(5, 5, 5)));
}

TEST(Vector3, Subtract) {
  const math::vec3i_t a(1, 2, 3);
  const math::vec3i_t b(1, 1, 1);

  auto res = a - b;
  EXPECT_TRUE(res.equals(math::vec3i_t(0, 1, 2)));
}

TEST(Vector3, Dot) {
  const math::vec3i_t a(1, 2, 3);
  const math::vec3i_t b(1, 1, 1);

  auto res = math::vec3i_t::dot(a, b);
  EXPECT_TRUE(res == 6);
}

TEST(Vector3, Normalize) {
  auto res = math::vec3f_t::normalize(math::vec3f_t(1.0F, 2.0F, 3.0F));
  auto frm = core::misc::format("[%f, %f, %f]", res.getX(), res.getY(), res.getZ());
  EXPECT_TRUE(frm == std::string("[0.267261, 0.534522, 0.801784]"));
}
