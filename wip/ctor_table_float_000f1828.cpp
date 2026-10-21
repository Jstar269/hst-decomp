/* HSTMATCH module=EBOOT.BIN start=0x000f1828 end=0x000f19ac symbol=FUN_000f1828 lang=c++ */
extern int DAT_00307854;
extern int DAT_002d7804;
extern int DAT_002d6c9c;
extern int DAT_002d77a4;
extern int DAT_002d77d0;
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" int FUN_001039d8(void *, int, int);
extern "C" int FUN_001026b8(int, int);
extern "C" void FUN_000f19e4(void *);
extern "C" void FUN_000f1ad4(void *, int, float);
extern "C" void FUN_000f1b38(void *, int, float);
extern "C" void FUN_000f19b4(void *);

struct Entry {
    int idx;
    int id;
    int out;
};

struct Self {
    void *vt;
    char pad[0x50];
    int slots[5];
    int f68;
    int f6c;
    float f70;
    int f74;
    char b78;
    char b79;
    char pad2[2];
    int f7c;
};

extern "C" Self *FUN_000f1828(Self *self) {
    FUN_00102e38(self);
    self->vt = &DAT_00307854;
    FUN_00104118(self, &DAT_002d7804, 0);
    FUN_00103540(self, *(float *)&DAT_002d6c9c);
    FUN_001037c8(self, -251);
    unsigned int addr = (unsigned int)&DAT_002d77a4;
    self->slots[0] = FUN_001039d8(self, *(int *)addr, 0);
    int i = 0;
    Entry *e = (Entry *)&DAT_002d77d0;
    int off = 0;
    do {
        int *n = (int *)FUN_001026b8(self->slots[e->idx], e->id);
        *(int *)((unsigned int)self + off + 0x58) = (int)n;
        e->out = n[9];
        i++;
        off += 4;
        e++;
    } while (i < 4);
    self->f68 = *(int *)(self->slots[3] + 0x20);
    self->f6c = *(int *)(self->slots[4] + 0x20);
    self->f70 = (float)*(short *)(self->slots[1] + 4);
    self->b78 = 0;
    self->f74 = 0;
    self->f7c = 0x3c23d70a;
    FUN_000f19e4(self);
    self->b79 = 0;
    FUN_000f1ad4(self, 0, 0.0f);
    FUN_000f1ad4(self, 1, 0.0f);
    FUN_000f1ad4(self, 2, 0.0f);
    FUN_000f1b38(self, 1, 100.0f);
    FUN_000f19b4(self);
    return self;
}
// NEAR MISS: 94/97 words. The body is instruction-for-instruction identical to retail once shifted; only
// the read of DAT_002d77a4 differs: retail materialises the address (`lui v0,0x2d; addiu v0,v0,30628;
// lw a1,0(v0)`) while MWCC folds it into the load (`lw a1,30628(v0)`), one word short, and two more
// words are missing in the float tail (the three FUN_000f1ad4(self, n, 0.0f) calls order `li a1,n`
// before the mtc1). `int *p=&DAT; *p`, `unsigned addr=(unsigned)&DAT;`, `pp[0]` and a post-declaration
// assignment all fold.
// near miss from lane ds10 (unreviewed)
