/* HSTMATCH module=EBOOT.BIN start=0x002371e0 end=0x002372ec symbol=FUN_002371e0 lang=c++ */
/* Hand-written reconstruction from the disassembly (derived from the 0x165688 / 0xd9ccc forward range-append recipe: copy ctor member-by-member, inline placement new); exact match verified; names and types await human review. */
struct Rgb { unsigned char r, g, b; };
struct Elem_002371e0 {
    int id;
    float f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14;
    Rgb c0, c1, c2;
    Elem_002371e0(const Elem_002371e0 &o) : id(o.id), f1(o.f1), f2(o.f2), f3(o.f3), f4(o.f4), f5(o.f5), f6(o.f6), f7(o.f7), f8(o.f8), f9(o.f9), f10(o.f10), f11(o.f11), f12(o.f12), f13(o.f13), f14(o.f14), c0(o.c0), c1(o.c1), c2(o.c2) {}
};
struct Buf_002371e0 {
    Elem_002371e0 *data;
    int size;
};
inline void *operator new(unsigned, void *p) { return p; }

extern "C" void FUN_002371e0(Buf_002371e0 *b, Elem_002371e0 *first, Elem_002371e0 *last)
{
    Elem_002371e0 *p = b->data + b->size;
    for (; first < last; ++first) {
        new (p) Elem_002371e0(*first);
        ++p;
        ++b->size;
    }
}
