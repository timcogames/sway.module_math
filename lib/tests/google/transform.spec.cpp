#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

TEST(Transform, translate) {
  auto transform = math::Transform<int>::translate(8, 2, 5);

  EXPECT_EQ(transform.getValue(0, 0), 1);
  EXPECT_EQ(transform.getValue(0, 1), 0);
  EXPECT_EQ(transform.getValue(0, 2), 0);
  EXPECT_EQ(transform.getValue(0, 3), 8);
  EXPECT_EQ(transform.getValue(1, 0), 0);
  EXPECT_EQ(transform.getValue(1, 1), 1);
  EXPECT_EQ(transform.getValue(1, 2), 0);
  EXPECT_EQ(transform.getValue(1, 3), 2);
  EXPECT_EQ(transform.getValue(2, 0), 0);
  EXPECT_EQ(transform.getValue(2, 1), 0);
  EXPECT_EQ(transform.getValue(2, 2), 1);
  EXPECT_EQ(transform.getValue(2, 3), 5);
  EXPECT_EQ(transform.getValue(3, 0), 0);
  EXPECT_EQ(transform.getValue(3, 1), 0);
  EXPECT_EQ(transform.getValue(3, 2), 0);
  EXPECT_EQ(transform.getValue(3, 3), 1);
}
