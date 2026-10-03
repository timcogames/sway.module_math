#ifndef SWAY_MATH_MATRICES_MATRIXSTACK_HPP
#define SWAY_MATH_MATRICES_MATRIXSTACK_HPP

#include <sway/core.hpp>
#include <sway/math/matrices/matrix4.hpp>
#include <sway/math/matrices/matrixtypes.hpp>

#include <array>
#include <stack>

namespace sway::math {

/**
 * @ingroup matrices
 * @{
 */

class MatrixStack {
public:
  template <MatrixType::Enum TYPE>
  auto getStack() -> std::stack<mat4f_t> & {
    return std::get<core::toBase(TYPE)>(matrices_);
  }

  template <MatrixType::Enum TYPE>
  void push(const mat4f_t &mat) {
    getStack<TYPE>().push(mat);
  }

  template <MatrixType::Enum TYPE>
  void pop() {
    getStack<TYPE>().pop();
  }

  template <MatrixType::Enum TYPE>
  auto top() -> const mat4f_t & {
    return getStack<TYPE>().top();
  }

private:
  std::array<std::stack<mat4f_t>, NUM_OF_MATRICES> matrices_;
};

/** @} */

}  // namespace sway::math

#endif  // SWAY_MATH_MATRICES_MATRIXSTACK_HPP
