/* HSTMATCH module=hstp_trans_main.prx start=0x000f54f0 end=0x000f5660 symbol=FUN_000f54f0 lang=c++ */
/* Clone of src/eboot/ctor_three_loops_000efe28.cpp (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003b0ba0;
extern int DAT_0037e158;
extern int DAT_0037e08c;
extern int DAT_0037e0f0;
extern int DAT_0037e150;
extern "C" void FUN_0010873c(void *);
extern "C" void FUN_00109a44(void *, void *, int);
extern "C" void FUN_00108e6c(void *, float);
extern "C" void FUN_001090f4(void *, int);
extern "C" int FUN_00109304(void *, int, int);
extern "C" int FUN_00108124(int, int);
extern "C" void FUN_000f59e4(void *);

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

extern "C" Self *FUN_000f54f0(Self *self) {
    FUN_0010873c(self);
    self->vt = &DAT_003b0ba0;
    FUN_00109a44(self, &DAT_0037e158, 0);
    FUN_00108e6c(self, 3000.0f);
    FUN_001090f4(self, -304);
    {
        int i = 0;
        int *tab = (int *)&DAT_0037e08c;
        int off = 0;
        do {
            *(int *)((unsigned int)self + off + 0x58) = FUN_00109304(self, *tab, 0);
            i++;
            tab++;
            off += 4;
        } while (i < 3);
    }
    {
        int k = 0;
        Entry *e = (Entry *)&DAT_0037e0f0;
        int off2 = 0;
        do {
            int *n = (int *)FUN_00108124(self->slots[e->idx], e->id);
            *(int *)((unsigned int)self + off2 + 0x64) = (int)n;
            e->out = n[9];
            k++;
            off2 += 4;
            e++;
        } while (k < 8);
    }
    {
        int m = 0;
        int *tab3 = (int *)&DAT_0037e150;
        int off3 = 0;
        do {
            *(int *)((unsigned int)self + off3 + 0x84) = *(int *)(self->f64[*tab3] + 0x20);
            ((Iface *)*(int *)((unsigned int)self + off3 + 0x84))->hit(-16);
            m++;
            tab3++;
            off3 += 4;
        } while (m < 2);
    }
    FUN_000f59e4(self);
    self->f8c = 0;
    self->f90 = 0;
    self->f94 = 0x3f800000;
    return self;
}
