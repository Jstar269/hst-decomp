/* HSTMATCH module=EBOOT.BIN start=0x0017a694 end=0x0017a728 symbol=FUN_0017a694 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00146d44.cpp (hstclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern); a separate loop counter copied from n. Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_0017a694 {};
struct Elem_0017a694 { int v; ~Elem_0017a694() {} };
struct Base_0017a694 {
    Elem_0017a694 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_0017a694) { size -= n; }
    ~Base_0017a694() { int n = size; shrink(n, Alloc_0017a694()); delete data; }
};
struct Inner_0017a694 : Base_0017a694 { ~Inner_0017a694() {} };
inline void Destroy_0017a694(Inner_0017a694 *p) { if (p) p->~Inner_0017a694(); }
struct Outer_0017a694 { Inner_0017a694 *data; int size; };
extern "C" void FUN_0017a694(Outer_0017a694 *v, int n)
{
    Inner_0017a694 *p = v->data + v->size;
    v->size -= n;
    for (int i = n; i != 0; --i)
        Destroy_0017a694(--p);
}
