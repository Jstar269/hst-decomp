/* HSTMATCH module=EBOOT.BIN start=0x0006af20 end=0x0006b064 symbol=FUN_0006af20 lang=c++ */
/* Clone of src/sharing_main/vec_append_range_0006c508.cpp (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

inline void *operator new(unsigned, void *p) { return p; }
struct Tag_0006af20 {};
struct S2 { short a, b; };
struct S3 { short a, b, c; };

struct Elem_0006af20 {
    short s0, s1, s2, s3, s4;
    S2 sub1;
    S2 sub2;
    S3 sub3;
    S3 sub4;
    S2 sub5;
    short s17, s18, s19;

    Elem_0006af20(const Elem_0006af20 &o)
        : s0(o.s0), s1(o.s1), s2(o.s2), s3(o.s3), s4(o.s4),
          sub1(o.sub1), sub2(o.sub2), sub3(o.sub3), sub4(o.sub4), sub5(o.sub5),
          s17(o.s17), s18(o.s18), s19(o.s19) {}
};

struct Vec_0006af20 {
    Elem_0006af20 *data;
    unsigned size;
    unsigned cap;
};

extern "C" void FUN_0006d708(Vec_0006af20 *, unsigned, Tag_0006af20);

extern "C" void FUN_0006af20(Vec_0006af20 *self, const Elem_0006af20 *first, const Elem_0006af20 *last)
{
    unsigned n = ((char *)last - (char *)first) / (int)sizeof(Elem_0006af20);
    if (n != 0) {
        FUN_0006d708(self, n, Tag_0006af20());
        Elem_0006af20 *p = self->data + self->size;
        for (; first != last; ++first) {
            new (p) Elem_0006af20(*first);
            ++p;
            ++self->size;
        }
    }
}
