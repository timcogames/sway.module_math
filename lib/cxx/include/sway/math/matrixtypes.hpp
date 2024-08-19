#ifndef SWAY_MATH_MATRIXTYPES_HPP
#define SWAY_MATH_MATRIXTYPES_HPP

#include <sway/core.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

enum class MatrixType : i32_t { NONE = GLOB_IDX_INVALID, VIEW = GLOB_IDX_INITIAL, PROJ, TFRM, Latest };

NAMESPACE_END(math)
NAMESPACE_END(sway)

#define NUM_OF_MATRICES (sway::core::detail::toBase(sway::math::MatrixType::Latest))

#endif  // SWAY_MATH_MATRIXTYPES_HPP
