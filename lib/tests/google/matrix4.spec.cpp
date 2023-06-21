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
  const math::mat4i_t mat;

  ASSERT_EQ(mat.getValue(0, 0), 1);
  ASSERT_EQ(mat.getValue(0, 1), 0);
  ASSERT_EQ(mat.getValue(0, 2), 0);
  ASSERT_EQ(mat.getValue(0, 3), 0);

  ASSERT_EQ(mat.getValue(1, 0), 0);
  ASSERT_EQ(mat.getValue(1, 1), 1);
  ASSERT_EQ(mat.getValue(1, 2), 0);
  ASSERT_EQ(mat.getValue(1, 3), 0);

  ASSERT_EQ(mat.getValue(2, 0), 0);
  ASSERT_EQ(mat.getValue(2, 1), 0);
  ASSERT_EQ(mat.getValue(2, 2), 1);
  ASSERT_EQ(mat.getValue(2, 3), 0);

  ASSERT_EQ(mat.getValue(3, 0), 0);
  ASSERT_EQ(mat.getValue(3, 1), 0);
  ASSERT_EQ(mat.getValue(3, 2), 0);
  ASSERT_EQ(mat.getValue(3, 3), 1);
}

/**
 * @brief Убеждаемся, что установка всех компонентов матрицы проходит правильно.
 */
TEST(Matrix4, Set) {
  math::mat4i_t mat;

  mat.setValue(0, 0, RAND_MAT4[0][0]);
  mat.setValue(0, 1, RAND_MAT4[0][1]);
  mat.setValue(0, 2, RAND_MAT4[0][2]);
  mat.setValue(0, 3, RAND_MAT4[0][3]);

  mat.setValue(1, 0, RAND_MAT4[1][0]);
  mat.setValue(1, 1, RAND_MAT4[1][1]);
  mat.setValue(1, 2, RAND_MAT4[1][2]);
  mat.setValue(1, 3, RAND_MAT4[1][3]);

  mat.setValue(2, 0, RAND_MAT4[2][0]);
  mat.setValue(2, 1, RAND_MAT4[2][1]);
  mat.setValue(2, 2, RAND_MAT4[2][2]);
  mat.setValue(2, 3, RAND_MAT4[2][3]);

  mat.setValue(3, 0, RAND_MAT4[3][0]);
  mat.setValue(3, 1, RAND_MAT4[3][1]);
  mat.setValue(3, 2, RAND_MAT4[3][2]);
  mat.setValue(3, 3, RAND_MAT4[3][3]);

  ASSERT_TRUE(std::equal(std::begin(mat.getData()), std::end(mat.getData()), std::begin(RAND_MAT4x4)));
}

TEST(Matrix, multiplication) {
  // clang-format off
  auto a = math::Matrix<int, 3, 3>::fromArray({
      2,-1, 1,
      0,-2, 1,
      1,-2, 0
  });  // clang-format on

  // clang-format off
  auto b = math::Matrix<int, 3, 3>::fromArray({
     -2, 3, 5,
     -1,-3, 9,
      5, 6,-7
  });  // clang-format on

  // clang-format off
  auto expected = math::Matrix<int, 3, 3>::fromArray({
      2, 15,- 6,
      7, 12,-25,
      0,  9,-13
  });  // clang-format on

  EXPECT_EQ(a.multiply<3>(b.getData()), expected);
}

TEST(Matrix4, mult) {
  std::ostream &os = std::cout;

  math::mat4f_t matA;
  matA.setValue(0, 1, 2);
  matA.setValue(0, 2, 2);
  matA.setValue(1, 1, 3);
  os << "matA\n" << matA << std::endl;

  math::mat4f_t matB;
  matB.setValue(0, 1, 5);
  matB.setValue(0, 2, 2);
  matB.setValue(1, 1, 3);
  os << "matB\n" << matB << std::endl;

  const auto multAB = matA * matB;
  auto vecA = math::vec4f_t(2, 5, 6, 1);
  os << "MULT\n" << math::mat4f_t::transform(multAB.inverse(), vecA) << std::endl;
}
