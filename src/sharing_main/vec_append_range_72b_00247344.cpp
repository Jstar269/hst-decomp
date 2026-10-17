/* HSTMATCH module=hstp_trans_main.prx start=0x00247344 end=0x00247450 symbol=FUN_00247344 lang=c++ */
/* Clone of src/eboot/vec_append_range_72b_002371e0.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (derived from the 0x165688 / 0xd9ccc forward range-append recipe: copy ctor member-by-member, inline placement new); exact match verified; names and types await human review. */
struct Rgb { unsigned char r, g, b; };
struct Elem_00247344 {
    int id;
    float f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14;
    Rgb c0, c1, c2;
    Elem_00247344(const Elem_00247344 &o) : id(o.id), f1(o.f1), f2(o.f2), f3(o.f3), f4(o.f4), f5(o.f5), f6(o.f6), f7(o.f7), f8(o.f8), f9(o.f9), f10(o.f10), f11(o.f11), f12(o.f12), f13(o.f13), f14(o.f14), c0(o.c0), c1(o.c1), c2(o.c2) {}
};
struct Buf_00247344 {
    Elem_00247344 *data;
    int size;
};
inline void *operator new(unsigned, void *p) { return p; }

extern "C" void FUN_00247344(Buf_00247344 *b, Elem_00247344 *first, Elem_00247344 *last)
{
    Elem_00247344 *p = b->data + b->size;
    for (; first < last; ++first) {
        new (p) Elem_00247344(*first);
        ++p;
        ++b->size;
    }
}
