/* HSTMATCH module=hstp_trans_main.prx start=0x001aed64 end=0x001aedf4 symbol=FUN_001aed64 lang=c++ */
/* Clone of src/eboot/vec_push_back_00064f40.cpp (hstclone.py tag c41): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style vector of 12-byte vectors (of 4-byte elements): push_back(const value_type &x). With spare
   capacity, construct a copy in place through an allocator temporary (placement new: null-checked) whose
   inlined copy constructor zeroes the three fields and calls range init vec_init_range_001b30e0 with a
   DERIVED empty forward tag (never-written slot read with lb); otherwise grow through 0x146b44 with a plain
   empty tag (move/seb). The empty allocator temporary's slot puts the forward tag at 20(sp) as in retail;
   plain placement new leaves it at 24(sp). Names provisional. */
inline void *operator new(unsigned, void *p) { return p; }
struct InTag_001aed64 {};
struct FwdTag_001aed64 : InTag_001aed64 {};
struct Tag_001aed64 {};
typedef void *Elem_001aed64;
struct Inner_001aed64;
extern "C" void FUN_001b30e0(Inner_001aed64 *v, Elem_001aed64 *first, Elem_001aed64 *last, FwdTag_001aed64);
struct Inner_001aed64 {
    Elem_001aed64 *data;
    unsigned size;
    unsigned capacity;
    Inner_001aed64(const Inner_001aed64 &x) : data(0), size(0), capacity(0)
    {
        FUN_001b30e0(this, x.data, x.data + x.size, FwdTag_001aed64());
    }
};
struct Alloc_001aed64 {
    void construct(Inner_001aed64 *p, const Inner_001aed64 &x) { new (p) Inner_001aed64(x); }
};
struct Outer_001aed64;
extern "C" void FUN_001b3cc4(Outer_001aed64 *v, const Inner_001aed64 &x, Tag_001aed64);
struct Outer_001aed64 {
    Inner_001aed64 *data;
    unsigned size;
    unsigned capacity;
};
extern "C" void FUN_001aed64(Outer_001aed64 *v, const Inner_001aed64 &x)
{
    if (v->size < v->capacity) {
        Alloc_001aed64().construct(v->data + v->size, x);
        ++v->size;
    } else {
        FUN_001b3cc4(v, x, Tag_001aed64());
    }
}
