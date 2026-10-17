/* HSTMATCH module=EBOOT.BIN start=0x00237ee0 end=0x00237ff4 symbol=FUN_00237ee0 lang=c++ */
/* Hand-written reconstruction from the disassembly (backward range copy into the front of a split buffer; recipe of src/eboot/vec_move_front_range_00165c30.cpp with the 72-byte element and inline placement new of src/eboot/vec_append_range_72b_002371e0.cpp); exact match verified; names and types await human review. */
struct Rgb { unsigned char r, g, b; };
struct Elem_00237ee0 {
    int id;
    float f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14;
    Rgb c0, c1, c2;
    Elem_00237ee0(const Elem_00237ee0 &o) : id(o.id), f1(o.f1), f2(o.f2), f3(o.f3), f4(o.f4), f5(o.f5), f6(o.f6), f7(o.f7), f8(o.f8), f9(o.f9), f10(o.f10), f11(o.f11), f12(o.f12), f13(o.f13), f14(o.f14), c0(o.c0), c1(o.c1), c2(o.c2) {}
};
struct Buf_00237ee0 {
    Elem_00237ee0 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
};
inline void *operator new(unsigned, void *p) { return p; }

extern "C" void FUN_00237ee0(Buf_00237ee0 *b, Elem_00237ee0 *first, Elem_00237ee0 *last)
{
    Elem_00237ee0 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        new (p) Elem_00237ee0(*last);
        --b->start;
        ++b->size;
    }
}
