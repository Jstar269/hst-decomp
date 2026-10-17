/* HSTMATCH module=EBOOT.BIN start=0x001916e4 end=0x00191754 symbol=FUN_001916e4 lang=c++ */
/* Clone of src/eboot/cdeque_copy_ctor_00118b8c.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: copy constructor. The base constructor 0x118ca0 takes
   the allocator returned by the out-of-line get_allocator() 0x118cb8; the elements are copied by
   init(x.begin(), x.end(), forward_iterator_tag()) 0x11c270. The iterators come back by value from the
   out-of-line begin() 0x118c5c / end() 0x118bfc; the tag is a DERIVED empty class (forward : input), whose
   by-value temporary gets the never-written frame slot read with lb. Names provisional. */
struct InTag_001916e4 {};
struct FwdTag_001916e4 : InTag_001916e4 {};
typedef int Elem_001916e4;
struct Iter_001916e4 {
    Elem_001916e4 *ptr;
    Elem_001916e4 *beg;
    Elem_001916e4 *first;
    Elem_001916e4 *end;
};
struct Alloc_001916e4 {};
struct Cdeque_001916e4;
extern "C" const Alloc_001916e4 &FUN_00191810(const Cdeque_001916e4 *self);              /* get_allocator */
extern "C" Cdeque_001916e4 *FUN_001917f8(Cdeque_001916e4 *self, const Alloc_001916e4 &a); /* base ctor */
extern "C" Iter_001916e4 FUN_001917b4(const Cdeque_001916e4 *self);                       /* begin */
extern "C" Iter_001916e4 FUN_00191754(const Cdeque_001916e4 *self);                       /* end */
extern "C" void FUN_001923d0(Cdeque_001916e4 *self, Iter_001916e4 first, Iter_001916e4 last, FwdTag_001916e4);

extern "C" Cdeque_001916e4 *FUN_001916e4(Cdeque_001916e4 *self, const Cdeque_001916e4 *x)
{
    FUN_001917f8(self, FUN_00191810(x));
    FUN_001923d0(self, FUN_001917b4(x), FUN_00191754(x), FwdTag_001916e4());
    return self;
}
