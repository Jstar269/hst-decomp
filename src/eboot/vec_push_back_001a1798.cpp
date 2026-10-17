/* HSTMATCH module=EBOOT.BIN start=0x001a1798 end=0x001a1828 symbol=FUN_001a1798 lang=c++ */
/* Clone of src/eboot/vec_push_back_00146368.cpp (hstclone.py tag c40): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style vector of 12-byte vectors (of 4-byte elements): push_back(const value_type &x). With spare
   capacity, construct a copy in place through an allocator temporary (placement new: null-checked) whose
   inlined copy constructor zeroes the three fields and calls range init vec_init_range_001a5b14 with a
   DERIVED empty forward tag (never-written slot read with lb); otherwise grow through 0x146b44 with a plain
   empty tag (move/seb). The empty allocator temporary's slot puts the forward tag at 20(sp) as in retail;
   plain placement new leaves it at 24(sp). Names provisional. */
inline void *operator new(unsigned, void *p) { return p; }
struct InTag_001a1798 {};
struct FwdTag_001a1798 : InTag_001a1798 {};
struct Tag_001a1798 {};
typedef void *Elem_001a1798;
struct Inner_001a1798;
extern "C" void FUN_001a5b14(Inner_001a1798 *v, Elem_001a1798 *first, Elem_001a1798 *last, FwdTag_001a1798);
struct Inner_001a1798 {
    Elem_001a1798 *data;
    unsigned size;
    unsigned capacity;
    Inner_001a1798(const Inner_001a1798 &x) : data(0), size(0), capacity(0)
    {
        FUN_001a5b14(this, x.data, x.data + x.size, FwdTag_001a1798());
    }
};
struct Alloc_001a1798 {
    void construct(Inner_001a1798 *p, const Inner_001a1798 &x) { new (p) Inner_001a1798(x); }
};
struct Outer_001a1798;
extern "C" void FUN_001a66f8(Outer_001a1798 *v, const Inner_001a1798 &x, Tag_001a1798);
struct Outer_001a1798 {
    Inner_001a1798 *data;
    unsigned size;
    unsigned capacity;
};
extern "C" void FUN_001a1798(Outer_001a1798 *v, const Inner_001a1798 &x)
{
    if (v->size < v->capacity) {
        Alloc_001a1798().construct(v->data + v->size, x);
        ++v->size;
    } else {
        FUN_001a66f8(v, x, Tag_001a1798());
    }
}
