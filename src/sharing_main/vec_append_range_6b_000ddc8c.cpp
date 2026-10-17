/* HSTMATCH module=hstp_trans_main.prx start=0x000ddc8c end=0x000ddd44 symbol=FUN_000ddc8c lang=c++ */
/* Clone of src/eboot/vec_append_range_6b_000d9ccc.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v1) corrected by hand: forward range append of 6-byte elements (copy ctor, inline placement new, unused empty tag parameter and tag temporary for FUN_000de6ec as in the 0x165688 helpers); exact match verified; names and types await human review. */
struct False {};
struct Elem_000ddc8c {
    short a, b, c;
    Elem_000ddc8c(const Elem_000ddc8c &o) : a(o.a), b(o.b), c(o.c) {}
};
struct Buf_000ddc8c {
    Elem_000ddc8c *data;
    int size;
};
inline void *operator new(unsigned, void *p) { return p; }
extern "C" void FUN_000de6ec(Buf_000ddc8c *, int, False);

extern "C" void FUN_000ddc8c(Buf_000ddc8c *b, Elem_000ddc8c *first, Elem_000ddc8c *last, False)
{
    int n = last - first;
    if (n != 0) {
        FUN_000de6ec(b, n, False());
        Elem_000ddc8c *p = b->data + b->size;
        for (; first != last; ++first) {
            new (p) Elem_000ddc8c(*first);
            ++p;
            ++b->size;
        }
    }
}
