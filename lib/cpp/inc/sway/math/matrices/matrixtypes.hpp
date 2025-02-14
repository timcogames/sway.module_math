#ifndef SWAY_MATH_MATRICES_MATRIXTYPES_HPP
#define SWAY_MATH_MATRICES_MATRIXTYPES_HPP

#include <sway/core.hpp>

namespace sway::math {

/**
 * @ingroup matrices
 * @{
 */

DECLARE_ENUM_IDX(MatrixType, VIEW = GLOB_IDX_INITIAL, PROJ, TFRM);

/** @} */

}  // namespace sway::math

#define NUM_OF_MATRICES (sway::core::toBase(sway::math::MatrixType::Enum::Latest))

#endif  // SWAY_MATH_MATRICES_MATRIXTYPES_HPP
