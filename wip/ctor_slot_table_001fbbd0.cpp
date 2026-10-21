/* HSTMATCH module=EBOOT.BIN start=0x001fbbd0 end=0x001fbd28 symbol=FUN_001fbbd0 lang=c++ */
extern int DAT_00309570;
extern int DAT_002eeec8;
extern int DAT_002eedb8;
extern int DAT_002eee08;
extern int DAT_002eee68;
extern int DAT_002eeee8;
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void *FUN_001039d8(void *, int, int);
extern "C" int FUN_001026b8(int, int);
extern "C" void FUN_001fbdb8(void *, int);
extern "C" void *FUN_00000bcc(int);
extern "C" void *FUN_00050fc0(void *);
extern "C" void FUN_000511c4(void *, void *, int);
extern "C" void FUN_00051398(void *, float);

class Iface {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void hit(int x);
};

struct Entry {
    int idx;
    int id;
    int out;
};

struct SlotObj {
    void *vt;
    char pad[0x50];
    int slots[10];
    char b7c;
    char b7d;
};

extern "C" SlotObj *FUN_001fbbd0(SlotObj *self) {
    FUN_00102e38(self);
    self->vt = &DAT_00309570;
    FUN_00104118(self, &DAT_002eeec8, 0);
    self->slots[9] = 0;
    FUN_00103540(self, *(float *)&DAT_002eedb8);
    int *q = (int *)&DAT_002eee08;
    Iface *o = (Iface *)FUN_001039d8(self, *q, 0);
    self->slots[0] = (int)o;
    o->hit(-2);
    int i = 0;
    Entry *e = (Entry *)&DAT_002eee68;
    int off = 0;
    do {
        int *n = (int *)FUN_001026b8(self->slots[e->idx], e->id);
        *(int *)((char *)self + off + 0x58) = (int)n;
        if (n != 0) e->out = n[9];
        i++;
        e++;
        off += 4;
    } while (i < 8);
    FUN_001fbdb8(self, 0);
    void *p = FUN_00000bcc(72);
    if (p != 0) p = FUN_00050fc0(p);
    self->slots[9] = (int)p;
    FUN_000511c4(p, &DAT_002eeee8, 0);
    FUN_00051398(p, 100.0f + *(float *)&DAT_002eedb8);
    self->b7c = 1;
    self->b7d = 0;
    return self;
}
// NEAR MISS: 86/86 words, 46 differing (mostly schedule): retail fills the first call's slot with the
// next statement's `sw zero,120(s3)` and materialises a2 before the jal, stores `slots[0]` from v0 before
// `move a0` for the virtual call, and keeps the loop as i (s2) / entry (s1) / byte offset (s0). The
// virtual call needed `class { virtual m0..m4; virtual hit(int); }` (slot 5 = offset 28) and
// `extern int *`-style address-of reads; plain function pointers produce jalr v0 instead of t9.
// near miss from lane ds10 (unreviewed)
