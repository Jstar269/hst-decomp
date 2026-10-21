/* HSTMATCH module=EBOOT.BIN start=0x0021b478 end=0x0021b5d0 symbol=FUN_0021b478 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
extern int DAT_003097a4;
extern int DAT_002f0160;
extern int DAT_002eff88;
extern int DAT_002f00b8;
extern int DAT_002f0100;
extern int DAT_002f0154;
extern int DAT_002f0158;
extern int DAT_002f0190;
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" int FUN_001039d8(void *, int, int);
extern "C" int FUN_001026b8(int, int);
extern "C" void FUN_000143b0(void *, void *, int);
extern "C" void FUN_0021b79c(void *);

struct Entry {
    int idx;
    int id;
    int out;
};

struct SlotObj {
    void *vt;
    char pad[0x58];
    int f5c;
    int f60;
    int f64;
    int slots[3];
    int slots2[7];
    int f90;
    int f94;
    char buf[0x100];
    char f198;
};

extern "C" SlotObj *FUN_0021b478(SlotObj *self) {
    FUN_00102e38(self);
    self->vt = &DAT_003097a4;
    FUN_00104118(self, &DAT_002f0160, 0);
    FUN_00103540(self, *(float *)&DAT_002eff88);
    int i = 0;
    int *tab = (int *)&DAT_002f00b8;
    int off = 0;
    do {
        *(int *)((unsigned int)self + off + 0x68) = FUN_001039d8(self, *tab, 0);
        i++;
        tab++;
        off += 4;
    } while (i < 3);
    int k = 0;
    Entry *e = (Entry *)&DAT_002f0100;
    int off2 = 0;
    do {
        int *n = (int *)FUN_001026b8(*(int *)((char *)self + (e->idx << 2) + 0x68), e->id);
        *(int *)((unsigned int)self + off2 + 0x74) = (int)n;
        e->out = n[9];
        k++;
        off2 += 4;
        e++;
    } while (k < 7);
    int a = *(int *)&DAT_002f0154;
    int o1 = *(int *)((char *)self->slots2[a] + 0x20);
    self->f90 = o1;
    int b = *(int *)&DAT_002f0158;
    self->f94 = *(int *)((char *)self->slots2[b] + 0x20);
    self->f5c = 0;
    self->f64 = -1;
    self->f198 = 0;
    FUN_000143b0(self->buf, &DAT_002f0190, o1);
    FUN_0021b79c(self);
    return self;
}
