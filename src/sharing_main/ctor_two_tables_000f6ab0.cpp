/* HSTMATCH module=hstp_trans_main.prx start=0x000f6ab0 end=0x000f6c28 symbol=FUN_000f6ab0 lang=c++ */
/* Clone of src/eboot/ctor_two_tables_000f13e8.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003b0b40;
extern int DAT_0037e544;
extern int DAT_0037da74;
extern int DAT_0037e3b0;
extern int DAT_0037e484;
extern int DAT_003e1e84;
extern "C" void FUN_0010873c(void *);
extern "C" void FUN_00109a44(void *, void *, int);
extern "C" void FUN_00108e6c(void *, float);
extern "C" void FUN_001090f4(void *, int);
extern "C" int FUN_00109304(void *, int, int);
extern "C" int FUN_00108124(int, int);
extern "C" void FUN_00108dac(void *);
extern "C" void FUN_000f6c30(void *);

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

extern "C" Self *FUN_000f6ab0(Self *self) {
    FUN_0010873c(self);
    self->vt = &DAT_003b0b40;
    FUN_00109a44(self, &DAT_0037e544, 0);
    FUN_00108e6c(self, *(float *)&DAT_0037da74);
    FUN_001090f4(self, -251);
    int i = 0;
    int *tab = (int *)&DAT_0037e3b0;
    int off = 0;
    do {
        *(int *)((unsigned int)self + off + 0x54) = FUN_00109304(self, *tab, 0);
        i++;
        tab++;
        off += 4;
    } while (i < 4);
    int k = 0;
    Entry *e = (Entry *)&DAT_0037e484;
    int off2 = 0;
    do {
        int *n = (int *)FUN_00108124(self->f54[e->idx], e->id);
        *(int *)((unsigned int)self + off2 + 0x64) = (int)n;
        e->out = n[9];
        k++;
        off2 += 4;
        e++;
    } while (k < 16);
    int a = *(int *)(DAT_003e1e84 + 0xb8);
    self->fa4 = a % 10;
    int b = *(int *)(DAT_003e1e84 + 0xbc);
    self->fa8 = b % 10;
    ((Base2 *)self->f54[2])->m1(1);
    self->fac = 0;
    self->fb0 = 0;
    self->fb4 = 0;
    *(float *)(self->f54[2] + 0x60) = 385.0f;
    FUN_00108dac(self);
    FUN_000f6c30(self);
    return self;
}
