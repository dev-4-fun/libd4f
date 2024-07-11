#define _d4f__coord2d_h_IMPL
#include "d4f__coord2d.h"
#undef _d4f__coord2d_h_IMPL

d4f__BOOL d4f__Coord2d_collide(const d4f__Coord2d a, const d4f__Coord2d b) {
    return (a.x == b.x && a.y == b.y);
}

