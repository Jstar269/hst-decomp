/* HSTMATCH module=hstp_trans_main.prx start=0x0022a9ec end=0x0022ab44 symbol=FUN_0022a9ec lang=c++ */
/* Clone of src/eboot/ctor_slots_0021b478.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
extern int DAT_003b2a70;
extern int DAT_0039852c;
extern int DAT_00398354;
extern int DAT_00398484;
extern int DAT_003984cc;
extern int DAT_00398520;
extern int DAT_00398524;
extern int DAT_0039855c;
extern "C" void FUN_0010873c(void *);
extern "C" void FUN_00109a44(void *, void *, int);
extern "C" void FUN_00108e6c(void *, float);
extern "C" int FUN_00109304(void *, int, int);
extern "C" int FUN_00108124(int, int);
extern "C" void FUN_000143b0(void *, void *, int);
extern "C" void FUN_0022ad10(void *);

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

extern "C" SlotObj *FUN_0022a9ec(SlotObj *self) {
    FUN_0010873c(self);
    self->vt = &DAT_003b2a70;
    FUN_00109a44(self, &DAT_0039852c, 0);
    FUN_00108e6c(self, *(float *)&DAT_00398354);
    int i = 0;
    int *tab = (int *)&DAT_00398484;
    int off = 0;
    do {
        *(int *)((unsigned int)self + off + 0x68) = FUN_00109304(self, *tab, 0);
        i++;
        tab++;
        off += 4;
    } while (i < 3);
    int k = 0;
    Entry *e = (Entry *)&DAT_003984cc;
    int off2 = 0;
    do {
        int *n = (int *)FUN_00108124(*(int *)((char *)self + (e->idx << 2) + 0x68), e->id);
        *(int *)((unsigned int)self + off2 + 0x74) = (int)n;
        e->out = n[9];
        k++;
        off2 += 4;
        e++;
    } while (k < 7);
    int a = *(int *)&DAT_00398520;
    int o1 = *(int *)((char *)self->slots2[a] + 0x20);
    self->f90 = o1;
    int b = *(int *)&DAT_00398524;
    self->f94 = *(int *)((char *)self->slots2[b] + 0x20);
    self->f5c = 0;
    self->f64 = -1;
    self->f198 = 0;
    FUN_000143b0(self->buf, &DAT_0039855c, o1);
    FUN_0022ad10(self);
    return self;
}
