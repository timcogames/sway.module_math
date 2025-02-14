#ifndef SWAY_MATH_BOUNDINGRECT_H
#define SWAY_MATH_BOUNDINGRECT_H

#include <maths.h>
#include <types.h>

typedef enum intersection
{
  OUTSIDE,
  INTERSECTS,
  INSIDE
} INTERSECTION;

typedef struct bounding_rect
{
  s16 min_x;
  s16 min_y;
  u16 max_x;
  u16 max_y;
} BOUNDING_RECT;

BOUNDING_RECT
BOUNDING_RECT_make(s16 x, s16 y, u16 w, u16 h);

BOUNDING_RECT
BOUNDING_RECT_make_empty();

bool
BOUNDING_RECT_is_empty(BOUNDING_RECT rect);

void
BOUNDING_RECT_get_wdt(BOUNDING_RECT rect, s16* wdt);

void
BOUNDING_RECT_get_hgt(BOUNDING_RECT rect, s16* hgt);

void
BOUNDING_RECT_get_center(BOUNDING_RECT rect, s16* center_x, s16* center_y);

INTERSECTION
BOUNDING_RECT_is_inside(BOUNDING_RECT a, BOUNDING_RECT b);

INTERSECTION
BOUNDING_RECT_is_inside_fast(BOUNDING_RECT a, BOUNDING_RECT b);

u8
BOUNDING_RECT_intersection(BOUNDING_RECT a, BOUNDING_RECT b, BOUNDING_RECT* result);

/**
 * \~russian
 * @brief Метод смещения бокса.
 * @param[in, out] rect Ограничивающий прямоугольник, который необходимо сместить.
 * @param[in] offset_x Смещение по оси X.
 * @param[in] offset_y Смещение по оси Y.
 * 
 * \~english
 * @brief Bounding box shift method.
 * @param[in, out] rect Bounding box that needs to be shifted.
 * @param[in] offset_x Offset on the X axis.
 * @param[in] offset_y Offset on the Y axis.
 */
void
BOUNDING_RECT_shift(BOUNDING_RECT* rect, s16 offset_x, s16 offset_y);

#endif // SWAY_MATH_BOUNDINGRECT_H
