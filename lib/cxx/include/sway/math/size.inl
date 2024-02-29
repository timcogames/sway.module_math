#include <sway/math/size.hpp>

#include <iostream>  // std::ostream
#include <sstream>  // std::stringstream
#include <string>  // std::string

NAMESPACE_BEGIN(std)

template <typename TValueType>
inline auto operator<<(ostream &str, const sway::math::Size<TValueType> &size) -> ostream & {
  return str << std::fixed << std::setprecision(3) << "{w:" << size.getW() << ", h:" << size.getH() << "}";
}

template <typename TValueType>
inline auto to_string(const sway::math::Size<TValueType> &size) -> string {
  stringstream stream;
  stream << size;
  return stream.str();
}

NAMESPACE_END(std)
