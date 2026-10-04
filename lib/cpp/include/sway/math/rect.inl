#include <sway/math/size.hpp>

#include <iomanip>
#include <ostream>
#include <sstream>  // std::stringstream
#include <string> 

namespace sway::math {

template <typename TYPE>
Rect<TYPE>::Rect(TYPE x, TYPE y, const Size<TYPE> &size)
    : Vector4<TYPE>(x, y, x + size.getW(), y + size.getH()) {}

}  // namespace sway::math

NS_BEGIN(std)

template <typename TYPE>
FORCE_INLINE auto operator<<(ostream &str, const sway::math::Rect<TYPE> &rect) -> ostream & {
  const auto flags = str.flags();
  const auto precision = str.precision();

  str << fixed << setprecision(3) 
    << "{l:" << rect.getL() << ", t:" << rect.getT() 
    << ", r:" << rect.getR() << ", b:" << rect.getB() 
    << ", size:" << rect.asSize() << "}";

  str.flags(flags);
  str.precision(precision);

  return str;
}

template <typename TYPE>
FORCE_INLINE auto to_string(const sway::math::Rect<TYPE> &rect) -> string {
  stringstream stream;
  stream << rect;
  return stream.str();
}

NS_END()
