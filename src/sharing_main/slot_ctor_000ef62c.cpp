/* HSTMATCH module=hstp_trans_main.prx start=0x000ef62c end=0x000ef83c symbol=FUN_000ef62c lang=c++ */
/* Clone of src/eboot/slot_ctor_000ea41c.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
};

struct Slot {
    Vec4 v[7];
};

struct Obj {
    int vptr;
    char pad04[0x38];
    int f3c;
    char pad40[0x10];
    Slot slots[40];
    int cur;
};

extern "C" {
extern char DAT_003b09bc;
void FUN_0001ec44(void *);
void FUN_000efa78(void *);
}

static inline void Copy(Vec4 &d, const Vec4 *s)
{
    d.x = s->x;
    d.y = s->y;
    d.z = s->z;
    d.w = s->w;
}

extern "C" Obj *FUN_000ef62c(Obj *self, int p2, Vec4 *p3, Vec4 *p4, Vec4 *p5, Vec4 *p6, Vec4 *p7, Vec4 *p8, Vec4 *p9)
{
    FUN_0001ec44(self);
    *(char **)self = &DAT_003b09bc;
    self->f3c = p2;
    FUN_000efa78(self);
    self->cur = 0;
    Copy(self->slots[self->cur].v[2], p5);
    Copy(self->slots[self->cur].v[3], p6);
    Copy(self->slots[self->cur].v[0], p3);
    Copy(self->slots[self->cur].v[1], p4);
    Copy(self->slots[self->cur].v[4], p7);
    Copy(self->slots[self->cur].v[5], p8);
    Copy(self->slots[self->cur].v[6], p9);
    return self;
}
