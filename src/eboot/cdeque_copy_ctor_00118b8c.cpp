/* HSTMATCH module=EBOOT.BIN start=0x00118b8c end=0x00118bfc symbol=FUN_00118b8c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: copy constructor. The base constructor 0x118ca0 takes
   the allocator returned by the out-of-line get_allocator() 0x118cb8; the elements are copied by
   init(x.begin(), x.end(), forward_iterator_tag()) 0x11c270. The iterators come back by value from the
   out-of-line begin() 0x118c5c / end() 0x118bfc; the tag is a DERIVED empty class (forward : input), whose
   by-value temporary gets the never-written frame slot read with lb. Names provisional. */
struct InTag_00118b8c {};
struct FwdTag_00118b8c : InTag_00118b8c {};
typedef int Elem_00118b8c;
struct Iter_00118b8c {
    Elem_00118b8c *ptr;
    Elem_00118b8c *beg;
    Elem_00118b8c *first;
    Elem_00118b8c *end;
};
struct Alloc_00118b8c {};
struct Cdeque_00118b8c;
extern "C" const Alloc_00118b8c &FUN_00118cb8(const Cdeque_00118b8c *self);              /* get_allocator */
extern "C" Cdeque_00118b8c *FUN_00118ca0(Cdeque_00118b8c *self, const Alloc_00118b8c &a); /* base ctor */
extern "C" Iter_00118b8c FUN_00118c5c(const Cdeque_00118b8c *self);                       /* begin */
extern "C" Iter_00118b8c FUN_00118bfc(const Cdeque_00118b8c *self);                       /* end */
extern "C" void FUN_0011c270(Cdeque_00118b8c *self, Iter_00118b8c first, Iter_00118b8c last, FwdTag_00118b8c);

extern "C" Cdeque_00118b8c *FUN_00118b8c(Cdeque_00118b8c *self, const Cdeque_00118b8c *x)
{
    FUN_00118ca0(self, FUN_00118cb8(x));
    FUN_0011c270(self, FUN_00118c5c(x), FUN_00118bfc(x), FwdTag_00118b8c());
    return self;
}
