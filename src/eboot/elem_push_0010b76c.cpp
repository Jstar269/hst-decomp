/* HSTMATCH module=EBOOT.BIN start=0x0010b76c end=0x0010b8cc symbol=FUN_0010b76c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idioms: Elem is a union with a float[3] view (its copy is then the 3x lwc1/swc1 block copy); push_back is an inline member with an unused Tag parameter (frame +16); the two re-reads of the cached index use char* arithmetic. */
struct Tag {};
struct Vec;
extern "C" void FUN_00115f24(void *, void *, Tag);
extern "C" void FUN_0010b684(void *, int, int);
extern "C" void FUN_0010b3cc(void *);

union Elem {
    struct {
        short x;
        short y;
        unsigned char f4;
        unsigned char f5;
        unsigned char f6;
        unsigned char f7;
        int f8;
    } s;
    float f[3];
};

struct Vec {
    Elem *data;
    int count;
    int cap;
    void push_back(const Elem &x, Tag)
    {
        if ((unsigned int)count < (unsigned int)cap) {
            Elem *p = &data[count];
            if (p != 0) {
                *p = x;
            }
            count = count + 1;
        } else {
            FUN_00115f24(this, (void *)&x, Tag());
        }
    }
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
    e.s.x = x;
    e.s.y = y;
    e.s.f4 = c;
    e.s.f8 = v;
    self->vec.push_back(e, Tag());
    if (idx == 0 || flag != 0) {
        self->f110 = idx;
        self->fDC = idx;
        self->fEC = self->vec.data[self->fDC].s.x;
        self->fEE = ((Elem *)((char *)self->vec.data + self->fDC * 12))->s.y;
        FUN_0010b684(self, ((Elem *)((char *)self->vec.data + self->fDC * 12))->s.f8, 1);
        FUN_0010b3cc(self);
    }
    self->fE0 = 0;
    self->fE4 = self->vec.count - 1;
}
