/* HSTMATCH module=hstp_trans_main.prx start=0x001f2e60 end=0x001f2f7c symbol=FUN_001f2e60 lang=c++ */
/* Clone of src/eboot/panel_setup_001e4c48.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the table row is read through a local `Row *r = &DAT_003eaaf0[idx]` (a direct `DAT_003eaaf0[idx].s18` folds the +0x18 into the lui/addiu base); the float parameter is declared before the int that is forwarded to 0x1e4d64 (callee prototyped (Obj *, float, int)); `&o->f248` / `&o->f25c` are held in locals (retail keeps both addresses in s4/s3 across the getter call). Names provisional. */
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
extern Row DAT_003eaaf0[];
void FUN_001773e0(int);
void FUN_001f08e8(Obj *);
void FUN_00108f54(void *, int);
void FUN_00105470(void *, int);
Ctx *FUN_001fc5c8(void);
void FUN_001f2f7c(Obj *, float, int);
void FUN_001f2e60(Obj *o, int idx, float f, int a);
}
void FUN_001f2e60(Obj *o, int idx, float f, int a)
{
    Row *r = &DAT_003eaaf0[idx];
    FUN_001773e0(r->s18);
    FUN_001f08e8(o);
    FUN_00108f54(o->f1f4, 0);
    FUN_00105470(o->f270, 1);
    o->f1f8->s1(1);
    void **p248 = &o->f248;
    void **p25c = &o->f25c;
    if (idx == FUN_001fc5c8()->f3cc) {
        FUN_00105470(*p248, 0);
        FUN_00105470(*p25c, 1);
    } else {
        FUN_00105470(*p248, 1);
        FUN_00105470(*p25c, 0);
    }
    FUN_00105470(o->f34c, 1);
    FUN_00105470(o->f338, 1);
    FUN_001f2f7c(o, f, a);
}
