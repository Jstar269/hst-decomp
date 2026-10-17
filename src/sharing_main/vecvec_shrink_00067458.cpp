/* HSTMATCH module=hstp_trans_main.prx start=0x00067458 end=0x000674ec symbol=FUN_00067458 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00066004.cpp (hstclone.py tag x15): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern); a separate loop counter copied from n. Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00067458 {};
struct Elem_00067458 { int v; ~Elem_00067458() {} };
struct Base_00067458 {
    Elem_00067458 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00067458) { size -= n; }
    ~Base_00067458() { int n = size; shrink(n, Alloc_00067458()); delete data; }
};
struct Inner_00067458 : Base_00067458 { ~Inner_00067458() {} };
inline void Destroy_00067458(Inner_00067458 *p) { if (p) p->~Inner_00067458(); }
struct Outer_00067458 { Inner_00067458 *data; int size; };
extern "C" void FUN_00067458(Outer_00067458 *v, int n)
{
    Inner_00067458 *p = v->data + v->size;
    v->size -= n;
    for (int i = n; i != 0; --i)
        Destroy_00067458(--p);
}
