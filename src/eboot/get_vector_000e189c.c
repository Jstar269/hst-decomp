/* HSTMATCH module=EBOOT.BIN start=0x000e189c end=0x000e193c symbol=FUN_000e189c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: Vec4 local temporaries and field-wise destination copy; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct VecSource {
    char pad0[0x38];
    u32 key;                /* 0x38 */
} VecSource;

typedef struct VecOwner {
    char pad0[0x3c];
    VecSource *source;      /* 0x3c */
    char pad40[0x80 - 0x40];
    Vec4 vec;               /* 0x80 */
} VecOwner;

extern u32 DAT_002d6b4c[];
extern void FUN_0001d7e4(Vec4 *out, u32 param_2);

/* Sets the owner's vector from its source key, or from the table entry for `index` when there is one. */
void FUN_000e189c(VecOwner *self, int index)
{
    Vec4 base;
    Vec4 override;

    FUN_0001d7e4(&base, self->source->key);
    if (DAT_002d6b4c[index] != 0) {
        FUN_0001d7e4(&override, DAT_002d6b4c[index]);
        base = override;
    }
    self->vec.x = base.x;
    self->vec.y = base.y;
    self->vec.z = base.z;
    self->vec.w = base.w;
}
