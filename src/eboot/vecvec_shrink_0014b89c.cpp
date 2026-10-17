/* HSTMATCH module=EBOOT.BIN start=0x0014b89c end=0x0014b930 symbol=FUN_0014b89c lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00146c4c.cpp (hstclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern). Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_0014b89c {};
struct Elem_0014b89c { int v; ~Elem_0014b89c() {} };
struct Base_0014b89c {
    Elem_0014b89c *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_0014b89c) { size -= n; }
    ~Base_0014b89c() { int n = size; shrink(n, Alloc_0014b89c()); delete data; }
};
struct Inner_0014b89c : Base_0014b89c { ~Inner_0014b89c() {} };
inline void Destroy_0014b89c(Inner_0014b89c *p) { if (p) p->~Inner_0014b89c(); }
struct Outer_0014b89c { Inner_0014b89c *data; int size; };
extern "C" void FUN_0014b89c(Outer_0014b89c *v, int n)
{
    Inner_0014b89c *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n)
        Destroy_0014b89c(--p);
}
