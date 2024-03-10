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
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(Rect, ArrayCtor) {
  std::array<s32_t, 4> arr = {8, 16, 32, 64};
  math::rect4i_t rect(arr);

  ASSERT_EQ(rect.getL(), 8);
  ASSERT_EQ(rect.getT(), 16);
  ASSERT_EQ(rect.getR(), 32);
  ASSERT_EQ(rect.getB(), 64);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(Rect, ComponentCtor) {
  const auto x = 8, y = 16, xw = 24, yh = 32;
  math::rect4i_t rect(x, y, xw, yh);

  ASSERT_EQ(rect.getL(), x);
  ASSERT_EQ(rect.getT(), y);
  ASSERT_EQ(rect.getR(), xw);
  ASSERT_EQ(rect.getB(), yh);
  ASSERT_EQ(rect.getW(), xw - x);
  ASSERT_EQ(rect.getH(), yh - y);
}

TEST(Rect, OffsetPositive) {
  const auto x = 8, y = 16, xw = 24, yh = 32;
  const auto xoffset = 2, yoffset = 4;

  math::rect4i_t rect(x, y, xw, yh);
  rect.offset(xoffset, yoffset);

  ASSERT_EQ(rect.getL(), x + xoffset);
  ASSERT_EQ(rect.getT(), y + yoffset);
  ASSERT_EQ(rect.getR(), xw + xoffset);
  ASSERT_EQ(rect.getB(), yh + yoffset);
  ASSERT_EQ(rect.getW(), xw - x);
  ASSERT_EQ(rect.getH(), yh - y);
}

TEST(Rect, OffsetNegative) {
  const auto x = -24, y = -32, xw = -8, yh = -16;
  const auto xoffset = 2, yoffset = 4;

  math::rect4i_t rect(x, y, xw, yh);
  rect.offset(xoffset, yoffset);

  ASSERT_EQ(rect.getL(), x + xoffset);
  ASSERT_EQ(rect.getT(), y + yoffset);
  ASSERT_EQ(rect.getR(), xw + xoffset);
  ASSERT_EQ(rect.getB(), yh + yoffset);
  ASSERT_EQ(rect.getW(), xw - x);
  ASSERT_EQ(rect.getH(), yh - y);
}

/**
 * @brief Убеждаемся, что преобразование в Size<type> проходит правильно.
 */
TEST(Rect, ConvertToSize) {
  const auto x = 8, y = 16, xw = 24, yh = 32;

  math::rect4i_t rect(x, y, xw, yh);
  math::size2i_t size = rect.size();

  ASSERT_EQ(size.getW(), xw - x);
  ASSERT_EQ(size.getH(), yh - y);
}

TEST(Rect, IsEmpty) {
  ASSERT_TRUE(math::Rect<s32_t>(0, 0, 0, 32).empty());
  ASSERT_TRUE(math::Rect<s32_t>(0, 0, 32, 0).empty());
  EXPECT_FALSE(math::Rect<s32_t>(0, 0, 32, 32).empty());
}

TEST(Rect, contains) {
  ASSERT_TRUE(math::Rect<s32_t>(0, 0, 32, 16).contains(math::Point<s32_t>(24, 8)));
  ASSERT_TRUE(math::Rect<s32_t>(-16, -8, 16, 8).contains(math::Point<s32_t>(-10, 4)));
  ASSERT_FALSE(math::Rect<s32_t>(0, 0, 32, 16).contains(math::Point<s32_t>(32, 17)));
}

TEST(Rect, toString) {
  EXPECT_STREQ(std::to_string(math::rect4i_t(8, 16, 24, 32)).c_str(), "{x:8, y:16, xw:24, yh:32, w:16, h:16}");
}
