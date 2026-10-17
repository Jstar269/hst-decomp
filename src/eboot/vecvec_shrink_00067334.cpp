/* HSTMATCH module=EBOOT.BIN start=0x00067334 end=0x000673c8 symbol=FUN_00067334 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00146c4c.cpp (hstclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern). Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00067334 {};
struct Elem_00067334 { int v; ~Elem_00067334() {} };
struct Base_00067334 {
    Elem_00067334 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00067334) { size -= n; }
    ~Base_00067334() { int n = size; shrink(n, Alloc_00067334()); delete data; }
};
struct Inner_00067334 : Base_00067334 { ~Inner_00067334() {} };
inline void Destroy_00067334(Inner_00067334 *p) { if (p) p->~Inner_00067334(); }
struct Outer_00067334 { Inner_00067334 *data; int size; };
extern "C" void FUN_00067334(Outer_00067334 *v, int n)
{
    Inner_00067334 *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n)
        Destroy_00067334(--p);
}
