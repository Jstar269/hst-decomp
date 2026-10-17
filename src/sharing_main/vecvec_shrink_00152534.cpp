/* HSTMATCH module=hstp_trans_main.prx start=0x00152534 end=0x001525c8 symbol=FUN_00152534 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00065dd0.cpp (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern). Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00152534 {};
struct Elem_00152534 { int v; ~Elem_00152534() {} };
struct Base_00152534 {
    Elem_00152534 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00152534) { size -= n; }
    ~Base_00152534() { int n = size; shrink(n, Alloc_00152534()); delete data; }
};
struct Inner_00152534 : Base_00152534 { ~Inner_00152534() {} };
inline void Destroy_00152534(Inner_00152534 *p) { if (p) p->~Inner_00152534(); }
struct Outer_00152534 { Inner_00152534 *data; int size; };
extern "C" void FUN_00152534(Outer_00152534 *v, int n)
{
    Inner_00152534 *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n)
        Destroy_00152534(--p);
}
