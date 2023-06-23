#include <sway/math.hpp>

#include <gtest/gtest.h>

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/matrix.hpp>
#include <glm/vec3.hpp>

using namespace sway;

TEST(Transform, translate) {
  math::mat4i_t matModelTransform;
  matModelTransform = math::Transform<int>::translate(matModelTransform, 8, 2, 5);

  EXPECT_EQ(matModelTransform.getValue(0, 0), 1);
  EXPECT_EQ(matModelTransform.getValue(0, 1), 0);
  EXPECT_EQ(matModelTransform.getValue(0, 2), 0);
  EXPECT_EQ(matModelTransform.getValue(0, 3), 8);
  EXPECT_EQ(matModelTransform.getValue(1, 0), 0);
  EXPECT_EQ(matModelTransform.getValue(1, 1), 1);
  EXPECT_EQ(matModelTransform.getValue(1, 2), 0);
  EXPECT_EQ(matModelTransform.getValue(1, 3), 2);
  EXPECT_EQ(matModelTransform.getValue(2, 0), 0);
  EXPECT_EQ(matModelTransform.getValue(2, 1), 0);
  EXPECT_EQ(matModelTransform.getValue(2, 2), 1);
  EXPECT_EQ(matModelTransform.getValue(2, 3), 5);
  EXPECT_EQ(matModelTransform.getValue(3, 0), 0);
  EXPECT_EQ(matModelTransform.getValue(3, 1), 0);
  EXPECT_EQ(matModelTransform.getValue(3, 2), 0);
  EXPECT_EQ(matModelTransform.getValue(3, 3), 1);
}
