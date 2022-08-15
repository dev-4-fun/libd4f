#ifndef D4F__APP_H
#define D4F__APP_H


#ifdef D4F__APP_IMPORT
#define EXTERN
#else
#define EXTERN extern
#endif

#ifdef __cplusplus
extern "C" {
#endif


    typedef void* d4f__App;
    typedef void (*d4f__AppOnInitFn)(d4f__App self);
    typedef void (*d4f__AppOnExitFn)(d4f__App self);
    typedef void (*d4f__AppOnUpdateFn)(d4f__App self);
    typedef struct d4f__AppOptions {
        d4f__AppOnInitFn onInit;
        d4f__AppOnUpdateFn onUpdate;
        d4f__AppOnExitFn onExit;
    } d4f__AppOptions;

    EXTERN d4f__App d4f__App_create(const d4f__AppOptions options);
    EXTERN void d4f__App_destroy(d4f__App self);
    EXTERN void d4f__App_setOnInit(d4f__App self, d4f__AppOnInitFn fn);
    EXTERN void d4f__App_setOnExit(d4f__App self, d4f__AppOnExitFn fn);
    EXTERN void d4f__App_setOnUpdate(d4f__App self, d4f__AppOnUpdateFn fn);
    EXTERN int d4f__App_run(d4f__App self);
    EXTERN void d4f__App_exit(d4f__App self);


#ifdef __cplusplus
}
#endif

#undef EXTERN

#endif