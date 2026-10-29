/* HSTMATCH module=EBOOT.BIN start=0x000ea41c end=0x000ea62c symbol=FUN_000ea41c lang=c++ */
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
extern char DAT_003076f0;
void FUN_0001f06c(void *);
void FUN_000ea868(void *);
}

static inline void Copy(Vec4 &d, const Vec4 *s)
{
    d.x = s->x;
    d.y = s->y;
    d.z = s->z;
    d.w = s->w;
}

extern "C" Obj *FUN_000ea41c(Obj *self, int p2, Vec4 *p3, Vec4 *p4, Vec4 *p5, Vec4 *p6, Vec4 *p7, Vec4 *p8, Vec4 *p9)
{
    FUN_0001f06c(self);
    *(char **)self = &DAT_003076f0;
    self->f3c = p2;
    FUN_000ea868(self);
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
