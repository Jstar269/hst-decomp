/* HSTMATCH module=EBOOT.BIN start=0x000e7df0 end=0x000e7f0c symbol=FUN_000e7df0 lang=c++ */
/* Clone of src/sharing_main/init_obj_000ecec4.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0c) corrected by hand: C++ struct with virtual slot 5, Vec4 value copies, and null-checked subobject allocation; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
};

struct Ctx_000e7df0 {
    char pad[0x8c];
    int f8c;
};

struct Obj_000e7df0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad04[0x3c - 4];
    void *f3c;
    char pad40[0x50 - 0x40];
    char sub50[0x318 - 0x50];
    int f318;
    int pad31c;
    Vec4 v320;
    Vec4 v330;
    char pad340[0x390 - 0x340];
    float f390;
};

extern "C" {
extern char DAT_00307614[];
extern void *FUN_00000bcc(unsigned);
extern void FUN_0001f06c(Obj_000e7df0 *);
extern void *FUN_00054f08(void *, int);
extern void FUN_000550ec(void *, float);
extern void FUN_0005b670(char *);
}

extern "C" Obj_000e7df0 *FUN_000e7df0(Obj_000e7df0 *self, Ctx_000e7df0 *ctx, Vec4 *p3, Vec4 *p4)
{
    Vec4 v1 = *p3;
    Vec4 v2 = *p4;
    FUN_0001f06c(self);
    *(char **)self = DAT_00307614;
    FUN_0005b670(self->sub50);
    self->v5();
    int arg = ctx->f8c;
    self->v320 = v1;
    self->v330 = v2;
    void *p = FUN_00000bcc(0xa0);
    if (p != 0) {
        p = FUN_00054f08(p, arg);
    }
    self->f3c = p;
    FUN_000550ec(p, 1.01f);
    self->f318 = 0;
    self->f390 = 1.0f;
    return self;
}
