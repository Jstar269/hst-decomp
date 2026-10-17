/* HSTMATCH module=hstp_trans_main.prx start=0x000ecec4 end=0x000ecfe0 symbol=FUN_000ecec4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0c) corrected by hand: C++ struct with virtual slot 5, Vec4 value copies, and null-checked subobject allocation; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
};

struct Ctx_000ecec4 {
    char pad[0x8c];
    int f8c;
};

struct Obj_000ecec4 {
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
extern char DAT_003b08e0[];
extern void *FUN_00000bcc(unsigned);
extern void FUN_0001ec44(Obj_000ecec4 *);
extern void *FUN_00055a28(void *, int);
extern void FUN_00055c0c(void *, float);
extern void FUN_0005c2f8(char *);
}

extern "C" Obj_000ecec4 *FUN_000ecec4(Obj_000ecec4 *self, Ctx_000ecec4 *ctx, Vec4 *p3, Vec4 *p4)
{
    Vec4 v1 = *p3;
    Vec4 v2 = *p4;
    FUN_0001ec44(self);
    *(char **)self = DAT_003b08e0;
    FUN_0005c2f8(self->sub50);
    self->v5();
    int arg = ctx->f8c;
    self->v320 = v1;
    self->v330 = v2;
    void *p = FUN_00000bcc(0xa0);
    if (p != 0) {
        p = FUN_00055a28(p, arg);
    }
    self->f3c = p;
    FUN_00055c0c(p, 1.01f);
    self->f318 = 0;
    self->f390 = 1.0f;
    return self;
}
