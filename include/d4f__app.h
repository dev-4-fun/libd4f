#ifndef D4F__APP_H
#define D4F__APP_H

#ifdef D4F__APP_NS
#define App d4f__App
#define AppOnInitFn d4f__AppOnInitFn
#define AppOnUpdateFn d4f__AppOnUpdateFn
#define AppOnExitFn d4f__AppOnExitFn
#define AppOptions d4f__AppOptions
#define App_create d4f__App_create
#define App_destroy d4f__App_destroy
#define App_run d4f__App_run
#define App_exit d4f__App_exit
#endif

#ifdef __cplusplus
extern "C" {
#endif

    typedef void* d4f__App;
    typedef void (*d4f__AppOnInitFn)();
    typedef void (*d4f__AppOnExitFn)();
    typedef void (*d4f__AppOnUpdateFn)(float f_elapsed);
    typedef struct d4f__AppOptions {
        d4f__AppOnInitFn onInit;
        d4f__AppOnUpdateFn onUpdate;
        d4f__AppOnExitFn onExit;
    } d4f__AppOptions;

    extern d4f__App d4f__App_create(const d4f__AppOptions options);
    extern void d4f__App_destroy(d4f__App self);
    extern int d4f__App_run(d4f__App self);
    extern void d4f__App_exit(d4f__App self);

#ifdef __cplusplus
}
#endif

#endif