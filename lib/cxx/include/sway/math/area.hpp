#ifndef SWAY_MATH_AREA_HPP
#define SWAY_MATH_AREA_HPP

#include <sway/core.hpp>
#include <sway/math/areatypes.hpp>
#include <sway/math/rectedges.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TYPE>
class Size;

template <typename TYPE>
class Area {
public:
#pragma region "Ctors/Dtor"

  Area(AreaType type, const Size<TYPE> &size = Size<TYPE>((TYPE)0, (TYPE)0))
      : type_(type)
      , size_(size) {
    resetEdges();
  }

#pragma endregion

  void setContent(const Size<TYPE> &size) { size_ = size; }

  [[nodiscard]]
  auto getContent() const -> Size<TYPE> {
    return size_;
  }

  void resetEdges() { edges_.fill((TYPE)0); }

  void set(TYPE l, TYPE t, TYPE r, TYPE b) {
    edges_[core::detail::toBase(RectEdge::IDX_L)] = l;
    edges_[core::detail::toBase(RectEdge::IDX_T)] = t;
    edges_[core::detail::toBase(RectEdge::IDX_R)] = r;
    edges_[core::detail::toBase(RectEdge::IDX_B)] = b;
  }

  auto at(RectEdge edge) const -> const TYPE & { return edges_[core::detail::toBase(edge)]; }

  auto at(RectEdge edge) -> TYPE & { return edges_[core::detail::toBase(edge)]; }

  [[nodiscard]]
  auto type() const -> AreaType {
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
  Size<TYPE> size_;
  std::array<TYPE, NUM_OF_EDGES> edges_;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_AREA_HPP
