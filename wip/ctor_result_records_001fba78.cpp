/* HSTMATCH module=EBOOT.BIN start=0x001fba78 end=0x001fbb5c symbol=FUN_001fba78 lang=c++ */
/* Near miss: delaying the address of the record table until after the virtual call matches the this register. */
typedef struct { int idx; void *name; int out; } Rec;

struct VC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(int);
};

extern "C" void **DAT_002eedc0;
extern "C" Rec DAT_002eedd0;
extern "C" float DAT_002eedb8;
extern "C" char DAT_002eeddc;
extern "C" char DAT_00309590;

extern "C" void FUN_00102e38();
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void *FUN_001039d8(void *, void *, int);
extern "C" void *FUN_001026b8(void *, void *);
extern "C" void FUN_00103480(void *);

extern "C" void *FUN_001fba78(char *o) {
    void *q;
    FUN_00102e38();
    *(void **)o = &DAT_00309590;
    FUN_00104118(o, &DAT_002eeddc, 0);
    FUN_00103540(o, DAT_002eedb8 - 100.0f);
    *(void **)(o + 0x54) = FUN_001039d8(o, *DAT_002eedc0, 0);
    ((VC *)*(void **)(o + 0x54))->m5(-256);
    void *r = &DAT_002eedd0;
    q = FUN_001026b8(*(void **)(o + 0x54 + ((Rec *)r)->idx * 4), ((Rec *)r)->name);
    *(void **)(o + 0x58) = q;
    if (q != 0) ((Rec *)r)->out = *(int *)((char *)q + 0x24);
    *(int *)(*(int *)(o + 0x54) + 0x78) = 0x3f000000;
    *(char *)(o + 0x5c) = 0;
    FUN_00103480(o);
    return o;
}
// Best after the lane pass: 35/57 words differ. Moving `r = &DAT_002eedd0` after the object factory and
// virtual call changes `this` from s1 to retail's s0 and keeps the record-table address in s1. The
// remaining mismatch is concentrated around loading DAT_002eedc0 for FUN_001039d8 and the null-result
// branch/tail after FUN_001026b8. Tried typed/global record accesses, a typed object layout, moving and
// changing the type of r, pointer/reference aliases for this, explicit base-constructor this argument,
// and volatile/address-pointer forms for DAT_002eedc0; none beat 35 words.
// improved by lane lnm1 (unreviewed): 40 -> 35 differing words
// BEST 57/57 words, 3 differing, first at +0x58 (was 35 differing / 56 words).
// The whole item hung on one spelling: `DAT_002eedc0` is a `void **` global read as
// `*DAT_002eedc0` (double indirection). With `extern void *DAT` (value) or a struct/array
// form MWCC folds the symbol into `lw a1,-4672(v0)`; with `void **` + `*` it emits
// `lui/lw v0,-4672(v0)/lw a1,0(v0)` and 32 of the 35 differing words disappear.
// Remaining: retail materialises the address (`lui v0,0x2f; addiu v0,v0,-4672; lw a1,0(v0)`)
// where MWCC 2.19 folds the base into the first load (`lw v0,-4672(v0)`). Tried and no change:
// struct member 0, `void *G[1]` + `G[0]`, `char G[]` + cast, local `gp`/`g` staging,
// volatile pointer. Also ruled out: `void *DAT` + `*(void **)&DAT` and `void *const DAT` +
// `*(void *const *)&DAT` both collapse back to the folded form (56 words, 35 differing) - the `void **`
// declaration is required for the two dependent loads. Words and every other instruction match.
// improved by lane dsn1 (unreviewed): 35 -> 3 differing words
