/* HSTMATCH module=EBOOT.BIN start=0x001e4c48 end=0x001e4d64 symbol=FUN_001e4c48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the table row is read through a local `Row *r = &DAT_003417b8[idx]` (a direct `DAT_003417b8[idx].s18` folds the +0x18 into the lui/addiu base); the float parameter is declared before the int that is forwarded to 0x1e4d64 (callee prototyped (Obj *, float, int)); `&o->f248` / `&o->f25c` are held in locals (retail keeps both addresses in s4/s3 across the getter call). Names provisional. */
struct VC {
    virtual void s0();
    virtual void s1(int);
};
struct Row {
    char pad[0x18];
    short s18;
    char pad2[0x120 - 0x1a];
};
struct Ctx {
    char pad[0x3cc];
    int f3cc;
};
struct Obj {
    char pad0[0x1f4];
    void *f1f4;
    VC *f1f8;
    char pad1[0x248 - 0x1fc];
    void *f248;
    char pad2[0x25c - 0x24c];
    void *f25c;
    char pad3[0x270 - 0x260];
    void *f270;
    char pad4[0x338 - 0x274];
    void *f338;
    char pad5[0x34c - 0x33c];
    void *f34c;
};
extern "C" {
extern Row DAT_003417b8[];
void FUN_0016b21c(int);
void FUN_001e2694(Obj *);
void FUN_00103628(void *, int);
void FUN_000ffb3c(void *, int);
Ctx *FUN_001ee200(void);
void FUN_001e4d64(Obj *, float, int);
void FUN_001e4c48(Obj *o, int idx, float f, int a);
}
void FUN_001e4c48(Obj *o, int idx, float f, int a)
{
    Row *r = &DAT_003417b8[idx];
    FUN_0016b21c(r->s18);
    FUN_001e2694(o);
    FUN_00103628(o->f1f4, 0);
    FUN_000ffb3c(o->f270, 1);
    o->f1f8->s1(1);
    void **p248 = &o->f248;
    void **p25c = &o->f25c;
    if (idx == FUN_001ee200()->f3cc) {
        FUN_000ffb3c(*p248, 0);
        FUN_000ffb3c(*p25c, 1);
    } else {
        FUN_000ffb3c(*p248, 1);
        FUN_000ffb3c(*p25c, 0);
    }
    FUN_000ffb3c(o->f34c, 1);
    FUN_000ffb3c(o->f338, 1);
    FUN_001e4d64(o, f, a);
}
