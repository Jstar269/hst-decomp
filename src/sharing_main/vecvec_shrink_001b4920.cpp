/* HSTMATCH module=hstp_trans_main.prx start=0x001b4920 end=0x001b49b4 symbol=FUN_001b4920 lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00066004.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern); a separate loop counter copied from n. Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_001b4920 {};
struct Elem_001b4920 { int v; ~Elem_001b4920() {} };
struct Base_001b4920 {
    Elem_001b4920 *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001b4920) { size -= n; }
    ~Base_001b4920() { int n = size; shrink(n, Alloc_001b4920()); delete data; }
};
struct Inner_001b4920 : Base_001b4920 { ~Inner_001b4920() {} };
inline void Destroy_001b4920(Inner_001b4920 *p) { if (p) p->~Inner_001b4920(); }
struct Outer_001b4920 { Inner_001b4920 *data; int size; };
extern "C" void FUN_001b4920(Outer_001b4920 *v, int n)
{
    Inner_001b4920 *p = v->data + v->size;
    v->size -= n;
    for (int i = n; i != 0; --i)
        Destroy_001b4920(--p);
}
