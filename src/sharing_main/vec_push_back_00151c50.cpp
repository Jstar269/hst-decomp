/* HSTMATCH module=hstp_trans_main.prx start=0x00151c50 end=0x00151ce0 symbol=FUN_00151c50 lang=c++ */
/* Clone of src/eboot/vec_push_back_00064f40.cpp (hstclone.py tag c41): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style vector of 12-byte vectors (of 4-byte elements): push_back(const value_type &x). With spare
   capacity, construct a copy in place through an allocator temporary (placement new: null-checked) whose
   inlined copy constructor zeroes the three fields and calls range init vec_init_range_00151de8 with a
   DERIVED empty forward tag (never-written slot read with lb); otherwise grow through 0x146b44 with a plain
   empty tag (move/seb). The empty allocator temporary's slot puts the forward tag at 20(sp) as in retail;
   plain placement new leaves it at 24(sp). Names provisional. */
inline void *operator new(unsigned, void *p) { return p; }
struct InTag_00151c50 {};
struct FwdTag_00151c50 : InTag_00151c50 {};
struct Tag_00151c50 {};
typedef void *Elem_00151c50;
struct Inner_00151c50;
extern "C" void FUN_00151de8(Inner_00151c50 *v, Elem_00151c50 *first, Elem_00151c50 *last, FwdTag_00151c50);
struct Inner_00151c50 {
    Elem_00151c50 *data;
    unsigned size;
    unsigned capacity;
    Inner_00151c50(const Inner_00151c50 &x) : data(0), size(0), capacity(0)
    {
        FUN_00151de8(this, x.data, x.data + x.size, FwdTag_00151c50());
    }
};
struct Alloc_00151c50 {
    void construct(Inner_00151c50 *p, const Inner_00151c50 &x) { new (p) Inner_00151c50(x); }
};
struct Outer_00151c50;
extern "C" void FUN_0015242c(Outer_00151c50 *v, const Inner_00151c50 &x, Tag_00151c50);
struct Outer_00151c50 {
    Inner_00151c50 *data;
    unsigned size;
    unsigned capacity;
};
extern "C" void FUN_00151c50(Outer_00151c50 *v, const Inner_00151c50 &x)
{
    if (v->size < v->capacity) {
        Alloc_00151c50().construct(v->data + v->size, x);
        ++v->size;
    } else {
        FUN_0015242c(v, x, Tag_00151c50());
    }
}
