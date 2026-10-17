/* HSTMATCH module=EBOOT.BIN start=0x0017bde0 end=0x0017beb4 symbol=FUN_0017bde0 lang=c99 */
/* Clone of src/sharing_main/init_item_vectors_001884d4.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
typedef unsigned int uint;

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    char pad[8];
    void **items;
    uint count;
    char pad2[0x20 - 0x10];
    Vec4 v;
} Obj;

extern void FUN_00091d90(void *p, Vec4 *v);
extern void FUN_00091db4(void *p, Vec4 *v);
extern void FUN_0017c204(Obj *self);
extern void FUN_0017de50(float f);

void FUN_0017bde0(Obj *self)
{
    self->v.x = 0.0f;
    self->v.y = 0.0f;
    self->v.z = 0.0f;
    self->v.w = 1.0f;
    FUN_0017de50(0.0f);
    for (uint i = 0; i < self->count; i++) {
        Vec4 a;
        a.y = -1.0f;
        a.x = 0.0f;
        a.z = 0.0f;
        a.w = 1.0f;
        FUN_00091db4((char *)self->items[i] + 16, &a);
        Vec4 b;
        b.x = 0.0f;
        b.y = 0.0f;
        b.z = 0.0f;
        b.w = 1.0f;
        FUN_00091d90((char *)self->items[i] + 16, &b);
    }
    FUN_0017c204(self);
}
