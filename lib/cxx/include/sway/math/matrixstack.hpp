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
  template <MatrixType Type>
  auto getStack() -> std::stack<mat4f_t> & {
    return std::get<core::detail::toUnderlying(Type)>(matrices_);
  }

  template <MatrixType Type>
  void push(const mat4f_t &mat) {
    getStack<Type>().push(mat);
  }

  template <MatrixType Type>
  void pop() {
    getStack<Type>().pop();
  }

  template <MatrixType Type>
  auto top() -> const mat4f_t & {
    return getStack<Type>().top();
  }

private:
  std::array<std::stack<mat4f_t>, MATRIX_LENGTH> matrices_;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_MATRIXSTACK_HPP
