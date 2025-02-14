#include <sway/math/boundingrect.h>

BOUNDING_RECT
BOUNDING_RECT_make(s16 x, s16 y, u16 w, u16 h)
{
  return (BOUNDING_RECT){ .min_x = x, .min_y = y, .max_x = x + w, .max_y = y + h };
}

BOUNDING_RECT
BOUNDING_RECT_make_empty()
{
  return (BOUNDING_RECT){ .min_x = 0, .min_y = 0, .max_x = 0, .max_y = 0 };
}

bool
BOUNDING_RECT_is_empty(BOUNDING_RECT rect)
{
  return (rect.min_x >= rect.max_x || rect.min_y >= rect.max_y);
}

void
BOUNDING_RECT_get_wdt(BOUNDING_RECT rect, s16* wdt)
{
  *wdt = abs(rect.max_x - rect.min_x);
}

void
BOUNDING_RECT_get_hgt(BOUNDING_RECT rect, s16* hgt)
{
  *hgt = abs(rect.max_y - rect.min_y);
}

void
BOUNDING_RECT_get_center(BOUNDING_RECT rect, s16* center_x, s16* center_y)
{
  *center_x = rect.min_x + rect.max_x / 2;
  *center_y = rect.min_y + rect.max_y / 2;
}

INTERSECTION
BOUNDING_RECT_is_inside(BOUNDING_RECT a, BOUNDING_RECT b)
{
  if (a.max_x < b.min_x || a.min_x > b.max_x || a.max_y < b.min_y || a.min_y > b.max_y) {
    return OUTSIDE;
  } else if (a.min_x < b.min_x || a.max_x > b.max_x || a.min_y < b.min_y || a.max_y > b.max_y) {
    return INTERSECTS;
  } else {
    return INSIDE;
  }
}

INTERSECTION
BOUNDING_RECT_is_inside_fast(BOUNDING_RECT a, BOUNDING_RECT b)
{
  if (a.max_x < b.min_x || a.min_x > b.max_x || a.max_y < b.min_y || a.min_y > b.max_y) {
    return OUTSIDE;
  } else {
    return INSIDE;
  }
}

u8
BOUNDING_RECT_intersection(BOUNDING_RECT a, BOUNDING_RECT b, BOUNDING_RECT* result)
{
  if (BOUNDING_RECT_is_inside(a, b) == OUTSIDE) {
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
BOUNDING_RECT_shift(BOUNDING_RECT* rect, s16 offset_x, s16 offset_y)
{
  rect->min_x += offset_x;
  rect->min_y += offset_y;
  rect->max_x += offset_x;
  rect->max_y += offset_y;
}
