/* HSTMATCH module=hstp_trans_main.prx start=0x001b5870 end=0x001b5904 symbol=FUN_001b5870 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00066004.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern); a separate loop counter copied from n. Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_001b5870 {};
struct Elem_001b5870 { int v; ~Elem_001b5870() {} };
struct Base_001b5870 {
    Elem_001b5870 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001b5870) { size -= n; }
    ~Base_001b5870() { int n = size; shrink(n, Alloc_001b5870()); delete data; }
};
struct Inner_001b5870 : Base_001b5870 { ~Inner_001b5870() {} };
inline void Destroy_001b5870(Inner_001b5870 *p) { if (p) p->~Inner_001b5870(); }
struct Outer_001b5870 { Inner_001b5870 *data; int size; };
extern "C" void FUN_001b5870(Outer_001b5870 *v, int n)
{
    Inner_001b5870 *p = v->data + v->size;
    v->size -= n;
    for (int i = n; i != 0; --i)
        Destroy_001b5870(--p);
}
