/* HSTMATCH module=EBOOT.BIN start=0x0013c80c end=0x0013c8c4 symbol=FUN_0013c80c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct BitIt {
    unsigned *p;
    unsigned mask;
    BitIt(unsigned *pp, unsigned m) : p(pp), mask(m) {}
    BitIt &operator=(bool x)
    {
        if (x) *p |= mask;
        else *p &= ~mask;
        return *this;
    }
};
struct BitVec {
    unsigned *data;
    unsigned size;
    unsigned cap;
    BitIt at(unsigned i) { return BitIt(data + (i >> 5), 1u << (i & 31)); }
};
extern "C" unsigned FUN_0005f7d0(BitVec *v, unsigned n);
extern "C" void FUN_0005f230(BitVec *v, unsigned n);
extern "C" void FUN_0013c80c(BitVec *v, bool x)
{
    if (v->size == v->cap * 32) {
        FUN_0005f230(v, FUN_0005f7d0(v, 1));
    }
    ++v->size;
    v->at(v->size - 1) = x;
}
