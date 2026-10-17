/* HSTMATCH module=hstp_trans_main.prx start=0x0024e6dc end=0x0024e758 symbol=FUN_0024e6dc lang=c++ */
/* Clone of src/eboot/vec_shrink_free_0023e544.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_0024e6dc(Vec *v, int n)
{
  Elem *p = v->cut(n, Alloc());
  for (; n != 0; n--) {
    --p;
    if (p && (p->flags & 1)) FUN_00000a00(p->ptr);
  }
}
