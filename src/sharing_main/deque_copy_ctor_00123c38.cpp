/* HSTMATCH module=hstp_trans_main.prx start=0x00123c38 end=0x00123ca8 symbol=FUN_00123c38 lang=c++ */
/* Clone of src/eboot/deque_copy_ctor_00118a64.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 12-byte elements (42 per block): copy constructor, same shape as cdeque_copy_ctor_00118b8c.cpp.
   Base constructor 0x118ae4 takes the allocator returned by get_allocator() 0x118ce8; the elements are copied by
   init(x.begin(), x.end(), forward_iterator_tag()) 0x11c440 (deque_init_range_00127614.cpp), with the 24-byte
   iterators coming back by value from 0x118adc (begin) / 0x118ad4 (end). Names provisional. */
struct InTag_00123c38 {};
struct FwdTag_00123c38 : InTag_00123c38 {};
struct Elem_00123c38 { int a; int b; float c; };
typedef Elem_00123c38 *Block_00123c38;
struct BlkIter_00123c38 {
    Block_00123c38 *ptr;
    Block_00123c38 *beg;
    Block_00123c38 *first;
    Block_00123c38 *end;
};
struct Iter_00123c38 {
    BlkIter_00123c38 i_;
    Elem_00123c38 *cur_;
    Elem_00123c38 *end_;
    Iter_00123c38() {}
};
struct Alloc_00123c38 {};
struct Deque_00123c38;
extern "C" const Alloc_00123c38 &FUN_00123ebc(const Deque_00123c38 *self);              /* get_allocator */
extern "C" Deque_00123c38 *FUN_00123cb8(Deque_00123c38 *self, const Alloc_00123c38 &a); /* base ctor */
extern "C" Iter_00123c38 FUN_00123cb0(const Deque_00123c38 *self);                       /* begin */
extern "C" Iter_00123c38 FUN_00123ca8(const Deque_00123c38 *self);                       /* end */
extern "C" void FUN_00127614(Deque_00123c38 *self, Iter_00123c38 first, Iter_00123c38 last, FwdTag_00123c38);

extern "C" Deque_00123c38 *FUN_00123c38(Deque_00123c38 *self, const Deque_00123c38 *x)
{
    FUN_00123cb8(self, FUN_00123ebc(x));
    FUN_00127614(self, FUN_00123cb0(x), FUN_00123ca8(x), FwdTag_00123c38());
    return self;
}
