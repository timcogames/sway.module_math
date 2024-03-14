#ifndef SWAY_MATH_BORDER_HPP
#define SWAY_MATH_BORDER_HPP

#include <sway/core.hpp>
#include <sway/math/rectedges.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(math)

template <typename TValueType>
class Border {
public:
  Border()
      : Border(0, 0, 0, 0) {}

  Border(TValueType l, TValueType t, TValueType r, TValueType b) {
    data_[core::detail::toUnderlying(RectEdge::IDX_L)] = l;
    data_[core::detail::toUnderlying(RectEdge::IDX_T)] = t;
    data_[core::detail::toUnderlying(RectEdge::IDX_R)] = r;
    data_[core::detail::toUnderlying(RectEdge::IDX_B)] = b;
  }

  Border(TValueType val)
      : Border(val, val, val, val) {}

  Border(TValueType x, TValueType y)
      : Border(x, y, x, y) {}

  auto getL() const -> TValueType { return data_[core::detail::toUnderlying(RectEdge::IDX_L)]; }

  auto getT() const -> TValueType { return data_[core::detail::toUnderlying(RectEdge::IDX_T)]; }

  auto getR() const -> TValueType { return data_[core::detail::toUnderlying(RectEdge::IDX_R)]; }

  auto getB() const -> TValueType { return data_[core::detail::toUnderlying(RectEdge::IDX_B)]; }

private:
  std::array<TValueType, 4> data_;
};

NAMESPACE_END(math)
NAMESPACE_END(sway)

#endif  // SWAY_MATH_BORDER_HPP
