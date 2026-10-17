/* HSTMATCH module=EBOOT.BIN start=0x0023e544 end=0x0023e5c0 symbol=FUN_0023e544 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-a2) corrected by hand: restructured as a vector shrink (inline cut(n, Alloc()) then destroy walk), delete takes the element pointer; exact match verified; names and types await human review. */
struct Elem { unsigned flags; int pad; void *ptr; };
struct Alloc {};
extern "C" void FUN_00000a00(void *);

struct Vec {
  Elem *data;
  int size;
  Elem *cut(int n, Alloc) {
    Elem *p = data + size;
    size -= n;
    return p;
  }
};

extern "C" void FUN_0023e544(Vec *v, int n)
{
  Elem *p = v->cut(n, Alloc());
  for (; n != 0; n--) {
    --p;
    if (p && (p->flags & 1)) FUN_00000a00(p->ptr);
  }
}
