/* HSTMATCH module=hstp_trans_main.prx start=0x00065e04 end=0x00065e94 symbol=FUN_00065e04 lang=c++ */
/* Clone of src/eboot/vec_push_back_00064f40.cpp (hstclone.py tag c41): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style vector of 12-byte vectors (of 4-byte elements): push_back(const value_type &x). With spare
   capacity, construct a copy in place through an allocator temporary (placement new: null-checked) whose
   inlined copy constructor zeroes the three fields and calls range init vec_init_range_00067134 with a
   DERIVED empty forward tag (never-written slot read with lb); otherwise grow through 0x146b44 with a plain
   empty tag (move/seb). The empty allocator temporary's slot puts the forward tag at 20(sp) as in retail;
   plain placement new leaves it at 24(sp). Names provisional. */
inline void *operator new(unsigned, void *p) { return p; }
struct InTag_00065e04 {};
struct FwdTag_00065e04 : InTag_00065e04 {};
struct Tag_00065e04 {};
typedef void *Elem_00065e04;
struct Inner_00065e04;
extern "C" void FUN_00067134(Inner_00065e04 *v, Elem_00065e04 *first, Elem_00065e04 *last, FwdTag_00065e04);
struct Inner_00065e04 {
    Elem_00065e04 *data;
    unsigned size;
    unsigned capacity;
    Inner_00065e04(const Inner_00065e04 &x) : data(0), size(0), capacity(0)
    {
        FUN_00067134(this, x.data, x.data + x.size, FwdTag_00065e04());
    }
};
struct Alloc_00065e04 {
    void construct(Inner_00065e04 *p, const Inner_00065e04 &x) { new (p) Inner_00065e04(x); }
};
struct Outer_00065e04;
extern "C" void FUN_000671e0(Outer_00065e04 *v, const Inner_00065e04 &x, Tag_00065e04);
struct Outer_00065e04 {
    Inner_00065e04 *data;
    unsigned size;
    unsigned capacity;
};
extern "C" void FUN_00065e04(Outer_00065e04 *v, const Inner_00065e04 &x)
{
    if (v->size < v->capacity) {
        Alloc_00065e04().construct(v->data + v->size, x);
        ++v->size;
    } else {
        FUN_000671e0(v, x, Tag_00065e04());
    }
}
