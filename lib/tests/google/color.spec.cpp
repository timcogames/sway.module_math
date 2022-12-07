#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(TColor, DefaultConstructor) {
  const math::col4f_t color;

  ASSERT_EQ(color.getR(), 0.0f);
  ASSERT_EQ(color.getG(), 0.0f);
  ASSERT_EQ(color.getB(), 0.0f);
  ASSERT_EQ(color.getA(), 1.0f);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(TColor, ComponentConstructor) {
  const f32_t r = 0.1f, g = 0.2f, b = 0.3f, a = 1.0f;
  const math::col4f_t color(r, g, b, a);

  ASSERT_EQ(color.getR(), r);
  ASSERT_EQ(color.getG(), g);
  ASSERT_EQ(color.getB(), b);
  ASSERT_EQ(color.getA(), a);
}

/**
 * @brief Убеждаемся, что преобразование в TVector4<type> проходит правильно.
 */
TEST(TColor, ConvertToVector4) {
  const f32_t r = 0.1f, g = 0.2f, b = 0.3f, a = 1.0f;

  math::col4f_t color(r, g, b, a);
  math::vec4f_t vec4 = color.toVec4();

  ASSERT_EQ(vec4.getX(), r);
  ASSERT_EQ(vec4.getY(), g);
  ASSERT_EQ(vec4.getZ(), b);
  ASSERT_EQ(vec4.getW(), a);
}
