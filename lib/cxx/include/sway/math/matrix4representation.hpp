#ifndef SWAY_MATH_MATRIX4REPRESENTATION_HPP
#define SWAY_MATH_MATRIX4REPRESENTATION_HPP

#include <sway/core/misc/string/representation.hpp>
#include <sway/math/matrix4.hpp>

namespace sway::core {

template <>
struct Representation<math::Matrix4<f32_t>> {
  static auto get(const math::Matrix4<f32_t> &val) -> std::string {
    std::stringstream stream;
    // clang-format off
    stream << std::fixed << std::setprecision(6) 
           << "mat4x4((" << val.getValue(0, 0) << ", " << val.getValue(1, 0) << ", " << val.getValue(2, 0) << ", " << val.getValue(3, 0) << "), "
           <<        "(" << val.getValue(0, 1) << ", " << val.getValue(1, 1) << ", " << val.getValue(2, 1) << ", " << val.getValue(3, 1) << "), "
           <<        "(" << val.getValue(0, 2) << ", " << val.getValue(1, 2) << ", " << val.getValue(2, 2) << ", " << val.getValue(3, 2) << "), "
           <<        "(" << val.getValue(0, 3) << ", " << val.getValue(1, 3) << ", " << val.getValue(2, 3) << ", " << val.getValue(3, 3) << "))";
    // clang-format on
    return stream.str();
  }
};

}  // namespace sway::core

#endif  // SWAY_MATH_MATRIX4REPRESENTATION_HPP
