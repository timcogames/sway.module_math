#ifndef SWAY_MATH_MARGIN_HPP
#define SWAY_MATH_MARGIN_HPP

#include <sway/core.hpp>
#include <sway/math/rectedges.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType>
class Margin {
public:
  Margin()
      : Margin(0, 0, 0, 0) {}

  Margin(TValueType l, TValueType t, TValueType r, TValueType b) {
    data_[core::detail::toBase(RectEdge::IDX_L)] = l;
    data_[core::detail::toBase(RectEdge::IDX_T)] = t;
    data_[core::detail::toBase(RectEdge::IDX_R)] = r;
    data_[core::detail::toBase(RectEdge::IDX_B)] = b;
  }

  Margin(TValueType val)
      : Margin(val, val, val, val) {}

  Margin(TValueType x, TValueType y)
      : Margin(x, y, x, y) {}

  auto at(RectEdge edge) const -> TValueType { return data_[core::detail::toBase(edge)]; }

  auto getL() const -> TValueType { return this->at(RectEdge::IDX_L); }

  auto getT() const -> TValueType { return this->at(RectEdge::IDX_T); }

  auto getR() const -> TValueType { return this->at(RectEdge::IDX_R); }

  auto getB() const -> TValueType { return this->at(RectEdge::IDX_B); }

  auto getLR() const -> TValueType { return this->getL() + this->getR(); }

  auto getTB() const -> TValueType { return this->getT() + this->getB(); }

private:
  std::array<TValueType, 4> data_;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_MARGIN_HPP
