/* HSTMATCH module=hstp_trans_main.prx start=0x00157184 end=0x00157218 symbol=FUN_00157184 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00065dd0.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern). Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00157184 {};
struct Elem_00157184 { int v; ~Elem_00157184() {} };
struct Base_00157184 {
    Elem_00157184 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00157184) { size -= n; }
    ~Base_00157184() { int n = size; shrink(n, Alloc_00157184()); delete data; }
};
struct Inner_00157184 : Base_00157184 { ~Inner_00157184() {} };
inline void Destroy_00157184(Inner_00157184 *p) { if (p) p->~Inner_00157184(); }
struct Outer_00157184 { Inner_00157184 *data; int size; };
extern "C" void FUN_00157184(Outer_00157184 *v, int n)
{
    Inner_00157184 *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n)
        Destroy_00157184(--p);
}
