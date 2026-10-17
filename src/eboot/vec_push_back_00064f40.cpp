/* HSTMATCH module=EBOOT.BIN start=0x00064f40 end=0x00064fd0 symbol=FUN_00064f40 lang=c++ */
/* Clone of src/eboot/vec_push_back_00146368.cpp (hstclone.py tag c40): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style vector of 12-byte vectors (of 4-byte elements): push_back(const value_type &x). With spare
   capacity, construct a copy in place through an allocator temporary (placement new: null-checked) whose
   inlined copy constructor zeroes the three fields and calls range init vec_init_range_00065ce0 with a
   DERIVED empty forward tag (never-written slot read with lb); otherwise grow through 0x146b44 with a plain
   empty tag (move/seb). The empty allocator temporary's slot puts the forward tag at 20(sp) as in retail;
   plain placement new leaves it at 24(sp). Names provisional. */
inline void *operator new(unsigned, void *p) { return p; }
struct InTag_00064f40 {};
struct FwdTag_00064f40 : InTag_00064f40 {};
struct Tag_00064f40 {};
typedef void *Elem_00064f40;
struct Inner_00064f40;
extern "C" void FUN_00065ce0(Inner_00064f40 *v, Elem_00064f40 *first, Elem_00064f40 *last, FwdTag_00064f40);
struct Inner_00064f40 {
    Elem_00064f40 *data;
    unsigned size;
    unsigned capacity;
    Inner_00064f40(const Inner_00064f40 &x) : data(0), size(0), capacity(0)
    {
        FUN_00065ce0(this, x.data, x.data + x.size, FwdTag_00064f40());
    }
};
struct Alloc_00064f40 {
    void construct(Inner_00064f40 *p, const Inner_00064f40 &x) { new (p) Inner_00064f40(x); }
};
struct Outer_00064f40;
extern "C" void FUN_00065d8c(Outer_00064f40 *v, const Inner_00064f40 &x, Tag_00064f40);
struct Outer_00064f40 {
    Inner_00064f40 *data;
    unsigned size;
    unsigned capacity;
};
extern "C" void FUN_00064f40(Outer_00064f40 *v, const Inner_00064f40 &x)
{
    if (v->size < v->capacity) {
        Alloc_00064f40().construct(v->data + v->size, x);
        ++v->size;
    } else {
        FUN_00065d8c(v, x, Tag_00064f40());
    }
}
