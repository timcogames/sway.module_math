#include <sway/math/size.h>

#include <string> // std::string
#include <iostream> // std::ostream
#include <sstream> // std::stringstream

NAMESPACE_BEGIN(std)

template<typename TYPE>
inline ostream & operator<<(ostream & str, const sway::math::TSize<TYPE> & size) {
	return str << '(' << size.getW() << ' ' << size.getH() << ')';
}

template<typename TYPE>
inline string to_string(const sway::math::TSize<TYPE> & size) {
	stringstream stream;
	stream << size;
	return stream.str();
}

NAMESPACE_END(std)
