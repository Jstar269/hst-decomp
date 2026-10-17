/* HSTMATCH module=EBOOT.BIN start=0x00118cf8 end=0x00118d68 symbol=FUN_00118cf8 lang=c++ */
/* Clone of src/eboot/deque_copy_ctor_00118a64.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 12-byte elements (42 per block): copy constructor, same shape as cdeque_copy_ctor_00118b8c.cpp.
   Base constructor 0x118ae4 takes the allocator returned by get_allocator() 0x118ce8; the elements are copied by
   init(x.begin(), x.end(), forward_iterator_tag()) 0x11c440 (deque_init_range_0011be88.cpp), with the 24-byte
   iterators coming back by value from 0x118adc (begin) / 0x118ad4 (end). Names provisional. */
struct InTag_00118cf8 {};
struct FwdTag_00118cf8 : InTag_00118cf8 {};
struct Elem_00118cf8 { int a; int b; float c; };
typedef Elem_00118cf8 *Block_00118cf8;
struct BlkIter_00118cf8 {
    Block_00118cf8 *ptr;
    Block_00118cf8 *beg;
    Block_00118cf8 *first;
    Block_00118cf8 *end;
};
struct Iter_00118cf8 {
    BlkIter_00118cf8 i_;
    Elem_00118cf8 *cur_;
    Elem_00118cf8 *end_;
    Iter_00118cf8() {}
};
struct Alloc_00118cf8 {};
struct Deque_00118cf8;
extern "C" const Alloc_00118cf8 &FUN_00118f7c(const Deque_00118cf8 *self);              /* get_allocator */
extern "C" Deque_00118cf8 *FUN_00118d78(Deque_00118cf8 *self, const Alloc_00118cf8 &a); /* base ctor */
extern "C" Iter_00118cf8 FUN_00118d70(const Deque_00118cf8 *self);                       /* begin */
extern "C" Iter_00118cf8 FUN_00118d68(const Deque_00118cf8 *self);                       /* end */
extern "C" void FUN_0011be88(Deque_00118cf8 *self, Iter_00118cf8 first, Iter_00118cf8 last, FwdTag_00118cf8);

extern "C" Deque_00118cf8 *FUN_00118cf8(Deque_00118cf8 *self, const Deque_00118cf8 *x)
{
    FUN_00118d78(self, FUN_00118f7c(x));
    FUN_0011be88(self, FUN_00118d70(x), FUN_00118d68(x), FwdTag_00118cf8());
    return self;
}
