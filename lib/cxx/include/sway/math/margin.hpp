#ifndef SWAY_MATH_MARGIN_HPP
#define SWAY_MATH_MARGIN_HPP

#include <sway/core.hpp>
#include <sway/math/rectedges.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TYPE>
class Margin {
public:
#pragma region "Ctors/Dtor"

  Margin()
      : Margin(0, 0, 0, 0) {}

  Margin(TYPE l, TYPE t, TYPE r, TYPE b) {
    data_[core::detail::toBase(RectEdge::IDX_L)] = l;
    data_[core::detail::toBase(RectEdge::IDX_T)] = t;
    data_[core::detail::toBase(RectEdge::IDX_R)] = r;
    data_[core::detail::toBase(RectEdge::IDX_B)] = b;
  }

  Margin(TYPE val)
      : Margin(val, val, val, val) {}

  Margin(TYPE x, TYPE y)
      : Margin(x, y, x, y) {}

#pragma endregion

  auto at(RectEdge edge) const -> TYPE { return data_[core::detail::toBase(edge)]; }

  auto getL() const -> TYPE { return this->at(RectEdge::IDX_L); }

  auto getT() const -> TYPE { return this->at(RectEdge::IDX_T); }

  auto getR() const -> TYPE { return this->at(RectEdge::IDX_R); }

  auto getB() const -> TYPE { return this->at(RectEdge::IDX_B); }

  auto getLR() const -> TYPE { return this->getL() + this->getR(); }

  auto getTB() const -> TYPE { return this->getT() + this->getB(); }

private:
  std::array<TYPE, 4> data_;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_MARGIN_HPP
