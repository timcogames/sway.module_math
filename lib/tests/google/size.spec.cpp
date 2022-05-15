#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(TSize, DefaultConstructor) {
  const math::size2i_t size;

  ASSERT_EQ(size.getW(), 0);
  ASSERT_EQ(size.getH(), 0);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *    которые были заданы.
 */
TEST(TSize, ComponentConstructor) {
  const s32_t w = 1, h = 2;
  const math::size2i_t size(w, h);

  ASSERT_EQ(size.getW(), w);
  ASSERT_EQ(size.getH(), h);
}

TEST(TSize, ScalarConstructor) {
  const s32_t w = 1, h = 2;
  const math::size2i_t size(math::TSize<s32_t>(w, h));

  ASSERT_EQ(size.getW(), w);
  ASSERT_EQ(size.getH(), h);
}

/*!
 * \brief
 *    Тест для оператора равенства.
 */
TEST(TSize, EqualityOperator) {
  const math::size2i_t size(1, 2);

  EXPECT_TRUE(size == math::size2i_t(1, 2));
  EXPECT_FALSE(size == math::size2i_one);
}

/*!
 * \brief
 *    Тест для оператора неравенства.
 */
TEST(TSize, NonEqualityOperator) {
  const math::size2i_t size(2, 1);

  EXPECT_TRUE(size != math::size2i_one);
  EXPECT_FALSE(size != math::size2i_t(2, 1));
}
