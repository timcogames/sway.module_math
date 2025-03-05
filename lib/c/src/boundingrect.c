#include <sway/math/boundingrect.h>

BOUNDING_RECT
BOUNDING_RECT_make(s16 x, s16 y, u16 w, u16 h)
{
  BOUNDING_RECT rect;
  rect.min_x = x;
  rect.min_y = y;
  rect.w = w;
  rect.h = h;
  rect.enabled = TRUE;

  BOUNDING_RECT_update_max(&rect);

  return (rect);
}

BOUNDING_RECT
BOUNDING_RECT_make_empty()
{
  BOUNDING_RECT rect;
  rect.min_x = rect.min_y = 0;
  rect.max_x = rect.max_y = 0;
  rect.w = 0;
  rect.h = 0;
  rect.enabled = FALSE;

  return rect;
}

u8
BOUNDING_RECT_is_empty(BOUNDING_RECT rect)
{
  return (rect.min_x >= rect.max_x || rect.min_y >= rect.max_y);
}

void
BOUNDING_RECT_update_max(BOUNDING_RECT_PTR rect)
{
  rect->max_x = rect->min_x + rect->w;
  rect->max_y = rect->min_y + rect->h;
}

void
BOUNDING_RECT_get_wdt(BOUNDING_RECT rect, u16* w)
{
  *w = abs(rect.max_x - rect.min_x);
}

void
BOUNDING_RECT_get_hgt(BOUNDING_RECT rect, u16* h)
{
  *h = abs(rect.max_y - rect.min_y);
}

void
BOUNDING_RECT_update_dim(BOUNDING_RECT_PTR rect)
{
  BOUNDING_RECT_get_wdt(*rect, &rect->w);
  BOUNDING_RECT_get_hgt(*rect, &rect->h);
}

void
BOUNDING_RECT_get_area(BOUNDING_RECT rect, u16* area)
{
  *area = rect.w * rect.h;
}

void
BOUNDING_RECT_get_center(BOUNDING_RECT rect, s16* center_x, s16* center_y)
{
  *center_x = rect.min_x + (rect.w >> 1);
  *center_y = rect.min_y + (rect.h >> 1);
}

INTERSECTION
BOUNDING_RECT_is_inside(BOUNDING_RECT a, BOUNDING_RECT b)
{
  if (a.max_x <= b.min_x || a.min_x >= b.max_x || a.max_y <= b.min_y || a.min_y >= b.max_y) {
    return INTERSECTION_OUTSIDE;
  }

  if (a.min_x < b.min_x || a.max_x > b.max_x || a.min_y < b.min_y || a.max_y > b.max_y) {
    return INTERSECTION_INTERSECTS;
  }

  return INTERSECTION_INSIDE;
}

INTERSECTION
BOUNDING_RECT_is_inside_fast(BOUNDING_RECT a, BOUNDING_RECT b)
{
  if (a.max_x <= b.min_x || a.min_x >= b.max_x || a.max_y <= b.min_y || a.min_y >= b.max_y) {
    return INTERSECTION_OUTSIDE;
  }

  return INTERSECTION_INSIDE;
}

u8
BOUNDING_RECT_intersection(BOUNDING_RECT a, BOUNDING_RECT b, BOUNDING_RECT_PTR result)
{
  if (BOUNDING_RECT_is_inside(a, b) == INTERSECTION_OUTSIDE) {
    *result = BOUNDING_RECT_make_empty();
    return FALSE;
  }

  *result = (BOUNDING_RECT){ .min_x = max(a.min_x, b.min_x),
                             .min_y = max(a.min_y, b.min_y),
                             .max_x = min(a.max_x, b.max_x),
                             .max_y = min(a.max_y, b.max_y) };

  return TRUE;
}

void
BOUNDING_RECT_shift(BOUNDING_RECT_PTR rect, s16 offset_x, s16 offset_y)
{
  rect->min_x += offset_x;
  rect->min_y += offset_y;
  rect->max_x += offset_x;
  rect->max_y += offset_y;
}
