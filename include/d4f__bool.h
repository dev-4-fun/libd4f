#ifndef _d4f__bool_h
#define _d4f__bool_h

#ifdef D4F__BOOL_NS
#define BOOL d4f__BOOL
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef int d4f__BOOL;

#ifdef __cplusplus
}
#endif

#endif /* !_d4f__bool_h */