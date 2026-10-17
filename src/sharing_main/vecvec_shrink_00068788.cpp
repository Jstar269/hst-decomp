/* HSTMATCH module=hstp_trans_main.prx start=0x00068788 end=0x0006881c symbol=FUN_00068788 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00065dd0.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern). Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00068788 {};
struct Elem_00068788 { int v; ~Elem_00068788() {} };
struct Base_00068788 {
    Elem_00068788 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00068788) { size -= n; }
    ~Base_00068788() { int n = size; shrink(n, Alloc_00068788()); delete data; }
};
struct Inner_00068788 : Base_00068788 { ~Inner_00068788() {} };
inline void Destroy_00068788(Inner_00068788 *p) { if (p) p->~Inner_00068788(); }
struct Outer_00068788 { Inner_00068788 *data; int size; };
extern "C" void FUN_00068788(Outer_00068788 *v, int n)
{
    Inner_00068788 *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n)
        Destroy_00068788(--p);
}
