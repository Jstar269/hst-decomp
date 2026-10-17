/* HSTMATCH module=hstp_trans_main.prx start=0x00067224 end=0x000672b8 symbol=FUN_00067224 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00065dd0.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern). Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00067224 {};
struct Elem_00067224 { int v; ~Elem_00067224() {} };
struct Base_00067224 {
    Elem_00067224 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00067224) { size -= n; }
    ~Base_00067224() { int n = size; shrink(n, Alloc_00067224()); delete data; }
};
struct Inner_00067224 : Base_00067224 { ~Inner_00067224() {} };
inline void Destroy_00067224(Inner_00067224 *p) { if (p) p->~Inner_00067224(); }
struct Outer_00067224 { Inner_00067224 *data; int size; };
extern "C" void FUN_00067224(Outer_00067224 *v, int n)
{
    Inner_00067224 *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n)
        Destroy_00067224(--p);
}
