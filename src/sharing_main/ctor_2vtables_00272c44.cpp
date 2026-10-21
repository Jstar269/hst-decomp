/* HSTMATCH module=hstp_trans_main.prx start=0x00272c44 end=0x00272da4 symbol=FUN_00272c44 lang=c++ */
/* Clone of src/eboot/ctor_2vtables_00261e1c.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_003b264c;
extern int DAT_003b2d3c;
extern int DAT_003e1a08;
extern int DAT_003a6988;
extern int DAT_003a69a8;
extern int DAT_003a69b4;
extern int DAT_003a69bc;
extern int DAT_003a69c8;
extern int DAT_003a69d8;
extern int DAT_003a69e8;
extern "C" void FUN_0010873c(void *);
extern "C" void FUN_00109a44(void *, void *, int);
extern "C" int FUN_00109304(void *, void *, int);
extern "C" int FUN_00108124(int, void *);
extern "C" void FUN_000143b0(void *, void *, unsigned);

class Base {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

struct Self {
    void *vt;
    char pad[0x50];
    char b54;
    char b55;
    int f58;
    int f5c;
    int f60;
    int f64;
    int f68[4];
    int f78;
    int f7c;
    int f80;
    int f84;
    int f88;
};

static inline int *SlotOf(Self *s, int off) {
    return (int *)((char *)s + off + 0x68);
}

extern "C" Self *FUN_00272c44(Self *self) {
    FUN_0010873c(self);
    self->vt = &DAT_003b264c;
    self->b54 = 0;
    self->b55 = 0;
    self->f58 = 0;
    self->vt = &DAT_003b2d3c;
    int f = *(int *)(DAT_003e1a08 + 0x40);
    self->f5c = f;
    FUN_00109a44(self, &DAT_003a6988, 0);
    self->f64 = FUN_00109304(self, &DAT_003a69a8, 0);
    int v = FUN_00108124(self->f64, &DAT_003a69b4);
    int obj = *(int *)(v + 0x20);
    self->f58 = obj;
    *(int *)(obj + 0xd8) = 2;
    *(char *)(obj + 0x114) = 1;
    char buf[0x40];
    unsigned i = 0;
    unsigned off = 0;
    for (; i < 4; i++) {
        FUN_000143b0(buf, &DAT_003a69bc, i);
        *SlotOf(self, off) = FUN_00108124(self->f64, buf);
        off += 4;
    }
    self->f78 = FUN_00108124(self->f64, &DAT_003a69c8);
    self->f7c = FUN_00108124(self->f64, &DAT_003a69d8);
    int w = FUN_00108124(self->f64, &DAT_003a69e8);
    self->f80 = w;
    self->f84 = *(int *)(w + 0x24);
    self->f88 = 1;
    self->b55 = 0;
    ((Base *)self)->m7();
    return self;
}
