/* HSTMATCH module=hstp_trans_main.prx start=0x0019def4 end=0x0019df64 symbol=FUN_0019def4 lang=c++ */
/* Clone of src/eboot/cdeque_copy_ctor_00118b8c.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: copy constructor. The base constructor 0x118ca0 takes
   the allocator returned by the out-of-line get_allocator() 0x118cb8; the elements are copied by
   init(x.begin(), x.end(), forward_iterator_tag()) 0x11c270. The iterators come back by value from the
   out-of-line begin() 0x118c5c / end() 0x118bfc; the tag is a DERIVED empty class (forward : input), whose
   by-value temporary gets the never-written frame slot read with lb. Names provisional. */
struct InTag_0019def4 {};
struct FwdTag_0019def4 : InTag_0019def4 {};
typedef int Elem_0019def4;
struct Iter_0019def4 {
    Elem_0019def4 *ptr;
    Elem_0019def4 *beg;
    Elem_0019def4 *first;
    Elem_0019def4 *end;
};
struct Alloc_0019def4 {};
struct Cdeque_0019def4;
extern "C" const Alloc_0019def4 &FUN_0019e020(const Cdeque_0019def4 *self);              /* get_allocator */
extern "C" Cdeque_0019def4 *FUN_0019e008(Cdeque_0019def4 *self, const Alloc_0019def4 &a); /* base ctor */
extern "C" Iter_0019def4 FUN_0019dfc4(const Cdeque_0019def4 *self);                       /* begin */
extern "C" Iter_0019def4 FUN_0019df64(const Cdeque_0019def4 *self);                       /* end */
extern "C" void FUN_0019ebe0(Cdeque_0019def4 *self, Iter_0019def4 first, Iter_0019def4 last, FwdTag_0019def4);

extern "C" Cdeque_0019def4 *FUN_0019def4(Cdeque_0019def4 *self, const Cdeque_0019def4 *x)
{
    FUN_0019e008(self, FUN_0019e020(x));
    FUN_0019ebe0(self, FUN_0019dfc4(x), FUN_0019df64(x), FwdTag_0019def4());
    return self;
}
