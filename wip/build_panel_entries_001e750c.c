/* HSTMATCH module=EBOOT.BIN start=0x001e750c end=0x001e7700 symbol=FUN_001e750c lang=c99 */
// NEAR MISS (119/125 words, 111 differ, first at +0x1c): the loop structure, the three 20-byte-entry
// arrays at p+0x21ec+{0x14,0x50,0x8c}, the mode dispatch (==2 / ==1 / ==0 with 8/7/6) and the tail
// sequence are all reconstructed, and the big struct layout puts Holder at 0x22b4 and arg22c0 at 0x22c0.
// What does not match is the ADDRESSING: retail materialises three pointers with THREE adds each
// (`addiu v0,s1,80; addu v0,s4,v0; addiu v1,v0,8684`), i.e. index-offset, then base, then the 0x21ec
// struct offset LAST, and keeps two counters (s2 = i for the count test, s1 = i*20 for the offset).
// MWCC (this profile) always folds 0x50+0x21ec into one immediate and keeps a single walking base, in
// every spelling tried: nested struct arrays, one flat array accessed as arr[i+K], explicit pointer
// locals (assigned inside or outside the loop), an explicit `off = i*0x14` accumulator, an intermediate
// char* local, and `#pragma opt_strength_reduction off` (which instead emits the sll/add/sll multiply
// chain). Conclusion: retail's third add is a base-class/subobject adjustment that MWCC schedules after
// the member offset, not a source-visible constant fold -- reproducing it needs a multiple-inheritance
// layout, not a different address expression.
typedef unsigned char undefined1;

extern void FUN_000ffb3c();
extern void FUN_000ffc70();
extern void FUN_00102c54();
extern void FUN_0010b980();
extern void FUN_0010d4a8();
extern int FUN_001ee200();
extern int FUN_001fea10();

typedef struct {
    int f0;
    int pad[3];
    int f10;
} Entry;

typedef struct {
    unsigned char pad[0x14];
    Entry color[3];
    Entry first[3];
    Entry second[3];
} Sub;

typedef struct Scene_s Scene;

typedef struct {
    int unused;
    Scene *obj;
    int unused2;
} Holder;

typedef struct {
    unsigned char pad0[0x21ec];
    Sub sub;
    Holder holder;
    int arg22c0;
    unsigned char pad1[0x94];
    int n2358;
} Big;

struct Scene_s {
    unsigned char pad0[100];
    float f64;
    unsigned char pad1[0x90];
    int f_f8;
    unsigned char pad2[0x3c];
    int f_138;
};

void FUN_001e750c(Big *p)
{
    Scene *o;

    int mode = *(int *)((char *)FUN_001ee200() + 0x8178);
    FUN_001ee200();
    FUN_0010b980(p->arg22c0, mode, 0);

    for (int i = 0; i < 3; i++) {
        int off = i * 0x14;
        Entry *a = (Entry *)((char *)p + off + 0x50 + 0x21ec);
        Entry *b = (Entry *)((char *)p + off + 0x8c + 0x21ec);
        Entry *c = (Entry *)((char *)p + off + 0x14 + 0x21ec);

        if (mode == i) {
            FUN_000ffb3c(a->f0, 0);
            FUN_000ffb3c(b->f0, 1);
            FUN_000ffc70(c->f0, 0x80808080);
        } else {
            FUN_000ffb3c(a->f0, 1);
            FUN_000ffb3c(b->f0, 0);
            FUN_000ffc70(c->f0, c->f10);
        }
    }

    if (mode == 2) {
        o = p->holder.obj;
        o->f64 = (float)(p->n2358 + 9);
        FUN_00102c54(p->holder.obj);
        o = p->holder.obj;
        o->f_f8 = FUN_001fea10(0x11, 0x12, 8);
        o->f_138 = 1;
        FUN_0010d4a8();
    } else if (mode == 1) {
        o = p->holder.obj;
        o->f64 = (float)p->n2358;
        FUN_00102c54(p->holder.obj);
        o = p->holder.obj;
        o->f_f8 = FUN_001fea10(0x11, 0x12, 7);
        o->f_138 = 1;
        FUN_0010d4a8();
    } else if (mode == 0) {
        o = p->holder.obj;
        o->f64 = (float)(p->n2358 + 9);
        FUN_00102c54(p->holder.obj);
        o = p->holder.obj;
        o->f_f8 = FUN_001fea10(0x11, 0x12, 6);
        o->f_138 = 1;
        FUN_0010d4a8();
    }
}
// near miss from lane ds1 (unreviewed)
