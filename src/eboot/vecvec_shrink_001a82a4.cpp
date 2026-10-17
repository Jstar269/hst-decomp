/* HSTMATCH module=EBOOT.BIN start=0x001a82a4 end=0x001a8338 symbol=FUN_001a82a4 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00146d44.cpp (hstclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern); a separate loop counter copied from n. Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_001a82a4 {};
struct Elem_001a82a4 { int v; ~Elem_001a82a4() {} };
struct Base_001a82a4 {
    Elem_001a82a4 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001a82a4) { size -= n; }
    ~Base_001a82a4() { int n = size; shrink(n, Alloc_001a82a4()); delete data; }
};
struct Inner_001a82a4 : Base_001a82a4 { ~Inner_001a82a4() {} };
inline void Destroy_001a82a4(Inner_001a82a4 *p) { if (p) p->~Inner_001a82a4(); }
struct Outer_001a82a4 { Inner_001a82a4 *data; int size; };
extern "C" void FUN_001a82a4(Outer_001a82a4 *v, int n)
{
    Inner_001a82a4 *p = v->data + v->size;
    v->size -= n;
    for (int i = n; i != 0; --i)
        Destroy_001a82a4(--p);
}
