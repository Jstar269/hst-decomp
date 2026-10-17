/* HSTMATCH module=EBOOT.BIN start=0x00118a64 end=0x00118ad4 symbol=FUN_00118a64 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 12-byte elements (42 per block): copy constructor, same shape as cdeque_copy_ctor_00118b8c.cpp.
   Base constructor 0x118ae4 takes the allocator returned by get_allocator() 0x118ce8; the elements are copied by
   init(x.begin(), x.end(), forward_iterator_tag()) 0x11c440 (deque_init_range_0011c440.cpp), with the 24-byte
   iterators coming back by value from 0x118adc (begin) / 0x118ad4 (end). Names provisional. */
struct InTag_00118a64 {};
struct FwdTag_00118a64 : InTag_00118a64 {};
struct Elem_00118a64 { int a; int b; float c; };
typedef Elem_00118a64 *Block_00118a64;
struct BlkIter_00118a64 {
    Block_00118a64 *ptr;
    Block_00118a64 *beg;
    Block_00118a64 *first;
    Block_00118a64 *end;
};
struct Iter_00118a64 {
    BlkIter_00118a64 i_;
    Elem_00118a64 *cur_;
    Elem_00118a64 *end_;
    Iter_00118a64() {}
};
struct Alloc_00118a64 {};
struct Deque_00118a64;
extern "C" const Alloc_00118a64 &FUN_00118ce8(const Deque_00118a64 *self);              /* get_allocator */
extern "C" Deque_00118a64 *FUN_00118ae4(Deque_00118a64 *self, const Alloc_00118a64 &a); /* base ctor */
extern "C" Iter_00118a64 FUN_00118adc(const Deque_00118a64 *self);                       /* begin */
extern "C" Iter_00118a64 FUN_00118ad4(const Deque_00118a64 *self);                       /* end */
extern "C" void FUN_0011c440(Deque_00118a64 *self, Iter_00118a64 first, Iter_00118a64 last, FwdTag_00118a64);

extern "C" Deque_00118a64 *FUN_00118a64(Deque_00118a64 *self, const Deque_00118a64 *x)
{
    FUN_00118ae4(self, FUN_00118ce8(x));
    FUN_0011c440(self, FUN_00118adc(x), FUN_00118ad4(x), FwdTag_00118a64());
    return self;
}
