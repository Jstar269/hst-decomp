/* HSTMATCH module=EBOOT.BIN start=0x00118e20 end=0x00118e90 symbol=FUN_00118e20 lang=c++ */
/* Clone of src/eboot/cdeque_copy_ctor_00118b8c.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: copy constructor. The base constructor 0x118ca0 takes
   the allocator returned by the out-of-line get_allocator() 0x118cb8; the elements are copied by
   init(x.begin(), x.end(), forward_iterator_tag()) 0x11c270. The iterators come back by value from the
   out-of-line begin() 0x118c5c / end() 0x118bfc; the tag is a DERIVED empty class (forward : input), whose
   by-value temporary gets the never-written frame slot read with lb. Names provisional. */
struct InTag_00118e20 {};
struct FwdTag_00118e20 : InTag_00118e20 {};
typedef int Elem_00118e20;
struct Iter_00118e20 {
    Elem_00118e20 *ptr;
    Elem_00118e20 *beg;
    Elem_00118e20 *first;
    Elem_00118e20 *end;
};
struct Alloc_00118e20 {};
struct Cdeque_00118e20;
extern "C" const Alloc_00118e20 &FUN_00118f4c(const Cdeque_00118e20 *self);              /* get_allocator */
extern "C" Cdeque_00118e20 *FUN_00118f34(Cdeque_00118e20 *self, const Alloc_00118e20 &a); /* base ctor */
extern "C" Iter_00118e20 FUN_00118ef0(const Cdeque_00118e20 *self);                       /* begin */
extern "C" Iter_00118e20 FUN_00118e90(const Cdeque_00118e20 *self);                       /* end */
extern "C" void FUN_0011bcb8(Cdeque_00118e20 *self, Iter_00118e20 first, Iter_00118e20 last, FwdTag_00118e20);

extern "C" Cdeque_00118e20 *FUN_00118e20(Cdeque_00118e20 *self, const Cdeque_00118e20 *x)
{
    FUN_00118f34(self, FUN_00118f4c(x));
    FUN_0011bcb8(self, FUN_00118ef0(x), FUN_00118e90(x), FwdTag_00118e20());
    return self;
}
