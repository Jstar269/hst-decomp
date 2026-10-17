/* HSTMATCH module=EBOOT.BIN start=0x000fa884 end=0x000fa98c symbol=FUN_000fa884 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC_000fa884 { virtual void s0(); virtual void s1(); };
struct Rec_000fa884 {
    unsigned char f0;
    int f4, f8, fc, f10, f14;
    char pad18[8];
    int f20, f24, f28;
    float f2c;
    int f30;
    char pad34[0xc];
};
struct Obj88_000fa884 {
    char pad0[0xa0];
    Rec_000fa884 recs[16];
};
struct Blk_000fa884 {
    unsigned char f0;
    char pad1[7];
    float f8;
};
struct Self_000fa884 {
    char pad0[0x54];
    void *f54;
    char pad58[0x6c - 0x58];
    VC_000fa884 *f6c;
    VC_000fa884 *f70;
    VC_000fa884 *f74;
    VC_000fa884 *f78;
    unsigned char *f7c;
    Blk_000fa884 *f80;
    char pad84[4];
    Obj88_000fa884 *f88;
    void *f8c;
    void *f90;
    void *f94;
};
extern "C" {
extern void FUN_000f3640(void *);
extern void FUN_000f6b0c(void *, int);
extern void FUN_001ec518(void *, int);
}

#pragma opt_unroll_loops off
extern "C" void FUN_000fa884(Self_000fa884 *self)
{
    FUN_000f3640(self->f54);
    self->f70->s1();
    self->f6c->s1();
    self->f74->s1();
    self->f78->s1();
    *self->f7c = 1;
    Blk_000fa884 *b = self->f80;
    b->f0 = 1;
    b->f8 = -1.0f;
    unsigned i = 0;
    char *p = (char *)self->f88;
    do {
        Rec_000fa884 *r = (Rec_000fa884 *)(p + 0xa0);
        r->f0 = 0;
        r->f4 = 0x10;
        r->f8 = 0;
        r->fc = -1;
        r->f10 = 0;
        r->f14 = 0;
        r->f20 = 0;
        r->f24 = 0;
        r->f28 = 0;
        r->f2c = 1.0f;
        r->f30 = 0;
        i++;
        p += 0x40;
    } while (i < 16);
    FUN_000f6b0c(self->f8c, 0);
    FUN_000f6b0c(self->f90, 0);
    FUN_001ec518(self->f94, 1);
}
