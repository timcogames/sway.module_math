#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/*!
 * \brief
 *    Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(TRect, DefaultConstructor) {
  const math::rect4i_t rect;

  ASSERT_EQ(rect.getL(), 0);
  ASSERT_EQ(rect.getT(), 0);
  ASSERT_EQ(rect.getR(), 0);
  ASSERT_EQ(rect.getB(), 0);
}

/*!
 * \brief
 *    Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *    которые были заданы.
 */
TEST(TRect, ComponentConstructor) {
  const s32_t x = 8, y = 16, w = 32, h = 64;
  const math::rect4i_t rect(x, y, w, h);

  ASSERT_EQ(rect.getL(), x);
  ASSERT_EQ(rect.getT(), y);
  ASSERT_EQ(rect.getR(), x + w);
  ASSERT_EQ(rect.getB(), y + h);
  ASSERT_EQ(rect.getW(), w);
  ASSERT_EQ(rect.getH(), h);
}

TEST(TRect, Offset) {
  const s32_t x = 8, y = 16, w = 32, h = 64;
  const s32_t xoffset = 2, yoffset = 4;

  math::rect4i_t rect(x, y, w, h);
  rect.offset(xoffset, yoffset);

  ASSERT_EQ(rect.getL(), x + xoffset);
  ASSERT_EQ(rect.getT(), y + yoffset);
  ASSERT_EQ(rect.getR(), x + xoffset + w);
  ASSERT_EQ(rect.getB(), y + yoffset + h);
  ASSERT_EQ(rect.getW(), w);
  ASSERT_EQ(rect.getH(), h);
}

/*!
 * \brief
 *    Убеждаемся, что преобразование в TSize<type> проходит правильно.
 */
TEST(TRect, ConvertToSize) {
  const s32_t x = 8, y = 16, w = 32, h = 64;

  math::rect4i_t rect(x, y, w, h);
  math::size2i_t size = rect.toSize();

  ASSERT_EQ(size.getW(), w);
  ASSERT_EQ(size.getH(), h);
}

TEST(TRect, IsEmpty) {
  ASSERT_TRUE(math::TRect<s32_t>(0, 0, 0, 32).isEmpty());
  ASSERT_TRUE(math::TRect<s32_t>(0, 0, 32, 0).isEmpty());
  EXPECT_FALSE(math::TRect<s32_t>(0, 0, 32, 32).isEmpty());
}