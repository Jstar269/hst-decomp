/* HSTMATCH module=hstp_trans_main.prx start=0x00123ff4 end=0x00124064 symbol=FUN_00123ff4 lang=c++ */
/* Clone of src/eboot/cdeque_copy_ctor_00118b8c.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: copy constructor. The base constructor 0x118ca0 takes
   the allocator returned by the out-of-line get_allocator() 0x118cb8; the elements are copied by
   init(x.begin(), x.end(), forward_iterator_tag()) 0x11c270. The iterators come back by value from the
   out-of-line begin() 0x118c5c / end() 0x118bfc; the tag is a DERIVED empty class (forward : input), whose
   by-value temporary gets the never-written frame slot read with lb. Names provisional. */
struct InTag_00123ff4 {};
struct FwdTag_00123ff4 : InTag_00123ff4 {};
typedef int Elem_00123ff4;
struct Iter_00123ff4 {
    Elem_00123ff4 *ptr;
    Elem_00123ff4 *beg;
    Elem_00123ff4 *first;
    Elem_00123ff4 *end;
};
struct Alloc_00123ff4 {};
struct Cdeque_00123ff4;
extern "C" const Alloc_00123ff4 &FUN_00124120(const Cdeque_00123ff4 *self);              /* get_allocator */
extern "C" Cdeque_00123ff4 *FUN_00124108(Cdeque_00123ff4 *self, const Alloc_00123ff4 &a); /* base ctor */
extern "C" Iter_00123ff4 FUN_001240c4(const Cdeque_00123ff4 *self);                       /* begin */
extern "C" Iter_00123ff4 FUN_00124064(const Cdeque_00123ff4 *self);                       /* end */
extern "C" void FUN_00126e8c(Cdeque_00123ff4 *self, Iter_00123ff4 first, Iter_00123ff4 last, FwdTag_00123ff4);

extern "C" Cdeque_00123ff4 *FUN_00123ff4(Cdeque_00123ff4 *self, const Cdeque_00123ff4 *x)
{
    FUN_00124108(self, FUN_00124120(x));
    FUN_00126e8c(self, FUN_001240c4(x), FUN_00124064(x), FwdTag_00123ff4());
    return self;
}
