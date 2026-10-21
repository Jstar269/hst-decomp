/* HSTMATCH module=EBOOT.BIN start=0x001b4edc end=0x001b50a4 symbol=FUN_001b4edc lang=c++ */
struct Cont {
    int f0;
    int f4;
    void *f8;
    char f12;
};

struct Self {
    void *vptr;
    char pad4[0x3c - 4];
    Cont c1;
    int f4c, f50, f54, f58;
    int *f5c;
    char *f60;
    int f64, f68, f6c;
    char f70, f71, pad72[2];
    int f74;
    char f78, f79, f7a, f7b;
    int f7c, f80, f84;
    char pad88[8];
    char f90, f91, f92, f93, f94;
    char pad95[0xa0 - 0x95];
    short *slots[18];
    int fe8, fec;
    Cont c2;
};

struct Iter {
    void *p;
};

extern "C" {
extern char DAT_003092dc[];
extern char DAT_0034179c[];
void FUN_0001f06c(void);
void FUN_001b9708(Cont *c);
void FUN_001b94f8(void *out, Cont *c, Iter *first, Iter *last);
void FUN_001b86f8(Self *self);
void FUN_001b3590(void *p, int n);
void *FUN_00000a90(unsigned n);
void *FUN_00000bcc(unsigned n);
}

inline void InitCont(Cont *c)
{
    FUN_001b9708(c);
    c->f12 = 0;
    void *out;
    Iter first;
    Iter last;
    last.p = &c->f4;
    first.p = c->f8;
    FUN_001b94f8(&out, c, &first, &last);
}

extern "C" Self *FUN_001b4edc(Self *self)
{
    void *out2;
    Iter first2;
    Iter last2;
    FUN_0001f06c();
    InitCont(&self->c1);
    self->vptr = DAT_003092dc;
    self->f74 = 0;
    FUN_001b9708(&self->c2);
    self->f4c = -1;
    self->f50 = -1;
    self->f54 = -1;
    self->f58 = -1;
    self->f5c = (int *)FUN_00000a90(16);
    self->f60 = (char *)FUN_00000a90(4);
    self->f5c[0] = -1;
    self->f60[0] = 0;
    self->f5c[1] = -1;
    self->f60[1] = 0;
    self->f5c[2] = -1;
    self->f60[2] = 0;
    self->f5c[3] = -1;
    self->f60[3] = 0;
    self->f64 = -1;
    self->f68 = -1;
    self->f6c = 0;
    self->f70 = 0;
    self->f71 = 0;
    self->f78 = 1;
    self->f79 = 1;
    self->f7a = 1;
    self->f7b = 0;
    self->f7c = 0;
    self->f80 = 0;
    self->f84 = 0;
    self->f90 = 0;
    self->f91 = 0;
    self->f92 = 0;
    self->f93 = 0;
    self->f94 = 0;
    FUN_001b86f8(self);
    int i = 0;
    int off = 0;
    do {
        short *p = *(short **)((unsigned int)self + off + 0xa0) = (short *)FUN_00000bcc(6);
        p[0] = 0;
        p[1] = 2;
        p[2] = 0;
        i++;
        off += 4;
    } while (i < 18);
    self->fe8 = 0xd0;
    self->fec = 0xd0;
    last2.p = &self->c2.f4;
    first2.p = self->c2.f8;
    FUN_001b94f8(&out2, &self->c2, &first2, &last2);
    FUN_001b3590(DAT_0034179c, 1);
    return self;
}
// PARKED (lane sn2, ~20 compiles): 110 of 114 words, all differ from the first word on (register colouring and frame size).
// Known facts: retail has 4 saved registers (s2 = self, s0 = pointer to the first container member self+0x3c then the loop byte offset, s1 = loop counter,
// s3 = the slot ADDRESS `self + off + 0xa0` computed BEFORE the call to 0xbcc and stored through afterwards: `addu v0,s2,s0; addiu s3,v0,160; jal 0xbcc; sw v0,0(s3)`),
// frame 64, and the base ctor call is `FUN_0001f06c()` WITHOUT argument (`move s2,a0` sits before the jal). The two iterator groups of the container "clear"
// (out/first/last at sp+48/44/40 for the first container, 60/56/52 for the second; FUN_001b94f8(out, cont, &first, &last), first = cont->f8, last = &cont->f4)
// get distinct slots (first group LOWER) when the first group is expanded inside an inline helper that also holds the container ctor + `f12 = 0` (as here) and the second
// group is written in the body. Not solved: (1) keeping self in s2 and the container pointer in s0 (ours: self = s0), (2) computing the slot address before the call
// (a pointer local, a chained assignment and an unsigned-address cast were all sunk below the call by the scheduler), (3) the resulting frame 64.
// near miss from lane sn2 (unreviewed)
