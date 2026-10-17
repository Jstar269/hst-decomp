/* HSTMATCH module=EBOOT.BIN start=0x0025b090 end=0x0025b100 symbol=FUN_0025b090 lang=c++ */
/* Clone of src/eboot/cdeque_copy_ctor_00118b8c.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: copy constructor. The base constructor 0x118ca0 takes
   the allocator returned by the out-of-line get_allocator() 0x118cb8; the elements are copied by
   init(x.begin(), x.end(), forward_iterator_tag()) 0x11c270. The iterators come back by value from the
   out-of-line begin() 0x118c5c / end() 0x118bfc; the tag is a DERIVED empty class (forward : input), whose
   by-value temporary gets the never-written frame slot read with lb. Names provisional. */
struct InTag_0025b090 {};
struct FwdTag_0025b090 : InTag_0025b090 {};
typedef int Elem_0025b090;
struct Iter_0025b090 {
    Elem_0025b090 *ptr;
    Elem_0025b090 *beg;
    Elem_0025b090 *first;
    Elem_0025b090 *end;
};
struct Alloc_0025b090 {};
struct Cdeque_0025b090;
extern "C" const Alloc_0025b090 &FUN_0025b1bc(const Cdeque_0025b090 *self);              /* get_allocator */
extern "C" Cdeque_0025b090 *FUN_0025b1a4(Cdeque_0025b090 *self, const Alloc_0025b090 &a); /* base ctor */
extern "C" Iter_0025b090 FUN_0025b160(const Cdeque_0025b090 *self);                       /* begin */
extern "C" Iter_0025b090 FUN_0025b100(const Cdeque_0025b090 *self);                       /* end */
extern "C" void FUN_0025bcc8(Cdeque_0025b090 *self, Iter_0025b090 first, Iter_0025b090 last, FwdTag_0025b090);

extern "C" Cdeque_0025b090 *FUN_0025b090(Cdeque_0025b090 *self, const Cdeque_0025b090 *x)
{
    FUN_0025b1a4(self, FUN_0025b1bc(x));
    FUN_0025bcc8(self, FUN_0025b160(x), FUN_0025b100(x), FwdTag_0025b090());
    return self;
}
