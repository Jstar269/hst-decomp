/* HSTMATCH module=EBOOT.BIN start=0x000f13e8 end=0x000f1560 symbol=FUN_000f13e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_00307874;
extern int DAT_002d776c;
extern int DAT_002d6c9c;
extern int DAT_002d75d8;
extern int DAT_002d76ac;
extern int DAT_00338b44;
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" int FUN_001039d8(void *, int, int);
extern "C" int FUN_001026b8(int, int);
extern "C" void FUN_00103480(void *);
extern "C" void FUN_000f1568(void *);

class Base2 {
public:
    virtual void m0();
    virtual void m1(int v);
};

struct Entry {
    int idx;
    int id;
    int out;
};

struct Self {
    void *vt;
    char pad[0x50];
    int f54[4];
    int f64[16];
    int fa4;
    int fa8;
    int fac;
    int fb0;
    int fb4;
};

extern "C" Self *FUN_000f13e8(Self *self) {
    FUN_00102e38(self);
    self->vt = &DAT_00307874;
    FUN_00104118(self, &DAT_002d776c, 0);
    FUN_00103540(self, *(float *)&DAT_002d6c9c);
    FUN_001037c8(self, -251);
    int i = 0;
    int *tab = (int *)&DAT_002d75d8;
    int off = 0;
    do {
        *(int *)((unsigned int)self + off + 0x54) = FUN_001039d8(self, *tab, 0);
        i++;
        tab++;
        off += 4;
    } while (i < 4);
    int k = 0;
    Entry *e = (Entry *)&DAT_002d76ac;
    int off2 = 0;
    do {
        int *n = (int *)FUN_001026b8(self->f54[e->idx], e->id);
        *(int *)((unsigned int)self + off2 + 0x64) = (int)n;
        e->out = n[9];
        k++;
        off2 += 4;
        e++;
    } while (k < 16);
    int a = *(int *)(DAT_00338b44 + 0xb8);
    self->fa4 = a % 10;
    int b = *(int *)(DAT_00338b44 + 0xbc);
    self->fa8 = b % 10;
    ((Base2 *)self->f54[2])->m1(1);
    self->fac = 0;
    self->fb0 = 0;
    self->fb4 = 0;
    *(float *)(self->f54[2] + 0x60) = 385.0f;
    FUN_00103480(self);
    FUN_000f1568(self);
    return self;
}
