#ifndef SWAY_MATH_MATRIXTYPES_HPP
#define SWAY_MATH_MATRIXTYPES_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

enum class MatrixType : u32_t { NONE = 0, VIEW, PROJ, TFRM, Latest };

#define NUM_OF_MATRICES (core::detail::toBase(MatrixType::Latest) - 1)

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_MATRIXTYPES_HPP
