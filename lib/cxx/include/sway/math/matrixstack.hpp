#ifndef SWAY_MATH_MATRIXSTACK_HPP
#define SWAY_MATH_MATRIXSTACK_HPP

#include <sway/core.hpp>
#include <sway/math/matrix4.hpp>
#include <sway/math/matrixtypes.hpp>

#include <array>
#include <stack>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

class MatrixStack {
public:
  template <MatrixType TYPE>
  auto getStack() -> std::stack<mat4f_t> & {
    return std::get<core::detail::toBase(TYPE)>(matrices_);
  }

  template <MatrixType TYPE>
  void push(const mat4f_t &mat) {
    getStack<TYPE>().push(mat);
  }

  template <MatrixType TYPE>
  void pop() {
    getStack<TYPE>().pop();
  }

  template <MatrixType TYPE>
  auto top() -> const mat4f_t & {
    return getStack<TYPE>().top();
  }

private:
  std::array<std::stack<mat4f_t>, NUM_OF_MATRICES> matrices_;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_MATRIXSTACK_HPP
