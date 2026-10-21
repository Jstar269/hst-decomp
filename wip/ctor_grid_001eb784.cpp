/* HSTMATCH module=EBOOT.BIN start=0x001eb784 end=0x001eb960 symbol=FUN_001eb784 lang=c++ */
extern int DAT_00309480;
extern int DAT_002ee3e0;
extern int DAT_002ec1c4;
extern int DAT_002ee144;
extern int DAT_002ee288;
extern int DAT_002ee3d8;
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" int FUN_001039d8(void *, int, int);
extern "C" int FUN_001026b8(int, int);
extern "C" void FUN_000ffc3c(void *, int);

class Base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(int);
    virtual void m6();
    virtual void m7();
};

struct Entry {
    int idx;
    int id;
    int out;
};

struct Node {
    void *vt;
    char pad[0x1c];
    int f20;
    int f24;
};

struct Extra {
    void *vt;
    char pad[0x1c];
    int f20;
};

struct Self {
    void *vt;
    char pad[0x50];
    int slots[5];
    int nodes[28];
    int fD8[2];
    int fE0;
    int fE4;
    int fE8;
    int grid[2][6];
    int f11C;
    int f120;
    int f124;
    unsigned char b12C;
    unsigned char b12D;
    unsigned char b12E;
    unsigned char b12F;
    int f134;
    int f138;
};

extern "C" Self *FUN_001eb784(Self *self) {
    FUN_00102e38(self);
    self->vt = &DAT_00309480;
    FUN_00104118(self, &DAT_002ee3e0, 0);
    FUN_00103540(self, *(float *)&DAT_002ec1c4);
    int i = 0;
    int *tab = &DAT_002ee144;
    int off = 0;
    do {
        Node *p = (Node *)FUN_001039d8(self, *tab, 0);
        *(int *)((unsigned int)self + off + 0x54) = (int)p;
        ((Base *)*(int *)((unsigned int)self + off + 0x54))->m5(-2);
        i++;
        tab++;
        off += 4;
    } while (i < 5);
    int k = 0;
    Entry *e = (Entry *)&DAT_002ee288;
    int off2 = 0;
    do {
        Node *n = (Node *)FUN_001026b8(*(int *)((char *)self + (e->idx << 2) + 0x54), e->id);
        *(int *)((unsigned int)self + off2 + 0x68) = (int)n;
        if (n != 0) {
            FUN_000ffc3c(n, -256);
        }
        e->out = ((Node *)*(int *)((char *)self + (0x68 + off2)))->f24;
        k++;
        off2 += 4;
        e++;
    } while (k < 28);
    int j = 0;
    int *tab2 = &DAT_002ee3d8;
    int off3 = 0;
    do {
        Extra *x = (Extra *)*(int *)((unsigned int)self + (*tab2 << 2) + 0x68);
        *(int *)((unsigned int)self + off3 + 0xD8) = x->f20;
        ((Base *)x)->m5(-16);
        j++;
        tab2++;
        off3 += 4;
    } while (j < 2);
    self->fE0 = 1;
    self->fE4 = 0;
    self->f11C = 0;
    self->f124 = -1;
    for (int r = 0; r < 2; r++) {
        self->grid[r][0] = 0;
        self->grid[r][1] = 0;
        self->grid[r][2] = 0;
        self->grid[r][3] = 0;
        self->grid[r][4] = 0;
        self->grid[r][5] = 0;
    }
    self->b12C = 0;
    self->b12D = 0;
    self->b12E = 0;
    self->b12F = 0;
    self->f134 = 0;
    self->f138 = 0;
    return self;
}
// near miss (118/119 words, 1 short): loop1 and loop2's store match; the reload after the
// 0xffc3c call groups as `addiu v0,s1,104; addu v0,s0,v0; lw v0,0(v0)` where retail has
// `addu v0,s0,s1; lw v0,104(v0)` (writing `(unsigned)self + off2 + 0x68` gives the right two
// words but MWCC then hoists the address into a saved register across the call); the 2x6 grid
// clearing tail stays unrolled (retail keeps it rolled with a phantom `self+4*i` IV) and the
// fE4/f11C/f124 stores use two base registers there.
// near miss from lane ds10 (unreviewed)
