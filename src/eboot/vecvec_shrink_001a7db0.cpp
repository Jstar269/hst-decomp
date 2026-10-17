/* HSTMATCH module=EBOOT.BIN start=0x001a7db0 end=0x001a7e44 symbol=FUN_001a7db0 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00146c4c.cpp (hstclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern). Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_001a7db0 {};
struct Elem_001a7db0 { int v; ~Elem_001a7db0() {} };
struct Base_001a7db0 {
    Elem_001a7db0 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001a7db0) { size -= n; }
    ~Base_001a7db0() { int n = size; shrink(n, Alloc_001a7db0()); delete data; }
};
struct Inner_001a7db0 : Base_001a7db0 { ~Inner_001a7db0() {} };
inline void Destroy_001a7db0(Inner_001a7db0 *p) { if (p) p->~Inner_001a7db0(); }
struct Outer_001a7db0 { Inner_001a7db0 *data; int size; };
extern "C" void FUN_001a7db0(Outer_001a7db0 *v, int n)
{
    Inner_001a7db0 *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n)
        Destroy_001a7db0(--p);
}
