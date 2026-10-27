/* HSTMATCH module=hstp_trans_main.prx start=0x001e46a4 end=0x001e4834 symbol=FUN_001e46a4 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/node_ctor_two_columns_001d68b4.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Matching idiom: the per-index fields are addressed as `base + off4/off2 + const` with a separate local `int base = (int)self` and explicit byte-offset counters `off4 += 4; off2 += 2` next to the unsigned counter `i`; array members indexed by i, `(char *)self + off`, `(int)self + off` and `base + i * 4` all fold into pointer induction variables that start at self, while retail's two offset counters start at 0. The slot is re-read after the short store (aliasing); the shorts are signed `/ 2`. */
extern "C" {
extern char DAT_003b264c;
extern char DAT_003b2680;
extern char DAT_002d7334[];
extern char DAT_002d7340[];
extern char DAT_002d7348[];
extern char DAT_002d7354[];
extern char DAT_002d735c[];
}
struct Rect {
    char pad0[4];
    short s4;
    short s6;
    short s8;
    short sa;
    char pad1[0x20 - 0xc];
    int f20;
};
struct Node {
    void *vptr;
    char pad[0x50];
    unsigned char f54;
    unsigned char f55;
    int f58;
    int f5c;
    char pad60[4];
    void *f64;
    void *f68;
    char pad6c[0x84 - 0x6c]; /* two {Rect *item; short cx, cy; float scale} columns, see the loop */
    int f84;
};
struct VC {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void m();
};
extern "C" {
void FUN_0010873c(Node *);
void FUN_00109a44(Node *, char *, int);
void *FUN_00109304(Node *, char *, int);
Rect *FUN_00108124(void *, char *);
void FUN_000143b0(char *, char *, unsigned);
void FUN_001dff28(Rect *);
void FUN_001dfd08(Node *);
}
extern "C" Node *FUN_001e46a4(Node *self)
{
    char buf[64];
    FUN_0010873c(self);
    self->vptr = &DAT_003b264c;
    self->f54 = 0;
    self->f55 = 0;
    self->f58 = 0;
    self->vptr = &DAT_003b2680;
    self->f84 = 0;
    FUN_00109a44(self, DAT_002d735c, 0);
    self->f64 = FUN_00109304(self, DAT_002d7354, 0);
    self->f68 = FUN_00109304(self, DAT_002d7348, 0);
    self->f58 = FUN_00108124(self->f68, DAT_002d7340)->f20;
    int base = (int)self; /* column offsets are separate byte IVs (+0x6c items, +0x74 cx, +0x78 cy, +0x7c scale) */
    unsigned i = 0;
    int off4 = 0;
    int off2 = 0;
    do {
        FUN_000143b0(buf, DAT_002d7334, i);
        Rect *r = FUN_00108124(self->f68, buf);
        *(Rect **)(base + off4 + 0x6c) = r;
        *(short *)(base + off2 + 0x74) = (r->s4 + r->s8) / 2;
        r = *(Rect **)(base + off4 + 0x6c);
        *(short *)(base + off2 + 0x78) = (r->s6 + r->sa) / 2;
        *(float *)(base + off4 + 0x7c) = 1.0f;
        i++;
        off4 += 4;
        off2 += 2;
    } while (i < 2);
    self->f55 = 0;
    self->f5c = 2;
    FUN_001dff28((Rect *)self->f58);
    self->f55 = 0;
    FUN_001dfd08(self);
    ((VC *)self)->m();
    return self;
}
