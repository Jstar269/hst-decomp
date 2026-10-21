/* HSTMATCH module=EBOOT.BIN start=0x00261e1c end=0x00261f7c symbol=FUN_00261e1c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_00309380;
extern int DAT_00309a54;
extern int DAT_003386c8;
extern int DAT_002fdd78;
extern int DAT_002fdd98;
extern int DAT_002fdda4;
extern int DAT_002fddac;
extern int DAT_002fddb8;
extern int DAT_002fddc8;
extern int DAT_002fddd8;
extern "C" void FUN_00102e38(void *);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" int FUN_001039d8(void *, void *, int);
extern "C" int FUN_001026b8(int, void *);
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

extern "C" Self *FUN_00261e1c(Self *self) {
    FUN_00102e38(self);
    self->vt = &DAT_00309380;
    self->b54 = 0;
    self->b55 = 0;
    self->f58 = 0;
    self->vt = &DAT_00309a54;
    int f = *(int *)(DAT_003386c8 + 0x40);
    self->f5c = f;
    FUN_00104118(self, &DAT_002fdd78, 0);
    self->f64 = FUN_001039d8(self, &DAT_002fdd98, 0);
    int v = FUN_001026b8(self->f64, &DAT_002fdda4);
    int obj = *(int *)(v + 0x20);
    self->f58 = obj;
    *(int *)(obj + 0xd8) = 2;
    *(char *)(obj + 0x114) = 1;
    char buf[0x40];
    unsigned i = 0;
    unsigned off = 0;
    for (; i < 4; i++) {
        FUN_000143b0(buf, &DAT_002fddac, i);
        *SlotOf(self, off) = FUN_001026b8(self->f64, buf);
        off += 4;
    }
    self->f78 = FUN_001026b8(self->f64, &DAT_002fddb8);
    self->f7c = FUN_001026b8(self->f64, &DAT_002fddc8);
    int w = FUN_001026b8(self->f64, &DAT_002fddd8);
    self->f80 = w;
    self->f84 = *(int *)(w + 0x24);
    self->f88 = 1;
    self->b55 = 0;
    ((Base *)self)->m7();
    return self;
}
