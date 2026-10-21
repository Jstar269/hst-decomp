/* HSTMATCH module=EBOOT.BIN start=0x000efe28 end=0x000eff98 symbol=FUN_000efe28 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003078d4;
extern int DAT_002d7380;
extern int DAT_002d72b4;
extern int DAT_002d7318;
extern int DAT_002d7378;
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" int FUN_001039d8(void *, int, int);
extern "C" int FUN_001026b8(int, int);
extern "C" void FUN_000f031c(void *);

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

struct Self {
    void *vt;
    char pad[0x54];
    int slots[3];
    int f64[8];
    int f84[2];
    int f8c;
    int f90;
    int f94;
};

extern "C" Self *FUN_000efe28(Self *self) {
    FUN_00102e38(self);
    self->vt = &DAT_003078d4;
    FUN_00104118(self, &DAT_002d7380, 0);
    FUN_00103540(self, 3000.0f);
    FUN_001037c8(self, -304);
    {
        int i = 0;
        int *tab = (int *)&DAT_002d72b4;
        int off = 0;
        do {
            *(int *)((unsigned int)self + off + 0x58) = FUN_001039d8(self, *tab, 0);
            i++;
            tab++;
            off += 4;
        } while (i < 3);
    }
    {
        int k = 0;
        Entry *e = (Entry *)&DAT_002d7318;
        int off2 = 0;
        do {
            int *n = (int *)FUN_001026b8(self->slots[e->idx], e->id);
            *(int *)((unsigned int)self + off2 + 0x64) = (int)n;
            e->out = n[9];
            k++;
            off2 += 4;
            e++;
        } while (k < 8);
    }
    {
        int m = 0;
        int *tab3 = (int *)&DAT_002d7378;
        int off3 = 0;
        do {
            *(int *)((unsigned int)self + off3 + 0x84) = *(int *)(self->f64[*tab3] + 0x20);
            ((Iface *)*(int *)((unsigned int)self + off3 + 0x84))->hit(-16);
            m++;
            tab3++;
            off3 += 4;
        } while (m < 2);
    }
    FUN_000f031c(self);
    self->f8c = 0;
    self->f90 = 0;
    self->f94 = 0x3f800000;
    return self;
}
