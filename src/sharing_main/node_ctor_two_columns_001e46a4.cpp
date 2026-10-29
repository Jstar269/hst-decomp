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
#define COLUMN_COUNT 2

struct Rect {
    char pad0[4];
    short left;   /* 0x04 */
    short top;    /* 0x06 */
    short right;  /* 0x08 */
    short bottom; /* 0x0a */
    char pad1[0x20 - 0xc];
    int unk20;    /* 0x20 */
};
struct Node {
    void *vptr;
    char pad[0x50];
    unsigned char unk54;
    unsigned char unk55;
    int rectRef;       /* 0x58 value of the unk20 field of a rect looked up in part68 */
    int columnCount;   /* 0x5c */
    char pad60[4];
    void *part64;      /* 0x64 */
    void *part68;      /* 0x68 group the column rects are looked up in */
    char pad6c[0x84 - 0x6c]; /* two {Rect *item; short cx, cy; float scale} columns, see the loop */
    int unk84;
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
    char name[64];
    FUN_0010873c(self);
    self->vptr = &DAT_003b264c;
    self->unk54 = 0;
    self->unk55 = 0;
    self->rectRef = 0;
    self->vptr = &DAT_003b2680;
    self->unk84 = 0;
    FUN_00109a44(self, DAT_002d735c, 0);
    self->part64 = FUN_00109304(self, DAT_002d7354, 0);
    self->part68 = FUN_00109304(self, DAT_002d7348, 0);
    self->rectRef = FUN_00108124(self->part68, DAT_002d7340)->unk20;
    int base = (int)self; /* column offsets are separate byte IVs (+0x6c items, +0x74 cx, +0x78 cy, +0x7c scale) */
    unsigned i = 0;
    int off4 = 0;
    int off2 = 0;
    do {
        FUN_000143b0(name, DAT_002d7334, i);
        Rect *rect = FUN_00108124(self->part68, name);
        *(Rect **)(base + off4 + 0x6c) = rect;
        *(short *)(base + off2 + 0x74) = (rect->left + rect->right) / 2;
        rect = *(Rect **)(base + off4 + 0x6c);
        *(short *)(base + off2 + 0x78) = (rect->top + rect->bottom) / 2;
        *(float *)(base + off4 + 0x7c) = 1.0f;
        i++;
        off4 += 4;
        off2 += 2;
    } while (i < COLUMN_COUNT);
    self->unk55 = 0;
    self->columnCount = COLUMN_COUNT;
    FUN_001dff28((Rect *)self->rectRef);
    self->unk55 = 0;
    FUN_001dfd08(self);
    ((VC *)self)->m();
    return self;
}
