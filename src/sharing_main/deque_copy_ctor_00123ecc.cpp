/* HSTMATCH module=hstp_trans_main.prx start=0x00123ecc end=0x00123f3c symbol=FUN_00123ecc lang=c++ */
/* Clone of src/eboot/deque_copy_ctor_00118a64.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 12-byte elements (42 per block): copy constructor, same shape as cdeque_copy_ctor_00118b8c.cpp.
   Base constructor 0x118ae4 takes the allocator returned by get_allocator() 0x118ce8; the elements are copied by
   init(x.begin(), x.end(), forward_iterator_tag()) 0x11c440 (deque_init_range_0012705c.cpp), with the 24-byte
   iterators coming back by value from 0x118adc (begin) / 0x118ad4 (end). Names provisional. */
struct InTag_00123ecc {};
struct FwdTag_00123ecc : InTag_00123ecc {};
struct Elem_00123ecc { int a; int b; float c; };
typedef Elem_00123ecc *Block_00123ecc;
struct BlkIter_00123ecc {
    Block_00123ecc *ptr;
    Block_00123ecc *beg;
    Block_00123ecc *first;
    Block_00123ecc *end;
};
struct Iter_00123ecc {
    BlkIter_00123ecc i_;
    Elem_00123ecc *cur_;
    Elem_00123ecc *end_;
    Iter_00123ecc() {}
};
struct Alloc_00123ecc {};
struct Deque_00123ecc;
extern "C" const Alloc_00123ecc &FUN_00124150(const Deque_00123ecc *self);              /* get_allocator */
extern "C" Deque_00123ecc *FUN_00123f4c(Deque_00123ecc *self, const Alloc_00123ecc &a); /* base ctor */
extern "C" Iter_00123ecc FUN_00123f44(const Deque_00123ecc *self);                       /* begin */
extern "C" Iter_00123ecc FUN_00123f3c(const Deque_00123ecc *self);                       /* end */
extern "C" void FUN_0012705c(Deque_00123ecc *self, Iter_00123ecc first, Iter_00123ecc last, FwdTag_00123ecc);

extern "C" Deque_00123ecc *FUN_00123ecc(Deque_00123ecc *self, const Deque_00123ecc *x)
{
    FUN_00123f4c(self, FUN_00124150(x));
    FUN_0012705c(self, FUN_00123f44(x), FUN_00123f3c(x), FwdTag_00123ecc());
    return self;
}
