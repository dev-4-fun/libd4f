#ifndef D4F__BOOL_H
#define D4F__BOOL_H

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

#endif