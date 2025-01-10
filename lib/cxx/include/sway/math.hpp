#ifndef SWAY_MATH_HPP
#define SWAY_MATH_HPP

/**
 * @namespace sway::math
 * @brief \~english The math module provides a variety of mathematical tools, including vector arithmetic, matrix
 * transformations, and geometric calculations to support graphics and physics simulations within the Sway framework.
 * \~russian Модуль math предоставляет различные математические инструменты, включая арифметику векторов, преобразования
 * матриц и геометрические вычисления для поддержки графики и физического моделирования в рамках фреймворка Sway.
 */

/**
 * @defgroup LAC Linear algebra classes
 * @brief \~english This group contains classes that involve linear algebra.
 *
 * The files implementing linear algebra functionality are in the
 * <code>lac</code> subdirectory, an abbreviation for <em>L</em>inear
 * <em>A</em>lgebra <em>C</em>lasses.
 *
 * \~russian Этот группа содержит классы, связанные с линейной алгеброй.
 *
 * Файлы, реализующие функционал линейной алгебры, находятся в подкаталоге
 * <code>lac</code>, аббревиатура для <em>L</em>inear <em>A</em>lgebra <em>C</em>lasses.
 */

#include <sway/math/alignments.hpp>
#include <sway/math/axises.hpp>
#include <sway/math/boundingbox.hpp>
#include <sway/math/color.hpp>
#include <sway/math/extensions/coordinatesystemutils.hpp>
#include <sway/math/extensions/projection.hpp>
#include <sway/math/extensions/projectiontypes.hpp>
#include <sway/math/matrices.hpp>
#include <sway/math/point.hpp>
#include <sway/math/ray.hpp>
#include <sway/math/rect.hpp>
#include <sway/math/rectedges.hpp>
#include <sway/math/size.hpp>
#include <sway/math/texel.hpp>
#include <sway/math/transform.hpp>
#include <sway/math/utils.hpp>
#include <sway/math/vector.hpp>
#include <sway/math/vector2.hpp>
#include <sway/math/vector3.hpp>
#include <sway/math/vector4.hpp>
#include <sway/math/vertex.hpp>

#endif  // SWAY_MATH_HPP
