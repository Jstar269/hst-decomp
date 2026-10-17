/* HSTMATCH module=EBOOT.BIN start=0x001a7354 end=0x001a73e8 symbol=FUN_001a7354 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00146d44.cpp (hstclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern); a separate loop counter copied from n. Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_001a7354 {};
struct Elem_001a7354 { int v; ~Elem_001a7354() {} };
struct Base_001a7354 {
    Elem_001a7354 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001a7354) { size -= n; }
    ~Base_001a7354() { int n = size; shrink(n, Alloc_001a7354()); delete data; }
};
struct Inner_001a7354 : Base_001a7354 { ~Inner_001a7354() {} };
inline void Destroy_001a7354(Inner_001a7354 *p) { if (p) p->~Inner_001a7354(); }
struct Outer_001a7354 { Inner_001a7354 *data; int size; };
extern "C" void FUN_001a7354(Outer_001a7354 *v, int n)
{
    Inner_001a7354 *p = v->data + v->size;
    v->size -= n;
    for (int i = n; i != 0; --i)
        Destroy_001a7354(--p);
}
