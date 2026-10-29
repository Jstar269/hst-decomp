/* HSTMATCH module=EBOOT.BIN start=0x0010cd24 end=0x0010cf4c symbol=FUN_0010cd24 lang=c++ */
/* Hand-written reconstruction from the disassembly; 133/138 words, 78 differ (parked). */

struct Obj {
    char pad0[0x10];
    void **tab;
    char pad1[0xd0 - 0x14];
    int fD0;
    int padD4;
    int fD8;
    int fDC;
    int fE0;
    int fE4;
    unsigned char bE8;
    unsigned char bE9;
    unsigned char bEA;
    char pad2[0x114 - 0xeb];
    signed char b114;
    char pad3[0x120 - 0x115];
    short *arr;
};

struct Self {
    Obj *o;
    int f4;
    int f8;
    int f0c;
    char pad[0x68 - 0x10];
    int state;
    signed char b6c;
    signed char b6d;
};

extern "C" void FUN_0010bc70(Obj *o);
extern "C" void FUN_001b1c44(void *fmt, int n);
extern "C" void FUN_0010c69c(Self *self, int n);
extern "C" void FUN_0001dfe8(void *p, int n);
extern "C" void FUN_0001e23c(void *p, int n, int m);
extern "C" char DAT_0034179c;
extern "C" signed char *DAT_002cfc8c;
extern "C" int DAT_002d9218;

extern "C" void FUN_0010cd24(Self *self)
{
    void *base;
    void *elem;
    unsigned short flags;
    int d;
    int n;
    int old;
    short a;
    short b;

    self->b6c = 0;
    self->b6d = 0;
    if (self->state != 1)
        FUN_0010bc70(self->o);
    base = *(void **)((char *)self->o + 16);
    elem = *(void **)((char *)base + self->f0c * 4);
    flags = *(unsigned short *)((char *)elem + 14);
    if ((flags & 3) != 0)
        return;
    if (self->o->bEA != 0)
        FUN_001b1c44(&DAT_0034179c, 1);
    if (self->state == 0) {
        if (self->o->bE8 != 0) {
            self->state = 1;
            self->f8 = 0;
            if (self->o->fDC == 0) {
                self->b6c = 1;
                FUN_001b1c44(&DAT_0034179c, 3);
            } else {
                self->b6d = 1;
                FUN_001b1c44(&DAT_0034179c, 4);
            }
            Obj *o = self->o;
            o->fD8 = 0;
            o->b114 = 1;
        } else if (!(((DAT_002cfc8c[0x8b] << 26) >> 30) != 0)) {
            self->state = 2;
            d = self->o->fE4 - self->o->fE0;
            n = DAT_002d9218;
            if (n < 2)
                n = 1;
            old = self->o->fDC;
            if (old != n) {
                self->o->fDC = n;
                a = self->o->arr[old * 6];
                b = self->o->arr[n * 6];
                self->o->fD0 = (a == b) ? 0 : 3;
                self->o->bEA = 1;
                self->o->fDC = n;
            }
            FUN_0001dfe8(DAT_002cfc8c, 0x4000);
            FUN_0001e23c(DAT_002cfc8c, 0x4000, 1);
            self->b6d = 1;
            FUN_001b1c44(&DAT_0034179c, 4);
        }
    } else if (self->state == 1) {
        if (self->f8 >= 20)
            self->state = 2;
    }
    FUN_0010c69c(self, self->o->fDC);
}

// Parked 2026-10-29 (lane dsn3, phase 2). 133/138 words, 78 differ, head exact to +0x50.
// Body decoded: (1) clear b6c/b6d, call FUN_0010bc70(o) unless state==1;
// (2) o->tab[f0c] -> obj, if (obj->h14 & 3) return; (3) if (o->bEA) log(&DAT_0034179c,1);
// (4) state machine: state 0 -> if (o->bE8) { state=1; f8=0; fDC==0 ? (b6c=1,log 3) : (b6d=1,log 4);
// o->fD8=0; o->b114=1; } else if (((DAT_002cfc8c->b8b >> 2) & 3) == 0) { state=2;
// d=o->fE4-o->fE0; n=DAT_002d9218; if(n<2)n=1; if(o->fDC!=n){ o->fDC=n; compare o->arr[old*6]/arr[n*6];
// o->fD0 = equal?0:3; o->bEA=1; o->fDC=n; } FUN_0001dfe8(DAT_002cfc8c,0x4000); FUN_0001e23c(...,1);
// b6d=1; log 4; } else if (state==1 && f8>=20) state=2; (5) tail: FUN_0010c69c(self, self->o->fDC).
// Residuals: retail keeps self in s0 only (every self->o is re-read; a cached Obj* costs an s1 save),
// the fD8/b114 pair must be stored through ONE load of self->o placed after the two log calls,
// and the DAT_002cfc8c bit test materialises as sltu+xori (field==0) with beqzl, not a direct bnez.
// Also FUN_ addresses need EIGHT hex digits (FUN_0001dfe8) or they report MISSING_SYMBOLS.
// near miss from lane dsn3 (unreviewed)
