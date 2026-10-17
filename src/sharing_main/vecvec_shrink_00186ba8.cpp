/* HSTMATCH module=hstp_trans_main.prx start=0x00186ba8 end=0x00186c3c symbol=FUN_00186ba8 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00065dd0.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern). Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00186ba8 {};
struct Elem_00186ba8 { int v; ~Elem_00186ba8() {} };
struct Base_00186ba8 {
    Elem_00186ba8 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00186ba8) { size -= n; }
    ~Base_00186ba8() { int n = size; shrink(n, Alloc_00186ba8()); delete data; }
};
struct Inner_00186ba8 : Base_00186ba8 { ~Inner_00186ba8() {} };
inline void Destroy_00186ba8(Inner_00186ba8 *p) { if (p) p->~Inner_00186ba8(); }
struct Outer_00186ba8 { Inner_00186ba8 *data; int size; };
extern "C" void FUN_00186ba8(Outer_00186ba8 *v, int n)
{
    Inner_00186ba8 *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n)
        Destroy_00186ba8(--p);
}
