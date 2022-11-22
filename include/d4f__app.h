#ifndef _d4f__app_h
#define _d4f__app_h

#include "d4f__bool.h"

#ifdef D4F__APP_NS
#define AppOnInitFn d4f__AppOnInitFn
#define AppOnUpdateFn d4f__AppOnUpdateFn
#define AppOnExitFn d4f__AppOnExitFn
#define AppOptions d4f__AppOptions
#define App_init d4f__App_init
#define App_run d4f__App_run
#define App_exit d4f__App_exit
#endif

#ifndef _d4f__app_h_IMPL
#define EXTERN extern
#else
#define EXTERN
#endif


#ifdef __cplusplus
extern "C" {
#endif

    typedef int (*d4f__AppOnInitFn)(void);
    typedef int (*d4f__AppOnExitFn)(void);
    typedef int (*d4f__AppOnUpdateFn)(void);
    typedef struct d4f__AppOptions {
        d4f__AppOnInitFn onInit;
        d4f__AppOnExitFn onExit;
        d4f__AppOnUpdateFn onUpdate;
    } d4f__AppOptions;

    EXTERN d4f__BOOL d4f__App_init(const d4f__AppOptions options);
    EXTERN int d4f__App_run();
    EXTERN int d4f__App_exit();

#ifdef __cplusplus
}
#endif

#undef EXTERN

#endif /* !_d4f__app_h */