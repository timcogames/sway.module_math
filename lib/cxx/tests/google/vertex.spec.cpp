#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(VertexPosition, DefaultCtor) {
  math::VertexPosition vertex;

  ASSERT_EQ(vertex.x, 0.0F);
  ASSERT_EQ(vertex.y, 0.0F);
  ASSERT_EQ(vertex.z, 0.0F);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(VertexPosition, ComponentCtor) {
  math::VertexPosition vertex(math::vec3f_t(1.0F, 2.0F, 3.0F));
  auto position = vertex.getPosition();

  ASSERT_EQ(position.getX(), 1.0f);
  ASSERT_EQ(position.getY(), 2.0f);
  ASSERT_EQ(position.getZ(), 3.0f);
}

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(VertexColor, DefaultCtor) {
  math::VertexColor vertex;

  ASSERT_EQ(vertex.x, 0.0F);
  ASSERT_EQ(vertex.y, 0.0F);
  ASSERT_EQ(vertex.z, 0.0F);

  ASSERT_EQ(vertex.r, 0.0F);
  ASSERT_EQ(vertex.g, 0.0F);
  ASSERT_EQ(vertex.b, 0.0F);
  ASSERT_EQ(vertex.a, 0.0F);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(VertexColor, ComponentCtor) {
  math::VertexColor vertex(math::vec3f_t(1.0F, 2.0F, 3.0F), math::col4f_t(0.1F, 0.2F, 0.3F));
  auto position = vertex.getPosition();
  auto color = vertex.getColor();

  ASSERT_EQ(position.getX(), 1.0F);
  ASSERT_EQ(position.getY(), 2.0F);
  ASSERT_EQ(position.getZ(), 3.0F);

  ASSERT_EQ(color.getR(), 0.1F);
  ASSERT_EQ(color.getG(), 0.2F);
  ASSERT_EQ(color.getB(), 0.3F);
  ASSERT_EQ(color.getA(), 1.0F);
}

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит все компоненты к нулю.
 */
TEST(VertexTexCoord, DefaultCtor) {
  math::VertexTexCoord vertex;

  ASSERT_EQ(vertex.x, 0.0F);
  ASSERT_EQ(vertex.y, 0.0F);
  ASSERT_EQ(vertex.z, 0.0F);

  ASSERT_EQ(vertex.u, 0.0F);
  ASSERT_EQ(vertex.v, 0.0F);
}

/**
 * @brief Убеждаемся, что конструктор устанавливает все значения компонентов в те,
 *        которые были заданы.
 */
TEST(VertexTexCoord, ComponentCtor) {
  math::VertexTexCoord vertex(math::vec3f_t(1.0F, 2.0F, 3.0F), math::vec2f_t(0.1F, 0.2F));
  auto position = vertex.getPosition();
  auto texcoord = vertex.getTexCoord();

  ASSERT_EQ(position.getX(), 1.0F);
  ASSERT_EQ(position.getY(), 2.0F);
  ASSERT_EQ(position.getZ(), 3.0F);

  ASSERT_EQ(texcoord.getX(), 0.1F);
  ASSERT_EQ(texcoord.getY(), 0.2F);
}
