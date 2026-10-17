/* HSTMATCH module=EBOOT.BIN start=0x00146368 end=0x001463f8 symbol=FUN_00146368 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style vector of 12-byte vectors (of 4-byte elements): push_back(const value_type &x). With spare
   capacity, construct a copy in place through an allocator temporary (placement new: null-checked) whose
   inlined copy constructor zeroes the three fields and calls range init vec_init_range_00146500 with a
   DERIVED empty forward tag (never-written slot read with lb); otherwise grow through 0x146b44 with a plain
   empty tag (move/seb). The empty allocator temporary's slot puts the forward tag at 20(sp) as in retail;
   plain placement new leaves it at 24(sp). Names provisional. */
inline void *operator new(unsigned, void *p) { return p; }
struct InTag_00146368 {};
struct FwdTag_00146368 : InTag_00146368 {};
struct Tag_00146368 {};
typedef void *Elem_00146368;
struct Inner_00146368;
extern "C" void FUN_00146500(Inner_00146368 *v, Elem_00146368 *first, Elem_00146368 *last, FwdTag_00146368);
struct Inner_00146368 {
    Elem_00146368 *data;
    unsigned size;
    unsigned capacity;
    Inner_00146368(const Inner_00146368 &x) : data(0), size(0), capacity(0)
    {
        FUN_00146500(this, x.data, x.data + x.size, FwdTag_00146368());
    }
};
struct Alloc_00146368 {
    void construct(Inner_00146368 *p, const Inner_00146368 &x) { new (p) Inner_00146368(x); }
};
struct Outer_00146368;
extern "C" void FUN_00146b44(Outer_00146368 *v, const Inner_00146368 &x, Tag_00146368);
struct Outer_00146368 {
    Inner_00146368 *data;
    unsigned size;
    unsigned capacity;
};
extern "C" void FUN_00146368(Outer_00146368 *v, const Inner_00146368 &x)
{
    if (v->size < v->capacity) {
        Alloc_00146368().construct(v->data + v->size, x);
        ++v->size;
    } else {
        FUN_00146b44(v, x, Tag_00146368());
    }
}
