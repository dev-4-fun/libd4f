#ifndef _d4f__coord2d_h
#define _d4f__coord2d_h

#include "d4f__bool.h"

#ifdef D4F__COORD2D_NS
#define Coord2D d4f__Coord2d
#define Coord2D_f d4f__Coord2d_f
#endif

#ifndef _d4f__coord2d_h_IMPL
#define EXTERN extern
#else
#define EXTERN
#endif

typedef struct {
    int x;
    int y;
} d4f__Coord2d;

typedef struct {
    float x;
    float y;
} d4f__Coord2d_f;

EXTERN d4f__BOOL d4f__Coord2d_collide(const d4f__Coord2d a, const d4f__Coord2d b);

#undef EXTERN

#endif /* !_d4f__coord2d_h */