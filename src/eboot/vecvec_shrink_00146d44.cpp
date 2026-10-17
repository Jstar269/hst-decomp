/* HSTMATCH module=EBOOT.BIN start=0x00146d44 end=0x00146dd8 symbol=FUN_00146d44 lang=c++ */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern); a separate loop counter copied from n. Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00146d44 {};
struct Elem_00146d44 { int v; ~Elem_00146d44() {} };
struct Base_00146d44 {
    Elem_00146d44 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00146d44) { size -= n; }
    ~Base_00146d44() { int n = size; shrink(n, Alloc_00146d44()); delete data; }
};
struct Inner_00146d44 : Base_00146d44 { ~Inner_00146d44() {} };
inline void Destroy_00146d44(Inner_00146d44 *p) { if (p) p->~Inner_00146d44(); }
struct Outer_00146d44 { Inner_00146d44 *data; int size; };
extern "C" void FUN_00146d44(Outer_00146d44 *v, int n)
{
    Inner_00146d44 *p = v->data + v->size;
    v->size -= n;
    for (int i = n; i != 0; --i)
        Destroy_00146d44(--p);
}
