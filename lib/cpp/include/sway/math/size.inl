#include <sway/math/rect.hpp>

#include <iostream>  // std::ostream
#include <sstream>  // std::stringstream
#include <string>  // std::string

namespace sway::math {

template <typename TYPE>
auto Size<TYPE>::asRect() const -> Rect<TYPE> {
  return Rect<TYPE>(static_cast<TYPE>(0), static_cast<TYPE>(0), getW(), getH());
}

}  // namespace sway::math

NS_BEGIN(std)

template <typename TYPE>
FORCE_INLINE auto operator<<(ostream &str, const sway::math::Size<TYPE> &size) -> ostream & {
  const auto flags = str.flags();
  const auto precision = str.precision();

  str << std::fixed << std::setprecision(3)
      << "{w:" << size.getW() << ", h:" << size.getH() << "}";

  str.flags(flags);
  str.precision(precision);
  
  return str;
}

template <typename TYPE>
FORCE_INLINE auto to_string(const sway::math::Size<TYPE> &size) -> string {
  stringstream stream;
  stream << size;
  return stream.str();
}

NS_END()
