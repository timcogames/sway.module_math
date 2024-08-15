#ifndef SWAY_MATH_AREA_HPP
#define SWAY_MATH_AREA_HPP

#include <sway/core.hpp>
#include <sway/math/areatypes.hpp>
#include <sway/math/rectedges.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TYPE>
class Area {
public:
#pragma region "Ctors/Dtor"

  Area(AreaType type)
      : type_(type) {
    edges_.fill((TYPE)0);
  }

  Area(AreaType type, TYPE val)
      : type_(type) {
    set(val, val, val, val);
  }

  Area(AreaType type, TYPE hsize, TYPE vsize)
      : type_(type) {
    set(hsize, vsize, hsize, vsize);
  }

  Area(AreaType type, TYPE left, TYPE top, TYPE right, TYPE bottom)
      : type_(type) {
    set(left, top, right, bottom);
  }

#pragma endregion

  void set(TYPE left, TYPE top, TYPE right, TYPE bottom) {
    edges_[core::detail::toBase(RectEdge::IDX_L)] = left;
    edges_[core::detail::toBase(RectEdge::IDX_T)] = top;
    edges_[core::detail::toBase(RectEdge::IDX_R)] = right;
    edges_[core::detail::toBase(RectEdge::IDX_B)] = bottom;
  }

  auto at(RectEdge edge) const -> const TYPE & { return edges_[core::detail::toBase(edge)]; }

  auto at(RectEdge edge) -> TYPE & { return edges_[core::detail::toBase(edge)]; }

  [[nodiscard]]
  auto getType() const -> AreaType {
    return type_;
  }

  [[nodiscard]]
  auto getL() const -> TYPE {
    return this->at(RectEdge::IDX_L);
  }

  [[nodiscard]]
  auto getT() const -> TYPE {
    return this->at(RectEdge::IDX_T);
  }

  [[nodiscard]]
  auto getR() const -> TYPE {
    return this->at(RectEdge::IDX_R);
  }

  [[nodiscard]]
  auto getB() const -> TYPE {
    return this->at(RectEdge::IDX_B);
  }

  [[nodiscard]]
  auto getLR() const -> TYPE {
    return this->getL() + this->getR();
  }

  [[nodiscard]]
  auto getTB() const -> TYPE {
    return this->getT() + this->getB();
  }

private:
  AreaType type_;
  std::array<TYPE, NUM_OF_EDGES> edges_;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_AREA_HPP
