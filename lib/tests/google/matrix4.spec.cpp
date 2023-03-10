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

  ASSERT_EQ(mat4.getValue(0, 0), 1);
  ASSERT_EQ(mat4.getValue(0, 1), 0);
  ASSERT_EQ(mat4.getValue(0, 2), 0);
  ASSERT_EQ(mat4.getValue(0, 3), 0);

  ASSERT_EQ(mat4.getValue(1, 0), 0);
  ASSERT_EQ(mat4.getValue(1, 1), 1);
  ASSERT_EQ(mat4.getValue(1, 2), 0);
  ASSERT_EQ(mat4.getValue(1, 3), 0);

  ASSERT_EQ(mat4.getValue(2, 0), 0);
  ASSERT_EQ(mat4.getValue(2, 1), 0);
  ASSERT_EQ(mat4.getValue(2, 2), 1);
  ASSERT_EQ(mat4.getValue(2, 3), 0);

  ASSERT_EQ(mat4.getValue(3, 0), 0);
  ASSERT_EQ(mat4.getValue(3, 1), 0);
  ASSERT_EQ(mat4.getValue(3, 2), 0);
  ASSERT_EQ(mat4.getValue(3, 3), 1);
}

/**
 * @brief Убеждаемся, что установка всех компонентов матрицы проходит правильно.
 */
TEST(Matrix4, Set) {
  math::mat4i_t mat4;

  mat4.setValue(0, 0, RAND_MAT4[0][0]);
  mat4.setValue(0, 1, RAND_MAT4[0][1]);
  mat4.setValue(0, 2, RAND_MAT4[0][2]);
  mat4.setValue(0, 3, RAND_MAT4[0][3]);

  mat4.setValue(1, 0, RAND_MAT4[1][0]);
  mat4.setValue(1, 1, RAND_MAT4[1][1]);
  mat4.setValue(1, 2, RAND_MAT4[1][2]);
  mat4.setValue(1, 3, RAND_MAT4[1][3]);

  mat4.setValue(2, 0, RAND_MAT4[2][0]);
  mat4.setValue(2, 1, RAND_MAT4[2][1]);
  mat4.setValue(2, 2, RAND_MAT4[2][2]);
  mat4.setValue(2, 3, RAND_MAT4[2][3]);

  mat4.setValue(3, 0, RAND_MAT4[3][0]);
  mat4.setValue(3, 1, RAND_MAT4[3][1]);
  mat4.setValue(3, 2, RAND_MAT4[3][2]);
  mat4.setValue(3, 3, RAND_MAT4[3][3]);

  ASSERT_TRUE(std::equal(std::begin(mat4.getData()), std::end(mat4.getData()), std::begin(RAND_MAT4x4)));
}

TEST(Matrix4, Multiply) {
  math::mat4f_t mat4;
  mat4.makeIdentity();
  mat4.setValue(0, 1, 2);
  mat4.setValue(0, 2, 2);
  mat4.setValue(1, 1, 3);

  math::mat4f_t mat42;
  mat42.makeIdentity();
  mat42.setValue(0, 1, 5);
  mat42.setValue(0, 2, 2);
  mat42.setValue(1, 1, 3);

  std::wstringstream wss;
  wss << std::fixed << std::setprecision(2);

  for (int i = 0; i < 16; ++i) {
    wss.str(L"");
    wss << mat4.getData()[i] << std::ends;
    printf("%s ", wss.str().c_str());
    if ((i + 1) % 4 == 0) {
      printf("\n");
    }
  }

  printf("\n");

  const auto result = mat4.multiply(mat42);

  for (int i = 0; i < 16; ++i) {
    wss.str(L"");
    wss << result.getValue(i) << std::ends;
    printf("%s ", wss.str().c_str());
    if ((i + 1) % 4 == 0) {
      printf("\n");
    }
  }

  wss << std::resetiosflags(std::ios_base::fixed | std::ios_base::floatfield);
}
