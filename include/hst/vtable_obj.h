/* Minimal object view for destructor-style functions that only touch the vtable pointer. */
#ifndef HST_VTABLE_OBJ_H
#define HST_VTABLE_OBJ_H

typedef struct VtableObj {
    const void *vtable; /* 0x0 */
} VtableObj;

#endif
