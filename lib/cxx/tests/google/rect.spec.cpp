#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(Rect, DefaultCtor) {
  math::rect4i_t rect;

  ASSERT_EQ(rect.getL(), 0);
  ASSERT_EQ(rect.getT(), 0);
  ASSERT_EQ(rect.getR(), 0);
  ASSERT_EQ(rect.getB(), 0);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(Rect, ComponentCtor) {
  const auto x = 8, y = 16, w = 32, h = 64;
  math::rect4i_t rect(x, y, w, h);

  ASSERT_EQ(rect.getL(), x);
  ASSERT_EQ(rect.getT(), y);
  ASSERT_EQ(rect.getR(), x + w);
  ASSERT_EQ(rect.getB(), y + h);
  ASSERT_EQ(rect.getW(), w);
  ASSERT_EQ(rect.getH(), h);
}

TEST(Rect, Offset) {
  const auto x = 8, y = 16, w = 32, h = 64;
  const auto xoffset = 2, yoffset = 4;

  math::rect4i_t rect(x, y, w, h);
  rect.offset(xoffset, yoffset);

  ASSERT_EQ(rect.getL(), x + xoffset);
  ASSERT_EQ(rect.getT(), y + yoffset);
  ASSERT_EQ(rect.getR(), x + xoffset + w);
  ASSERT_EQ(rect.getB(), y + yoffset + h);
  ASSERT_EQ(rect.getW(), w);
  ASSERT_EQ(rect.getH(), h);
}

/**
 * @brief Убеждаемся, что преобразование в Size<type> проходит правильно.
 */
TEST(Rect, ConvertToSize) {
  const auto x = 8, y = 16, w = 32, h = 64;

  math::rect4i_t rect(x, y, w, h);
  math::size2i_t size = rect.size();

  ASSERT_EQ(size.getW(), w);
  ASSERT_EQ(size.getH(), h);
}

TEST(Rect, IsEmpty) {
  ASSERT_TRUE(math::Rect<s32_t>(0, 0, 0, 32).empty());
  ASSERT_TRUE(math::Rect<s32_t>(0, 0, 32, 0).empty());
  EXPECT_FALSE(math::Rect<s32_t>(0, 0, 32, 32).empty());
}

TEST(Rect, contains) {
  ASSERT_TRUE(math::Rect<s32_t>(0, 0, 32, 16).contains(math::Point<s32_t>(24, 8)));
  ASSERT_FALSE(math::Rect<s32_t>(0, 0, 32, 16).contains(math::Point<s32_t>(32, 17)));
}
