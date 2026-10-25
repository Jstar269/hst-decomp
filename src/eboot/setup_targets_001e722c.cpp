/* HSTMATCH module=EBOOT.BIN start=0x001e722c end=0x001e73d8 symbol=FUN_001e722c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

struct Other_001e722c {
    char pad0[0xf8];
    void *f0f8;
    char pad1[0x138 - 0xfc];
    int f138;
};

extern "C" {
extern void *DAT_0034189c;
void FUN_0010d4a8(Other_001e722c *other);
void FUN_000ffb3c(void *elem, int flag);
}

struct Target_001e722c {
    char pad[0x24];
    int f24;
    int f28;
};

struct Sub_001e722c {
    Target_001e722c *ptr;
    int off;
};

struct Obj_001e722c {
    char pad0[0x818];
    Sub_001e722c sub0;
    int pad_sub0[3];
    Sub_001e722c sub1;
    int pad_sub1[3];
    Sub_001e722c sub2;
    int pad_sub2[3];
    Sub_001e722c sub3;
    int pad_sub3[8];
    Sub_001e722c sub5;
    int pad_sub5[4];
    Other_001e722c *other;
};

extern "C" void FUN_001e722c(Obj_001e722c *self, int param_2, int param_3, int param_4) {
    Other_001e722c *other = self->other;
    other->f0f8 = &DAT_0034189c;
    other->f138 = 1;
    FUN_0010d4a8(other);

    Sub_001e722c *s0 = &self->sub0;
    if (param_4 != 0) {
        FUN_000ffb3c(s0->ptr, 0);
        int v = s0->off + param_2;
        Target_001e722c *t = s0->ptr;
        t->f24 = v;
        t->f28 = v;
    } else {
        FUN_000ffb3c(s0->ptr, 1);
    }

    Sub_001e722c *s2 = &self->sub2;
    Sub_001e722c *s1 = &self->sub3;
    s0 = &self->sub1;
    Sub_001e722c *s6 = &self->sub5;

    FUN_000ffb3c(s2->ptr, 1);
    FUN_000ffb3c(s1->ptr, 1);
    FUN_000ffb3c(s0->ptr, 1);
    FUN_000ffb3c(s6->ptr, 1);

    if (param_4 != 0) {
        FUN_000ffb3c(s2->ptr, 0);
        FUN_000ffb3c(s1->ptr, 0);
        FUN_000ffb3c(s0->ptr, 0);
        if (param_3 != 0) {
            int v2 = s2->off + 1;
            Target_001e722c *t2 = s2->ptr;
            t2->f24 = v2;
            t2->f28 = v2;

            int v1 = s1->off + 1;
            Target_001e722c *t1 = s1->ptr;
            t1->f24 = v1;
            t1->f28 = v1;

            int v0 = s0->off + 17 + param_2;
            Target_001e722c *t0 = s0->ptr;
            t0->f24 = v0;
            t0->f28 = v0;
        } else {
            int v2 = s2->off;
            Target_001e722c *t2 = s2->ptr;
            t2->f24 = v2;
            t2->f28 = v2;

            int v1 = s1->off;
            Target_001e722c *t1 = s1->ptr;
            t1->f24 = v1;
            t1->f28 = v1;

            int v0 = s0->off + param_2;
            Target_001e722c *t0 = s0->ptr;
            t0->f24 = v0;
            t0->f28 = v0;
        }
        FUN_000ffb3c(s6->ptr, 0);
    }
}
