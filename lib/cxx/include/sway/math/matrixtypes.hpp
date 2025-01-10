#ifndef SWAY_MATH_MATRIXTYPES_HPP
#define SWAY_MATH_MATRIXTYPES_HPP

#include <sway/core.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(math)

DECLARE_ENUM_IDX(MatrixType, VIEW = GLOB_IDX_INITIAL, PROJ, TFRM);

NS_END()  // namespace math
NS_END()  // namespace sway

#define NUM_OF_MATRICES (sway::core::toBase(sway::math::MatrixType::Enum::Latest))

#endif  // SWAY_MATH_MATRIXTYPES_HPP
