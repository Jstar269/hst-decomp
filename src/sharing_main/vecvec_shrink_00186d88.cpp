/* HSTMATCH module=hstp_trans_main.prx start=0x00186d88 end=0x00186e1c symbol=FUN_00186d88 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00066004.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern); a separate loop counter copied from n. Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_00186d88 {};
struct Elem_00186d88 { int v; ~Elem_00186d88() {} };
struct Base_00186d88 {
    Elem_00186d88 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_00186d88) { size -= n; }
    ~Base_00186d88() { int n = size; shrink(n, Alloc_00186d88()); delete data; }
};
struct Inner_00186d88 : Base_00186d88 { ~Inner_00186d88() {} };
inline void Destroy_00186d88(Inner_00186d88 *p) { if (p) p->~Inner_00186d88(); }
struct Outer_00186d88 { Inner_00186d88 *data; int size; };
extern "C" void FUN_00186d88(Outer_00186d88 *v, int n)
{
    Inner_00186d88 *p = v->data + v->size;
    v->size -= n;
    for (int i = n; i != 0; --i)
        Destroy_00186d88(--p);
}
