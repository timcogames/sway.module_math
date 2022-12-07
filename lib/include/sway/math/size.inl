#include <sway/math/size.hpp>

#include <iostream>  // std::ostream
#include <sstream>  // std::stringstream
#include <string>  // std::string

NAMESPACE_BEGIN(std)

template <typename TYPE>
inline ostream &operator<<(ostream &str, const sway::math::TSize<TYPE> &size) {
  return str << '(' << size.getW() << ' ' << size.getH() << ')';
}

template <typename TYPE>
inline auto toStr(const sway::math::TSize<TYPE> &size) -> string {
  stringstream stream;
  stream << size;
  return stream.str();
}

NAMESPACE_END(std)
