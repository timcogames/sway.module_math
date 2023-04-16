#ifndef SWAY_MATH_PROJECTIONTYPES_HPP
#define SWAY_MATH_PROJECTIONTYPES_HPP

#include <sway/namespacemacros.hpp>
#include <sway/types.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

enum class ProjectionType : u32_t { UNKNOWN, ORTHO, PERSP };

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_PROJECTIONTYPES_HPP
