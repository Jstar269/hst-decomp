/* HSTMATCH module=EBOOT.BIN start=0x0014e4a8 end=0x0014e650 symbol=FUN_0014e4a8 lang=c++ rodata=0x002c1a50 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Element factory: builds the element object for a type code read from the stream (cases 1/2 a 4-byte word
   read as int or float, case 3 an object holding a packed 4/12-bit halfword, 4..15 no payload); the caller is
   the container reader 0x14df40. The vtable pointers are written explicitly (base 0x308460 first, then the
   derived one), as the inlined constructors do.
   Matching idioms: C++ `new` with inline constructors (the C spelling of the same stores gives other branch
   fills); case 3 is initialised through an inline helper that takes the raw allocation as `void *` and converts
   it to a local, which keeps the allocation result in v0 for the first stores and the object in s1 after the
   calls (a constructor or a same-type copy is coalesced into one register). */
struct Stream {
    char *cur;
};

extern "C" {
int FUN_0014f028(Stream *s);            /* read a 4-byte word */
float FUN_0014f014(Stream *s);          /* read a 4-byte float */
unsigned short FUN_0014f050(Stream *s); /* read a halfword */
extern char DAT_00308460[], DAT_003083f0[], DAT_00308444[], DAT_0030840c[], DAT_00308428[], DAT_003082b8[];
}

union Word {
    int i;
    float f;
};

struct Elem {
    void *vt;
    int type;
    Elem(int t) { vt = DAT_00308460; type = t; }
};

struct WordElem : Elem {
    Word value;
    WordElem(int t, Word v) : Elem(t) { vt = DAT_003083f0; value = v; }
};

struct Field {
    void *vt;
    unsigned char flag;
    Field() { vt = DAT_0030840c; flag = 0; }
};

struct PackedField : Field {
    int hi;
    int lo;
    PackedField(Stream *s)
    {
        unsigned short h;
        vt = DAT_00308428;
        h = FUN_0014f050(s);
        hi = (h >> 12) & 0xf;
        lo = h & 0xfff;
    }
};

struct FieldElem {
    void *vt;
    int type;
    PackedField *field;
};

static inline FieldElem *InitFieldElem(void *mem, int t, Stream *s)
{
    FieldElem *self = (FieldElem *)mem;
    self->vt = DAT_00308460;
    self->type = t;
    self->vt = DAT_00308444;
    FUN_0014f050(s);
    self->field = new PackedField(s);
    return self;
}

struct EmptyElem : Elem {
    EmptyElem(int t) : Elem(t) { vt = DAT_003082b8; }
};

extern "C" void *FUN_0014e4a8(void *self, int type, Stream *s)
{
    void *r = 0;
    switch (type) {
    case 1: {
        Word v;
        v.i = FUN_0014f028(s);
        r = new WordElem(type, v);
        break;
    }
    case 2: {
        Word v;
        v.f = FUN_0014f014(s);
        r = new WordElem(type, v);
        break;
    }
    case 3: {
        void *p = operator new(12);
        if (p != 0)
            p = InitFieldElem(p, type, s);
        r = p;
        break;
    }
    case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
        r = new EmptyElem(type);
        break;
    }
    return r;
}
