#include <sway/math/rect.hpp>

#include <iostream>  // std::ostream
#include <sstream>  // std::stringstream
#include <string>  // std::string

NS_BEGIN(std)

template <typename TYPE>
inline auto operator<<(ostream &str, const sway::math::Rect<TYPE> &rect) -> ostream & {
  // clang-format off
  return str << fixed << setprecision(3) << "{" 
             << "l:" << rect.getL() << ", " << "t:" << rect.getT() << ", "
             << "r:" << rect.getR() << ", " << "b:" << rect.getB() << ", " 
             << "size:" << rect.asSize() << "}";
  // clang-format on
}

template <typename TYPE>
inline auto to_string(const sway::math::Rect<TYPE> &rect) -> string {
  stringstream stream;
  stream << rect;
  return stream.str();
}

NS_END()
