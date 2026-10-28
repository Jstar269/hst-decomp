/* HSTMATCH module=hstp_trans_main.prx start=0x00147e58 end=0x00147f10 symbol=FUN_00147e58 lang=c++ */
/* Clone of src/eboot/bitvec_push_back_0013c80c.cpp (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" unsigned FUN_000605c0(BitVec *v, unsigned n);
extern "C" void FUN_00060020(BitVec *v, unsigned n);
extern "C" void FUN_00147e58(BitVec *v, bool x)
{
    if (v->size == v->cap * 32) {
        FUN_00060020(v, FUN_000605c0(v, 1));
    }
    ++v->size;
    v->at(v->size - 1) = x;
}
