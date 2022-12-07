#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

constexpr s32_t IDEN_MAT4[4][4] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
constexpr s32_t RAND_MAT4[4][4] = {6, 5, 9, 8, 8, 0, 3, 4, 8, 2, 7, 9, 1, 1, 5, 3};
constexpr s32_t RAND_MAT4x4[16] = {6, 5, 9, 8, 8, 0, 3, 4, 8, 2, 7, 9, 1, 1, 5, 3};

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит матрицу к единичной.
 */
TEST(Matrix4, DefaultConstructor) {
  const math::mat4i_t mat4;

  ASSERT_EQ(mat4.get(0, 0), 1);
  ASSERT_EQ(mat4.get(0, 1), 0);
  ASSERT_EQ(mat4.get(0, 2), 0);
  ASSERT_EQ(mat4.get(0, 3), 0);

  ASSERT_EQ(mat4.get(1, 0), 0);
  ASSERT_EQ(mat4.get(1, 1), 1);
  ASSERT_EQ(mat4.get(1, 2), 0);
  ASSERT_EQ(mat4.get(1, 3), 0);

  ASSERT_EQ(mat4.get(2, 0), 0);
  ASSERT_EQ(mat4.get(2, 1), 0);
  ASSERT_EQ(mat4.get(2, 2), 1);
  ASSERT_EQ(mat4.get(2, 3), 0);

  ASSERT_EQ(mat4.get(3, 0), 0);
  ASSERT_EQ(mat4.get(3, 1), 0);
  ASSERT_EQ(mat4.get(3, 2), 0);
  ASSERT_EQ(mat4.get(3, 3), 1);
}

/**
 * @brief Убеждаемся, что установка всех компонентов матрицы проходит правильно.
 */
TEST(Matrix4, Set) {
  math::mat4i_t mat4;

  mat4.set(0, 0, RAND_MAT4[0][0]);
  mat4.set(0, 1, RAND_MAT4[0][1]);
  mat4.set(0, 2, RAND_MAT4[0][2]);
  mat4.set(0, 3, RAND_MAT4[0][3]);

  mat4.set(1, 0, RAND_MAT4[1][0]);
  mat4.set(1, 1, RAND_MAT4[1][1]);
  mat4.set(1, 2, RAND_MAT4[1][2]);
  mat4.set(1, 3, RAND_MAT4[1][3]);

  mat4.set(2, 0, RAND_MAT4[2][0]);
  mat4.set(2, 1, RAND_MAT4[2][1]);
  mat4.set(2, 2, RAND_MAT4[2][2]);
  mat4.set(2, 3, RAND_MAT4[2][3]);

  mat4.set(3, 0, RAND_MAT4[3][0]);
  mat4.set(3, 1, RAND_MAT4[3][1]);
  mat4.set(3, 2, RAND_MAT4[3][2]);
  mat4.set(3, 3, RAND_MAT4[3][3]);

  ASSERT_TRUE(std::equal(std::begin(mat4.get()), std::end(mat4.get()), std::begin(RAND_MAT4x4)));
}
