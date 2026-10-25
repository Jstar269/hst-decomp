/* HSTMATCH module=hstp_trans_main.prx start=0x001f5444 end=0x001f55f0 symbol=FUN_001f5444 lang=c++ */
/* Clone of src/eboot/setup_targets_001e722c.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

struct Other_001f5444 {
    char pad0[0xf8];
    void *f0f8;
    char pad1[0x138 - 0xfc];
    int f138;
};

extern "C" {
extern void *DAT_003eabd4;
void FUN_00113a50(Other_001f5444 *other);
void FUN_00105470(void *elem, int flag);
}

struct Target_001f5444 {
    char pad[0x24];
    int f24;
    int f28;
};

struct Sub_001f5444 {
    Target_001f5444 *ptr;
    int off;
};

struct Obj_001f5444 {
    char pad0[0x818];
    Sub_001f5444 sub0;
    int pad_sub0[3];
    Sub_001f5444 sub1;
    int pad_sub1[3];
    Sub_001f5444 sub2;
    int pad_sub2[3];
    Sub_001f5444 sub3;
    int pad_sub3[8];
    Sub_001f5444 sub5;
    int pad_sub5[4];
    Other_001f5444 *other;
};

extern "C" void FUN_001f5444(Obj_001f5444 *self, int param_2, int param_3, int param_4) {
    Other_001f5444 *other = self->other;
    other->f0f8 = &DAT_003eabd4;
    other->f138 = 1;
    FUN_00113a50(other);

    Sub_001f5444 *s0 = &self->sub0;
    if (param_4 != 0) {
        FUN_00105470(s0->ptr, 0);
        int v = s0->off + param_2;
        Target_001f5444 *t = s0->ptr;
        t->f24 = v;
        t->f28 = v;
    } else {
        FUN_00105470(s0->ptr, 1);
    }

    Sub_001f5444 *s2 = &self->sub2;
    Sub_001f5444 *s1 = &self->sub3;
    s0 = &self->sub1;
    Sub_001f5444 *s6 = &self->sub5;

    FUN_00105470(s2->ptr, 1);
    FUN_00105470(s1->ptr, 1);
    FUN_00105470(s0->ptr, 1);
    FUN_00105470(s6->ptr, 1);

    if (param_4 != 0) {
        FUN_00105470(s2->ptr, 0);
        FUN_00105470(s1->ptr, 0);
        FUN_00105470(s0->ptr, 0);
        if (param_3 != 0) {
            int v2 = s2->off + 1;
            Target_001f5444 *t2 = s2->ptr;
            t2->f24 = v2;
            t2->f28 = v2;

            int v1 = s1->off + 1;
            Target_001f5444 *t1 = s1->ptr;
            t1->f24 = v1;
            t1->f28 = v1;

            int v0 = s0->off + 17 + param_2;
            Target_001f5444 *t0 = s0->ptr;
            t0->f24 = v0;
            t0->f28 = v0;
        } else {
            int v2 = s2->off;
            Target_001f5444 *t2 = s2->ptr;
            t2->f24 = v2;
            t2->f28 = v2;

            int v1 = s1->off;
            Target_001f5444 *t1 = s1->ptr;
            t1->f24 = v1;
            t1->f28 = v1;

            int v0 = s0->off + param_2;
            Target_001f5444 *t0 = s0->ptr;
            t0->f24 = v0;
            t0->f28 = v0;
        }
        FUN_00105470(s6->ptr, 0);
    }
}
