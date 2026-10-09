#ifndef SWAY_MATH_MATRICES_MATRIXTYPES_HPP
#define SWAY_MATH_MATRICES_MATRIXTYPES_HPP

#include <sway/core.hpp>

namespace sway::math {

/**
 * @ingroup matrices
 * @{
 */

// clang-format off
#define MATRIX_TYPE_LIST(ITEM) \
  ITEM(VIEW, 0) \
  ITEM(PROJ, 1) \
  ITEM(TFRM, 2)
// clang-format on

DECLARE_ENUM_IDX(MatrixType, MATRIX_TYPE_LIST)

/** @} */

}  // namespace sway::math

#define NUM_OF_MATRICES (sway::math::MatrixType::EnumInfo::getCountWithoutNone())

#endif  // SWAY_MATH_MATRICES_MATRIXTYPES_HPP
