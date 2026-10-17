/* HSTMATCH module=EBOOT.BIN start=0x00066004 end=0x00066098 symbol=FUN_00066004 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00146d44.cpp (hstclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern); a separate loop counter copied from n. Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00066004 {};
struct Elem_00066004 { int v; ~Elem_00066004() {} };
struct Base_00066004 {
    Elem_00066004 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00066004) { size -= n; }
    ~Base_00066004() { int n = size; shrink(n, Alloc_00066004()); delete data; }
};
struct Inner_00066004 : Base_00066004 { ~Inner_00066004() {} };
inline void Destroy_00066004(Inner_00066004 *p) { if (p) p->~Inner_00066004(); }
struct Outer_00066004 { Inner_00066004 *data; int size; };
extern "C" void FUN_00066004(Outer_00066004 *v, int n)
{
    Inner_00066004 *p = v->data + v->size;
    v->size -= n;
    for (int i = n; i != 0; --i)
        Destroy_00066004(--p);
}
