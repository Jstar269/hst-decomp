/* HSTMATCH module=EBOOT.BIN start=0x0010b76c end=0x0010b8cc symbol=FUN_0010b76c lang=c++ */
extern "C" void FUN_00115f24(void *, void *, int);
extern "C" void FUN_0010b684(void *, int, int);
extern "C" void FUN_0010b3cc(void *);

struct Elem {
    short x;
    short y;
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    int f8;
};

struct Vec {
    Elem *data;
    int count;
    int cap;
};

struct Self {
    char pad0[0xDC];
    int fDC;
    int fE0;
    int fE4;
    char pad1[4];
    short fEC;
    short fEE;
    char pad2[0x110 - 0xF0];
    int f110;
    char pad3[0x120 - 0x114];
    Vec vec;
};

extern "C" void FUN_0010b76c(Self *self, short x, short y, int flag, unsigned char c, int v) {
    int idx = self->vec.count;
    Elem e = { 0 };
    e.x = x;
    e.y = y;
    e.f4 = c;
    e.f8 = v;
    if ((unsigned int)self->vec.count < (unsigned int)self->vec.cap) {
        Elem *p = &self->vec.data[self->vec.count];
        if (p != 0) {
            *p = e;
        }
        self->vec.count = self->vec.count + 1;
    } else {
        FUN_00115f24(&self->vec, &e, 0);
    }
    if (idx == 0 || flag != 0) {
        self->f110 = idx;
        self->fDC = idx;
        self->fEC = self->vec.data[idx].x;
        self->fEE = self->vec.data[idx].y;
        FUN_0010b684(self, self->vec.data[idx].f8, 1);
        FUN_0010b3cc(self);
    }
    self->fE0 = 0;
    self->fE4 = self->vec.count - 1;
}
// near miss (86/88 words): the element copy in the in-range path is 3 lwc1/swc1 pairs from
// the stack temp in retail, but MWCC expands our `*p = e` into field stores (sh/sh/sb/sw) from
// the initialiser values, and the tail re-derives `data[idx]` per access in retail (one lw of
// the index member between accesses) where we keep one pointer; the element temp also sits at
// sp+36 in a 48-byte frame in retail, sp+20 in our 32-byte frame.
// near miss from lane ds10 (unreviewed)
