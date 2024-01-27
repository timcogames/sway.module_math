#include <sway/math.hpp>

#include <gtest/gtest.h>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/matrix.hpp>
#include <glm/vec4.hpp>

using namespace sway;

constexpr s32_t IDEN_MAT4[4][4] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
constexpr s32_t RAND_MAT4[4][4] = {6, 5, 9, 8, 8, 0, 3, 4, 8, 2, 7, 9, 1, 1, 5, 3};
constexpr s32_t RAND_MAT4x4[16] = {6, 5, 9, 8, 8, 0, 3, 4, 8, 2, 7, 9, 1, 1, 5, 3};

/**
 * @brief Убеждаемся, что конструктор по умолчанию приводит матрицу к единичной.
 */
TEST(Matrix4, DefaultCtor) {
  math::mat4i_t mtx;

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

// TEST(Matrix, multiplication) {
//   // clang-format off
//   auto a = math::Matrix<int, 3, 3>::fromArray({
//       2,-1, 1,
//       0,-2, 1,
//       1,-2, 0
//   });  // clang-format on

//   // clang-format off
//   auto b = math::Matrix<int, 3, 3>::fromArray({
//      -2, 3, 5,
//      -1,-3, 9,
//       5, 6,-7
//   });  // clang-format on

//   // clang-format off
//   auto expected = math::Matrix<int, 3, 3>::fromArray({
//       2, 15,- 6,
//       7, 12,-25,
//       0,  9,-13
//   });  // clang-format on

//   EXPECT_EQ(a.multiply<3>(b.getData()), expected);
// }

TEST(Matrix4, mult) {
  std::ostream &os = std::cout;

  auto arrA = math::Matrix<f32_t, 4, 4>::fromArray(
      {1.0f, 0.0165f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0432f, 0.032f, 0.0f, 0.09f, -50.0f, 0.02f, 0.04f, 0.076f, -1.0f, 1.0})
                  .getData();
  math::mat4f_t matA;
  matA.setData(arrA);

  auto arrB = math::Matrix<f32_t, 4, 4>::fromArray({1.0f, 0.0f, 0.0f, -0.486085, 0.0f, 1.0f, 0.0f, -0.454206, 0.0f,
                                                       0.0f, 1.0f, -0.000230312, 0.0f, 0.0f, 1.0f, 0.99977})
                  .getData();
  math::mat4f_t matB;
  matB.setData(arrB);

  auto vecA = math::vec4f_t(3.0f, 8.0f, -1.34f, 1.0f);
  const auto multAB = math::mat4f_t::transform((matA * matB).inverse(), vecA);
  os << "MULT\n" << multAB << std::endl;

  auto matAA = glm::make_mat4(arrA.data());
  auto matBB = glm::make_mat4(arrB.data());
  const auto multAABB = glm::inverse(matAA * matBB);
  auto vecAA = glm::vec4(3.0f, 8.0f, -1.34f, 1.0f);
  std::cout << "\n" << glm::to_string(multAABB * vecAA) << std::endl;
}
