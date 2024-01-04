#ifndef SWAY_MATH_MATRIXTYPES_HPP
#define SWAY_MATH_MATRIXTYPES_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

enum class MatrixType : u32_t { VIEW, PROJ, TFRM, Latest };

#define NUM_MATRIX_TYPES (core::detail::toUnderlying(MatrixType::Latest))

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_MATRIXTYPES_HPP
