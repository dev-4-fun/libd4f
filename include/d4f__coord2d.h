#ifndef _d4f__coord2d_h
#define _d4f__coord2d_h

#ifdef D4F__COORD2D_NS
#define Coord2D d4f__Coord2d
#define Coord2D_f d4f__Coord2d_f
#endif

typedef struct {
    int x;
    int y;
} d4f__Coord2d;

typedef struct {
    float x;
    float y;
} d4f__Coord2d_f;

#undef EXTERN

#endif /* !_d4f__coord2d_h */