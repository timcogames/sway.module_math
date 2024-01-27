#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(Vector3, DefaultCtor) {
  math::vec3i_t vec;

  ASSERT_EQ(vec.getX(), 0);
  ASSERT_EQ(vec.getY(), 0);
  ASSERT_EQ(vec.getZ(), 0);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(Vector3, ComponentCtor) {
  const auto x = 1, y = 2, z = 3;
  math::vec3i_t vec(x, y, z);

  ASSERT_EQ(vec.getX(), x);
  ASSERT_EQ(vec.getY(), y);
  ASSERT_EQ(vec.getZ(), z);
}

TEST(Vector3, Size) { ASSERT_EQ(math::vec3i_t::DataElementCount_t, 3); }

TEST(Vector3, Divide) {
  math::vec3i_t vec(4, 6, 8);
  vec.divide(2);

  EXPECT_TRUE(vec.equals(math::vec3i_t(2, 3, 4)));
}

TEST(Vector3, Added) {
  math::vec3i_t vec(1, 2, 3);

  vec = vec.add(math::vec3i_t(2, 1, 0));
  EXPECT_TRUE(vec.equals(math::vec3i_t(3, 3, 3)));

  vec = vec + math::vec3i_t(1, 1, 1);
  EXPECT_TRUE(vec.equals(math::vec3i_t(4, 4, 4)));

  vec += math::vec3i_t(1, 1, 1);
  EXPECT_TRUE(vec.equals(math::vec3i_t(5, 5, 5)));
}

TEST(Vector3, Subtract) {
  math::vec3i_t a(1, 2, 3);
  math::vec3i_t b(1, 1, 1);

  auto res = a - b;
  EXPECT_TRUE(res.equals(math::vec3i_t(0, 1, 2)));
}

TEST(Vector3, Dot) {
  math::vec3i_t a(1, 2, 3);
  math::vec3i_t b(1, 1, 1);

  auto res = math::vec3i_t::dot(a, b);
  EXPECT_TRUE(res == 6);
}

TEST(Vector3, Normalize) {
  auto res = math::vec3f_t::normalize(math::vec3f_t(1.0F, 2.0F, 3.0F));
  auto frm = core::misc::format("[%f, %f, %f]", res.getX(), res.getY(), res.getZ());
  EXPECT_TRUE(frm == std::string("[0.267261, 0.534522, 0.801784]"));
}
