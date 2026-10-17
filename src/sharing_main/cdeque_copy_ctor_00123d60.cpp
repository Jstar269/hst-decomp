/* HSTMATCH module=hstp_trans_main.prx start=0x00123d60 end=0x00123dd0 symbol=FUN_00123d60 lang=c++ */
/* Clone of src/eboot/cdeque_copy_ctor_00118b8c.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: copy constructor. The base constructor 0x118ca0 takes
   the allocator returned by the out-of-line get_allocator() 0x118cb8; the elements are copied by
   init(x.begin(), x.end(), forward_iterator_tag()) 0x11c270. The iterators come back by value from the
   out-of-line begin() 0x118c5c / end() 0x118bfc; the tag is a DERIVED empty class (forward : input), whose
   by-value temporary gets the never-written frame slot read with lb. Names provisional. */
struct InTag_00123d60 {};
struct FwdTag_00123d60 : InTag_00123d60 {};
typedef int Elem_00123d60;
struct Iter_00123d60 {
    Elem_00123d60 *ptr;
    Elem_00123d60 *beg;
    Elem_00123d60 *first;
    Elem_00123d60 *end;
};
struct Alloc_00123d60 {};
struct Cdeque_00123d60;
extern "C" const Alloc_00123d60 &FUN_00123e8c(const Cdeque_00123d60 *self);              /* get_allocator */
extern "C" Cdeque_00123d60 *FUN_00123e74(Cdeque_00123d60 *self, const Alloc_00123d60 &a); /* base ctor */
extern "C" Iter_00123d60 FUN_00123e30(const Cdeque_00123d60 *self);                       /* begin */
extern "C" Iter_00123d60 FUN_00123dd0(const Cdeque_00123d60 *self);                       /* end */
extern "C" void FUN_00127444(Cdeque_00123d60 *self, Iter_00123d60 first, Iter_00123d60 last, FwdTag_00123d60);

extern "C" Cdeque_00123d60 *FUN_00123d60(Cdeque_00123d60 *self, const Cdeque_00123d60 *x)
{
    FUN_00123e74(self, FUN_00123e8c(x));
    FUN_00127444(self, FUN_00123e30(x), FUN_00123dd0(x), FwdTag_00123d60());
    return self;
}
