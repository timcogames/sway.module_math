#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(Size, DefaultCtor) {
  math::size2i_t size;

  ASSERT_EQ(size.getW(), 0);
  ASSERT_EQ(size.getH(), 0);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(Size, ComponentCtor) {
  const auto w = 1, h = 2;
  math::size2i_t size(w, h);

  ASSERT_EQ(size.getW(), w);
  ASSERT_EQ(size.getH(), h);
}

TEST(Size, ScalarConstructor) {
  const auto w = 1, h = 2;
  math::size2i_t size(math::Size<s32_t>(w, h));

  ASSERT_EQ(size.getW(), w);
  ASSERT_EQ(size.getH(), h);
}

/**
 * @brief Тест для оператора равенства.
 */
TEST(Size, EqualityOperator) {
  math::size2i_t size(1, 2);

  EXPECT_TRUE(size == math::size2i_t(1, 2));
  EXPECT_FALSE(size == math::size2i_one);
}

/**
 * @brief Тест для оператора неравенства.
 */
TEST(Size, NonEqualityOperator) {
  math::size2i_t size(2, 1);

  EXPECT_TRUE(size != math::size2i_one);
  EXPECT_FALSE(size != math::size2i_t(2, 1));
}

TEST(Size, MultiplyOperator) {
  math::size2i_t size(2, 7);
  size = size * 3;

  EXPECT_TRUE(size == math::size2i_t(6, 21));
}

TEST(Size, DivideOperator) {
  math::size2i_t size(4, 16);
  size = size / 2;

  EXPECT_TRUE(size == math::size2i_t(2, 8));
}

TEST(Size, ToString) { EXPECT_STREQ(std::to_string(math::size2i_t(1, 2)).c_str(), "{w: 1, h: 2}"); }
