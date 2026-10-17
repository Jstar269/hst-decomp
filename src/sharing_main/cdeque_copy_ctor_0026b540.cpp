/* HSTMATCH module=hstp_trans_main.prx start=0x0026b540 end=0x0026b5b0 symbol=FUN_0026b540 lang=c++ */
/* Clone of src/eboot/cdeque_copy_ctor_00118b8c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: copy constructor. The base constructor 0x118ca0 takes
   the allocator returned by the out-of-line get_allocator() 0x118cb8; the elements are copied by
   init(x.begin(), x.end(), forward_iterator_tag()) 0x11c270. The iterators come back by value from the
   out-of-line begin() 0x118c5c / end() 0x118bfc; the tag is a DERIVED empty class (forward : input), whose
   by-value temporary gets the never-written frame slot read with lb. Names provisional. */
struct InTag_0026b540 {};
struct FwdTag_0026b540 : InTag_0026b540 {};
typedef int Elem_0026b540;
struct Iter_0026b540 {
    Elem_0026b540 *ptr;
    Elem_0026b540 *beg;
    Elem_0026b540 *first;
    Elem_0026b540 *end;
};
struct Alloc_0026b540 {};
struct Cdeque_0026b540;
extern "C" const Alloc_0026b540 &FUN_0026b66c(const Cdeque_0026b540 *self);              /* get_allocator */
extern "C" Cdeque_0026b540 *FUN_0026b654(Cdeque_0026b540 *self, const Alloc_0026b540 &a); /* base ctor */
extern "C" Iter_0026b540 FUN_0026b610(const Cdeque_0026b540 *self);                       /* begin */
extern "C" Iter_0026b540 FUN_0026b5b0(const Cdeque_0026b540 *self);                       /* end */
extern "C" void FUN_0026c178(Cdeque_0026b540 *self, Iter_0026b540 first, Iter_0026b540 last, FwdTag_0026b540);

extern "C" Cdeque_0026b540 *FUN_0026b540(Cdeque_0026b540 *self, const Cdeque_0026b540 *x)
{
    FUN_0026b654(self, FUN_0026b66c(x));
    FUN_0026c178(self, FUN_0026b610(x), FUN_0026b5b0(x), FwdTag_0026b540());
    return self;
}
