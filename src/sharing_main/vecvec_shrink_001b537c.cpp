/* HSTMATCH module=hstp_trans_main.prx start=0x001b537c end=0x001b5410 symbol=FUN_001b537c lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00065dd0.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern). Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_001b537c {};
struct Elem_001b537c { int v; ~Elem_001b537c() {} };
struct Base_001b537c {
    Elem_001b537c *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_001b537c) { size -= n; }
    ~Base_001b537c() { int n = size; shrink(n, Alloc_001b537c()); delete data; }
};
struct Inner_001b537c : Base_001b537c { ~Inner_001b537c() {} };
inline void Destroy_001b537c(Inner_001b537c *p) { if (p) p->~Inner_001b537c(); }
struct Outer_001b537c { Inner_001b537c *data; int size; };
extern "C" void FUN_001b537c(Outer_001b537c *v, int n)
{
    Inner_001b537c *p = v->data + v->size;
    v->size -= n;
    for (; n != 0; --n)
        Destroy_001b537c(--p);
}
