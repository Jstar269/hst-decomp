/* HSTMATCH module=EBOOT.BIN start=0x0017b3bc end=0x0017b554 symbol=FUN_0017b3bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Constructor of a polymorphic object holding a vector of 240-byte nodes (data/size/cap at +8): reserves n slots, then appends n freshly built nodes. Matching idiom: `Node *x = p;` (the address-taken copy that goes to the out-of-line push_back) next to the allocation local p. */
struct Tag {};
struct Node {
    void *p0;
    void *p4;
    char pad8[8];
    char sub[0xe0];
};
struct NodeVec {
    Node **data;
    unsigned size;
    unsigned cap;
};
struct Obj {
    void *vptr;
    int f4;
    NodeVec vec;
    int f14[10];
    int f3c;
    unsigned char f40;
    unsigned char f41;
    char pad42[2];
    int f44;
    int f48;
    float f4c;
    int f50;
    int f54;
    unsigned char f58;
    unsigned char f59;
    char pad5a[2];
    char sub5c[0x144];
    char sub1a0[0x144];
    int f2e4;
    unsigned char f2e8;
    unsigned char f2e9;
    unsigned char f2ea;
    unsigned char f2eb;
    int f2ec;
    int f2f0;
    int f2f4;
    int f2f8;
    int f2fc;
    int f300;
};
extern char DAT_003090c8;
extern "C" {
void *FUN_00000bcc(unsigned);
void FUN_00091830(void *);
void FUN_0017df4c(NodeVec *, Node **, Tag);
void FUN_0017df90(NodeVec *, unsigned);
void FUN_001fe178(void *);
}

extern "C" Obj *FUN_0017b3bc(Obj *self, unsigned n)
{
    self->vptr = &DAT_003090c8;
    self->vec.data = 0;
    self->vec.size = 0;
    self->vec.cap = 0;
    self->f14[0] = 0;
    self->f14[1] = 0;
    self->f14[2] = 0;
    self->f14[3] = 0;
    self->f14[4] = 0;
    self->f14[5] = 0;
    self->f14[6] = 0;
    self->f14[7] = 0;
    self->f14[8] = 0;
    self->f14[9] = 0;
    self->f3c = 0;
    FUN_001fe178(self->sub5c);
    FUN_001fe178(self->sub1a0);
    self->f2e4 = 0x7fffffff;
    self->f2e8 = 0;
    self->f2e9 = 0;
    self->f2ea = 0;
    self->f2eb = 0;
    self->f2ec = 0x7fffffff;
    self->f2f0 = 0x7fffffff;
    self->f2f4 = 0x7fffffff;
    self->f2f8 = 0x7fffffff;
    self->f2fc = 0x7fffffff;
    self->f300 = 0x7fffffff;
    self->f50 = 0;
    self->f54 = 0;
    self->f40 = 0;
    self->f41 = 1;
    self->f44 = 0;
    self->f4c = 1.0f;
    self->f4 = 0;
    self->f58 = 0;
    self->f59 = 1;
    if (self->vec.cap < n)
        FUN_0017df90(&self->vec, n);
    for (int j = 0; j < (int)n; j++) {
        Node *p = (Node *)FUN_00000bcc(0xf0);
        if (p != 0) {
            FUN_00091830(p->sub);
            p->p0 = 0;
            p->p4 = 0;
        }
        Node *x = p;
        if (self->vec.size < self->vec.cap) {
            unsigned s = self->vec.size + 1;
            self->vec.size = s;
            self->vec.data[s - 1] = x;
        } else {
            FUN_0017df4c(&self->vec, &x, Tag());
        }
    }
    return self;
}
