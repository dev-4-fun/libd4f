#ifndef d4f__type_descriptor_h
#define d4f__type_descriptor_h

#ifdef __cplusplus
extern "C" {
#endif

    extern void* d4f__TypeDescriptor;

    extern void* d4f__new(const void* type, ...);
    extern void d4f__delete(void* self);
    extern void* d4f__clone(const void* self);

#ifdef __cplusplus
}
#endif

#endif /* !d4f__type_descriptor_h */

