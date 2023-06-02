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
  const math::mat4i_t mtx;

  ASSERT_EQ(mtx.getValue(0, 0), 1);
  ASSERT_EQ(mtx.getValue(0, 1), 0);
  ASSERT_EQ(mtx.getValue(0, 2), 0);
  ASSERT_EQ(mtx.getValue(0, 3), 0);

  ASSERT_EQ(mtx.getValue(1, 0), 0);
  ASSERT_EQ(mtx.getValue(1, 1), 1);
  ASSERT_EQ(mtx.getValue(1, 2), 0);
  ASSERT_EQ(mtx.getValue(1, 3), 0);

  ASSERT_EQ(mtx.getValue(2, 0), 0);
  ASSERT_EQ(mtx.getValue(2, 1), 0);
  ASSERT_EQ(mtx.getValue(2, 2), 1);
  ASSERT_EQ(mtx.getValue(2, 3), 0);

  ASSERT_EQ(mtx.getValue(3, 0), 0);
  ASSERT_EQ(mtx.getValue(3, 1), 0);
  ASSERT_EQ(mtx.getValue(3, 2), 0);
  ASSERT_EQ(mtx.getValue(3, 3), 1);
}

/**
 * @brief Убеждаемся, что установка всех компонентов матрицы проходит правильно.
 */
TEST(Matrix4, Set) {
  math::mat4i_t mtx;

  mtx.setValue(0, 0, RAND_MAT4[0][0]);
  mtx.setValue(0, 1, RAND_MAT4[0][1]);
  mtx.setValue(0, 2, RAND_MAT4[0][2]);
  mtx.setValue(0, 3, RAND_MAT4[0][3]);

  mtx.setValue(1, 0, RAND_MAT4[1][0]);
  mtx.setValue(1, 1, RAND_MAT4[1][1]);
  mtx.setValue(1, 2, RAND_MAT4[1][2]);
  mtx.setValue(1, 3, RAND_MAT4[1][3]);

  mtx.setValue(2, 0, RAND_MAT4[2][0]);
  mtx.setValue(2, 1, RAND_MAT4[2][1]);
  mtx.setValue(2, 2, RAND_MAT4[2][2]);
  mtx.setValue(2, 3, RAND_MAT4[2][3]);

  mtx.setValue(3, 0, RAND_MAT4[3][0]);
  mtx.setValue(3, 1, RAND_MAT4[3][1]);
  mtx.setValue(3, 2, RAND_MAT4[3][2]);
  mtx.setValue(3, 3, RAND_MAT4[3][3]);

  ASSERT_TRUE(std::equal(std::begin(mtx.getData()), std::end(mtx.getData()), std::begin(RAND_MAT4x4)));
}

TEST(Matrix4, Multiply) {
  math::mat4f_t mtxA;
  mtxA.makeIdentity();
  mtxA.setValue(0, 1, 2);
  mtxA.setValue(0, 2, 2);
  mtxA.setValue(1, 1, 3);

  math::mat4f_t mtxB;
  mtxB.makeIdentity();
  mtxB.setValue(0, 1, 5);
  mtxB.setValue(0, 2, 2);
  mtxB.setValue(1, 1, 3);

  std::wstringstream wss;
  wss << std::fixed << std::setprecision(2);

  for (int i = 0; i < 16; ++i) {
    wss.str(L"");
    wss << mtxA.getData()[i] << std::ends;
    printf("%s ", wss.str().c_str());
    if ((i + 1) % 4 == 0) {
      printf("\n");
    }
  }

  printf("\n");

  const auto result = mtxA.multiply(mtxB);

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
