/* HSTMATCH module=hstp_trans_main.prx start=0x0015262c end=0x001526c0 symbol=FUN_0015262c lang=c++ */
/* Clone of src/eboot/vecvec_shrink_00066004.cpp (hstclone.py tag x15): addresses substituted; exact match verified; names and types await human review. */
/* Destroy the last n elements of a vector of 12-byte containers: shrink the size, then walk back over
   the removed elements; destroy(p) checks p, and the inline derived and base destructors each add a
   null check before the container body (the 0xfc2ec pattern); a separate loop counter copied from n. Needs inline_depth(8). Names provisional. */
#pragma inline_depth(8)
struct Alloc_0015262c {};
struct Elem_0015262c { int v; ~Elem_0015262c() {} };
struct Base_0015262c {
    Elem_0015262c *data;
    int size;
    unsigned capacity;
    void shrink(int n, Alloc_0015262c) { size -= n; }
    ~Base_0015262c() { int n = size; shrink(n, Alloc_0015262c()); delete data; }
};
struct Inner_0015262c : Base_0015262c { ~Inner_0015262c() {} };
inline void Destroy_0015262c(Inner_0015262c *p) { if (p) p->~Inner_0015262c(); }
struct Outer_0015262c { Inner_0015262c *data; int size; };
extern "C" void FUN_0015262c(Outer_0015262c *v, int n)
{
    Inner_0015262c *p = v->data + v->size;
    v->size -= n;
    for (int i = n; i != 0; --i)
        Destroy_0015262c(--p);
}
