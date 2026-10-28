/* HSTMATCH module=hstp_trans_main.prx start=0x001884d4 end=0x001885a8 symbol=FUN_001884d4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
#include "hst/types.h"

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    char pad[8];
    void **items;
    u32 count;
    char pad2[0x20 - 0x10];
    Vec4 v;
} Obj;

extern void FUN_00093a28(void *p, Vec4 *v);
extern void FUN_00093a4c(void *p, Vec4 *v);
extern void FUN_001888f8(Obj *self);
extern void FUN_0018a544(float f);

void FUN_001884d4(Obj *self)
{
    self->v.x = 0.0f;
    self->v.y = 0.0f;
    self->v.z = 0.0f;
    self->v.w = 1.0f;
    FUN_0018a544(0.0f);
    for (u32 i = 0; i < self->count; i++) {
        Vec4 a;
        a.y = -1.0f;
        a.x = 0.0f;
        a.z = 0.0f;
        a.w = 1.0f;
        FUN_00093a4c((char *)self->items[i] + 16, &a);
        Vec4 b;
        b.x = 0.0f;
        b.y = 0.0f;
        b.z = 0.0f;
        b.w = 1.0f;
        FUN_00093a28((char *)self->items[i] + 16, &b);
    }
    FUN_001888f8(self);
}
