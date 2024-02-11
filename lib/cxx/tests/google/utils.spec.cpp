#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

TEST(Utils, powerOf2) {
  EXPECT_EQ(math::util::powerOf2(1), 1);
  EXPECT_EQ(math::util::powerOf2(2), 2);
  EXPECT_EQ(math::util::powerOf2(3), 4);
  EXPECT_EQ(math::util::powerOf2(4), 4);
  EXPECT_EQ(math::util::powerOf2(5), 8);
}
