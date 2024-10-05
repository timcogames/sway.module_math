#include <sway/core.hpp>
#include <sway/math/transform.hpp>

NS_BEGIN_SWAY()
NS_BEGIN(math)

template <typename NODE, typename TYPE>
Transform<NODE, TYPE>::Transform()
    : position_(vec3f_zero)
    , scale_(vec3f_one) {}

template <typename NODE, typename TYPE>
auto Transform<NODE, TYPE>::getModelMatrix() -> Matrix4<TYPE> {
  auto parent = this->getParentNode();
  if (!parent || parent.value()->getNodeIdx().chainEqual({core::container::NODEIDX_NEGATIVE})) {
    return getInternalMatrix_();
  }

  return std::static_pointer_cast<Transform<NODE, TYPE>>(parent.value())->getModelMatrix() * getInternalMatrix_();
}

template <typename NODE, typename TYPE>
void Transform<NODE, TYPE>::setPosition(TYPE x, TYPE y, TYPE z) {
  position_ = Vector3<TYPE>(x, y, z);
}

template <typename NODE, typename TYPE>
void Transform<NODE, TYPE>::setPosition(const Vector3<TYPE> &pos) {
  position_ = pos;
}

template <typename NODE, typename TYPE>
auto Transform<NODE, TYPE>::getPosition() -> Vector3<TYPE> {
  return position_;
}

template <typename NODE, typename TYPE>
void Transform<NODE, TYPE>::setTranslate(TYPE x, TYPE y, TYPE z) {
  position_ += Vector3<TYPE>(x, y, z);
}

template <typename NODE, typename TYPE>
void Transform<NODE, TYPE>::setTranslate(const Vector3<TYPE> &pos) {
  position_ += pos;
}

template <typename NODE, typename TYPE>
void Transform<NODE, TYPE>::setScale(TYPE x, TYPE y, TYPE z) {
  scale_ = Vector3<TYPE>(x, y, z);
}

template <typename NODE, typename TYPE>
auto Transform<NODE, TYPE>::getInternalMatrix_() const -> Matrix4<TYPE> {
  Matrix4<TYPE> matCombined;
  matCombined = Transform<Dummy, TYPE>::translate(matCombined, position_.getX(), position_.getY(), position_.getZ());
  matCombined = Transform<Dummy, TYPE>::scale(matCombined, scale_.getX(), scale_.getY(), scale_.getZ());

  return matCombined;
}

NS_END()  // namespace math
NS_END()  // namespace sway
