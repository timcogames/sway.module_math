#include <sway/math/size.hpp>

#include <iostream>  // std::ostream
#include <sstream>  // std::stringstream
#include <string>  // std::string

NS_BEGIN(std)

template <typename TYPE>
inline auto operator<<(ostream &str, const sway::math::Size<TYPE> &size) -> ostream & {
  return str << std::fixed << std::setprecision(3) << "{w:" << size.getW() << ", h:" << size.getH() << "}";
}

template <typename TYPE>
inline auto to_string(const sway::math::Size<TYPE> &size) -> string {
  stringstream stream;
  stream << size;
  return stream.str();
}

NS_END()
