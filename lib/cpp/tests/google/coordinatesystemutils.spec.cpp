#include <sway/math.hpp>

#include <gtest/gtest.h>

using namespace sway;

const auto dims = math::size2i_t(1024, 768);

// 0, 0 -> -1.0, 1.0
TEST(NDC, convFromScreen_LT) {
  auto ndc = math::NDC::convFromScreen(math::point2f_t(0.0F, 0.0F), dims);
  ASSERT_NEAR(ndc.getX(), -1.0F, 1e-6);
  ASSERT_NEAR(ndc.getY(), +1.0F, 1e-6);
}

// -1.0, 1.0 -> 0.0, 0.0
TEST(NDC, convToScreen_LT) {
  auto ndc = math::NDC::convToScreen(math::vec2f_t(-1.0F, 1.0F));
  ASSERT_NEAR(ndc.getX(), 0.0F, 1e-6);
  ASSERT_NEAR(ndc.getY(), 0.0F, 1e-6);
}

// 0, 768 -> -1.0, -1.0
TEST(NDC, convFromScreen_LB) {
  auto ndc = math::NDC::convFromScreen(math::point2f_t(0.0F, 768.0F), dims);
  ASSERT_NEAR(ndc.getX(), -1.0F, 1e-6);
  ASSERT_NEAR(ndc.getY(), -1.0F, 1e-6);
}

// -1.0, -1.0 -> 0.0, 1.0
TEST(NDC, convToScreen_LB) {
  auto ndc = math::NDC::convToScreen(math::vec2f_t(-1.0F, -1.0F));
  ASSERT_NEAR(ndc.getX(), 0.0F, 1e-6);
  ASSERT_NEAR(ndc.getY(), 1.0F, 1e-6);
}

// 1024, 0 -> 1.0, 1.0
TEST(NDC, convFromScreen_RT) {
  auto ndc = math::NDC::convFromScreen(math::point2f_t(1024.0F, 0.0F), dims);
  ASSERT_NEAR(ndc.getX(), 1.0F, 1e-6);
  ASSERT_NEAR(ndc.getY(), 1.0F, 1e-6);
}

// 1.0, 0.0 -> 1.0, 0.0
TEST(NDC, convToScreen_RT) {
  auto ndc = math::NDC::convToScreen(math::vec2f_t(1.0F, 1.0F));
  ASSERT_NEAR(ndc.getX(), 1.0F, 1e-6);
  ASSERT_NEAR(ndc.getY(), 0.0F, 1e-6);
}

// 1024, 768 -> 1.0, -1.0
TEST(NDC, convFromScreen_RB) {
  auto ndc = math::NDC::convFromScreen(math::point2f_t(1024.0F, 768.0F), dims);
  ASSERT_NEAR(ndc.getX(), +1.0F, 1e-6);
  ASSERT_NEAR(ndc.getY(), -1.0F, 1e-6);
}

// 1.0, -1.0 -> 1.0, 1.0
TEST(NDC, convToScreen_RB) {
  auto ndc = math::NDC::convToScreen(math::vec2f_t(1.0F, -1.0F));
  ASSERT_NEAR(ndc.getX(), 1.0F, 1e-6);
  ASSERT_NEAR(ndc.getY(), 1.0F, 1e-6);
}
