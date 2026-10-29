/* HSTMATCH module=hstp_trans_main.prx start=0x000c4d90 end=0x000c5140 symbol=FUN_000c4d90 lang=c++ */
/* Clone of src/eboot/vec_erase_one_000c16f0.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (replaces the ds2 near miss, whose hand-unrolled copy and sign-bit guard are not needed: the plain element-wise copy loop makes MWCC emit its own 8x unroll, trip-count guard and 64-byte block copy); exact match verified; names and types await human review. */
struct Blob {
    char v[64];
};
struct Rec {
    Blob a;
    int b0, b1, b2, b3;
    Rec(const Rec &o) : a(o.a), b0(o.b0), b1(o.b1), b2(o.b2), b3(o.b3) {}
};
struct C {
    Rec *data;
    int size;
};
extern "C" Rec *FUN_000c4d90(C *c, Rec *first)
{
    Rec *end = c->data + c->size;
    if (end - first - 1 != 0) {
        Rec *src = first + 1;
        Rec *dst = first;
        for (; src < end; ++src, ++dst)
            *dst = *src;
    }
    c->size--;
    return first;
}
